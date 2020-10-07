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
    ++op Incrementa di un'unità l'operando prima che venga restituito il suo valore.
    op++ Incrementa di un'unità l'operando dopo averne restituito il suo valore.
    --op Decrementa di un'unità l'operando prima che venga restituito il suo valore.
    op--Decrementa di un'unità l'operando dopo averne restituito il suo valore.
    +op Non ha alcun effetto(nel K&R non esiste) specifica che una costante numerica è positiva
    -op Inverte il segno dell'operando (prima di restituirne il valore).
    X   op1 + op2 Somma i due operandi.
    X   op1 - op2 Sottrae dal primo il secondo operando.
    X   op1 * op2 Moltiplica i due operandi.
    X   op1 / op2 Divide il primo operando per il secondo (se operandi interi tronca il risultato).
    NON SO SE MI TORNA GIUSTO X   op1 % op2 Calcola il resto della divisione tra il primo e il secondo operando, richiede operandi interi.
    X   var = valore Assegna alla variabile il valore alla destra.
    op1 += op2 op1 = (op1 + op2)
    op1 -= op2 op1 = (op1 -op2)
    op1 *= op2 op1 = (op1 * op2)
    op1 /= op2 op1 = (op1 / op2)
    op1 %= op2 op1 = (op1 % op2)

    OPERATORI RELAZIONALI
    < Primo operando minore del secondo operando
    > Primo operando maggiore del secondo operando
    <= Primo operando minore o uguale al secondo operando
    >= Primo operando maggiore o uguale al secondo operando
    == Primo operando uguale al secondo operando
    != Primo operando non uguale al secondo operando

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

    //Usiamo l'operatore di assegnamento nella dichiarazione delle variabili.

    int num1=5;
    int num2=15;
    printf("Le variabili sono le seguenti:\n");
    printf("TIPO\t\t\tNOME\t\t\tVALORE\n");
    printf("Int\t\t\tnum1\t\t\t%d\n",num1);
    printf("Int\t\t\tnum2\t\t\t%d\n",num2);

    //Uso degli operatori aritmetici
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


    system("pause");
    return 0;
}
