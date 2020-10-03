/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)

 DATE:   20201003

 NOTE:   Text Ex01:

          Scrivere un programma C che dichiari una variabile per ogni tipo studiato (usando anche i qualificatori short, long, signed e unsigned), ne stampi il valore
          e l’occupazione di memoria in byte. Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti (modificatore, campoMinimo,
          precisione, modificatoreLunghezza). Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che quest’ultima ha stampato.
          Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato.*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    //Dichiarazione delle variabili studiate.

    int varIn = -10;
    short int var_ShIn = -4;
    long int var_LoIn = -2340566;
    unsigned int var_UIn = 5;
    unsigned short int var_UShIn = 6;
    unsigned long int var_ULoIn = 345678978;
    char varCh = 'a';
    signed char var_SCh = 'D';
    unsigned char var_UCh = 'C';
    float varFl = 5.78;
    double varDo = 6.7891;
    long double var_LDo = 23.456788646788;
    int caratteriStampati;


    //Stampa a video delle variabili indicando il loro tipo e i valori ad esse assegnati.

    caratteriStampati = printf("Le variabili sono le seguenti:\n");
    printf("la printf precedente stampa :%d caratteri \n\n",caratteriStampati);//Stampa numero di caratteri presenti nella printf precedente.
    printf("TIPO\t\t\tNOME\t\t\tVALORE\n\n");
    printf("Int\t\t\tvarIn\t\t\t%d\n",varIn);
    printf("Short Int\t\tvar_ShIn\t\t%d\n",var_ShIn);
    printf("Long Int\t\tvar_LoIn\t\t%ld\n",var_LoIn);
    printf("Unsigned Short Int\tvar_UShIn\t\t%u\n",var_UShIn);
    printf("Unsigned Long Int\tvar_ULoIn\t\t%lu\n",var_ULoIn);
    printf("Char\t\t\tvarCh\t\t\t%c\n",varCh);
    printf("Signed Char\t\tvar_SCh\t\t\t%c\n",var_SCh);
    printf("Unsigned Char\t\tvar_UCh\t\t\t%c\n",var_UCh);
    printf("Float\t\t\tvarFl\t\t\t%.2f\n",varFl);
    printf("Double\t\t\tvarDo\t\t\t%.4f\n",varDo);
    __mingw_printf("Long Double\t\tvar_LDo\t\t\t%Lf\n",var_LDo);
    printf("\n\n\n");


    //Stampa a video del valore di Bytes occupati da ogni tipologia di varibiale più le i relativi valori di massimo e minimo.


    caratteriStampati = printf("Quantitativo di Bytes occupati e corrispondenti valori di Max e Min\n");
    printf("la printf precedente stampa:%d caratteri \n\n",caratteriStampati);

    printf("TIPO\t\t\tBYTES\t\tMIN\t\t\tMAX\n");
    printf("Int\t\t\t%d\t\t%d\t\t%d\n",sizeof(varIn),INT_MIN,INT_MAX);
    printf("Short Int\t\t%d\t\t%d\t\t\t%d\n",sizeof(var_ShIn),SHRT_MIN,SHRT_MAX);
    printf("Long Int\t\t%d\t\t%ld\t\t%ld\n",sizeof(var_LoIn),LONG_MIN,LONG_MAX);
    printf("Unsigned Short Int\t%d\t\t0\t\t\t%u\n",sizeof(var_UShIn),USHRT_MAX);
    printf("Unsigned Long Int\t%d\t\t0\t\t\t%lu\n",sizeof(var_ULoIn),ULONG_MAX);
    printf("Char\t\t\t%d\t\t%d\t\t\t%d\n",sizeof(varCh),CHAR_MIN,CHAR_MAX);
    printf("Signed Char\t\t%d\t\t%d\t\t\t%d\n",sizeof(var_SCh),SCHAR_MIN,SCHAR_MAX);
    printf("Unsigned Char\t\t%d\t\t0\t\t\t%u\n",sizeof(var_UCh),UCHAR_MAX);
    printf("Float\t\t\t%d\t\t%.2e\t\t%.2e\n",sizeof(varFl),FLT_MIN,FLT_MAX);
    printf("Double\t\t\t%d\t\t%.2e\t\t%.2e\n",sizeof(varDo),DBL_MIN,DBL_MAX);
    __mingw_printf("Long Double\t\t%d\t\t%Le\t\t%Le\n",sizeof(var_LDo),LDBL_MIN,LDBL_MAX);
    printf("\n\n\n");


    //Stampa delle variabili con i vari argomenti della funzione printf( Modificatore CampoMinimo, precisione, ModificatoreLunghezza).

    printf("Stampa in diversi formati delle varibili int: \n\n");

    printf("Int \t\t    %d |%5d|%-5d|%00d|\n",varIn,varIn,varIn,varIn);
    printf("Unsigned Long Int   %Lu |%10Lu|%-10Lu|%00Lu|%+Lu|%12.11Lu\n\n",var_ULoIn,var_ULoIn,var_ULoIn,var_ULoIn,var_ULoIn,var_ULoIn);

    printf("Stampa in diversi formati della varibile char: \n\n");
    printf("Char %c |%-c| %c| \n\n",varCh,varCh,varCh);

    printf("Stampa in diversi formati delle varibili float, double, long double: \n\n");
    printf("Float \t\t\t%f| %g| %.2f| %5f| %5.3f|%-5.3f| %0004.2f| \n",varFl,varFl,varFl,varFl,varFl,varFl,varFl);
    printf("Double \t\t\t%f| %g| %.4f| %6f| %3.6f| %-2.5f| %002.7f\n",varDo,varDo,varDo,varDo,varDo,varDo,varDo);
    __mingw_printf("Long Double \t\t%Lf| %Lg| %.8Lf| %2Lf| %2.8Lf| %-2.9Lf| %002.8Lf\n\n",var_LDo,var_LDo,var_LDo,var_LDo,var_LDo,var_LDo,var_LDo);


    system("pause");
    return 0;
}
