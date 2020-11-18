/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201120
 NOTE:    Text Ex02: Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti iscritti ad un corso
          di laurea. Il programma utilizza un vettore di strutture, ognuna delle quali memorizza le informazioni di uno studente
          (numero matricola, nome e cognome, anno di immatricolazione, piano di studi, …).
          Il programma utilizza inoltre un vettore di strutture, ognuna delle quali memorizza le informazioni di un insegnamento
          (codice, descrizione, anno di somministrazione, crediti, …). Il programma deve fornire la possibilità di:
            - aggiungere un nuovo studente, stampando un messaggio di errore se lo studente è già presente (individuato dalla matricola)
              o se il vettore è pieno; la funzione deve inoltre assegnargli un piano di studi scegliendo fra gli insegnamenti disponibili.
            - dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore
              se la matricola non è presente nel vettore
            - dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto
              oppure stampando un messaggio di errore se la matricola non è presente nel vettore.
            - Calcolare la media dei voti di tutti gli studenti che hanno completato il piano di studi pesata sul numero di crediti
              di ogni insegnamento.
          Il piano di studi all’interno della struttura studente è un vettore di NUM_ESAMI elementi ognuno di tipo struttura
          contenete il codice dell'insegnamento e il voto corrispondente (0 se non sostenuto).
          Modificare poi il programma in modo che il vettore di studenti venga allocato dinamicamente usando la funzione malloc().*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_STUDENTI_CORSO 244
// ogni anno 60 CFU -> x3 anni tot. 180 CFU & ogni materia minimo 6 CFU => 180/6= 30 MAX_INSEGNAMENTI_CORSO
#define MAX_INSEGNAMENTI_CORSO 30

// creazione sinonimo di tipo "STUDENTE" per identificare la struttura con i campi per ogni studente inserito
typedef struct {
    char s_Nmatricola[10], s_nome[30], s_cognome[30]; //MEMO qnd inserisco n_matricola voglio trattarlo come char, in quanto codice, ma input must isdigit()
    int s_annoImm;
    //piano di studi mi serve un tipo specifico apposta mi sa
}STUDENTE;

typedef struct {
    char i_codice[10], i_descrizione[100];
    int i_annoSomm, i_crediti;
}INSEGNAMENTO;

/* creazione sinonimo di tipo "STUDENTI_CORSO" per identificare la struttura che memorizza l'array
   (contenente strutture degli studenti con relative info) e la sua lunghezza*/
typedef struct
{
    STUDENTE list[MAX_STUDENTI_CORSO];
    int len;
}STUDENTI_CORSO;

typedef struct
{
    INSEGNAMENTO list[MAX_INSEGNAMENTI_CORSO];
    int len;
}INSEGNAMENTI_CORSO;

/*********************** PROTOTIPI delle FUNZIONI ************************/

int codeChoiceMenu();
int printMenu();

/********************************* MAIN **********************************/

/* 2 versioniiiiiiiiiiiiiiiiiiiiiiiii :))))))))))
          if (2versioni==true){
                versione2=0,99*versione1;    //copia e incolla is the way 99% (come i batteri che elimina l'amuchina)
          }
    oky vi saluto e faccio qualcosa di utile entro sera amichi di uni, promesso u.u*/

int main ()
{
    bool temp = true, tmp = true;
    //menu di scelta tra le due variazioni richieste del programma
    while(tmp)
    {
        switch(codeChoiceMenu())
        {
            case 1: // allocazione dinamica
                while(temp)
                {
                    switch(printMenu())
                    {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 0:
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
                }
            case 2: // altra modalità
                while(temp)
                {
                    switch(printMenu())
                    {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 0:
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
                }
            case 0:
                tmp = false;
                break;
            default:
                printf("!!Valore inserito non valido!! Riprova.\n");
                break;
            }
    }
    system("pause");
    return 0;
}

// stampa menu di scelta tra le 2 varianti richieste del programma
int codeChoiceMenu()
{
    int choice;

    printf("Quale variazione del codice vuoi eseguire?\n");
    printf("1) Allocazione dinamica della memoria\n");
    printf("2) Altra modalita\'\n");
    printf("0) Termina il processo ed esci dal programma\n\n");

    printf("Scegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);

    // pulisco lo schermo dal primo menu
    system("cls");

    return choice;
}

// stampa menu del programma
int printMenu()
{
    int choice;

    printf("Rubrica\n");
    printf("1) Aggiungere un nuovo studente\n");
    printf("2) Stampare le informazioni di uno studente fornendo il numero di matricola\n");
    printf("3) Modificare le informazioni del piano di studi aggiungendo un voto di uno studente fornendo il numero di matricola\n");
    printf("4) Stampare la media dei voti di tutti gli studenti che hanno completato il piano di studi\n");
    printf("   (calcolo automaticamente effettuato in base al numero di crediti di ogni insegnamento)\n");
    printf("0) Esci dal programma\n\n");

    printf("Scegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);

    return choice;
}
