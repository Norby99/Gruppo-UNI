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
    //entering a string ending with #
    printf("Enter a text ending with the character #:\n");
    char ch;
    char text[100], up_text[100], lo_text[100];
    int i, u, l, c_space=0, c_upper=0, c_alnum=0, c_cntrl=0, c_digit=0, c_print=0, c_graph=0, c_lo=0, c_alpha=0, c_xdec=0, c_punct=0;
    //function memset() to clear the memory location
    memset(text, '\0', sizeof(text));
    memset(up_text, '\0', sizeof(up_text));
    memset(lo_text, '\0', sizeof(lo_text));
    for (i=0, u=0; (ch=getchar()) != END_TEXT; ) //getchar() reads a single char, returning it
    {
        text[i++] = ch;
        /*using library <ctype.h> functions
            1. number of spaces*/
        if (isspace(ch)!=0)
        {
                c_space++;
                //count number of new lines characters

        }
        //  2. number of uppercase letters
        if (isupper(ch)!=0)
        {
                c_upper++;
        }
        //  3. number of alphanumeric characters
        if (isalnum(ch)!=0)
        {
                c_alnum++;
        }
        //  4. number of alphanumerical characters
        if (isxdigit(ch)!=0)
        {
                c_xdec++;
        }
        //  5. number of control characters
        if (iscntrl(ch)!=0)
        {
                //the exercise requires only new lines char. so we must exclude the other control char.
                if (ch=='\n')
                {
                    c_cntrl++;
                }
        }
        //  6. number of numeric characters
        if (isdigit(ch)!=0)
        {
                c_digit++;
        }
        //  7. number of graphic characters
        if (isgraph(ch)!=0)
        {
                c_graph++;
        }
        //  8. number of lower characters
        if (islower(ch)!=0)
        {
                c_lo++;
        }
        //  9. number of printable characters
        if (isprint(ch)!=0)
        {
                c_print++;
        }
        //  10. number of punctuation characters
        if (ispunct(ch)!=0)
        {
                c_punct++;
        }
        //  11. number of hexadecimal characters
        if (isxdigit(ch)!=0)
        {
                c_xdec++;
        }
        //transforming text format and saving them in two other string to save and print them later outside the loop
        up_text[u++] = toupper(ch);
        lo_text[l++] = tolower(ch);
    }
    printf("\nThe input text considered is:\n%s\n", text);
    printf("\nNumber of:\n- printed characters:\t\t%d\n", c_print); //instead of c_print even i could be used for this purpose
    printf("- graphic characters:\t\t%d\n", c_graph);
    printf("- white spaces:\t\t\t%d\n", c_space);
    printf("- new lines:\t\t\t%d\n", c_cntrl);
    printf("- punctuation characters:\t%d\n", c_punct);
    printf("- uppercase letters:\t\t%d\n", c_upper);
    printf("- lowercase characters:\t\t%d\n", c_lo);
    printf("- alphabetic characters:\t%d\n", c_alpha);
    printf("- numeric characters:\t\t%d\n", c_digit);
    printf("- alphanumeric characters:\t%d\n", c_alnum);
    printf("- hexadecimal characters:\t%d\n", c_xdec);
    printf("\nHere's the input text all changed in:\n- uppercase:\t%s\n", up_text);
    printf("- lowercase:\t%s\n\n\n\n", lo_text);
    system ("pause");
    return 0;
}
