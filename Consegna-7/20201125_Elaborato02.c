/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201121
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

#define MAX_INSEGNAMENTI_CORSO 30
#define MAX_STUDENTI_CORSO 244
#define N_ESAMI 3
#define MAX_CODE_LEN 10
#define MAX_NAME_LEN 30
#define MAX_VOTO 30

/************************** STRUTTURE dei TIPI ***************************/

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

/********************* STRUTTURE degli ARRAY di STRUTTURE ****************/

typedef struct {
    PIANO_STUDI *list;
    int len;
}S_PIANO_STUDI;                 // array che archivia tutti gli insegnamenti di un PIANO DI STUDI di 1 STUDENTE

/**** 1) malloc ****/
typedef struct
{
    STUDENTE *list;
    int len;
}STUDENTI_CORSO1;               // array che archivia tutti gli studenti inseriti

/**** 2) no malloc ****/
typedef struct
{
    STUDENTE list[MAX_STUDENTI_CORSO];
    int len;
}STUDENTI_CORSO2;

/*********************** PROTOTIPI delle FUNZIONI ************************/

int codeChoiceMenu();
int printMenu();

// prototipi funzioni per l'inizializzazione gruppi di strutture...
INSEGNAMENTO *ins_c_init();
S_PIANO_STUDI *s_ps_init ();
STUDENTI_CORSO1 *s_corso_init1();    // 1) malloc
STUDENTI_CORSO2 *s_corso_init2();    // 2) no malloc

// ... e la loro cancellazione dalla memoria
void destroyer(INSEGNAMENTO *, S_PIANO_STUDI *, STUDENTI_CORSO1 *, STUDENTI_CORSO2 *);

// funzioni del menu

/**** 1) malloc ****/
bool isIn1(STUDENTI_CORSO1 *, int *);
void addStudente1(STUDENTI_CORSO1 *, int *, char *, char *, int *, S_PIANO_STUDI *, int *, int *);
void tryAddStudente1(STUDENTI_CORSO1 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void printStudente1(STUDENTI_CORSO1 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void addVoto1(STUDENTI_CORSO1 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void mediaVoti1(STUDENTI_CORSO1 *, S_PIANO_STUDI *,  INSEGNAMENTO *);

/**** 2) no malloc ****/
bool isIn2(STUDENTI_CORSO2 *, int *);
void addStudente2(STUDENTI_CORSO2 *, int *, char *, char *, int *, S_PIANO_STUDI *, int *, int *);
void tryAddStudente2(STUDENTI_CORSO2 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void printStudente2(STUDENTI_CORSO2 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void addVoto2(STUDENTI_CORSO2 *, S_PIANO_STUDI *, INSEGNAMENTO *);
void mediaVoti2(STUDENTI_CORSO2 *, S_PIANO_STUDI *,  INSEGNAMENTO *);

/********************************* MAIN **********************************/

int main ()
{   // creazione istanze
    INSEGNAMENTO *ins_corso = ins_c_init();
    S_PIANO_STUDI *s_piano_studi = s_ps_init ();
    STUDENTI_CORSO1 *s_corso_1 = s_corso_init1();        // 1) malloc
    STUDENTI_CORSO2 *s_corso_2 = s_corso_init2();        // 2) no malloc
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
                            tryAddStudente1(s_corso_1, s_piano_studi, ins_corso);
                            break;
                        case 2:
                            printStudente1(s_corso_1, s_piano_studi, ins_corso);
                            break;
                        case 3:
                            addVoto1(s_corso_1, s_piano_studi, ins_corso);
                            break;
                        case 4:
                            mediaVoti1(s_corso_1, s_piano_studi, ins_corso);
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
                            tryAddStudente2(s_corso_2, s_piano_studi, ins_corso);
                            break;
                        case 2:
                            printStudente2(s_corso_2, s_piano_studi, ins_corso);
                            break;
                        case 3:
                            addVoto2(s_corso_2, s_piano_studi, ins_corso);
                            break;
                        case 4:
                            mediaVoti2(s_corso_2, s_piano_studi, ins_corso);
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

    destroyer(ins_corso, s_piano_studi, s_corso_1, s_corso_2);  // restituisce al s.o. la gestione della memoria

    system("pause");
    return 0;
}

/******************************* FUNZIONI MENU ***************************/

/**** 1) malloc ****/

// aggiunge effettivamente i dati nella struttura studente dentro l'array con tutti gli studenti del corso
void addStudente1 (STUDENTI_CORSO1 *sc, int *m, char *n, char *c, int *a, S_PIANO_STUDI *s_ps, int *i, int *v)
{
    sc->list[sc->len].s_Nmatricola = m;
    sc->list[sc->len].s_nome = n;
    sc->list[sc->len].s_cognome = c;
    sc->list[sc->len].s_annoImm = a;
    sc->list[sc->len].s_pianoStudi = (PIANO_STUDI*)malloc(100*sizeof(PIANO_STUDI));
    sc->list[sc->len].s_pianoStudi[0].ps_insegnamento = (INSEGNAMENTO*)malloc(100*sizeof(INSEGNAMENTO));
    sc->list[sc->len].s_pianoStudi[0].ps_insegnamento->i_codice = i;
    sc->list[sc->len].s_pianoStudi[0].ps_voto = v;

    s_ps->len++;    // incrementa array di piano studenti per ogni studente che viene aggiunto
    sc->len++;      // incrementa array di studenti per ogni studente che viene aggiunto
}

bool isIn1(STUDENTI_CORSO1 *sc, int *m) // controlla se matricola studente già registrata
{
    for(int i=0; i < sc->len; i++)
    {
        printf("\n\n --%d\t%d\n\n", m, sc->list[i].s_Nmatricola);
        if(sc->list[i].s_Nmatricola == m)
            return true;
    }
    return false;
}

void tryAddStudente1 (STUDENTI_CORSO1 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic) // verifica se studente in input non sia già presente
{
    int *s_Nmatricola=(int*)malloc(sizeof(int)), *s_annoImm, *i_annoSomm, *i_crediti;
    char *s_nome = (char*)malloc(MAX_NAME_LEN*sizeof(char)), *s_cognome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    char *i_descrizione = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    int *ps_insegnamento = (int*)malloc(N_ESAMI*sizeof(int));
    int *ps_voto = (int*)malloc(N_ESAMI*sizeof(int));
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
        do
            {
                printf("- anno di immatricolazione:\t");
                scanf(" %d", &s_annoImm);
                fflush(stdin);
                if (s_annoImm < 1 || s_annoImm > 3)
                printf("\n!!L'anno di immatricolazione dev'essere compreso tra 0 e 3!! Reinserire correttamente:\n");
            }while(s_annoImm < 1 || s_annoImm > 3);
        
        printf("****\nQuali insegnamenti vuoi inserire? (MAX ESAMI %d)\n", N_ESAMI);
        for(int i=0; i<6; i++)
        {
            printf("\tDescrizione:\t\t\t%s\n", ic[i].i_descrizione);
            printf("\tCodice:\t\t\t\t%d \n", ic[i].i_codice);
            printf("\tAnno di somministrazione:\t%d\n", ic[i].i_annoSomm);
            printf("\tCFU:\t\t\t%d\n", ic[i].i_crediti);
        }
        printf("****\nPiano di studi:\n");
        for (int i=0; i<N_ESAMI; i++)
        {
            do
                {
                  printf("\n- codice insegnamento:\t\t\t");
                  scanf(" %d", &ps_insegnamento[i]);
                  fflush(stdin);
                  if (ps_insegnamento[i] < 1 || ps_insegnamento[i] > 6)
                    printf("\n!!Il codice insegnamento non e\' corretto!! Reinserire correttamente:\n");
                }while(ps_insegnamento[i] < 1 || ps_insegnamento[i] > 6);
                       ps_voto[i]=0;
                       continue;
        }
        addStudente1 (sc, s_Nmatricola, s_nome, s_cognome, s_annoImm, s_ps, ps_insegnamento, ps_voto);
    }
}

void printStudente1(STUDENTI_CORSO1 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int*)malloc(sizeof(int));
    printf("Quale studente vuoi visualizzare? Inserire numero di matricola: ");
    scanf("%d", &n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr))
    {
        for(int i=0; i < sc->len; i++)
        {
            if(n_matr==sc->list[i].s_Nmatricola)
            {
                printf("Numero di matricola:\t\t%d\n", sc->list[i].s_Nmatricola);
                printf("Nome:\t\t\t\t%s\n", sc->list[i].s_nome);
                printf("Cognome:\t\t\t%s\n", sc->list[i].s_cognome);
                printf("Anno di immatricolazione:\t%d\n", sc->list[i].s_annoImm);
                for(int k=0; k<N_ESAMI; k++)
                {
                    printf("Codice di insegnamento:\t\t%d\n", sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k]);
                    printf("Voto:\t\t\t\t%d\n", sc->list[i].s_pianoStudi[0].ps_voto[k]);
                }
                break;
            }
        }
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void addVoto1(STUDENTI_CORSO1 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int*)malloc(sizeof(int)), c_ins;
    bool fl=false;
    printf("A quale studente vuoi aggiungere un voto? Inserire numero di matricola:");
    scanf(" %d", &n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr))
    {
        printf("Codice insegnamento: ");
        scanf(" %d", &c_ins);
        fflush(stdin);
        for(int i=0; i < sc->len; i++)
        {
            if(n_matr == sc->list[i].s_Nmatricola)
            {
                for(int k=0; k<N_ESAMI; k++)
                {
                    if(c_ins == sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k])
                    {
                        do
                        {
                            printf("- voto:\t\t\t\t");
                            scanf(" %d", &sc->list[i].s_pianoStudi[0].ps_voto[k]);
                            fflush(stdin);
                            if (sc->list[i].s_pianoStudi[0].ps_voto[k] < 0 || sc->list[i].s_pianoStudi[0].ps_voto[k] > 30)
                                printf("\n!!Il voto dev'essere compreso tra 0 e 30!! Reinserire correttamente:\n");
                        }while(sc->list[i].s_pianoStudi[0].ps_voto[k] < 0 || sc->list[i].s_pianoStudi[0].ps_voto[k] > 30);
                        fl=true;
                        continue;
                    }
                }
            }
        }
        if(fl!=true)
        {
            printf("Non e\' stato registrato alcun insegnamento con questo codice.\n\n");
        }
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void mediaVoti1(STUDENTI_CORSO1 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int *)malloc(sizeof(int)), sum=0, sum1=0, voti=0, crediti=0;
    float media=0;
    printf("Di quale studente vuoi la media dei voti? Inserire numero di matricola: ");
    scanf(" %d", &n_matr);
    fflush(stdin);
    if(isIn1(sc, n_matr))
    {
        for(int i=0; i < sc->len; i++)
        {
                if(n_matr == sc->list[i].s_Nmatricola)
                {
                    for(int k=0; k<N_ESAMI; k++)
                    {
                        voti = sc->list[i].s_pianoStudi[0].ps_voto[k];
                        crediti = sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k];
                        sum= sum + (voti * crediti);
                        sum1= sum1 + crediti;
                    }
                }
        }
        media=(float)sum/sum1;
        printf("\nMedia =\t%.2f\n\n", media);
    }
    else
    {
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

/**** 2) no malloc ****/

// aggiunge effettivamente i dati nella struttura studente dentro l'array con tutti gli studenti del corso
void addStudente2 (STUDENTI_CORSO2 *sc, int *m, char *n, char *c, int *a, S_PIANO_STUDI *s_ps, int *i, int *v)
{
    sc->list[sc->len].s_Nmatricola = m;
    sc->list[sc->len].s_nome = n;
    sc->list[sc->len].s_cognome = c;
    sc->list[sc->len].s_annoImm = a;
    sc->list[sc->len].s_pianoStudi = (PIANO_STUDI*)malloc(100*sizeof(PIANO_STUDI));
    sc->list[sc->len].s_pianoStudi[0].ps_insegnamento = (INSEGNAMENTO*)malloc(100*sizeof(INSEGNAMENTO));
    sc->list[sc->len].s_pianoStudi[0].ps_insegnamento->i_codice = i;
    sc->list[sc->len].s_pianoStudi[0].ps_voto = v;

    s_ps->len++;    // incrementa array di piano studenti per ogni studente che viene aggiunto
    sc->len++;      // incrementa array di studenti per ogni studente che viene aggiunto
}

bool isIn2(STUDENTI_CORSO2 *sc, int *m) // controlla se matricola studente già registrata
{
    for(int i=0; i < sc->len; i++)
    {
        if(sc->list[i].s_Nmatricola == m)
            return true;
    }
    return false;
}

void tryAddStudente2 (STUDENTI_CORSO2 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic) // verifica se studente in input non sia già presente
{
    int *s_Nmatricola=(int*)malloc(sizeof(int)), *s_annoImm, *i_annoSomm, *i_crediti;
    char *s_nome = (char*)malloc(MAX_NAME_LEN*sizeof(char)), *s_cognome = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    char *i_descrizione = (char*)malloc(MAX_NAME_LEN*sizeof(char));
    int *ps_insegnamento = (int*)malloc(N_ESAMI*sizeof(int));
    int *ps_voto = (int*)malloc(N_ESAMI*sizeof(int));
    printf("Inserire:\n- numero di matricola:\t\t");
    scanf(" %d", &s_Nmatricola);
    fflush(stdin);
    if(isIn2(sc, s_Nmatricola))
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
        printf("****\nQuali insegnamenti vuoi inserire? (MAX ESAMI %d)\n", N_ESAMI);
        for(int i=0; i<6; i++)
        {
            printf("\tDescrizione:\t\t\t%s\n", ic[i].i_descrizione);
            printf("\tCodice:\t\t\t\t%d \n", ic[i].i_codice);
            printf("\tAnno di somministrazione:\t%d\n", ic[i].i_annoSomm);
            printf("\tCFU:\t\t\t%d\n", ic[i].i_crediti);
        }
        printf("****\nPiano di studi:\n");
        for (int i=0; i<N_ESAMI; i++)
        {
            printf("- codice insegnamento:\t");
            scanf(" %d", &ps_insegnamento[i]);
            fflush(stdin);
            ps_voto[i]=0;
        }
        addStudente2 (sc, s_Nmatricola, s_nome, s_cognome, s_annoImm, s_ps, ps_insegnamento, ps_voto);
    }
}

void printStudente2(STUDENTI_CORSO2 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int*)malloc(sizeof(int));
    printf("Quale studente vuoi visualizzare? Inserire numero di matricola: ");
    scanf("%d", &n_matr);
    fflush(stdin);
    if(isIn2(sc, n_matr))
    {
        for(int i=0; i < sc->len; i++)
        {
            if(n_matr==sc->list[i].s_Nmatricola)
            {
                printf("Numero di matricola:\t\t%d\n", sc->list[i].s_Nmatricola);
                printf("Nome:\t\t\t\t%s\n", sc->list[i].s_nome);
                printf("Cognome:\t\t\t%s\n", sc->list[i].s_cognome);
                printf("Anno di immatricolazione:\t%d\n", sc->list[i].s_annoImm);
                for(int k=0; k<N_ESAMI; k++)
                {
                    printf("Codice di insegnamento:\t\t%d\n", sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k]);
                    printf("Voto:\t\t\t\t%d\n", sc->list[i].s_pianoStudi[0].ps_voto[k]);
                }
                break;
            }
        }
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void addVoto2(STUDENTI_CORSO2 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int*)malloc(sizeof(int)), c_ins;
    bool fl=false;
    printf("A quale studente vuoi aggiungere un voto? Inserire numero di matricola:");
    scanf(" %d", &n_matr);
    fflush(stdin);
    if(isIn2(sc, n_matr))
    {
        printf("Codice insegnamento: ");
        scanf(" %d", &c_ins);
        fflush(stdin);
        for(int i=0; i < sc->len; i++)
        {
            if(n_matr == sc->list[i].s_Nmatricola)
            {
                for(int k=0; k<N_ESAMI; k++)
                {
                    if(c_ins == sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k])
                    {
                        do
                        {
                            printf("- voto:\t\t\t\t");
                            scanf(" %d", &sc->list[i].s_pianoStudi[0].ps_voto[k]);
                            fflush(stdin);
                            if (sc->list[i].s_pianoStudi[0].ps_voto[k] < 0 || sc->list[i].s_pianoStudi[0].ps_voto[k] > 30)
                                printf("\n!!Il voto dev'essere compreso tra 0 e 30!! Reinserire correttamente:\n");
                        }while(sc->list[i].s_pianoStudi[0].ps_voto[k] < 0 || sc->list[i].s_pianoStudi[0].ps_voto[k] > 30);
                        fl=true;
                        continue;
                    }
                }
            }
        }
        if(fl!=true)
        {
            printf("Non e\' stato registrato alcun insegnamento con questo codice.\n\n");
        }
    }else{
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

void mediaVoti2(STUDENTI_CORSO2 *sc, S_PIANO_STUDI *s_ps, INSEGNAMENTO *ic)
{
    int *n_matr=(int *)malloc(sizeof(int)), sum=0, sum1=0, voti=0, crediti=0;
    float media=0;
    printf("Di quale studente vuoi la media dei voti? Inserire numero di matricola: ");
    scanf(" %d", &n_matr);
    fflush(stdin);
    if(isIn2(sc, n_matr))
    {
        for(int i=0; i < sc->len; i++)
        {
                if(n_matr == sc->list[i].s_Nmatricola)
                {
                    for(int k=0; k<N_ESAMI; k++)
                    {
                        voti = sc->list[i].s_pianoStudi[0].ps_voto[k];
                        crediti = sc->list[i].s_pianoStudi[0].ps_insegnamento->i_codice[k];
                        sum= sum + (voti * crediti);
                        sum1= sum1 + crediti;
                    }
                }
        }
        media=(float)sum/sum1;
        printf("\nMedia =\t%.2f\n\n", media);
    }
    else
    {
        printf("Non e\' stato registrato alcuno studente con questo numero di matricola.\n\n");
    }
}

/***************************** GESTIONE ISTANZE **************************/

// inizializzazione

INSEGNAMENTO *ins_c_init()
{
    INSEGNAMENTO *ic=(INSEGNAMENTO*)malloc(6*sizeof(INSEGNAMENTO));
    ic[0].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[0].i_descrizione="Fisica";
    ic[0].i_codice=01;
    ic[0].i_annoSomm=2;
    ic[0].i_crediti=6;
    ic[1].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[1].i_descrizione="Matematica";
    ic[1].i_codice=02;
    ic[1].i_annoSomm=1;
    ic[1].i_crediti=12;
    ic[2].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[2].i_descrizione="Programmazione";
    ic[2].i_codice=03;
    ic[2].i_annoSomm=1;
    ic[2].i_crediti=12;
    ic[3].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[3].i_descrizione="Inglese";
    ic[3].i_codice=04;
    ic[3].i_annoSomm=1;
    ic[3].i_crediti=6;
    ic[4].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[4].i_descrizione="Algebra";
    ic[4].i_codice=05;
    ic[4].i_annoSomm=3;
    ic[4].i_crediti=12;
    ic[5].i_descrizione=malloc(MAX_NAME_LEN*sizeof(char));
    ic[5].i_descrizione="Geometria";
    ic[5].i_codice=06;
    ic[5].i_annoSomm=2;
    ic[5].i_crediti=12;
    return ic;
}

STUDENTI_CORSO1 *s_corso_init1 ()         // 1) malloc
{
    STUDENTI_CORSO1 *sc;
    sc = (STUDENTI_CORSO1*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTI_CORSO1));
    sc->list = (STUDENTE*)malloc(MAX_STUDENTI_CORSO*sizeof(STUDENTE)); // allocazione dinamica del vettore di strutture studenti
    sc->len=0;
    return sc;
}

S_PIANO_STUDI *s_ps_init ()
{
    S_PIANO_STUDI *s_ps;
    s_ps = (S_PIANO_STUDI*)malloc(N_ESAMI*sizeof(S_PIANO_STUDI));
    s_ps->len=0;
    return s_ps;
}

STUDENTI_CORSO2 *s_corso_init2 ()         // 2) no malloc
{
    STUDENTI_CORSO2 *sc;
    sc->len=0;
    return sc;
}

// liberazione della memoria
void destroyer (INSEGNAMENTO *ic, S_PIANO_STUDI *s_ps, STUDENTI_CORSO1 *sc_1, STUDENTI_CORSO2 *sc_2)
{
    free(ic);
    free(s_ps);
    free(sc_1);
    free(sc_2);
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
