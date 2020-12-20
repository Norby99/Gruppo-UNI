#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mypila.h"
#define MAX_NAME_LEN 20
#define MAX_PILA 3

/****************************** FUNZIONI DEL MENU' ******************************/

/** allocazione statica **/

SACCHETTO_STATICO* initPila_Sta (SACCHETTO_STATICO *s)
{
    //s = (SACCHETTO_DINAMICO *) malloc(sizeof(SACCHETTO_DINAMICO)*1);
    s->pos=-1;
    return s;
}

void pushStatic (SACCHETTO_STATICO *s)
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    int prezzo;
    if(TestPilaPiena1(*s))
        printf("ERRORE: PILA PIENA\n");
    else
    {
        printf("\nNome frutto:\t");
        gets(nome);
        printf("\nPrezzo:\t");
        scanf(" %d", &prezzo);
        fflush(stdin);
        s->pos++;
        s->spesa[s->pos].nome = nome;
        s->spesa[s->pos].prezzo = prezzo;
    }
}

void topStatic(SACCHETTO_STATICO *s)
{
    if (TestPilaVuota1(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("Nome frutto: %s", s->spesa[s->pos].nome);
        printf("\nPrezzo: %d", s->spesa[s->pos].prezzo);
    }
}

SACCHETTO_STATICO *popStatic(SACCHETTO_STATICO *s)
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

void printAllStatic(SACCHETTO_STATICO *s)
{
    if (TestPilaVuota1(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        for(int i = 0; i <= s->pos; i++)
        {
            printf("Nome frutto: %s\n", s->spesa[i].nome);
            printf("Prezzo: %d\n", s->spesa[i].prezzo);
        }
    }
}


/** allocazione dinamica **/

void pushDinamic(SACCHETTO_DINAMICO *s)
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    int prezzo;

    if(s->pos == (s->dim-1))
        PilaPiena(s);

    printf("\nNome frutto:\t");
    scanf(" %[^\n]%*c", nome);
    printf("\nPrezzo:\t");
    scanf(" %d", &prezzo);
    fflush(stdin);
    s->pos++;
    s->spesa[s->pos].nome = nome;
    s->spesa[s->pos].prezzo = prezzo;
}

void topDinamic (SACCHETTO_DINAMICO *s)
{
    if(TestPilaVuota2(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("\nNome:\t%s", s->spesa[s->pos].nome);
        printf("\nPrezzo:\t%d\n", s->spesa[s->pos].prezzo);
    }

}

SACCHETTO_DINAMICO *popDinamic(SACCHETTO_DINAMICO *s)
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
            printf("STO DIMEZZANDO");
            printf("---%d",s->dim);
            s->dim = s->dim/2;
            s->spesa = realloc(s->spesa, s->dim * sizeof(FRUTTA));
        }
    }
    printf("\nNome:\t%s", delFrutto->spesa[delFrutto->pos].nome);
    printf("\nPrezzo:\t%d\n", delFrutto->spesa[delFrutto->pos].prezzo);
    return delFrutto;
}

void printAllDinamic(SACCHETTO_DINAMICO *s)
{
    if (TestPilaVuota2(*s))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        for(int i = 0; i <= s->pos; i++)
        {
            printf("Nome frutto: %s\n", s->spesa[i].nome);
            printf("Prezzo: %d\n", s->spesa[i].prezzo);
        }
    }
}

/******strutture collegate**********/

FRUTTALINKED *initPila(FRUTTALINKED *s)
{
    ptr_frutta head = NULL;

    return head;
}

void pushLinked(ptr_frutta *head)
{
    char *nome=(char *)malloc(MAX_NAME_LEN*sizeof(char));
    int prezzo;

    ptr_frutta newFrutto = (ptr_frutta)malloc(sizeof(FRUTTALINKED));
    if(newFrutto == NULL)
    {
        printf("\nErrore nella malloc!\n\n");
        exit(1);
    }

    printf("\nNome frutto:\t");
    scanf(" %[^\n]%*c", nome);
    printf("\nPrezzo:\t");
    scanf(" %d", &prezzo);
    fflush(stdin);
    newFrutto->nome = nome;
    newFrutto->prezzo = prezzo;

    newFrutto->next = *head;
    *head= newFrutto;
}

void topLinked (ptr_frutta head)
{
    if(TestPilaVuota3(head))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        printf("\nNome:\t%s", head->nome);
        printf("\nPrezzo:\t%d\n", head->prezzo);
    }

}

ptr_frutta *popLinked(ptr_frutta *head)
{
    ptr_frutta delFrutto = NULL;
    ptr_frutta temp = head;

    if (TestPilaVuota3(*head))
        printf("ERRORE: PILA VUOTA\n");

    else
    {

        delFrutto = malloc(sizeof(ptr_frutta));
        *head = *head->next;

        while(temp != NULL)
        {
            delFrutto->nome = head->nome;
            delFrutto->prezzo = head->prezzo;
            temp = temp->next;

            printf("Frutto eliminato:\n");
        }
    }
    return delFrutto;
}

void printAllLinked(ptr_frutta head)
{
    ptr_frutta temp = head;

    if (TestPilaVuota3(head))
        printf("ERRORE: PILA VUOTA\n");
    else
    {
        while(temp != NULL)
        {
            printf("\n- Nome Frutto: %s\n",temp->nome);
            printf("- Prezzo Frutto: %d\n",temp->prezzo);
            temp = temp->next;
        }
    }
}




/****************************** GESTIONE STRUTTURE ******************************/

/** allocazione statica**/

bool TestPilaVuota1(SACCHETTO_STATICO s)        // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (s.pos == -1);
}

bool TestPilaPiena1(SACCHETTO_STATICO s)        // restituisceTRUE se la pila è piena, FALSE altrimenti
{
    return (s.pos == (MAX_PILA-1));
}

/** allocazione dinamica **/

SACCHETTO_DINAMICO* initPila_Din (SACCHETTO_DINAMICO *s)
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
        s->dim = s->dim*2;                      // pila piena: raddoppia la dimensione del vettore
        s->spesa = realloc(s->spesa, s->dim * sizeof(FRUTTA));
        // !!!!!! controlli realloc
    }
}

/*** strutture collegate ***/

bool TestPilaVuota3(ptr_frutta head)       // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (head == NULL);
}


/*void destroyer()
{
    free();
}*/
