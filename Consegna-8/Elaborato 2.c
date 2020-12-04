/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201204
 NOTE:    Text Ex02: Realizzare un programma che risolva tramite una funzione ricorsiva un qualche problema scelto dagli studenti;
          il programma deve stampare le variabili locali e i parametri di ogni chiamata alla funzione ricorsiva.
          In particolare, per ogni chiamata ricorsiva, deve visualizzare l’output su una riga separata e aggiungere un livello di
          rientro. Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
          L’obiettivo è quello di progettare e implementare un formato dell’output che aiuti l'utente a comprendere il meccanismo
          della ricorsione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REPETITIONS 6

typedef struct{
    int *element;
    int len;
}myArray;

// Funzioni generiche
void LookAndSay(myArray, int);


// Metodi di myArray
myArray newMyArray();
void printMyArray(myArray);
void appendMyArray(myArray*, int);
void destroyer(myArray*);

int main()
{
    printf("\n\t\t***** LOOK AND SAY *****\n\nQuesto programma genera una sequenza di Look and Say:\nla prima riga e' una costante (ovvero 1),");
    printf("\nle successive si generano in base al contenuto di quella precedente.\nIl procedimento e' il seguente:");
    printf("\nSi individua il primo numero e si fa il conteggio di quante volte compare\ndi fila e si printa il numero ottenuto e il numero stesso e cosi' via\n\n");
    myArray array = newMyArray();
    appendMyArray(&array, 1);

    printf("\t\t\t\t\t\t");
    printMyArray(array);
    LookAndSay(array, MAX_REPETITIONS);

    return 0;
}

void LookAndSay(myArray a, int repetitions){
    if(repetitions){
        printf("Numero di ripetizioni rimaste: %d\t\t", repetitions-1);
        int j;
        int cont;
        myArray array = newMyArray();

        for (int i=0; i < a.len; i++)
        {
            j = i+1;
            cont = 0;
            for (; j < a.len+1; j++)
            {
                if (j == a.len)
                    cont++;
                else{
                    cont++;
                    if (a.element[j] != a.element[j-1])
                        break;
                }
            }
            appendMyArray(&array, cont);
            appendMyArray(&array, a.element[i]);
            i = j-1;
        }
        printMyArray(array);
        LookAndSay(array, --repetitions);
        destroyer(&array);
    }
}

myArray newMyArray(){
    myArray a;
    a.len = 0;
    a.element = (int*)malloc(a.len * sizeof(int));
    return a;
}

void appendMyArray(myArray *a, int el){
    a->element = (int*)realloc(a->element, (a->len+1) * sizeof(int));
    a->element[a->len++] = el;
}

void destroyer(myArray *a){
    free(a->element);
    free(a);
}

void printMyArray(myArray a){
    for (int i=0; i < a.len; i++)
        printf("%d ", a.element[i]);
    printf("\n");
}
