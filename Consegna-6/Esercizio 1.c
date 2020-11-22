/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201113
 NOTE:    Text Ex01: Si realizzi un programma in linguaggio C in grado di gestire una rubrica di nomi e numeri telefonici.
          La rubrica può contenere fino a 100 voci diverse. Ciascuna voce è composta da un nome e da un numero di telefono.
          Il programma deve fornire all’utente un menù di scelta, con le seguenti voci:
          1) Aggiungi nuova voce in rubrica
          2) Ricerca esatta per nome
          3) Ricerca approssimata per nome
          4) Stampa completa rubrica
          0) Esci dal programma
          Una volta che l’utente ha scelto l’operazione desiderata (1-4),
          il programma acquisirà i dati necessari dall’utente ed eseguirà il comando.
          Nota: nella rubrica non possono esistere due voci con lo stesso nome.
          Realizzare una variante del programma implementando un vettore frastagliato.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOCI 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

// struttura che memorizza l'array di rubriche con e la lunghezza dell'array
typedef struct
{
    char *name[MAX_VOCI];
    char *phoneNumber[MAX_VOCI];
    int len;
}Rubrica1;

// 2 versione
typedef struct
{
    char name[MAX_VOCI][MAX_NAME_LENGTH];
    char phoneNumber[MAX_VOCI][MAX_PHONE_NUMBER_LENGTH];
    int len;
}Rubrica2;

Rubrica1 *newRubrica1();
Rubrica2 *newRubrica2();
void addVoice1(Rubrica1 *, char[], char[]);
void addVoice2(Rubrica2 *, char [], char []);
bool isIn1(Rubrica1 *, char[]);
bool isIn2(Rubrica2 *, char []);
void ExactSearch1(Rubrica1 *, char []);
void ExactSearch2(Rubrica2 *, char []);
void AproxSearch1(Rubrica1 *, char []);
void AproxSearch2(Rubrica2 *, char []);
void printAllValues1(Rubrica1 *);
void printAllValues2(Rubrica2 *);
void destroyer1(Rubrica1 *);
void destroyer2(Rubrica2 *);

int codeChoiceMenu();
int printMenu();
void tryAddVoice1(Rubrica1 *);
void tryAddVoice2(Rubrica2 *);
void tryExactSearch1(Rubrica1 *);
void tryExactSearch2(Rubrica2 *);
void tryAproxSearch1(Rubrica1 *);
void tryAproxSearch2(Rubrica2 *);


int main()
{
    Rubrica1 *rubrica1 = newRubrica1();
    Rubrica2 *rubrica2 = newRubrica2();
    bool temp = true, tmp = true;
    //menu di scelta tra le due variazioni richieste del programma
    while(tmp)
    {
        switch(codeChoiceMenu())
        {
            case 1: // vettore frastagliato
                while(temp)
                {
                    switch(printMenu())
                    {
                        case 1:
                            tryAddVoice1(rubrica1);
                            break;
                        case 2:
                            tryExactSearch1(rubrica1);
                            break;
                        case 3:
                            tryAproxSearch1(rubrica1);
                            break;
                        case 4:
                            printAllValues1(rubrica1);
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
                            tryAddVoice2(rubrica2);
                            break;
                        case 2:
                            tryExactSearch2(rubrica2);
                            break;
                        case 3:
                            tryAproxSearch2(rubrica2);
                            break;
                        case 4:
                            printAllValues2(rubrica2);
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

    destroyer1(rubrica1);
    destroyer2(rubrica2);
    return 0;
}

// istanzio la nuova rubrica
Rubrica1 *newRubrica1()
{
    Rubrica1 *r;
    r = (Rubrica1*)malloc(MAX_VOCI*sizeof(Rubrica1));
    r->len = 0;
    return r;
}

// 2 versione
Rubrica2 *newRubrica2()
{
    Rubrica2 *r;
    r = (Rubrica2*)malloc(MAX_VOCI*sizeof(Rubrica2));
    r->len = 0;
    return r;
}

// distruzione dell'istanza rubrica
void destroyer1(Rubrica1 *r){
    free(r);
}

// 2 versione
void destroyer2(Rubrica2 *r){
    free(r);
}

// aggiunta di un record alla rubrica
void addVoice1(Rubrica1 *r, char name[], char phoneNumber[])
{
    r->name[r->len] = malloc(sizeof(char)*MAX_NAME_LENGTH);
    r->phoneNumber[r->len] = malloc(sizeof(char)*MAX_PHONE_NUMBER_LENGTH);
    strcpy(r->name[r->len], name);
    strcpy(r->phoneNumber[r->len], phoneNumber);
    r->len++;   // gestione dell'incrementazione della lunghezza dell'array
}

// 2 versione
void addVoice2(Rubrica2 *r, char name[], char phoneNumber[])
{
    strncpy(r->name[r->len], name, MAX_NAME_LENGTH);
    strncpy(r->phoneNumber[r->len], phoneNumber, MAX_PHONE_NUMBER_LENGTH);
    r->len++;   // gestione dell'incrementazione della lunghezza dell'array
}

// visualizza tutta la rubrica
void printAllValues1(Rubrica1 *r)
{
    for(int i=0;i < r->len; i++){
        printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
    }
    printf("\n");
}

// 2 versione
void printAllValues2(Rubrica2 *r)
{
    for(int i=0;i < r->len; i++){
        printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
    }
    printf("\n");
}

// verifica se un certo elemento è presente tra i record della rubrica
bool isIn1(Rubrica1 *r, char n[])
{
    for(int i=0; i < r->len; i++)
    {
        if(strcmp(r->name[i], *&n) == 0)
            return true;
    }
    return false;
}

// 2 versione
bool isIn2(Rubrica2 *r, char n[])
{
    for(int i=0; i < r->len; i++)
    {
        if(strcmp(r->name[i], n) ==0)
            return true;
    }
    return false;
}

// prende in input un valore, dopo di che se l'elemento non è già presente tra i record dell'array, allora lo aggiunge
void tryAddVoice1(Rubrica1 *r)
{
    char name[MAX_NAME_LENGTH], phoneNumber[MAX_PHONE_NUMBER_LENGTH];

    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", &name);
    if(isIn1(r, name))
    {
        printf("Nome gia' presente!\n\n");
    }else{
        printf("Inserisci il numero di telefono: ");
        scanf(" %[^\n]%*c", &phoneNumber);
        addVoice1(r, name, phoneNumber);
    }
}

// versione 2
void tryAddVoice2(Rubrica2 *r)
{
    char name[MAX_NAME_LENGTH], phoneNumber[MAX_PHONE_NUMBER_LENGTH];

    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", &name);
    if(isIn2(r, name))
    {
        printf("Nome gia' presente!\n\n");
    }else{
        printf("Inserisci il numero di telefono: ");
        scanf(" %[^\n]%*c", &phoneNumber);
        addVoice2(r, name, phoneNumber);
    }
}

// prende in input un valore e se trova somiglianza con qualche record della rubrica, lo stampa
void tryAproxSearch1(Rubrica1 *r)
{
    char name[MAX_NAME_LENGTH];
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", &name);
    AproxSearch1(r, name);
}

//2 versione
void tryAproxSearch2(Rubrica2 *r)
{
    char name[MAX_NAME_LENGTH];
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", name);
    AproxSearch2(r, name);
}

// prende in input un valore e se è presente lo stampa
void tryExactSearch1(Rubrica1 *r)
{
    char name[MAX_NAME_LENGTH];
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", &name);
    ExactSearch1(r, &name);
}

// 2 versione
void tryExactSearch2(Rubrica2 *r)
{
    char name[MAX_NAME_LENGTH];
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", name);
    ExactSearch2(r, name);
}

// se presente, stampa il valore della ricerca
void ExactSearch1(Rubrica1 *r, char n[])
{
    for(int i=0;i < r->len; i++){
        if(strcmp(r->name[i], *&n) == 0){
            printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
            return;
        }
    }
    printf("Il nome selezionato non e' presente nella rubrica!\n\n");
}

// 2 versione
void ExactSearch2(Rubrica2 *r, char n[])
{
    for(int i=0; i < r->len; i++){
        if(strcmp(r->name[i], n) ==0){
            printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
            return;
        }
    }
    printf("Il nome selezionato non e' presente nella rubrica!\n\n");
}

// se nella rubrica trova un match con il valore inserito, allora stampa i valori dei record
void AproxSearch1(Rubrica1 *r, char n[])
{
    bool fl=false;
    for(int i=0;i < r->len; i++){
        if(strstr(r->name[i], n)){
            printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
            fl=true;
        }
    }
    if (!fl)
    {
        printf("Il nome selezionato non assomiglia a nessun record della rubrica!\n\n");
    }
}

// 2 versione
void AproxSearch2(Rubrica2 *r, char n[])
{
    bool fl=false;
    for(int i=0;i < r->len; i++){
        if(strstr(r->name[i], n)){
            printf("--%s : %s\n", r->name[i], r->phoneNumber[i]);
            fl=true;
        }
    }
    if (!fl)
    {
        printf("Il nome selezionato non assomiglia a nessun record della rubrica!\n\n");
    }
}

// stampa menu di scelta tra le 2 variazioni richieste del programma
int codeChoiceMenu()
{
    int choice;

    printf("Quale variazione del codice vuoi eseguire?\n");
    printf("1) Vettore frastagliato\n");
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
    printf("1) Aggiungi nuova voce in rubrica\n");
    printf("2) Ricerca esatta per nome\n");
    printf("3) Ricerca approssimata per nome\n");
    printf("4) Stampa completa rubrica\n");
    printf("0) Esci dal programma\n\n");

    printf("Scegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);

    return choice;
}
