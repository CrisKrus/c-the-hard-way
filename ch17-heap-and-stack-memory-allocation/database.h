#pragma once
#include "constants.h"
#include "address.h"
#include "connection.h"

struct Database {
    struct Address rows[MAX_ROWS];
};

void Database_load(struct Connection*);
struct Connection *Database_open(const char*, char);
void Database_close(struct Connection*);
void Database_write(struct Connection*);
void Database_create(struct Connection*);
void Database_set(struct Connection*, int, const char*, const char*);
void Database_get(struct Connection*, int);
void Database_delete(struct Connection*, int);
void Database_list(struct Connection*);
