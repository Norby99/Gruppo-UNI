#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_LENGHT 100
#define MAX_REPETITIONS 2

typedef struct{
    int *element;
    int len;
}myArray;

void LookAndSay(int*, int);

myArray newMyArray();
void printMyArray(myArray);
void appendMyArray(myArray*, int);


int main()
{
    
    myArray array = newMyArray();
    appendMyArray(&array, 1);

    printMyArray(array);
    LookAndSay(array, MAX_REPETITIONS);

    return 0;
}

void LookAndSay(int *a, int repetitions){

}

void PrintArray(int* array){

}

myArray newMyArray(){
    myArray a;
    a.element = (int*)malloc(MAX_ARRAY_LENGHT * sizeof(int));
    a.len = 0;
    return a;
}

void appendMyArray(myArray *a, int el){
    a->element[a->len++] = el;
}

void printMyArray(myArray a){
    for (int i=0; i < a.len; i++)
        printf("%d ", a.element[i]);
    printf("\n");
}