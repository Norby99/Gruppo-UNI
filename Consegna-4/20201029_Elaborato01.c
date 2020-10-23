/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201022
 NOTE:    Text Ex01: Siano dati due vettori di interi di lunghezza differente i cui valori sono inseriti da tastiera.
          Scrivere un programma C che generi un terzo vettore contenente l’intersezione tra i due vettori di input.
          Se un elemento è comune ai due vettori e presente più volte in un vettore farlo comparire anche nel vettore risultato.
          Implementare la variante in cui le ripetizioni non sono presenti nel risultato.
          Implementare inoltre anche l'inserimento random dei valori nei vettori.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define RANDOMNUMBER 5

int *randomisedArray(int);

int main(void)
{
    // entering array values
    int i, n1, n2, n3;
    int *a1, *a2, *a3, *a4;
    char inputType;
    int j, n4=0;
    bool flag=false, fl=false, f=false;

    printf("\"Intersection between 2 arrays\"");
    do
    {
        printf("\nDo you want to manually or randomly enter numbers?\nDigit m for manual and r for random: ");
        scanf("%c", &inputType);
        fflush(stdin);
        if (inputType != 'm' && inputType != 'r')
            printf("!! The character format is invalid. Please enter m or r.");
        else
        {
           do
            {
                printf("\n\nEnter array 1 length: ");
                scanf(" %d", &n1);
                a1 = malloc(sizeof(int) * n1);

                if (n1<=0)
                {
                    printf("!! The length format is invalid. Please put a number >0.\n");
                    continue;
                }
                else if (inputType=='m')
                {
                    printf("Fill the array:\n");
                    for (i=0; i<n1; i++)
                    {
                        printf("%d: ", i); //I'd like to put i++ here to order from 1 to 10 the output, but it messes the code up
                        scanf(" %d", &a1[i]);
                    }
                }
                else if(inputType == 'r'){
                        a1 = randomisedArray(n1);
                }
                // do-while loop to check if there's a different input length besides checking n2 correct length value
                do
                {
                    printf("\nEnter array 2 length: ");
                    scanf("%d", &n2);
                    a2 = malloc(sizeof(int) * n2);

                    if (n2<=0)
                    {
                        printf("!! The length format is invalid. Please put a number >0.\n");
                        continue;
                    }
                    if (n2==n1)
                    {
                        printf("\n!! Value must be different from the previous one.\n");
                    } else if (inputType=='m')
                    {
                        printf("Fill the array:\n");
                        for (i=0; i<n2; i++)
                        {
                            printf("%d: ", i); //I'd like to put i++ here to order from 1 to 10 the output, but it messes the code up
                            scanf(" %d", &a2[i]);
                        }
                    }else if(inputType == 'r'){
                        a2 = randomisedArray(n2);
                }
                } while (n2==n1||n2<=0);
            } while(n1<=0);
        }
    } while(inputType != 'm' && inputType != 'r');

    // finding intersections and storing them in a 3rd array
    a3 = malloc(sizeof(int) * n1);
    a4 = malloc(sizeof(int) * n1);
    for(i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)
        {
            if(a2[j] == a1[i])
            {
                flag = true;
                fl=true;
                break;
            }
        }
        if(flag == true)
        {
            a3[n3]=a2[j];

            f=false;
            for (j=0; j<n3; j++)
            {
                if (a4[j]==a3[n3])
                {
                    f=true;
                    break;
                }
            }
            if (f==false)
            {
                a4[n4]=a3[n3];
                n4++;
            }
            n3++;
        }
        flag = false;
    }

    // output of the final array

    if(inputType == 'r'){
        printf("\nArray 1:\n");
        for (i=0; i<n1; i++)
            printf("%d ", a1[i]);
        printf("\nArray 2:\n");
        for (i=0; i<n2; i++)
            printf("%d ", a2[i]);
    }
    if (fl==false)
        printf("\nThere's no intersection between the 2 arrays.\n");
    else
    {
        printf("\nHere's the full array with all intersections between the 2 arrays:\n");
        for (i=0; i<n3; i++)
            printf("%d ", a3[i]);
        printf("\nHere's the full array without repetitions all intersections between the 2 arrays:\n");
        for (i=0; i<n4; i++)
            printf("%d ", a4[i]);
    }

    printf("\n\n\n\n");
    system("pause");
    return 0;
}
// external randomize function
int *randomisedArray(int length){
    int *array = malloc(length * sizeof(*array));
    srand(time(NULL));

    for(int i=0; i<length; i++){
        array[i] = (rand() % RANDOMNUMBER);
    }
    return array;
}
