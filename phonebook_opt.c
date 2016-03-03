#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    while(pHead!=NULL) {
        if(!strcasecmp(lastname, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    //int index = lastName[0] - 97;
    //header_char[index]->pNext = (entry *)malloc(sizeof(entry));
    e->pNext = (entry *)malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName,lastName);
    e->pNext = NULL;
    return e;
}
