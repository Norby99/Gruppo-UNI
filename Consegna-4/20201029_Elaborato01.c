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
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    // entering array values
    int i, n1, n2, n3=0;
    printf("\"Intersection between 2 arrays\"\n\nEnter array 1 length: ");
    scanf("%d", &n1);
    fflush(stdin);
    printf("Fill the array:\n");
    int a1[n1];
    for (i=0; i<n1; i++)
    {
        printf("%d: ", i); //I'd like to put i++ here to order from 1 to 10 the output, but it messes the code up
        scanf("%d", &a1[i]);
        fflush(stdin);
    }
    // do-while loop to check if there's a different input length
    do
    {
        printf("\nEnter array 2 length: ");
        scanf("%d", &n2);
        fflush(stdin);
        if (n2==n1)
        {
            printf("\n!! Value must be different from the previous one.\n");
        }
    }
    while (n2==n1);
    printf("Fill the array:\n");
    int a2[n2];
    for (i=0; i<n2; i++)
    {
        printf("%d: ", i); //I'd like to put i++ here to order from 1 to 10 the output, but it messes the code up
        scanf("%d", &a2[i]);
        fflush(stdin);
    }
    // finding intersections and storing them in a 3rd array
    int j, a3[n3];
    bool flag;
    for(i = 0;i < n1;i++)
    {
        for(j = 0;j < n2;j++)
        {
            if(a2[i] == a1[j])
            {
                flag = 1;
            }
        }
        if(flag == 1)
        {
            a3[n3]=a2[i];
            n3++;
        }
        flag = 0;
    }
    // output of the final array
    if (flag==0)
        printf("\nThere's no intersection between the 2 arrays.\n");
    else
    {
        printf("\nHere's the full array with all intersections between the 2 arrays:\n");
        for (i=0; i<n3; i++)
            printf("%d ", a3[i]);
    }

    printf("\n\n\n\n");
    system ("pause");
    return 0;
}
