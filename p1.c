#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "fis.h"

El_t initEl()
{
    El_t elem;
    elem.key = 2 + rand()%12;
    elem.value = 10 + rand()%200/8.0;
    return elem;
} //creare elemente random

int main ()
{
    int n, key, index;
    printf("Introduceti un numar pentru generarea aleatoare de elemente: ");
    scanf("%d", &n);
    
    KVS_t *kvs = NULL;
    srand(time(0));
    
    for(int i = 0; i < n; i++)
        kvs = adauga(kvs,initEl());//adaugare elemente
    
    printKVS(kvs);//afisare kvs
    
    printf("Care cheie sa fie cautata?\n");
    scanf("%d", &key);
    
    index = cauta(kvs, key);//cautare cheie
    printf("Cheia %d ",key);
    if(index != -1)
        printf("apare la indexul %d\n", index);
    else
        printf("nu apare in tablou\n");
    
    free(kvs->array);
    free(kvs);//eliberare memorie
    return 0;
}
