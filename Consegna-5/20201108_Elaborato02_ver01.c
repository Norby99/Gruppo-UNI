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

int string_length (char *);
void getString (char *);
void str_replace(char *, char *);

int main (void)
{
    //
    char *s1, *s2;
    s1=malloc(sizeof(char)*30);
    getString(s1);
    printf ("Word: %s\n", s1);
    s2=malloc(sizeof(char)*30);
    getString(s2);
    printf ("Characters to replace with *: %s\n", s2);

    printf ("Substitute given characters in word with *:\n%s", str_replace(s1, s2));

    printf ("\n\n");
    system ("pause");
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
    } while (string_length(str)>30);
}

void str_replace (char *str, char *substr)
{
    int i;
    char *newstr;
    for (i=0; str[i]!='\n'; i++)
    {
        if (str[i] != substr[0] && str[i] != '\0')
        {
            newstr[i]=str[i];
        }
        else
            newstr[i]='*';
    }
}
