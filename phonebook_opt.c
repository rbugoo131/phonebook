#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    while(pHead!=NULL) {
        //printf("%s\n",pHead->lastName);
        if(!strcasecmp(lastname, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void init_head_char()
{
    int i = 0;
    for(i = 0; i<26; i++)
        head_char[i] = NULL;
}

entry *append(char lastName[], entry *e)
{
    entry *temp;
    if(e == NULL) {
        e = (entry*)malloc(sizeof(entry));
        temp = NULL;
    } else
        temp = e->pNext;
    entry *new_entry;
    new_entry = (entry *)malloc(sizeof(entry));
    //e = e->pNext;
    //strcpy(e->lastName,lastName);
    strcpy(new_entry->lastName,lastName);
    e->pNext = new_entry;
    new_entry->pNext = temp;
    return e;
}

void test(entry *e)
{
    while(e!=NULL) {
        printf("%s\n",e->lastName);
        e = e->pNext;
    }
}
