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

Agenda *newAgenda(){
    Agenda *a;
    a = (Agenda*)malloc(MAX_DAYS*sizeof(Agenda));
    a->len = 0;
    return a;
}

void inserisci_appuntamento(Agenda*);
void elimina_appuntamento(Agenda*, int);
void stampa_appuntamenti_del_mese(Agenda*);
void destroyer(Agenda *);

Appuntamento creaAppuntament();
int printMenu();

int main()
{
    Agenda *agenda = newAgenda();
    bool temp=true;
    //esempio di funzionamento
    /*inserisci_appuntamento(&agenda, creaAppuntament());
    printf("\n-- %d", agenda.appuntamenti[0].giorno);*/

    while(temp)
    {
       switch(printMenu())
       {
          case 1:
          inserisci_appuntamento(agenda);
          break;
          case 2:
          //elimina_appuntamento();
          break;
          case 3:
          stampa_appuntamenti_del_mese(agenda);
          break;
          case 0:
          temp=false;
          break;
        }
    }

    destroyer(agenda);
    return 0;
}

// metodi di Agenda

void inserisci_appuntamento(Agenda* a)
{
    Appuntamento ap;
    creaAppuntament(ap);

    a->appuntamenti[a->len].giorno = ap.giorno;
    a->appuntamenti[a->len].mese = ap.mese;
    a->appuntamenti[a->len].ora_inizio = ap.ora_inizio;
    a->appuntamenti[a->len].ora_fine = ap.ora_fine;
    a->appuntamenti[a->len].descrizione = ap.descrizione;
    a->len++;
}

void elimina_appuntamento(Agenda* a, int index)
{
    for(int i = index; i < a->len - 1; i++)
    {
        a[i] = a[i + 1];
    }
}

void stampa_appuntamenti_del_mese(Agenda* a)
{
    int num_mese;

    printf("Di quale mese vuoi stampare la tua agenda? ");
    scanf("%d ",&num_mese);
    fflush(stdin);

    for(int i = 0; i < a->len && a->appuntamenti[i].mese==num_mese ; i++)
    {
        printf("Appuntamnto n%d\nData %d/%d/%d\nDalle ore %d:00 alle %d:00\n Descrizione: %s", a->len, a->appuntamenti[i].giorno, a->appuntamenti[i].mese, a->appuntamenti[i].ora_inizio, a->appuntamenti[i].ora_fine, a->appuntamenti[i].descrizione);
    }

}

// funzioni generiche

Appuntamento creaAppuntament()
{
    Appuntamento ap;
    printf("Salve, stai per registrare un nuovo appuntamento.\n\n");
    printf("Inserisci il giorno e il mese [formato: gg/mm]: ");
    scanf(" %d %d", &ap.giorno, &ap.mese);
    printf("Inserisci l'ora di inzio e l'ora di fine [formato: Hi-Hf]: ");
    scanf(" %d %d", &ap.ora_inizio, &ap.ora_fine);
    printf("Inserisci la descrizione: ");
    scanf(" %s", ap.descrizione);

    return ap;
}

int printMenu()
{
    int choice;

    printf("MENU\' DI GESTIONE DELLA TUA AGENDA\n");
    printf("1) Inserimento nuovo appuntamento\n");
    printf("2) Elimina appuntamento\n");
    printf("3) Stampa dell'agenda\n");
    printf("\n(Premi 0 per uscire dal programma)\n");

    printf("\n\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice!=1 && choice!=2 && choice!=3 && choice!=0)
    {
        if(choice!=1 || choice!=2 || choice!=3 || choice!=0)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    system("cls");
    return choice;
}

void destroyer(Agenda *a)
{
    free(a);
}

