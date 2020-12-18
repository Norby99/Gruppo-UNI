#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mypila.h"
#define MAX_NAME_LEN 20
#define MAX_PILA 3

/****************************** FUNZIONI DEL MENU' ******************************/

/** allocazione statica **/
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
    strncpy(s->spesa[s->pos].nome, nome, MAX_NAME_LEN);
    printf("STO QUA");
    s->spesa[s->pos].prezzo = prezzo;
}
/*
topDinamic()
{

}

popDinamic()
{

}*/

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

void initPila (SACCHETTO_DINAMICO *s)
{
    s = malloc(sizeof(SACCHETTO_DINAMICO));
    s->spesa = malloc(MAX_PILA*sizeof(FRUTTA));
    s->pos = -1;
    s->dim = MAX_PILA;
}

bool TestPilaVuota2(SACCHETTO_DINAMICO s)       // restituisce TRUE se la pila è vuota, FALSE altrimenti
{
    return (s.pos == -1);
}

void PilaPiena(SACCHETTO_DINAMICO *s)            // aumenta le dimensioni della pila se questa è piena
{
    printf("STO RIALLOCANDO FORSE");
    if  (s->pos == (s->dim-1))
    {
        printf("STO RIALLOCANDO");
        s->dim = s->dim*2;                      // pila piena: raddoppia la dimensione del vettore
        s->spesa = realloc(s->spesa, s->dim* sizeof(FRUTTA));
        // !!!!!! controlli realloc
    }
}

/*void destroyer()
{
    free();
}*/
