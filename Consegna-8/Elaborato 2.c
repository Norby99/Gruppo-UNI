#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REPETITIONS 6

typedef struct{
    int *element;
    int len;
}myArray;


// ? Funzioni generiche
void LookAndSay(myArray, int);


// ? Metodi di myArray
myArray newMyArray();
void printMyArray(myArray);
void appendMyArray(myArray*, int);
void destroyer(myArray*);


int main()
{
    
    myArray array = newMyArray();
    appendMyArray(&array, 1);

    printMyArray(array);
    LookAndSay(array, MAX_REPETITIONS);

    return 0;
}

void LookAndSay(myArray a, int repetitions){
    if(repetitions){
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
    free(a);
}

void printMyArray(myArray a){
    for (int i=0; i < a.len; i++)
        printf("%d ", a.element[i]);
    printf("\n");
}