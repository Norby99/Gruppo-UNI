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

typedef struct {
    char *i_codice, *i_descrizione; //MEMO qnd inserisco codice voglio trattarlo come char, in quanto codice, ma input must isdigit()
    int *i_annoSomm, *i_crediti;
}INSEGNAMENTO;

typedef struct
{
    INSEGNAMENTO *list;
    int len;
}INSEGNAMENTI_CORSO;
//rivedi!!!!!!!!!1
typedef struct {
    INSEGNAMENTO *ps_insegnamento;
    int *voto, len;
}PIANO_STUDI;

typedef struct {
    char *s_Nmatricola, *s_nome, *s_cognome; //MEMOx2 qnd inserisco n_matricola voglio trattarlo come char, in quanto codice, ma input must isdigit()
    int *s_annoImm;
    PIANO_STUDI *s_pianoStudi; // RIVEDI!!!!!!! array contenente strutture di ogni INSEGNAMENTO e relativo voto
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
void addStudente1(STUDENTI_CORSO1 *, char *, char *, char *, int *, PIANO_STUDI *);
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
    for(int i=0;i < sc->len; i++){
        printf("%s : \n", sc->list[i].s_nome);
    }
    printf("\n");
}

/******************************* FUNZIONI MENU ***************************/

void addInsegnamento(INSEGNAMENTI_CORSO *ic, char *i_codice, char *i_descrizione, int *i_annoSomm, int *i_crediti)
{
}

/**** 1) malloc ****/

// controllo se nome studente già registrato
bool isIn1(STUDENTI_CORSO1 *sc, char *n)
{
    for(int i=0; i < sc->len; i++)
    {
        if(sc->list[i].s_nome == n)
            return true;
    }
    return false;
}

// aggiunge effettivamente studente all'array
void addStudente1 (STUDENTI_CORSO1 *sc, char *m, char *n, char *c, int *a, PIANO_STUDI *ps)
{
    sc->list[sc->len].s_Nmatricola = m;
    sc->len++;
}

void tryAddStudente1 (STUDENTI_CORSO1 *sc) // verifica se studente in input non sia già presente
{
    char *s_Nmatricola, *s_nome, *s_cognome;
    int *s_annoImm;
    PIANO_STUDI *s_pianoStudi;

    s_Nmatricola = (char*)malloc(MAX_CODE_LEN*sizeof(char));
    s_nome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    s_cognome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    s_annoImm = (int*)malloc(MAX_ANNO*sizeof(int));
    s_pianoStudi = (PIANO_STUDI*)malloc(N_ESAMI*sizeof(PIANO_STUDI));

    printf("Inserire il numero di matricola: ");
    scanf(" %[^\n]%*c", s_Nmatricola);
    fflush(stdin);
    if(isIn1(sc, s_Nmatricola))
    {
        printf("Numero di matricola gia' presente!\n\n");
    }else{
        //inserimento altri daati
        addStudente1 (sc, s_Nmatricola, s_nome, s_cognome, s_annoImm, s_pianoStudi);
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
