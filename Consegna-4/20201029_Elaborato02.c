/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201022
 NOTE:    Text Ex02: Scrivere un programma C che legga N numeri interi da tastiera e li memorizzi in un vettore.
          Il programma deve generare un secondo vettore compattando i numeri contenuti nel primo vettore. In particolare:
            1. ogni numero che compare ripetuto nel primo vettore, deve comparire una sola volta nel secondo vettore
            2. ogni numero uguale a zero presente nel primo vettore non deve comparire nel secondo vettore
          Prevedere anche la versione in cui i numeri sono generati random.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int *randomisedArray(int);

int main(void)
{
    int i, j, n = 6;
    bool temp;

    int *vet1, vet2[n];

    vet1 = randomisedArray(n);
/*
    for (i=0; i<n; i++)
    {
        temp=false;

        for (j=0; j<(sizeof (vet2)/sizeof (vet2[0])); j++)
        {
            if ((vet2[j] == vet1[i]) || vet2[j]==0)
                temp=true;
        }
        if (temp==false)
            vet2[(sizeof (vet2)/sizeof (vet2[0]))]=vet1[i];
    }*/

    for (i=0; n>i; i++)
    {
        printf("%d, ", vet1[i]);
    }

    return 0;
}

int *randomisedArray(int length){
    int *array = malloc(length * sizeof(*array));
    srand(time(NULL));

    for(int i=0; i<length; i++){
        array[i] = (rand() % 100);
    }
    return array;
}
