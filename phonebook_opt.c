#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    char name[MAX_LAST_NAME_SIZE] = "";
    strncpy(name,lastname+MINUS,MAX_LAST_NAME_SIZE-MINUS);
    while(pHead!=NULL) {
        //printf("%s\n",pHead->lastName);
        if(!strcasecmp(name, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void init_head_char()
{
    int i = 0;
    int j = 0;
    for(i = 0; i<26; i++)
        for(j = 0; j<27; j++)
            head_char[i][j] = NULL;
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
    strncpy(new_entry->lastName,lastName+MINUS,MAX_LAST_NAME_SIZE-MINUS);
    e->pNext = new_entry;
    new_entry->pNext = temp;
    return e;
}
