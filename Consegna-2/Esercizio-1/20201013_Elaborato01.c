/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201007
 NOTE:    Text Ex01: Scrivere un programma C che mostri l’utilizzo di tutti gli operatori studiati.
          Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi non appropriati
          alla dimensione delle variabili, quello che si ottiene usando più operatori con side effects
          all’interno della stessa istruzione, quello che si ottiene quando le regole di conversione implicita sono applicate
          e quando si supera il range dei valori disponibili per un tipo di dato.
          Il programma deve poi mostrare l’utilizzo di tutte le funzioni matematiche della libreria math.h.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /* ho riportato qui credo tutti gli operatori studiati che dobbiamo usare
    quelle che ho già inserito ho messo una X a inizio riga
    OPERATORI ARITMETICI p. 86 lucidi 4
    X  ++op Incrementa di un'unità l'operando prima che venga restituito il suo valore.
    X  op++ Incrementa di un'unità l'operando dopo averne restituito il suo valore.
    X  --op Decrementa di un'unità l'operando prima che venga restituito il suo valore.
    X  op--Decrementa di un'unità l'operando dopo averne restituito il suo valore.
    X  +op Non ha alcun effetto(nel K&R non esiste) specifica che una costante numerica è positiva
    X  -op Inverte il segno dell'operando (prima di restituirne il valore).
    X   op1 + op2 Somma i due operandi.
    X   op1 - op2 Sottrae dal primo il secondo operando.
    X   op1 * op2 Moltiplica i due operandi.
    X   op1 / op2 Divide il primo operando per il secondo (se operandi interi tronca il risultato).
    X   op1 % op2 Calcola il resto della divisione tra il primo e il secondo operando, richiede operandi interi.
    X   var = valore Assegna alla variabile il valore alla destra.
    X   op1 += op2 op1 = (op1 + op2)
    X   op1 -= op2 op1 = (op1 -op2)
    X   op1 *= op2 op1 = (op1 * op2)
    X   op1 /= op2 op1 = (op1 / op2)
    X   op1 %= op2 op1 = (op1 % op2)

    OPERATORI RELAZIONALI
    < Primo operando minore del secondo operando
    > Primo operando maggiore del secondo operando
    <= Primo operando minore o uguale al secondo operando
    >= Primo operando maggiore o uguale al secondo operando
    == Primo operando uguale al secondo operando
    X   != Primo operando non uguale al secondo operando

    OPERATORI LOGICI
    ! Calcola il NOT logico dell’operando
    && Calcola l’AND logico tra i due operandi
    || Calcola l’OR logico tra i due operandi

    OPERATORI BITWISE - esempi a p. 112 lucidi 4
    & AND logico bit a bit tra i due operandi
    | OR logico bit a bit tra i due operandi
    ^ XOR logico bit a bit tra i due operandi
    ~ Complemento a 1 dell’operando
    >> Shifta destra del primo operando per un numero di bit pari alvalore del secondo
    << Shifta sinistra del primo operando per un numero di bit pari alvalore del secondo

    non so se anche
    sizeof()
    X   casting
    */

    //usiamo l'operatore di assegnamento nella dichiarazione delle variabili
    int num1=5;
    int num2=15;
    printf("Le variabili sono le seguenti:\n");
    printf("TIPO\t\t\tNOME\t\t\tVALORE\n");
    printf("Int\t\t\tnum1\t\t\t%2d\n",num1);
    printf("Int\t\t\tnum2\t\t\t%d\n",num2);
    //uso degli operatori aritmetici
    printf("\nOperazioni con gli operatori aritmetici:\n");
    int sum=num1+num2;
    int sub=num1-num2;
    int prod=num1*num2;
    float div=(float)num1/num2; //conversione esplicita da int a float usando il casting
    int mod=num1%num2;
    printf("Somma:\t\t\t%3d\n",sum);
    printf("Sottrazione:\t\t%d\n",sub);
    printf("Prodotto:\t\t%3d\n",prod);
    printf("Divisione:\t\t%f\n",div);
    printf("Modulo:\t\t\t%3d\n",mod);
    //da qui usiamo operatori  di  assegnamento  compatti per modificare il valore di num1
    printf("\tnum1 iniziale =\t%3d\n",num1);
    printf("num1=num1(%d)+num2(%d)\t",num1, num2);
    num1+=num2;
    printf("num1=%3d\n",num1);
    printf("num1=num1(%d)-num2(%d)\t",num1, num2);
    num1-=num2;
    printf("num1=%3d\n",num1);
    printf("num1=num1(%d)*num2(%d)\t",num1, num2);
    num1*=num2;
    printf("num1=%3d\n",num1);
    printf("num1=num1(%d)/num2(%d)\t",num1, num2);
    num1/=num2;
    printf("num1=%3d\n",num1);
    printf("num1=num1(%d)%%num2(%d)\t",num1, num2);
    num1%=num2;
    printf("num1=%3d\n",num1);
    printf("\tnum1 finale =\t%3d\n",num1);
   
    /* FUNZIONI MATEMATICHE math.h nei lucidi 4 p. 137
    floor(x)
    ceil(x)
    fabs(x)
    ....
    ne dobbiamo fare almeno 15 (mai na gioia)
    */
    printf("\nFunzioni matematiche per il num1(%d)\n", num1);
    printf("1. Radice quadrata:\t\t\t%lf\n", sqrt(num1));
    printf("2. e elevato alla num1:\t\t\t%lf\n", exp(num1));
    printf("3. Logaritmo in base e:\t\t\t%lf\n", log(num1));
    printf("4. Logaritmo in base 10:\t\t%lf\n", log10(num1));
    printf("5. Resto num1/num2:\t\t\t%lf\n", fmod(num1, num2));
    printf("6. Potenza num1^num2:\t\t\t%lf\n", pow(num1, num2));
    float num6=0.5;
    printf("\nFunzioni matematiche per il num6(%f)\n", num6);
    printf("7. Coseno in radianti:\t\t\t%lf\n",  cos(num6));
    printf("8. Seno in radianti:\t\t\t%lf\n",  sin(num6));
    printf("9. Arc coseno in radianti:\t\t%lf\n",  acos(num6));
    printf("10. Arc seno in radianti:\t\t%lf\n",  asin(num6));
    printf("11. Arc tangente in radianti:\t\t%lf\n",  atan(num6));
    /*double atan2(double y, double x)
    Returns the arc tangent in radians of y/x based on the signs of both values to determine the correct quadrant.*/
    printf("12. Coseno iperbolico in radianti:\t%lf\n",  cosh(num6));
    printf("13. Seno iperbolico in radianti:\t%lf\n",  sinh(num6));
    printf("14. Tangente iperbolica in radianti:\t%lf\n",  tanh(num6));
    printf("15. Minor valore intero >= num6:\t%lf\n",  ceil(num6));
    printf("16. Maggior valore intero <= num6:\t%lf\n",  floor(num6));


    //operatori logici e relazionali applicati con l'istruzione di selezione if
    int a, b, c, num3, num4, num5, flag;
    do
    {
        printf("\nInserisci 3 numeri interi (int) da confrontare:\na:\t");
        scanf("%d", &a);
        fflush(stdin);
        printf("b:\t");
        scanf("%d", &b);
        fflush(stdin);
        printf("c:\t");
        scanf("%d", &c);
        fflush(stdin);
        if (a!=b&&b!=c&&a!=c)
        {
            printf("I numeri sono tutti diversi tra loro.\t");
            if (a>b)
            {
                if(b>c)
                {
                    num3 = c;
                    num4 = b;
                    num5 = a;
                }
                else
                {
                    num3=b;
                    if (c>a)
                    {
                        num4 = a;
                        num5 = c;
                    }
                    else
                    {
                        num4 = c;
                        num5 = a;
                    }
                }
            }
            else
            {
                if (a>c)
                {
                    num3=c;
                    num4=a;
                    num5=b;
                }
                else
                {
                    num3=a;
                    if (c>b)
                    {
                        num4=b;
                        num5=c;
                    }
                    else
                    {
                        num4=c;
                        num5=b;
                    }
                }
            }
            printf("Nell'ordine: %d < %d < %d.", num3, num4, num5);
        }
        else
        {
            printf("Numeri uguali tra loro:\n");
            if (a==b)
            {
                printf("a(%d)=b(%d)", a, b);
            }
            if (b==c)
            {
                printf("b(%d)=c(%d)", b, c);
            }
            if (a==c)
            {
                printf("a(%d)=c(%d)", a, c);
            }
        }
        printf("\n\nPer smettere di confrontare numeri, digitare 1:\t");
        scanf("%d", &flag);
        fflush(stdin);
    }
    while (flag!=1);

    printf("\nFunzioni matematiche:\n");
    printf("\n\n\n\n");
    system("pause");
    return 0;
}
