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

#define RANDOMNUMBER 5

int *randomisedArray(int);

int main(void)
{
    int i, j, k=0, length;
    char inputType;
    bool temp;
    int *vet1;

    printf("Vuoi inserire i dati manualmente o in maniera randomica? Inserisci m per manuale o r per randomica seguito dai numeri di valori ez = [r 8]:\n");
    scanf(" %c %d", &inputType, &length);

    /* DA FARE: inserire controllo sugli input!!! */
    if(inputType == 'm'){
        for (i=0; i<length; i++)
        {
            printf("Inserisci un valore %d:", i+1);
            scanf("%d", &vet1[i]);
        } 

    }else if(inputType == 'r'){
        vet1 = randomisedArray(length);
    }
    int vet2[length];

    for (i=0; length>i; i++)
    {
        printf("%d, ", vet1[i]);
    }

    for (i=0; i<length; i++)
    {
        temp=false;

        for (j=0; j<k; j++)
        {
            if ((vet2[j] == vet1[i]) || vet1[i] == 0)
            {
                temp=true;
                break;
            }
        }
        if (temp==false)
            vet2[k++]=vet1[i];
    }


    /* blocco dei print */
    printf("\nArray 1:\n");
    for (i=0; length>i; i++)
    {
        printf("%d, ", vet1[i]);
    }

    printf("\nArray 2:\n");
    for (i=0; k>i; i++)
    {
        printf("%d, ", vet2[i]);
    }

    return 0;
}

int *randomisedArray(int length){
    int *array = malloc(length * sizeof(*array));
    srand(time(NULL));

    for(int i=0; i<length; i++){
        array[i] = (rand() % RANDOMNUMBER);
    }
    return array;
}
