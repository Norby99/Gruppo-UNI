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
    int ora;
    int minuto;
}orario;

typedef struct{
    int giorno;
    int mese;
    orario ora_inizio;
    orario ora_fine;
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

void inserisci_appuntamento(Agenda*, Appuntamento);
void controllo_lunghezzaAgenda(Agenda *);
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
          inserisci_appuntamento(agenda, creaAppuntament());
          break;
          case 2:
          controllo_lunghezzaAgenda(agenda);
          break;
          case 3:
          stampa_appuntamenti_del_mese(agenda);
          break;
          case 0:
          temp=false;
          break;
        }
        printf("\n\n");
    }

    destroyer(agenda);
    return 0;
}

// metodi di Agenda

void inserisci_appuntamento(Agenda* a, Appuntamento ap)
{

    a->appuntamenti[a->len].giorno = ap.giorno;
    a->appuntamenti[a->len].mese = ap.mese;
    a->appuntamenti[a->len].ora_inizio.ora = ap.ora_inizio.ora;
    a->appuntamenti[a->len].ora_inizio.minuto = ap.ora_inizio.minuto;
    a->appuntamenti[a->len].ora_fine.ora = ap.ora_fine.ora;
    a->appuntamenti[a->len].ora_fine.minuto = ap.ora_fine.minuto;
    a->appuntamenti[a->len].descrizione = ap.descrizione;
    a->len++;

}

void elimina_appuntamento(Agenda* a, int index)
{

    //printf("%d",a->appuntamenti[0].giorno);
    for(int i = index; i < a->len - 1; i++)
    {
        a->appuntamenti[i]=a->appuntamenti[i+1];
    }
    a->len--;
}

void controllo_lunghezzaAgenda(Agenda *a)
{
    int temp;

    do
    {
        printf("Quale appuntamento vuoi eliminare dalla tua agenda? ");
        scanf(" %d",&temp);

        if(temp>=0 && temp <= a->len)
        {
            break;
        }
        else
        {
            printf("\nDato inserito non corretto\n");
        }
    }while(true);

    elimina_appuntamento(a,temp);
    printf("\nElemento %d",temp);

}

void stampa_appuntamenti_del_mese(Agenda* a)
{
    int num_mese;

    //printf("Di quale mese vuoi stampare la tua agenda? ");
    //scanf("%d ",&num_mese);
    //fflush(stdin);

    printf("Agenda 2021");
    for(int i = 0; i < a->len; i++)
    {
        printf("Appuntamento n %d\n\nData %d/%d\nDalle ore %d:%d alle %d:%d\nDescrizione: %s\n\n", i+1, a->appuntamenti[i].giorno, a->appuntamenti[i].mese, a->appuntamenti[i].ora_inizio.ora, a->appuntamenti[i].ora_inizio.minuto, a->appuntamenti[i].ora_fine.ora, a->appuntamenti[i].ora_fine.minuto, a->appuntamenti[i].descrizione);
    }

}

// funzioni generiche

Appuntamento creaAppuntament()
{
    Appuntamento ap;

    int max_giorni;

    printf("Salve, stai per registrare un nuovo appuntamento.\n\n");
    printf("Inserisci il mese e il giorno [formato: mm/gg]: ");
    scanf(" %d/%d", &ap.mese, &ap.giorno);

    while(ap.mese<1 || ap.mese>12)
    {
        if(ap.mese>=1 && ap.mese<=12)
        {
            switch(ap.mese)
            {
                case 4: case 6: case 9: case 11:
                    max_giorni=30;
                break;

                case 2:
                    max_giorni=28;
                break;
                default:
                    max_giorni=31;
                break;
            }

            while(ap.giorno<1 || ap.giorno>max_giorni)
            {
                if(!(ap.giorno>=1 && ap.giorno<=max_giorni))
                {
                    printf("Errore di inserimento, riprova a inserire il giorno: ");
                    scanf(" %d",&ap.giorno);
                }
            }
        }
        else
        {
            printf("Errore di inserimento, riprova a inserire il mese: ");
            scanf(" %d",&ap.mese);
        }
    }
    //printf("%d ",ap.giorno);
    printf("Inserisci l'ora di inzio [formato: hh:mm]: ");
    scanf(" %d:%d", &ap.ora_inizio.ora, &ap.ora_inizio.minuto);
    printf("Inserisci l'ora di fine [formato: hh:mm]: ");
    scanf(" %d:%d", &ap.ora_fine.ora, &ap.ora_fine.minuto);

    ap.descrizione = (char*)malloc(40);
    printf("Inserisci la descrizione: ");
    scanf(" %[^\n]%*c", ap.descrizione);

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
