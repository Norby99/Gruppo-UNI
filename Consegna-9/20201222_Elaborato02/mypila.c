#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mypila.h"
#define MAX_NAME_LEN 20
#define MAX_PILA 3

/****************************** FUNZIONI DEL MENU' ******************************/

/** allocazione statica **/

void pushStatic (SACCHETTO_STATICO *s) //Funzione Push Statica
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    float prezzo;
    if(TestPilaPiena1(*s))
        printf("ERRORE: PILA PIENA\n");
    else
    {
        printf("\nNome frutto:\t");
        gets(nome);
        printf("\nPrezzo:\t");
        scanf(" %f", &prezzo);
        fflush(stdin);
        s->pos++;
        s->spesa[s->pos].nome = nome;
        s->spesa[s->pos].prezzo = prezzo;
    }
}

void topStatic(SACCHETTO_STATICO *s) //Funzione Top Statica
{
    if (TestPilaVuota1(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("Nome frutto: %s", s->spesa[s->pos].nome);
        printf("\nPrezzo: %.2f", s->spesa[s->pos].prezzo);
    }
}

SACCHETTO_STATICO *popStatic(SACCHETTO_STATICO *s) //Funzione Pop Statica
{
    SACCHETTO_STATICO *delFrutto;
    delFrutto=malloc(sizeof(SACCHETTO_STATICO));

    if(TestPilaVuota1(*s))
    {
        delFrutto->pos=-1;
    }
    else
    {
        delFrutto->pos=0;
        delFrutto->spesa[delFrutto->pos]=s->spesa[s->pos];
        s->pos--;
        printf("Frutto eliminato:\n");
    }
    return delFrutto;
}

void printAllStatic(SACCHETTO_STATICO *s) //Funzione che stampa tutti gli elementi della pila
{
    if (TestPilaVuota1(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        for(int i = s->pos; i >= 0; i--)
        {
            printf("Nome frutto: %s\n", s->spesa[i].nome);
            printf("Prezzo: %.2f\n", s->spesa[i].prezzo);
        }
    }
}


/** allocazione dinamica **/

void pushDinamic(SACCHETTO_DINAMICO *s) //Funzione Push Dinamica
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    float prezzo;

    if(s->pos == (s->dim-1))
        PilaPiena(s);

    printf("\nNome frutto:\t");
    scanf(" %[^\n]%*c", nome);
    printf("\nPrezzo:\t");
    scanf(" %f", &prezzo);
    fflush(stdin);
    s->pos++;
    s->spesa[s->pos].nome = nome;
    s->spesa[s->pos].prezzo = prezzo;
}

void topDinamic (SACCHETTO_DINAMICO *s) //Funzione Top Dinamica
{
    if(TestPilaVuota2(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("\nNome:\t%s", s->spesa[s->pos].nome);
        printf("\nPrezzo:\t%.2f\n", s->spesa[s->pos].prezzo);
    }

}

SACCHETTO_DINAMICO *popDinamic(SACCHETTO_DINAMICO *s) //Funzione Pop Dinamica
{
    SACCHETTO_DINAMICO *delFrutto;


    delFrutto = malloc(sizeof(SACCHETTO_DINAMICO));
    delFrutto->spesa = malloc(MAX_PILA*sizeof(FRUTTA));


    if(TestPilaVuota2(*s))
    {
        delFrutto->pos = -1;
    }
    else
    {
        delFrutto->pos = 0;
        delFrutto->spesa[delFrutto->pos]=s->spesa[s->pos];
        s->pos--;
        printf("Frutto eliminato:\n");

        if(s->pos == (s->dim-1))
        {
            s->dim = s->dim/2;
            s->spesa = realloc(s->spesa, s->dim * sizeof(FRUTTA));
        }
    }
    return delFrutto;
}

void printAllDinamic(SACCHETTO_DINAMICO *s) //Funzione che stampa tutti gli elementi della pila
{
    if (TestPilaVuota2(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        for(int i = s->pos; i >= 0; i--)
        {
            printf("Nome frutto: %s\n", s->spesa[i].nome);
            printf("Prezzo: %.2f\n", s->spesa[i].prezzo);
        }
    }
}

/******strutture collegate**********/

void pushLinked(ptr_frutta *head) //Funzione Push per le Strutture Collegate
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    float prezzo;

    ptr_frutta newFrutto = (ptr_frutta)malloc(sizeof(FRUTTALINKED));
    if(newFrutto == NULL)
    {
        printf("\nErrore nella malloc!\n\n");
        exit(1);
    }

    printf("\nNome frutto:\t");
    scanf(" %[^\n]%*c", nome);
    printf("\nPrezzo:\t");
    scanf(" %f", &prezzo);
    fflush(stdin);
    newFrutto->nome = nome;
    newFrutto->prezzo = prezzo;

    newFrutto->next = *head;
    *head= newFrutto;
}

void topLinked (ptr_frutta head) //Funzione Top per le Strutture Collegate
{
    if(TestPilaVuota3(head))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("\nNome:\t%s", head->nome);
        printf("\nPrezzo:\t%.2f\n", head->prezzo);
    }

}

ptr_frutta popLinked(ptr_frutta *head) //Funzione Pop per le Strutture Collegate
{
    ptr_frutta delFrutto = NULL;
    ptr_frutta temp = *head;

    if (TestPilaVuota3(*head))
        printf("ERRORE: PILA VUOTA\n");

    else
    {

        delFrutto = (ptr_frutta)malloc(sizeof(FRUTTALINKED));

        while(temp != NULL)
        {
            delFrutto->nome = (*head)->nome;
            delFrutto->prezzo = (*head)->prezzo;
            temp = temp->next;
        }
         printf("Frutto eliminato:\n");
        *head = (*head)->next;
    }
    return delFrutto;
}

void printAllLinked(ptr_frutta head) //Funzione che stampa tutti gli elementi della pila
{
    ptr_frutta temp = head;

    if (TestPilaVuota3(head))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        while(temp != NULL)
        {
            printf("\n- Nome Frutto: %s\n",temp->nome);
            printf("- Prezzo Frutto: %.2f\n",temp->prezzo);
            temp = temp->next;
        }
    }
}




/****************************** GESTIONE STRUTTURE ******************************/

/** allocazione statica**/

SACCHETTO_STATICO* initPila_Sta (SACCHETTO_STATICO *s) //Inizializzazione stataica
{
    s->pos=-1;
    return s;
}

bool TestPilaVuota1(SACCHETTO_STATICO s)        // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (s.pos == -1);
}

bool TestPilaPiena1(SACCHETTO_STATICO s)        // restituisceTRUE se la pila è piena, FALSE altrimenti
{
    return (s.pos == (MAX_PILA-1));
}

/** allocazione dinamica **/

SACCHETTO_DINAMICO* initPila_Din (SACCHETTO_DINAMICO *s) //Inizializzazione dinamica
{
    s = (SACCHETTO_DINAMICO *)malloc(sizeof(SACCHETTO_DINAMICO)*MAX_PILA);
    s->spesa = malloc(MAX_PILA*sizeof(FRUTTA));
    s->pos = -1;
    s->dim = MAX_PILA;
    return s;
}

bool TestPilaVuota2(SACCHETTO_DINAMICO s)       // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (s.pos == -1);
}

void PilaPiena(SACCHETTO_DINAMICO *s)            // aumenta le dimensioni della pila se questa è piena
{
    if  (s->pos == (s->dim-1))
    {
        s->dim = s->dim*2;                                      // pila piena: raddoppia la dimensione del vettore
        s->spesa = realloc(s->spesa, s->dim * sizeof(FRUTTA));
        // !!!!!! controlli realloc
    }
}

void destroyerDinamic(SACCHETTO_DINAMICO *s) //Funzione che libera la memoria
{
    if (TestPilaVuota2(*s))
        printf("\nIl Sacchetto e\' gia\' vuoto!\n\n\n");

    else
    {
       free(s);
       printf("\nIl Sacchetto e\' stato svuotato!\n\n\n");
    }
}

/*** strutture collegate ***/

FRUTTALINKED *initPila(FRUTTALINKED *s) //Inizializzazione strutture collegate
{
    ptr_frutta head = NULL;

    return head;
}

bool TestPilaVuota3(ptr_frutta head)       // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (head == NULL);
}


void destroyerLinked(ptr_frutta *head) //Funzione che libera la memoria
{
    if (TestPilaVuota3(*head))
        printf("\nIl Sacchetto e\' gia\' vuoto!\n\n\n");
    else
    {
        ptr_frutta temp;
        while(*head!=NULL)
        {
            temp = *head;
            *head=(*head)->next;
            free(temp);
        }
       printf("\nIl Sacchetto e\' stato svuotato!\n\n\n");
    }
}
