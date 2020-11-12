/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201113
 NOTE:    Text Ex02: Scrivere un programma C dove sono inizializzate una variabile di tipo int, una di tipo float, una di tipo double,
          una di tipo char, ed un array di 5 interi (precisamente con i valori 10, 20, 30, 40, 50).
          Inizializzare un puntatore per ciascuna di queste variabili. Assegnare ad ogni variabile un valore tramite
          l'utilizzo della funzione scanf. Visualizzare il valore di ogni variabile in due modi:
          prima tramite accesso diretto alla variabile e a seguito tramite l'utilizzo del suo puntatore (accesso indiretto).
          Visualizzare la posizione in memoria della variabile tramite l'utilizzo diretto della variabile e tramite il suo puntatore.
          Visualizzare la posizione in memoria del puntatore.
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <ctype.h>
#define MAX 5

int main()
{
    int num_Intero, vet[MAX]= {10, 20, 30 ,40, 50},i;
    char carattere;
    float num_RealeF;
    double num_RealeD;

    int *p_num_Intero=&num_Intero, *p_vet=vet;
    char *p_carattere=&carattere;
    float *p_num_RealeF=&num_RealeF;
    double *p_num_RealeD=&num_RealeD;

    printf("Inserisci un numero intero: ");

    while( scanf("%d",&num_Intero)!=1)
    {
       printf("\nIl valore inserito non e\' conforme al tipo di varibile , riprova ");
       scanf("%d",&num_Intero);
       fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("Inserisci un carattere: ");
    scanf("%c",&carattere);
    fflush(stdin);

    while(isdigit(carattere)==1)
    {
        printf("\nIn realta\' il carattere inserito e\' una cifra, dovresti inserire una lettera, riprova:  ");
        scanf("%c",&carattere);
        fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("Inserisci un numero reale(float): ");

    while(scanf("%f",&num_RealeF)!=1)
    {
        printf("\nIl valore inserito non e\' conforme al tipo di varibile , riprova ");
        scanf("%f",&num_RealeF);
        fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("Inserisci un numero reale(double):");

    while(scanf("%lf",&num_RealeD)!=1)
    {
       printf("\nIl valore inserito non e\' conforme al tipo di varibile , riprova ");
       scanf("%f",&num_RealeD);
       fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("\nACCESSO DIRETTO\n");
    printf("Numero Intero: %d\n",num_Intero);
    printf("Carattere: %c\n",carattere);
    printf("Numero Reale(float): %.2f\n",num_RealeF);
    printf("Numero Reale(double): %.6lf\n",num_RealeD);
    printf("Vettore: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",vet[i]);
    }


    printf("\n\nACCESSO INDIRETTO\n");
    printf("Numero Intero: %d\n",*p_num_Intero);
    printf("Carattere: %c\n",*p_carattere);
    printf("Numero Reale(float): %.2f\n",*p_num_RealeF);
    printf("Numero Reale(double): %.6lf\n",*p_num_RealeD);
    printf("Vettore: ");//IL VETTORE È DA RIVEDERE
    for(i=0;i<MAX;i++)
    {
        printf("%d ",*p_vet++);
    }

    printf("\n\nINDIRIZZI DELLE VARIABILI(Diretto)\n");
    printf("Numero Intero: %d\n",&num_Intero);
    printf("Carattere: %d\n",&carattere);
    printf("Numero Reale(float): %d\n",&num_RealeF);
    printf("Numero Reale(double): %d\n",&num_RealeD);
    printf("Vettore: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",&vet[i]);
    }

    printf("\n\nINDIRIZZI DELLE VARIABILI(Indiretto)\n");
    printf("Numero Intero: %d\n",p_num_Intero);
    printf("Carattere: %d\n",p_carattere);
    printf("Numero Reale(float): %d\n",p_num_RealeF);
    printf("Numero Reale(double): %d\n",p_num_RealeD);
    printf("Vettore: ");//IL VETTORE È DA RIVEDERE
    for(i=0;i<MAX;i++)
    {
        printf("%d ",p_vet++);
    }

    printf("\n\nSTAMPA DEGLI INDIRIZZI DI MEMORIA DEI PUNTAORI STESSI\n");
     printf("Numero Intero: %d\n",&p_num_Intero);
    printf("Carattere: %d\n",&p_carattere);
    printf("Numero Reale(float): %d\n",&p_num_RealeF);
    printf("Numero Reale(double): %d\n",&p_num_RealeD);
    printf("Vettore: "); //IL VETTORE È DA RIVEDERE
    for(i=0;i<MAX;i++)
    {
        printf("%d ",&p_vet);
    }

    system("pause");
    return 0;
}
