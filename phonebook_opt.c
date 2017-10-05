#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

slot_unit *findName(char lastName[],slot_unit *hashpos)
{

    while (hashpos != NULL) {
        if (strcasecmp(lastName, hashpos->lastName) == 0)
            return hashpos;
        hashpos = hashpos->pNext;
    }
    return NULL;

}
void *append(char lastName[],unsigned int pos)
{

    while(strcmp(hashTable[pos]->lastName, "\000")) {
        hashTable[pos]->pNext = (slot_unit *) malloc(sizeof(slot_unit));
        hashTable[pos]=hashTable[pos]->pNext;
    }
    strcpy(hashTable[pos]->lastName, lastName);
    hashTable[pos]->pNext = (slot_unit *) malloc(sizeof(slot_unit));
    hashTable[pos]=hashTable[pos]->pNext;
}
unsigned int stringToInt(char *key)
{
    int number = 0;
    while (*key)
        number += (int)*key++;
    return number;
}
unsigned int hashFunction(unsigned int key)
{
    return key & ((1<<TWO_POWER_NUM)-1);
}

