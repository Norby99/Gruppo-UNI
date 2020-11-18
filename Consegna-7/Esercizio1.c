/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201120
 NOTE:    Text Ex01: Scrivere un programma C che simuli la gestione di un’agenda annuale e dei relativi appuntamenti.
          Ogni appuntamento deve essere rappresentato da una struttura contenente giorno, mese, ora inizio, ora fine e descrizione.
          Scrivere le funzioni:
          inserisci_appuntamento (verificare che nello stesso giorno e alla stessa ora non ci sia già un altro appuntamento),
          elimina_appuntamento,
          stampa_appuntamenti_del_mese*/

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
int printMenu();

int main()
{
    Agenda agenda = newAgenda();

    switch(printMenu())
    {
        case 1:
        inserisci_appuntamento();
        break;
        case 2:
        elimina_appuntamento():
        break;
        case 3:
        stampa_appuntamenti_del_mese();                
        break;
    }

    return 0;
}

void inserisci_appuntamento(Agenda a, Appuntamento ap)
{
    int i=0;

    printf("Salve, stai per registrare un nuovo appuntamento.\n\n");
    printf("Inserisci il giorno: ");
    scanf("%d ",&ap.giorno);
    printf("Inserisci l'ora di inzio: ");
    scanf("%d ",&ap.ora_inizio);
    printf("inserisci l'ora di fine: ");
    scanf("%d ",&ap.ora_fine);
    printf("Inserisci la descrizione: ");
    scanf("%d ",&ap.descrizione);

    i++;
}

void elimina_appuntamento(Agenda* a, int index)
{
    for(int i = index; i < a->len - 1; i++)
    {
        a[i] = a[i + 1];
    }
}

void stampa_appuntamenti_del_mese(Agenda a)
{
    for(int i = 0; i < a.len; i++)
    {
        printf("Appuntamnto n%d\nData %d/%d/%d\nDalle ore %d:00 alle %d:00\n Descrizione: %s", a.len, a.appuntamenti[i].giorno, a.appuntamenti[i].mese, a.appuntamenti[i].ora_inizio, a.appuntamenti[i].ora_fine, a.appuntamenti[i].descrizione);
    }

}

int printMenu()
{
    int choice;

    printf("MENU\' DI GESTIONE DELLA TUA AGENDA\n");
    printf("1) Inserimento nuovo appuntamento\n");
    printf("2) Elimina appuntamento\n");
    printf("3) Stampa dell'agenda\n");

    printf("\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice!=1 && choice!=2 && choice!=3)
    {
        if(choice!=1 || choice!=2 || choice!=3)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }

    return choice;
}
