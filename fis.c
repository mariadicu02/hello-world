#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "fis.h"

KVS_t* init()
{
    El_t* ar = malloc(sizeof(El_t));
    if(!ar)
    {
        printf("nu se poate crea un tablou");
        exit(-1);
    }
    KVS_t* p = malloc(sizeof(KVS_t));
    if(!p)
    {
        printf("nu se poate crea un kvs");
        free(ar);
        exit(-1);
    }
    p->size = 1;
    p->array = ar;
    return p;
}//initializare kvs -> complexitate O(1)


KVS_t* adauga(KVS_t *kvs, El_t elem)
{
    El_t *p;
    
    if(kvs == NULL)
        kvs = init();
    else
    {
        kvs->size++;
        if((p = realloc(kvs->array,sizeof(El_t)*kvs->size))==NULL)
        {
            printf("nu se poate realoca");
            free(kvs->array);
            free(kvs);
            exit(-1);
        }
        kvs->array = p;
    }
    kvs->array[kvs->size-1] = elem;
    return kvs;
}//adaugare in tablou -> O(1)

void printKVS(KVS_t *kvs)
{
    for(int i = 0; i < kvs->size; i++)
        printf("%d = %g\n", kvs->array[i].key, kvs->array[i].value);
}//afisare kvs -> O(n)

int cauta(KVS_t* kvs, unsigned k)
{
    for(int i = 0; i < kvs->size; i++)
        if(kvs->array[i].key == k)
            return i;
    return -1;
}//cautare cheie -> O(n)
