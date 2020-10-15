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

    //entering a string ending with #
    printf("Enter a text ending with the character #:\n");
    char ch;
    char text[100];
    int i, index = 0, counterA = 0;
    memset(text, '\0', sizeof(text)); //function memset() to clear the memory location
    while ((ch = getchar()) != CARATTERE) //getchar() reads a single char, returning it
    {
        text[index++] = ch;
        /*using library <ctype.h> functions
            1. number of blank spaces*/
        if (isspace(ch)!=0)
        {
                counterA++;
        }
    }
    printf("\nThe input sentence is:\n%s\n", text);
    printf("\nNumber of white spaces: %d\n", counterA);
    system ("pause");
    return 0;
}
    /*per terminare testo con #
    dispensa 4 es 12 scanf con stringa [^#]
    sennò modo dispensa 11 usato in questo codice*/
