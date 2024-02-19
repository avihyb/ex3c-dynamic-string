#include "StrLIst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _StrList
{
    size_t size;
    char** strings;
};

typedef struct _StrList StrList;

StrList* StrList_alloc(){
    StrList* list = (StrList*) malloc(sizeof(StrList));
    if(list != NULL){
        list->size = 0;
        list->strings = NULL;
    }
}

void StrList_free(StrList* StrList){
    if(StrList != NULL){
        for(size_t i = 0; i < StrList->size; i++){
            free(StrList->strings[i]);
        }
    }
}