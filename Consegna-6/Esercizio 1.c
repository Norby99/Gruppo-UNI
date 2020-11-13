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
#include <string.h>
#include <stdbool.h>

#define MAX_VOCI 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

// struttura che tiene traccia dei singoli record
typedef struct
{
    char *name;
    char *phoneNumber;

}voceRubrica;

// struttura che memorizza l'array di rubriche con e la lunghezza dell'array
typedef struct
{
    voceRubrica list[MAX_VOCI];
    int len;
}Rubrica;

Rubrica *newRubrica();
void addVoice(Rubrica *, char *, char *);
bool isIn(Rubrica *, char *);
void ExactSearch(Rubrica *, char *);
void AproxSearch(Rubrica *, char *);
void printAllValues(Rubrica *);
void destroyer(Rubrica *);

int codeChoiceMenu();
int printMenu();
void tryAddVoice(Rubrica *);
void tryExactSearch(Rubrica *);
void tryAproxSearch(Rubrica *);


int main()
{
    Rubrica *rubrica = newRubrica();
    bool temp = true;
    //menu di scelta tra le due variazioni richieste del programma
    switch(codeChoiceMenu())
    {
        case 1: // vettore frastagliato
            while(temp)
            {
                switch(printMenu())
                {
                    case 1:
                        tryAddVoice(rubrica);
                        break;
                    case 2:
                        tryExactSearch(rubrica);
                        break;
                    case 3:
                        tryAproxSearch(rubrica);
                        break;
                    case 4:
                        printAllValues(rubrica);
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

        case 0:
            break;
        default:
            printf("!!Valore inserito non valido!! Riprova.\n");
            break;
    }

    destroyer(rubrica);
    return 0;
}

// istanzio la nuova rubrica
Rubrica *newRubrica()
{
    Rubrica *r;
    r = (Rubrica*)malloc(MAX_VOCI*sizeof(Rubrica));
    r->len = 0;
    return r;
}

// distruzione dell'istanza rubrica
void destroyer(Rubrica *r){
    free(r);
}

// aggiunta di un record alla rubrica
void addVoice(Rubrica *r, char *name, char *phoneNumber)
{
    r->list[r->len].name = name;
    r->list[r->len].phoneNumber = phoneNumber;
    r->len++;   // gestione dell'incrementazione della lunghezza dell'array
}

// visualizza tutta la rubrica
void printAllValues(Rubrica *r)
{
    for(int i=0;i < r->len; i++){
        printf("--%s : %s\n", r->list[i].name, r->list[i].phoneNumber);
    }
    printf("\n");
}

// verifica se un certo elemento è presente tra i record della rubrica
bool isIn(Rubrica *r, char *n)
{
    for(int i=0;i < r->len; i++)
    {
        if(r->list[i].name == n)
            return true;
    }
    return false;
}

// prende in input un valore, dopo di che se l'elemento non è già presente tra i record dell'array, allora lo aggiunge
void tryAddVoice(Rubrica *r)
{
    char *name, *phoneNumber;
    name = (char*)malloc(MAX_NAME_LENGTH*sizeof(char));
    phoneNumber = (char*)malloc(MAX_PHONE_NUMBER_LENGTH*sizeof(char));

    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", name);
    if(isIn(r, name))
    {
        printf("Nome gia' presente!\n\n");
    }else{
        printf("Inserisci il numero di telefono: ");
        scanf(" %[^\n]%*c", phoneNumber);
        addVoice(r, name, phoneNumber);
    }
}

// prende in input un valore e se trova somiglianza con qualche record della rubrica, lo stampa
void tryAproxSearch(Rubrica *r)
{
    char *name;
    name = (char*)malloc(MAX_NAME_LENGTH*sizeof(char));
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", name);
    AproxSearch(r, name);
}

// prende in input un valore e se è presente lo stampa
void tryExactSearch(Rubrica *r)
{
    char *name;
    name = (char*)malloc(MAX_NAME_LENGTH*sizeof(char));
    printf("Inserisci il nome: ");
    scanf(" %[^\n]%*c", name);
    ExactSearch(r, name);
}

// se presente, stampa il valore della ricerca
void ExactSearch(Rubrica *r, char *n)
{
    for(int i=0;i < r->len; i++){
        if(*r->list[i].name == *n){
            printf("--%s : %s\n", r->list[i].name, r->list[i].phoneNumber);
            return;
        }
    }
    printf("Il nome selezionato non e' presente nella rubrica!\n\n");
}

// se nella rubrica trova un match con il valore inserito, allora stampa i valori dei record
void AproxSearch(Rubrica *r, char *n)
{
    for(int i=0;i < r->len; i++){
        if(strstr(r->list[i].name, n)){
            printf("--%s : %s\n", r->list[i].name, r->list[i].phoneNumber);
        }
    }
    printf("Il nome selezionato non assomiglia a nessun record della rubrica!\n\n");
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
