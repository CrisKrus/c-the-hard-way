#ifndef __ADDRESS_H__
#define __ADDRESS_H__
#include "constants.h"

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};
void Address_print(struct Address*);
#endif
