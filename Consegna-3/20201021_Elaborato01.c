/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201007
 NOTE:    Text Ex01: Scrivere un programma C che legga da tastiera un testo terminato dal carattere #
          e poi stampi le statistiche relative al numero di spazi, al numero di caratteri di nuova linea,
          al numero di caratteri letti, al numero di quelli maiuscoli, etc.
          utilizzando almeno una volta tutte le funzioni dell’header ctype.h*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define CARATTERE '#'

int main ()
{
    //link piccinini https://www.programiz.com/c-programming/library-function/ctype.h
    
    //Inserimento di una stringa che termina con #
    printf("Inserire un testo da terminare col carattere #:\n");
    char ch;
    char bufferA[100];
    int i, index = 0;
    memset(bufferA, '\0', sizeof(bufferA)); /*function memset() used to clear the memory location*/
    while ((ch = getchar()) != CARATTERE){  //legge un singolo carattere, restituendolo
        bufferA[index++]=ch;
    }
    printf("The input sentence is:\n%s\n", bufferA);
    //uso le funzioni della libreria <ctype.h>
    printf("Number of white spaces: %d\n", isspace(bufferA));

    system ("pause");
    return 0;
}
