#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DAYS 365

typedef struct{
    int giorno;
    int mese;
    int ora_inizio;
    int ora_fine;
    char *descrizione;
}Appuntamento;

typedef struct{
    Appuntamento appuntamenti[MAX_DAYS];
    int len;
}Agenda;

Agenda newAgenda(){
    Agenda a;
    a.len = 0;
    return a;
}

void inserisci_appuntamento(Agenda*, Appuntamento);
void elimina_appuntamento(Agenda*, int);
void stampa_appuntamenti_del_mese(Agenda);

int main()
{
    Agenda agenda = newAgenda();


    return 0;
}

void inserisci_appuntamento(Agenda* ag, Appuntamento ap){

}

void elimina_appuntamento(Agenda* a, int index){
    for(int i = index; i < a->len - 1; i++) a[i] = a[i + 1];
}

void stampa_appuntamenti_del_mese(Agenda a){
    for(int i = 0; i < a.len; i++)
    {
        printf("Appuntamnto n%d\nData %d/%d/%d\nDalle ore %d:00 alle %d:00\n Descrizione: %s", a.len, a.appuntamenti[i].giorno, a.appuntamenti[i].mese, a.appuntamenti[i].ora_inizio, a.appuntamenti[i].ora_fine, a.appuntamenti[i].descrizione);
    }
    
}