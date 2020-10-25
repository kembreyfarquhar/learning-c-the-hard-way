#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//initialize max size for data and rows
#define MAX_DATA 512
#define MAX_ROWS 100

//set up address struct
struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

//set up database struct
//the db may contain rows of address structs up to MAX_ROWS amount
struct Database {
	struct Address rows[MAX_ROWS];
};

//set up connection struct
//this containts a FILE where the data is stored object as well as the db
struct Connection {
	FILE *file;
	struct Database *db;
};

//message for errors that prints and exits the program
void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}

//prints a single address passed in 
void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

//can accept a name or email to search the database with, printing any matches
void a_search_char(struct Connection *conn, const char* key, const char* value)
{
	int i = 0;
	struct Database *db = conn->db;
	const char* name = "name";
	const char* email = "email";
	int found = 0;
	
	for(i=0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		if(strcmp(key, name) == 0 && strcmp(cur->name, value) == 0){
			Address_print(cur);
			found = 1;
		} else if(strcmp(key, email) == 0 && strcmp(cur->email, value) == 0){
			Address_print(cur);
			found = 1;
		}
	}
	
	if(found == 0)
		die("No records were found with given information");
}

void Database_load(struct Connection *conn)
{
	//load db so it's ready for reading and writing
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	
	if (rc != 1)
		die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	//allocate size for connection 
	struct Connection *conn = malloc(sizeof(struct Connection));
	
	if (!conn)
		die("Memory error");
		
	//allocate size for database 
	conn->db = malloc(sizeof(struct Database));
	if (!conn->db)
		die("Memory error");
		
	if (mode == 'c') {
		conn->file = fopen(filename, "w"); //Opens a text file for both reading and writing. 
											//It first truncates the file to zero length if it exists,
											//otherwise creates a file if it does not exist.
	} else {
		conn->file = fopen(filename, "r+"); //both for reading and writing
		
		//first checks for connection file, then loads it
		if(conn->file){
			Database_load(conn);
		}
	}
	
	if(!conn->file)
		die("Failed to open the file.");
		
	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn) {
		if(conn->file)
			fclose(conn->file);
		if(conn->db)
			free(conn->db);
		free(conn);
	}
}

//called when initializing db as well as when writing new input and when deleting db
void Database_write(struct Connection *conn)
{
	//Moves the file position indicator to the beginning of the given file stream.
	rewind(conn->file);
	
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die("Failed to write database.");
	
	rc = fflush(conn->file);
	if(rc == -1)
		die("Cannot flush database.");
}

//initialize db
void Database_create(struct Connection *conn)
{
	int i = 0;
	
	for(i = 0; i < MAX_ROWS; i++){
		//make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		//then just assign it
		conn->db->rows[i] = addr;
	}
}

//set given info into db
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
		die("Already set, delete it first.");
	
	addr->set = 1;
	//WARNING: bug, read the "How to break it" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	//demonstrate the strncpy bug
	if(!res)
		die("Name copy failed");
	
	res = strncpy(addr->email, email, MAX_DATA);
	if(!res)
		die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	
	if(addr->set){
		Address_print(addr);
	} else {
		die("ID is not set");
	}
	
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

//list all currently set rows of db 
void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	
	for(i=0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		
		if(cur->set){
			Address_print(cur);
		}
	}
}

int main (int argc, char *argv[])
{
	if (argc < 3) 
		die("USAGE: ex17 <dbfile> <action> [action params]");
		
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;
	
	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");
	
	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc == 4){
				Database_get(conn, id);
			} else if (argc == 5){
				a_search_char(conn, argv[3], argv[4]);
			} else {
				die("Incorrect search arguments.");
			}
			break;
		case 's':
			if(argc != 6)
				die("Need id, name, email to set");
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc != 4)
				die("Need id to delete");
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}
	
	Database_close(conn);
	
	return 0;
}
