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
#define MAX_CREDITI 12

typedef struct {
    char *i_descrizione;
    int *i_codice, *i_annoSomm, *i_crediti;
}INSEGNAMENTO;

typedef struct {
    INSEGNAMENTO *ps_insegnamento;
    int *ps_voto;
}PIANO_STUDI;

typedef struct {
    int *s_Nmatricola, *s_annoImm;
    char *s_nome, *s_cognome;
    PIANO_STUDI *s_pianoStudi;
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
void printAllValues(STUDENTI_CORSO1 *, INSEGNAMENTO *);


/*********************** PROTOTIPI delle FUNZIONI ************************/

int codeChoiceMenu();
int printMenu();

// prototipi funzioni per l'inizializzazione gruppi di strutture...
INSEGNAMENTO *ins_c_init();
STUDENTI_CORSO1 *s_corso_init1();    //**** 1) malloc ****
STUDENTI_CORSO2 s_corso_init2();     //**** 2) no malloc ****

// ... e la loro cancellazione dalla memoria
void destroyer(INSEGNAMENTO *, STUDENTI_CORSO1 *);

// funzioni del menu
//**** 1) malloc ****
bool isIn1(STUDENTI_CORSO1 *, int *);
void addStudente1(STUDENTI_CORSO1 *, int *, char *, char *, int *, INSEGNAMENTO *, int *);
void tryAddStudente1(STUDENTI_CORSO1 *, INSEGNAMENTO *);
void printStudente1(STUDENTI_CORSO1 *, INSEGNAMENTO *);
void addVoto1(STUDENTI_CORSO1 *, INSEGNAMENTO *);
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
    INSEGNAMENTO *ins_corso = ins_c_init();
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
                            tryAddStudente1(s_corso, ins_corso);
                            break;
                        case 2:
                            printStudente1(s_corso, ins_corso);
                            break;
                        case 3:
                            addVoto1(s_corso, ins_corso);
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

    destroyer(ins_corso, s_corso);  // restituisce al s.o. la gestione della memoria

    system("pause");
    return 0;
}

/********************print da usare per DEBUG********************/
void printAllValues(STUDENTI_CORSO1 *sc, INSEGNAMENTO *ic)
{
    printf("AAAAAA");
    for(int i=0; i < sc->len; i++)
    {
        printf("%d \n", sc->list[i].s_Nmatricola);
        printf("%s \n", sc->list[i].s_nome);
        printf("%s \n", sc->list[i].s_cognome);
        printf("%d \n", sc->list[i].s_annoImm);
        /*printf("%s \n", sc->list[i].s_pianoStudi.ps_insegnamento);
        printf("%d \n", sc->list[i].s_pianoStudi.ps_voto);*/
    }

    printf("\n");

    for(int i=0; i < 2; i++)
    {
        printf("%s \n", ic[i].i_descrizione);
        printf("%d \n", ic[i].i_codice);
        printf("%d \n", ic[i].i_annoSomm);
        printf("%d \n", ic[i].i_crediti);
    }

    printf("\n");
}

/******************************* FUNZIONI MENU ***************************/

/**** 1) malloc ****/

// aggiunge effettivamente i dati nella struttura studente dentro l'array con tutti gli studenti del corso
void addStudente1 (STUDENTI_CORSO1 *sc, int *m, char *n, char *c, int *a, INSEGNAMENTO *i, int *v)
{
    sc->list[sc->len].s_Nmatricola = m;
    sc->list[sc->len].s_nome = n;
    sc->list[sc->len].s_cognome = c;
    sc->list[sc->len].s_annoImm = a;
    sc->list[sc->len].s_pianoStudi.ps_insegnamento = i;
    sc->list[sc->len].s_pianoStudi.ps_voto = v;
    sc->len++;      // incrementa array di studenti per ogni studente che viene aggiunto
}

bool isIn1(STUDENTI_CORSO1 *sc, int *m) // controlla se matricola studente già registrata
{
    for(int i=0; i < sc->len; i++)
    {
        if(sc->list[i].s_Nmatricola == m)
            return true;
    }
    return false;
}

void tryAddStudente1 (STUDENTI_CORSO1 *sc, INSEGNAMENTO *ic) // verifica se studente in input non sia già presente
{
    int *s_Nmatricola, *s_annoImm, *i_annoSomm, *ps_voto, *i_crediti; //controllo voti e anno e crediti
    char *s_nome = (char*)malloc(MAX_NAME_LEN*sizeof(char)), *s_cognome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    char *i_descrizione = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    //INSEGNAMENTO *ps_insegnamento = (INSEGNAMENTO*)malloc(MAX_CODE_LEN*sizeof(INSEGNAMENTO));

    printf("Inserire:\n- numero di matricola:\t\t");
    scanf(" %d", &s_Nmatricola);
    fflush(stdin);
    if(isIn1(sc, s_Nmatricola))
    {
        printf("Numero di matricola gia' presente!!\n\n");
    }else{
        printf("- nome:\t\t\t\t");
        scanf(" %[^\n]%*c", s_nome);
        fflush(stdin);
        printf("- cognome:\t\t\t");
        scanf(" %[^\n]%*c", s_cognome);
        fflush(stdin);
        printf("- anno di immatricolazione:\t");
        scanf(" %d", &s_annoImm);
        fflush(stdin);


        /*printf("Piano di studi:\n- codice insegnamento:\t\t\t");
        scanf(" %[^\n]%*c", ps_insegnamento);
        fflush(stdin);
        printf("- voto:\t\t\t\t");
        scanf(" %d", &ps_voto);
        fflush(stdin);
        addStudente1 (sc, s_Nmatricola, s_nome, s_cognome, s_annoImm, ps_insegnamento, ps_voto);*/
    }

    printAllValues(sc, ic); //print di debug
    printf("\n\n\n\n");
}

void printStudente1(STUDENTI_CORSO1 *sc, INSEGNAMENTO *ic)
{
    int *n_matr;
    printf("Quale studente vuoi visualizzare? Inserire numero di matricola: ");
    scanf("%d", n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr)==true)
    {
        for(int i=0; i < sc->len; i++)
        {
            printf("Numero di matricola:\t\t%d \n", sc->list[i].s_Nmatricola);
            printf("Nome:\t\t%s \n", sc->list[i].s_nome);
            printf("Cognome:\t\t%s \n", sc->list[i].s_cognome);
            printf("Anno di immatricolazione:\t%d \n", sc->list[i].s_annoImm);
            printf("Insegnamento:\t\t%s \n", sc->list[i].s_pianoStudi.ps_insegnamento);
            printf("Voto:\t\t\t%d \n\n", sc->list[i].s_pianoStudi.ps_voto);
        }
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void addVoto1(STUDENTI_CORSO1 *sc, INSEGNAMENTO *ic)
{
    int *n_matr;
    printf("A quale studente vuoi aggiungere un voto? Inserire numero di matricola:");
    scanf(" %[^\n]%*c", n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr)==true)
    {   //funzione per aggiungere il voto
        printf("Insegnamento: ");   //controlla se insegnamento esiste se non esiste chiedere se aggiungerlo?
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void mediaVoti1(STUDENTI_CORSO1 *sc)
{
    int *n_matr;
    printf("Di quale studente vuoi la media dei voti? Inserire numero di matricola: ");
    scanf(" %d", n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr)==true)
    {
        int sum=0;
        float media=0;  // serve vettore piano di studi per studente
        /*for(int i=0; i < ps->len; i++)
        {
            sum+=sc->list[i].s_pianoStudi.ps_voto;
        }
        media=sum/(ps->len);
        printf("\nMedia =\t%g\n\n", media)*/
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
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

INSEGNAMENTO *ins_c_init()              //sistemare i valori
{
    INSEGNAMENTO *ic=malloc(2*sizeof(INSEGNAMENTO));
    ic[0].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[0].i_descrizione="Fisica";
    ic[0].i_codice=0;
    ic[0].i_annoSomm=4;
    ic[0].i_crediti=6;
    ic[1].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[1].i_descrizione="Matematica";
    ic[1].i_codice=2;
    ic[1].i_annoSomm=2;
    ic[1].i_crediti=6;
    return ic;
}

STUDENTI_CORSO1 *s_corso_init1 ()
{
    STUDENTI_CORSO1 *sc;
    sc = (STUDENTI_CORSO1*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTI_CORSO1));
    // senza la riga seguente non mi fa inserire + studenti di 1 e crasha
    sc->list = (STUDENTE*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTE)); // allocazione dinamica del vettore di strutture studenti
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
void destroyer (INSEGNAMENTO *ic, STUDENTI_CORSO1 *sc)
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
    scanf("%d", &choice);
    system("cls");
    return choice;
}

int printMenu()
{
    int choice;
    printf("\t\t\t\tOPZIONI ARCHIVIO\n");
    printf("1) Aggiungere un nuovo studente\n");
    printf("2) Stampare le informazioni di uno studente fornendo il numero di matricola\n");
    printf("3) Aggiungere un voto di uno studente fornendo il numero di matricola\n");
    printf("4) Stampare la media dei voti di tutti gli studenti che hanno completato il piano di studi\n");
    printf("   (calcolo automaticamente effettuato in base al numero di crediti di ogni insegnamento)\n");
    printf("0) Esci dal programma\n\n");
    printf("Scegli una tra le seguenti operazioni: ");
    scanf("%d", &choice);
    return choice;
}
