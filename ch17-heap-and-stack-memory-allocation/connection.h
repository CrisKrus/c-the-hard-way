#pragma once
#include "database.h"
#include <stdio.h>

struct Connection {
    FILE *file;
    struct Database *db;
};
