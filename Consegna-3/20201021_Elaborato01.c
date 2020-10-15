/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201016
 NOTE:    Text Ex01: Scrivere un programma C che legga da tastiera un testo terminato dal carattere #
          e poi stampi le statistiche relative al numero di spazi, al numero di caratteri di nuova linea,
          al numero di caratteri letti, al numero di quelli maiuscoli, etc.
          utilizzando almeno una volta tutte le funzioni dell’header ctype.h*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define END_TEXT '#'

int main ()
{
    //link piccinini https://www.programiz.com/c-programming/library-function/ctype.h

    //entering a string ending with #
    printf("Enter a text ending with the character #:\n");
    char ch;
    char text[100];
    int i, index = 0, count_space = 0, count_n = 0, count_upper = 0;
    memset(text, '\0', sizeof(text)); //function memset() to clear the memory location
    while ((ch = getchar()) != END_TEXT) //getchar() reads a single char, returning it
    {
        text[index++] = ch;
        //number of printed characters





        /*using library <ctype.h> functions
            1. number of blank spaces*/
        if (isspace(ch)!=0)
        {
                count_space++;
                //count number of new lines characters
                if (ch=='\n')
                {
                    count_n++;
                }
        }
        //  2. number of uppercase letters
        if (isupper(ch)!=0)
        {
                count_upper++;
        }
    }
    printf("\nThe input sentence is:\n%s\n", text);
    printf("Number of characters considered:\t%d\n", index);
    printf("Number of white spaces:\t\t\t%d\n", count_space);
    printf("Number of new lines:\t\t\t%d\n", count_n);
    printf("Number of uppercase letters:\t\t%d\n", count_upper);
    system ("pause");
    return 0;
}
    /*per terminare testo con #
    dispensa 4 es 12 scanf con stringa [^#]
    sennò modo dispensa 11 usato in questo codice*/
