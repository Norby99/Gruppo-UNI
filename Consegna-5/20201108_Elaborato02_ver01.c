/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201030
 NOTE:    Text Ex02: Scrivere un programma C che riceva in ingresso due parole inserite da tastiera.
          Si consideri che ciascuna parola può contenere al massimo 30 caratteri. Il programma deve essere case sensitive,
          cioè deve distinguere lettere minuscole da lettere maiuscole e deve essere in grado anche di analizzare numeri,
          simboli e segni di punteggiatura. Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola
          con il carattere ’*’.
          Ad esempio, inserite le parole
          abchdfffchdchdtlchd
          e
          chd
          il programma deve visualizzare la parola
          ab*fff**tl*
          Scrivere due versioni: la prima deve ignorare la presenza della libreria string.h e quindi dovete lavorare
          esplicitamente su ogni singolo carattere delle stringhe. La seconda deve usare le funzioni della libreria string.h
          per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 30

int string_length (char *);
void getString (char *);
void strReplace(char *, char *, char);

int main (void)
{
    char *s1, *s2;
    int i;

    s1=malloc(sizeof(char)*100);
    s2=malloc(sizeof(char)*100);

    printf("Enter a word, max 30 characters: ");
    getString(s1);

    printf("Enter a second word, max 30 characters: ");
    getString(s2);

    strReplace(s1, s2, '*');

    printf ("Replacement:\n%s", s1);

    return 0;
}

int string_length(char* given_string)
{
    // variable to store the length of the string
    int length = 0;
    while (*given_string != '\0')
    {
        length++;
        given_string++;
    }
    return length;
}

void getString (char *str)
{
    do
    {
        scanf ("%s", str);
        fflush(stdin);
    } while (string_length(str)>MAX_LENGTH);
}

void strReplace (char *s1, char *s2, char val)
{
    bool flag;
    int i, j;

    for(i=0;i<string_length(s1);i++){
        flag = false;
        if(s1[i] == s2[0]){
            flag = true;
            for(j=0; j<string_length(s2); j++){
                if(s2[j] != s1[j+i]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true){
            s1[i] = '*';
            for(int k=0;k<string_length(s1);k++){
                s1[i+1+k] = s1[i+k+string_length(s2)];
            }
            printf("--%s\n",&s1[i+string_length(s2)]);
        }
    }
}
