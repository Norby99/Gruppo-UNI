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
    char text[100], up_text[100], lo_text[100];
    int i, c_space=0, c_n=0, c_upper=0, c_alnum=0, c_cntrl=0, c_digit=0, c_print=0, c_graph=0, c_lo=0, c_alpha=0, c_xdec=0, c_punct=0;
    memset(text, '\0', sizeof(text)); //function memset() to clear the memory location
    for (i=0; (ch = getchar()) != END_TEXT; ) //getchar() reads a single char, returning it
    {
        text[i++] = ch;
        /*using library <ctype.h> functions
            1. number of blank spaces*/
        if (isspace(ch)!=0)
        {
                c_space++;
                //count number of new lines characters
                if (ch=='\n')
                {
                    c_n++;
                }
        }
        //  2. number of uppercase letters
        if (isupper(ch)!=0)
        {
                c_upper++;
        }
        //  3. number of alphanumeric character
        if (isalpha(ch)!=0)
        {
                c_alpha++;
        }
        //  4. number of control character
        if (iscntrl(ch)!=0)
        {
                c_cntrl++;
        }
        //  5. number of numeric character
        if (isdigit(ch)!=0)
        {
                c_digit++;
        }
        //  6. number of graphic character
        if (isgraph(ch)!=0)
        {
                c_graph++;
        }
        //  7. number of lower character
        if (islower(ch)!=0)
        {
                c_lo++;
        }
        //  8. number of printable character
        if (isprint(ch)!=0)
        {
                c_print++;
        }
        //  9. number of punctuation character
        if (ispunct(ch)!=0)
        {
                c_punct++;
        }
        //  10. number of hexadecimal character
        if (isxdigit(ch)!=0)
        {
                c_xdec++;
        }
    }
    printf("\nThe input sentence is:\n%s\n", text);
    printf("\nNumber of:\n- characters considered:\t%d %d\n", i, c_graph);
    printf("- printed characters:\t\t%d\n", c_print);
    printf("- white spaces:\t\t\t%d\n", c_space);
    printf("- new lines:\t\t\t%d\n", c_n);
    printf("- uppercase letters:\t\t%d\n", c_upper);
    printf("- lowercase characters:\t\t%d\n", c_lo);
    printf("- alphanumeric characters:\t%d\n", c_alnum);
    printf("- alphabetic characters:\t%d\n", c_alpha);
    printf("- control characters:\t\t%d\n", c_cntrl);
    printf("- numeric characters:\t\t%d\n", c_digit);
    printf("- graphic characters:\t\t%d\n", c_graph);
    printf("- punctuation characters:\t%d\n", c_punct);
    printf("- hexadecimal characters:\t%d\n", c_xdec);
    //transforming text format
    for (i=0; texti; i++) //getchar() reads a single char, returning it
    {
        up_text[i]=toupper(ch);
    }
    printf("\nThe input sentence is:\n- all uppercase:\n%s\n", up_text);
    /*tolower(text);
    printf("- all lowercase:\n%s\n", lo_text);
    */
    system ("pause");
    return 0;
}
    /*per terminare testo con #
    dispensa 4 es 12 scanf con stringa [^#]
    sennò modo dispensa 11 usato in questo codice*/
