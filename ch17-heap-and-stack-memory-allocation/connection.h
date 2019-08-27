#pragma once
#include "database.h"

struct Connection {
    FILE *file;
    struct Database *db;
};
