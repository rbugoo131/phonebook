#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{
    char name[MAX_LAST_NAME_SIZE] = "";
    int length = 0;
    int compare_length = sizeof(pHead->lastName);
    length = strlen(lastname)-MINUS;
    strncpy(name,lastname+MINUS,length);
    while(pHead!=NULL) {
        compare_length = (pHead->lastName == NULL) ? 0 : strlen(pHead->lastName);
        if(length == compare_length) {
            if(!strcasecmp(name, pHead->lastName))
                return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

void init_head_char()
{
    int i = 0;
    int j = 0;
    for(i = 0; i<24; i++)
        for(j = 0; j<27; j++)
            head_char1[i][j] = NULL;
    for(i=0; i<2; i++)
        for(j=0; j<28; j++)
            head_char0[i][j] = NULL;
}

entry *append(char lastName[], entry *e)
{
    int length = strlen(lastName)-MINUS;
    entry *temp;
    if(e == NULL) {
        e = (entry*)malloc(sizeof(entry));
        temp = NULL;
    } else
        temp = e->pNext;
    entry *new_entry;
    new_entry = (entry *)malloc(sizeof(entry));
    new_entry->lastName = (char*)malloc(length * sizeof(char));
    strncpy(new_entry->lastName,lastName+MINUS, length);
    e->pNext = new_entry;
    new_entry->pNext = temp;
    return e;
}
