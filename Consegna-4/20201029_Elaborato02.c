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
    // entering values
    int i, j, k=0, length;
    char inputType;
    bool temp;
    int *vet1;
    // input control
    do
    {
        printf("Do you want to manually or randomly enter numbers?\nDigit m for manual and r for random: ");
        scanf("%c", &inputType);
        fflush(stdin);
        if (inputType != 'm' && inputType != 'r')
            printf("!! The character format is invalid. Please enter m or r.");
        else
        {
            do
            {
                printf("Insert length: ");
                scanf("%d", &length);
                fflush(stdin);
                if (length<=0)
                    printf("!! The length format is invalid. Please put a number >0.");
            }
            while (length<=0);
            if(inputType == 'm')
            {
                vet1 = malloc(sizeof(int) * length);
                for (i=0; i<length; i++)
                    {
                        printf("Inserisci un valore %d:", i+1);
                        scanf(" %d", &vet1[i]);
                    }
                }else if(inputType == 'r'){
                    vet1 = randomisedArray(length);
                }
            }
    }while(inputType != 'm' && inputType != 'r');
    // formatting the final array without 0s and duplicates
    int vet2[length];
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
    // printing output
    printf("\nInput array:\n");
    for (i=0; length>i; i++)
    {
        printf("%d, ", vet1[i]);
    }
    printf("\n\nFinal formatted array:\n");
    for (i=0; k>i; i++)
    {
        printf("%d, ", vet2[i]);
    }
    printf("\n\n\n\n");
    system("pause");
    return 0;
}
// external randomize function
int *randomisedArray(int length)
{
    int *array = malloc(length * sizeof(*array));
    srand(time(NULL));
    // filling the array with integer random numbers
    for(int i=0; i<length; i++){
        array[i] = -(rand() % RANDOMNUMBER)+(rand() % RANDOMNUMBER);
    }
    return array;
}
