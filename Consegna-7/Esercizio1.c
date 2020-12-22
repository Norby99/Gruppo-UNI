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
//ciao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DAYS 365

//Dichiarazione delle strutture
typedef struct{
    int codice;
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

//Istanzio la nuova rubrica
Agenda *newAgenda(){
    Agenda *a;
    a = (Agenda*)malloc(MAX_DAYS*sizeof(Agenda));
    a->len = 0;
    return a;
}

//Dichirazione delle funzioni
void inserisci_appuntamento(Agenda*, Appuntamento);
void controllo_lunghezzaAgenda(Agenda *);
void elimina_appuntamento(Agenda*, int);
void stampa_appuntamenti_del_mese(Agenda*);
void destroyer(Agenda *);
bool controllo_accavallamentoAppuntamenti (Agenda*, Appuntamento);
Appuntamento creaAppuntament(Agenda *);
int printMenu();

int main()
{
    Agenda *agenda = newAgenda();
    bool temp=true;

    while(temp)
    {
        switch(printMenu())
        {
            case 1:
                inserisci_appuntamento(agenda, creaAppuntament(agenda));
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

//Funzione che inserisce gli appuntamenti all'interno dell'agenda

void inserisci_appuntamento(Agenda* a, Appuntamento ap)
{

    a->appuntamenti[a->len].codice = ap.codice;
    a->appuntamenti[a->len].giorno = ap.giorno;
    a->appuntamenti[a->len].mese = ap.mese;
    a->appuntamenti[a->len].ora_inizio = ap.ora_inizio;
    a->appuntamenti[a->len].ora_fine= ap.ora_fine;
    a->appuntamenti[a->len].descrizione = ap.descrizione;
    a->len++;


}

//Funzione che elimina un appuntamento all'interno dell'agenda in base al codice identificativo

void elimina_appuntamento(Agenda* a, int index)
{
    bool flag=false;

    for(int i = 0; i < a->len; i++)
    {
        if(a->appuntamenti[i].codice == index)
        {
            flag=true;
        }
        if(flag==true)
        {
            a->appuntamenti[i] = a->appuntamenti[i+1];
        }

    }
    a->len--;
}

//Funzione che controlla se il codice dell'appuntamento da eliminare è effettivamente presente nell'agenda

void controllo_lunghezzaAgenda(Agenda *a)
{
    int temp;
    bool flag=false;

    printf("Quale appuntamento vuoi eliminare dalla tua agenda? [Inserisci il codice] ");
    scanf(" %d",&temp);

    for(int i=0; i < a->len; i++)
    {
        if(a->appuntamenti[i].codice == temp)
            flag=true;
    }

    if(flag==false)
    {
        printf("\nNon esiste nessun appuntamento con questo codice\n");
    }
    else
    {
        elimina_appuntamento(a,temp);
        printf("\nL'appuntamento con codice %d, e\' stato eliminato\n",temp);
    }

}

//Funzione che stampa gli appuntamenti di un mese inserito dall'utente

void stampa_appuntamenti_del_mese(Agenda* a)
{
    int num_mese, c=0;

    printf("Di quale mese vuoi stampare la tua agenda? ");
    scanf(" %d",&num_mese);
    printf("\n\n");

    for(int i = 0; i < a->len; i++)
    {
        if(a->appuntamenti[i].mese == num_mese)
        {
            printf("Appuntamento/i \n\nCodice %d\nData %d/%d\nDalle ore %d:00 alle %d:00\nDescrizione: %s\n\n",a->appuntamenti[i].codice, a->appuntamenti[i].giorno, a->appuntamenti[i].mese, a->appuntamenti[i].ora_inizio, a->appuntamenti[i].ora_fine, a->appuntamenti[i].descrizione);
            c++;
        }
    }
    if(c==0)
        printf("\nNon sono presenti appuntamenti nel mese selezionato\n");

}

//Funzione che inserisce gli appuntamenti

Appuntamento creaAppuntament(Agenda *a)
{
    Appuntamento ap;
    ap.descrizione=NULL;

    int max_giorni;
    bool flag=false;

    do
    {
        printf("Salve, stai per registrare un nuovo appuntamento.\n\n");
        printf("Inserisci un codice identificativo: ");
        scanf(" %d",&ap.codice);

        for(int i=0; i < a->len; i++)
        {
            if(a->appuntamenti[i].codice == ap.codice)
            {
                 flag=true;
                 break;
            }
            else
                flag=false;
        }

        if(flag==true)
            printf("\nE\' gia\' presente un appuntamento con questo codice, ritenta l'inserimento: ");

    }while(flag==true);

    printf("Inserisci il mese e il giorno [formato: mm/gg]: ");
    scanf(" %d/%d", &ap.mese, &ap.giorno);

    while(true)
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

            while(true)
            {
                if(!(ap.giorno>=1 && ap.giorno<=max_giorni))
                {
                    printf("\nErrore di inserimento, riprova a reinserire la data: ");
                    scanf(" %d/%d", &ap.mese, &ap.giorno);

                }
                else
                {
                    break;
                }
            }
            break;
        }
        else
        {
            printf("\nErrore di inserimento, riprova a reinserire la data: ");
            scanf(" %d/%d", &ap.mese, &ap.giorno);

        }
    }
    printf("Inserisci l'ora di inzio [formato: hh]: ");
    scanf(" %d", &ap.ora_inizio);

    while(true)
    {
        if(!(ap.ora_inizio>=0 && ap.ora_inizio<=23))
        {
            printf("Orario di inzio sbagliato, ritenta: ");
            scanf(" %d", &ap.ora_inizio);
        }
        else
        {
            break;
        }

    }

    printf("Inserisci l'ora di fine [formato: hh]: ");
    scanf(" %d", &ap.ora_fine);

     while(true)
    {
        if(!(ap.ora_fine>=0 && ap.ora_fine<=23) || !(ap.ora_inizio<ap.ora_fine))
        {
            printf("Orario di fine sbagliato, ritenta: ");
            scanf(" %d", &ap.ora_fine);
        }
        else
        {
            break;
        }

    }

   while(true)
   {
        if(!controllo_accavallamentoAppuntamenti(a,ap))
        {
            if(ap.descrizione == NULL)
            {
                ap.descrizione = (char*)malloc(40);
                printf("Inserisci la descrizione: ");
                scanf(" %[^\n]%*c", ap.descrizione);
            }
            break;
        }
        else
        {
            printf("\nIn questo giorno a quest'ora e\' gia\' presente un appuntamento, ritenta inserimento: \n");
            ap = creaAppuntament(a);
        }
   }


    return ap;
}

//Funzione che controlla se gli appuntamenti scritti in uno stesso giorno si accavvallano

bool controllo_accavallamentoAppuntamenti (Agenda *a, Appuntamento ap)
{
    for(int i=0; i<a->len; i++)
    {
        if(a->appuntamenti[i].mese==ap.mese && a->appuntamenti[i].giorno==ap.giorno)
        {
            if(((ap.ora_inizio<a->appuntamenti[i].ora_inizio && a->appuntamenti[i].ora_inizio<ap.ora_fine ) || (ap.ora_inizio<a->appuntamenti[i].ora_fine && a->appuntamenti[i].ora_fine<ap.ora_fine ))||((a->appuntamenti[i].ora_inizio<ap.ora_inizio && ap.ora_inizio<a->appuntamenti[i].ora_fine ) || (a->appuntamenti[i].ora_inizio<ap.ora_fine && ap.ora_fine<a->appuntamenti[i].ora_fine )))
            {
              return true;
            }
        }
    }
    return false;
}

//Funzione che stampa il menù di scelta

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

//Funzione distruttore della malloc

void destroyer(Agenda *a)
{
    free(a);
}
