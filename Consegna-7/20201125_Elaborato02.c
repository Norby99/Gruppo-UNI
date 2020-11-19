/* rega ci ho provato, anche se non credo il tutto sia  così comprensibile.... mi sono bloccata già all'inserimento, sono molto simpatiche queste struct annidate....
comunque dai, su col morale, dobbiamo solo farne due versioni.... :))))))))))
if (2versioni==true)
{
          versione2=0.99*versione1; //99% copy and paste is the wayyyy, 99% come i batteri che ammazza l'amuchina ezy
          for(i=0; i<0,1%; ){
                   printf("the smallest bug the biggest time guys");
          }
}
ok ho finito lo sclero, abbiate pietà :_) <3

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

#define MAX_INSEGNAMENTI_CORSO 30 // 1 anno = 60 CFU -> x3 = 180 CFU & ogni materia minimo 6 CFU => 180/6= 30 MAX_INSEGNAMENTI_CORSO
#define MAX_STUDENTI_CORSO 244
#define N_ESAMI 10 // max 10 esami all'anno
#define MAX_CODE_LEN 10
#define MAX_NAME_LEN 30
#define MAX_ANNO 3000
#define MAX_VOTO 30

typedef struct {
    char *i_codice, *i_descrizione;
    int *i_annoSomm, *i_crediti;
}INSEGNAMENTO;

typedef struct
{
    INSEGNAMENTO *list;
    int len;
}INSEGNAMENTI_CORSO;

typedef struct {
    INSEGNAMENTO *ps_insegnamento;
    int *ps_voto;
}PIANO_STUDI;

typedef struct {
    char *s_Nmatricola, *s_nome, *s_cognome;
    int *s_annoImm;
    PIANO_STUDI s_pianoStudi;
}STUDENTE;

/**** 1) malloc ****/
typedef struct
{
    STUDENTE *list;
    int len;
}STUDENTI_CORSO1;

/**** 2) no malloc ****/
typedef struct
{
    STUDENTE list[MAX_STUDENTI_CORSO];
    int len;
}STUDENTI_CORSO2;


    /********************print da usare per DEBUG********************/
void printAllValues(STUDENTI_CORSO1 *);


/*********************** PROTOTIPI delle FUNZIONI ************************/

int codeChoiceMenu();
int printMenu();

// prototipi funzioni per l'inizializzazione gruppi di strutture...
INSEGNAMENTI_CORSO *ins_corso_init();
STUDENTI_CORSO1 *s_corso_init1();    //**** 1) malloc ****
STUDENTI_CORSO2 s_corso_init2();     //**** 2) no malloc ****

// ... e la loro cancellazione dalla memoria
void destroyer(INSEGNAMENTI_CORSO *, STUDENTI_CORSO1 *);

// funzioni del menu
void addInsegnamento(INSEGNAMENTI_CORSO *, char *, char *, int *, int *);
//**** 1) malloc ****
bool isIn1(STUDENTI_CORSO1 *, char *);
void addStudente1(STUDENTI_CORSO1 *, char *, char *, char *, int *, INSEGNAMENTO *, int *);
void tryAddStudente1(STUDENTI_CORSO1 *);
void printStudente1(STUDENTI_CORSO1 *);
void addVoto1(STUDENTI_CORSO1 *);
void mediaVoti1(STUDENTI_CORSO1 *);
//**** 2) no malloc ****
bool isIn2();
void addStudente2();
void tryAddStudente2();
void printStudente2();
void addVoto2();
void mediaVoti2();

/********************************* MAIN **********************************/

int main ()
{
    // creazione istanze
    INSEGNAMENTI_CORSO *ins_corso = ins_corso_init();
    STUDENTI_CORSO1 *s_corso = s_corso_init1();        //**** 1) malloc ****
    STUDENTI_CORSO2 s_corso_init2();                   //**** 2) no malloc ****

    // menu di scelta tra le due varianti richieste del programma
    bool temp = true, tmp = true;
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
                            tryAddStudente1(s_corso);
                            break;
                        case 2:
                            printStudente1(s_corso);
                            break;
                        case 3:
                            addVoto1(s_corso);
                            break;
                        case 4:
                            mediaVoti1(s_corso);
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
                            tryAddStudente2();
                            break;
                        case 2:
                            printStudente2();
                            break;
                        case 3:
                            addVoto2();
                            break;
                        case 4:
                            mediaVoti2();
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

    // cancellazione dalla memoria
    destroyer(ins_corso, s_corso);

    system("pause");
    return 0;
}

    /********************print da usare per DEBUG********************/
void printAllValues(STUDENTI_CORSO1 *sc)
{
    printf("AAAAAAAAAAAH\n");
    for(int i=0; i< sc->len; i++)
    {
        printf("%c : \n", sc->list[i].s_Nmatricola);
    }
    printf("\n");
}

/******************************* FUNZIONI MENU ***************************/

void addInsegnamento(INSEGNAMENTI_CORSO *ic, char *i_codice, char *i_descrizione, int *i_annoSomm, int *i_crediti)
{
}

/**** 1) malloc ****/

// aggiunge effettivamente i dati nella struttura studente dentro l'array con tutti gli studenti del corso
void addStudente1 (STUDENTI_CORSO1 *sc, char *m, char *n, char *c, int *a, INSEGNAMENTO *i, int *v)
{
    sc->list[sc->len].s_Nmatricola = m;
    sc->list[sc->len].s_nome = n;
    sc->list[sc->len].s_cognome = c;
    sc->list[sc->len].s_annoImm = a;
    sc->list[sc->len].s_pianoStudi.ps_insegnamento = i;
    sc->list[sc->len].s_pianoStudi.ps_voto = v;
    sc->len++;
}

// controllo se nome studente già registrato
bool isIn1(STUDENTI_CORSO1 *sc, char *m)
{
    for(int i=0; i < sc->len; i++)
    {
        if(sc->list[i].s_Nmatricola == m)
            return true;
    }
    return false;
}

void tryAddStudente1 (STUDENTI_CORSO1 *sc) // verifica se studente in input non sia già presente
{
    char *s_Nmatricola, *s_nome, *s_cognome;
    INSEGNAMENTO *ps_insegnamento;
    int *s_annoImm, *ps_voto;

    s_Nmatricola = (char*)malloc(MAX_CODE_LEN*sizeof(char));
    s_nome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    s_cognome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    ps_insegnamento = (INSEGNAMENTO*)malloc(MAX_NAME_LEN*sizeof(INSEGNAMENTO));
    s_annoImm = (int*)malloc(MAX_ANNO*sizeof(int));
    ps_voto = (int*)malloc(MAX_VOTO*sizeof(int));

    printf("Inserire:\n- numero di matricola: ");
    scanf(" %[^\n]%*c", s_Nmatricola);
    fflush(stdin);
    if(isIn1(sc, s_Nmatricola))
    {
        printf("Numero di matricola gia' presente!!\n\n");
    }else{
        printf("- nome: ");
        scanf(" %[^\n]%*c", s_nome);
        fflush(stdin);
        printf("- cognome: ");
        scanf(" %[^\n]%*c", s_cognome);
        fflush(stdin);
        printf("- anno di immatricolazione: ");
        scanf(" %[^\n]%*d", s_annoImm);
        fflush(stdin);
        printf("\nPiano di studi:\n- insegnamento: ");
        scanf(" %[^\n]%*c", ps_insegnamento);
        fflush(stdin);
        printf("- voto: ");
        scanf(" %[^\n]%*d", ps_voto);
        fflush(stdin);
        //crea funzione piano di studi
        addStudente1 (sc, s_Nmatricola, s_nome, s_cognome, s_annoImm, ps_insegnamento, ps_voto);
    }

    printAllValues(sc);
    printf("\n\n\n\n");
}

void printStudente1(STUDENTI_CORSO1 *sc)
{
}

void addVoto1(STUDENTI_CORSO1 *sc)
{
}

void mediaVoti1(STUDENTI_CORSO1 *sc)
{
}

/**** 2) no malloc ****/

void AddStudente2 ()
{
}

void tryAddStudente2 ()
{
}

void printStudente2()
{
}

void addVoto2()
{
}

void mediaVoti2()
{
}

/***************************** GESTIONE ISTANZE **************************/

// inizializzazione
INSEGNAMENTI_CORSO *ins_corso_init ()
{
    INSEGNAMENTI_CORSO *ic;
    ic = (INSEGNAMENTI_CORSO*)malloc(MAX_INSEGNAMENTI_CORSO*sizeof(INSEGNAMENTI_CORSO));
    ic->len=0;
    return ic;
}

STUDENTI_CORSO1 *s_corso_init1 ()
{
    STUDENTI_CORSO1 *sc;
    sc = (STUDENTI_CORSO1*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTI_CORSO1));
    sc->len=0;
    return sc;
}

/*STUDENTI_CORSO2 *s_corso_init2 ()
{
    STUDENTI_CORSO2 *sc;
    sc = (STUDENTI_CORSO*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTI_CORSO1));
    sc->len=0;
    return sc;
}*/

// cancellazione dalla memoria
void destroyer (INSEGNAMENTI_CORSO *ic, STUDENTI_CORSO1 *sc)
{
    free(ic);
    free(sc);
}

/**************************** STAMPA MENU *******************************/

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

int printMenu()
{
    int choice;

    printf("Rubrica\n");
    printf("1) Aggiungere un nuovo studente\n");
    printf("2) Stampare le informazioni di uno studente fornendo il numero di matricola\n");
    printf("3) Aggiungere un voto di uno studente fornendo il numero di matricola\n");
    printf("4) Stampare la media dei voti di tutti gli studenti che hanno completato il piano di studi\n");
    printf("   (calcolo automaticamente effettuato in base al numero di crediti di ogni insegnamento)\n");
    printf("0) Esci dal programma\n\n");

    printf("Scegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);

    return choice;
}
