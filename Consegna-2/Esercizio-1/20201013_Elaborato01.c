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

int main() {
          
          /* ho riportato qui credo tutti gli operatori studiati che dobbiamo usare
    OPERATORI ARITMETICI p. 86 lucidi 4
    ++op Incrementa di un'unità l'operando prima che venga restituito il suo valore.
    op++ Incrementa di un'unità l'operando dopo averne restituito il suo valore.
    --op Decrementa di un'unità l'operando prima che venga restituito il suo valore.
    op--Decrementa di un'unità l'operando dopo averne restituito il suo valore.
    +op Non ha alcun effetto(nel K&R non esiste) specifica che una costante numerica è positiva
    -op Inverte il segno dell'operando (prima di restituirne il valore).
    op1 + op2 Somma i due operandi.
    op1 -op2 Sottrae dal primo il secondo operando.
    op1 * op2 Moltiplica i due operandi.
    op1 / op2 Divide il primo operando per il secondo (se operandi interi tronca il risultato).
    op1 % op2 Calcola il resto della divisione tra il primo e il secondo operando, richiede operandi interi.
    var = valore Assegna alla variabile il valore alla destra.
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
    
    non so se anche sizeof() e casting
    */
          
    system("pause");
    return 0;

}
