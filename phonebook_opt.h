#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define OPT 1

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define TWO_POWER_NUM 8
#define MAX_HASH_TABLE_SIZE 1 << TWO_POWER_NUM

typedef struct __HASH_SLOT {
    struct __PHONE_BOOK_EXCEPT *info;
    char lastName[MAX_LAST_NAME_SIZE];
    struct __HASH_SLOT *pNext;
} slot_unit;

slot_unit *hashTable[MAX_HASH_TABLE_SIZE];
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __PHONE_BOOK_EXCEPT {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} except;

slot_unit *findName(char lastName[], slot_unit *hashpos);
void *append(char lastName[],unsigned int pos);
unsigned int stringToInt(char *key);
unsigned int hashFunction(unsigned int key);

#endif
