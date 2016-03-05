#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MINUS 2

#define OPT 1

static int index_first;
static int index_second;

typedef struct _PHONEBOOK_REST_ITEM {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail_item;

typedef struct __PHONE_BOOK_ENTRY {
    //char lastName[MAX_LAST_NAME_SIZE-MINUS];
    char *lastName;
    detail_item *rest;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

static entry *head_char1[24][27];
static entry *head_char0[2][28];

void init_head_char();
entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
