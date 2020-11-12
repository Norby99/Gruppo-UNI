/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201112
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
    //dichiarazione variabili
    int num_Intero, vet[MAX]= {10, 20, 30 ,40, 50}, i;
    char carattere;
    float num_RealeF;
    double num_RealeD;

    //dichiarazione e inizializzazione puntatori relativi a variabili
    int *p_num_Intero=&num_Intero, *p_vet=vet;
    char *p_carattere=&carattere;
    float *p_num_RealeF=&num_RealeF;
    double *p_num_RealeD=&num_RealeD;

    //inizializzazione variabili
    printf("Inserisci un numero intero: ");
    while(scanf("%d",&num_Intero)!=1)
    {
       printf("\n!!Il valore inserito non e\' conforme al tipo di varibile!!\nRiprova ");
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
        printf("\n!!Il valore inserito e\' un numero!!\nRiprova inserendo una lettera:  ");
        scanf("%c",&carattere);
        fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("Inserisci un numero reale(float): ");

    while(scanf("%f",&num_RealeF)!=1)
    {
        printf("\n!!Il valore inserito non e\' conforme al tipo di varibil!!\nRiprova ");
        scanf("%f",&num_RealeF);
        fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    printf("Inserisci un numero reale(double):");

    while(scanf("%lf",&num_RealeD)!=1)
    {
       printf("\n!!Il valore inserito non e\' conforme al tipo di varibile!!\nRiprova ");
       scanf("%f",&num_RealeD);
       fflush(stdin);
    }
    printf("\n");
    fflush(stdin);

    //pulizia dello schermo
    system("cls");

    //stampa delle variabili nelle diverse modalità di accesso
	printf("\n\t\t\t\"ACCESSO DIRETTO\"\t\"ACCESSO INDIRETTO\"\n\nVARIABILI:\n\n");
    printf("Numero Intero:\t\t%d\t\t\t%d\n", num_Intero, *p_num_Intero);
    printf("Carattere:\t\t%c\t\t\t%c\n",carattere, *p_carattere);
    printf("Numero Reale(float):\t%.2f\t\t\t%.2f\n",num_RealeF, *p_num_RealeF);
    printf("Numero Reale(double):\t%.6lf\t\t%.6lf\n",num_RealeD, *p_num_RealeD);
    printf("Vettore:");
    for(i=MAX-1;i<MAX;i++)
    {
        printf("\t\t%d\t\t\t%d\n",vet[0], *p_vet);
        for(i=1;i<MAX;i++)
        {
            printf("\t\t\t%d\t\t\t%d\n", vet[i], *(p_vet+i));
        }
    }

    //stampa degli indirizzi delle variabili con le diverse modalità di accesso
	printf("\nINDIRIZZI DELLE VARIABILI:\n\n");
    printf("Numero Intero:\t\t%d\t\t\t%d\n", &num_Intero, p_num_Intero);
    printf("Carattere:\t\t%d\t\t\t%d\n", &carattere, p_carattere);
    printf("Numero Reale(float):\t%d\t\t\t%d\n", &num_RealeF, p_num_RealeF);
    printf("Numero Reale(double):\t%d\t\t\t%d\n", &num_RealeD, p_num_RealeD);
    printf("Vettore:");
    for(i=MAX-1;i<MAX;i++)
    {
        printf("\t\t%d\t\t\t%d\n", &vet[0], p_vet);
        for(i=1;i<MAX;i++)
        {
            printf("\t\t\t%d\t\t\t%d\n", &vet[i], p_vet+i);
        }
    }

    printf("\n\nINDIRIZZI DI MEMORIA DEI PUNTATORI:\n");
    printf("Numero Intero:\t\t%d\n", &p_num_Intero);
    printf("Carattere:\t\t%d\n", &p_carattere);
    printf("Numero Reale(float):\t%d\n", &p_num_RealeF);
    printf("Numero Reale(double):\t%d\n", &p_num_RealeD);
    printf("Vettore:\t\t%d\n\n\n\n", &p_vet);

    system("pause");
    return 0;
}
