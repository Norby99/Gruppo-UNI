/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201211
 NOTE:    Text Ex01: Realizzare un programma che gestisca la lista di tutti i libri letti in un anno.
          Per ognuno di essi, il programma deve memorizzare una serie di informazioni, ad esempio il titolo, l’autore,
          l’anno di pubblicazione, la casa editrice, la lunghezza, il genere, il codice identificativo, la valutazione.
          Il programma dovrà permettere di inserire un nuovo libro, cancellarne uno, visualizzarli tutti, visualizzare
          solo quelli con una certa valutazione. Il programma deve lavorare leggendo e scrivendo le informazioni da e su file binario.
          Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LEN 30

/****************************** STRUTTURE ******************************/

typedef struct book {
    char *titolo, *autore, *casa_ed, *genere;
    int c_libro, anno_pubblicazione, lung, voto;
    struct book *next;
}BOOK;
typedef BOOK *ptr_book;


/****************************** PROTOTIPI ******************************/

int printMenu();
void destroyer();

void insMenu(ptr_book *head, char *t, char *a, char *ce, char *g, int c, int ap, int np, int v);
void ins_book(ptr_book *);
void head_ins(ptr_book *, char *, char *, char *, char *, int, int, int, int);

void del_book(ptr_book *);
void printAll_books(ptr_book);
void printBook(ptr_book);

/****************************** MAIN ******************************/

int main()
{
    ptr_book head = NULL;    // init della lista

    bool temp=true;
    while(temp)
    {
        switch(printMenu())
        {
            case 1:
                ins_book(&head);
                break;
            case 2:
                del_book(&head);
                break;
            case 3:
                printAll_books(head);
                break;
            case 4:
                printBook(head);
                break;
            case 0:
                temp=false;
                break;
        }
    }

    destroyer(&head);   // cancellazione lista
    system ("pause");
    return 0;
}

/****************************** FUNZIONI DEL MENU' ******************************/

void printBook(ptr_book head)
{
    printf("\n\n--HERE MA GUYZ DEBUGGO\n\n");
}

void printAll_books(ptr_book head)
{
    int c=0;
    if (head==NULL)
    {
        printf("\nLa lista e\' vuota!\n");
        return;
    }
    else
    {
        while (head!=NULL)
        {
            c++;
            printf("\nPosizione %d\tTitolo: %s\t(codice %d):\n", c, head->titolo, head->c_libro);
            printf("\n- Autore:\t\t\t%-30s\n- Casa Editrice:\t\t%-30s\n- Genere:\t\t\t%-30s", head->autore, head->casa_ed, head->genere);
            printf("\n- Anno di pubblicazione:\t%d\n- Lunghezza:\t\t\t\%d pagine\n- Valutazione:\t\t\t%d\n\n", head->anno_pubblicazione, head->lung, head->voto);
            head = head->next;
        }
    }

    printf("\n\n Stampati %d valori\n ", c);
}

void del_book(ptr_book *head)
{
    printf("\n\n--HERE MA GUYZ DEBUGGO\n\n");
}

void tail_ins(ptr_book *head, char *t, char *a, char *ce, char *g, int c, int ap, int np, int v)
{
    ptr_book newBook = (ptr_book)malloc(sizeof(BOOK)), temp;
    if(newBook==NULL){
        printf("Error in malloc!\n\n");
        system("pause");
        exit(1);
    }
    // aggiunta effettiva dei valori al nuovo elemento della lista
    newBook->c_libro = c;
    newBook->anno_pubblicazione = ap;
    newBook->autore = a;
    newBook->casa_ed = ce;
    newBook->genere = g;
    newBook->lung = np;
    newBook->titolo = t;
    newBook->voto = v;

    newBook->next = NULL;

    if (*head == NULL){
        *head = newBook;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newBook;
    }
}

void head_ins(ptr_book *head, char *t, char *a, char *ce, char *g, int c, int ap, int np, int v)
{
    ptr_book newBook = (ptr_book)malloc(sizeof(BOOK));
    if(newBook==NULL){
        printf("Error in malloc!\n\n");
        system("pause");
        exit(1);
    }
    // aggiunta effettiva dei valori al nuovo elemento della lista
    newBook->c_libro = c;
    newBook->anno_pubblicazione = ap;
    newBook->autore = a;
    newBook->casa_ed = ce;
    newBook->genere = g;
    newBook->lung = np;
    newBook->titolo = t;
    newBook->voto = v;

    newBook->next = *head;      // il next del nuovo elemento assume il valore della testa
    *head = newBook;            // ora la testa punta al nuovo elemento
}

void ins_book(ptr_book *head)
{
    char *t=(char*)malloc(MAX_NAME_LEN*sizeof(char)), *a=(char*)malloc(MAX_NAME_LEN*sizeof(char));
    char *ce=(char*)malloc(MAX_NAME_LEN*sizeof(char)), *g=(char*)malloc(MAX_NAME_LEN*sizeof(char));
    int c, ap, np, v;

    printf("\n- Titolo: ");
    scanf(" %[^\n]%*c", t);
    fflush(stdin);

    printf("\n- Autore: ");
    scanf(" %[^\n]%*c", a);
    fflush(stdin);

    printf("\n- Casa Editrice: ");
    scanf(" %[^\n]%*c", ce);
    fflush(stdin);

    printf("\n- Genere: ");
    scanf(" %[^\n]%*c", g);
    fflush(stdin);

    printf("\n- Codice:");
    scanf("%d", &c);
    fflush(stdin);

    printf("\n- Anno di pubblicazione: ");
    scanf(" %d", &ap);
    fflush(stdin);

    printf("\n- Lunghezza (numero pagine): ");
    scanf(" %d", &np);
    fflush(stdin);

    printf("\n- Valutazione: ");
    scanf(" %d", &v);
    fflush(stdin);
    insMenu(head, t, a, ce, g, c, ap, np, v);
}

void insMenu(ptr_book *head, char *t, char *a, char *ce, char *g, int c, int ap, int np, int v)
{
    int choice;
    do
    {
        printf("\nAggiungere il libro in testa o in coda?\n1)Testa\n2)Coda\n");
        scanf(" %d", &choice);
        fflush(stdin);
        system("cls");
        switch(choice)
        {
            case 1:
                head_ins(head, t, a, ce, g, c, ap, np, v);
                choice=0;
                break;
            case 2:
                tail_ins(head, t, a, ce, g, c, ap, np, v);
                choice=0;
                break;
            default:
                printf("Inserimento errato!!");
                break;
        }
    }while(choice==1||choice==2);
}


/****************************** GESTIONE STRUTTURE ******************************/

void destroyer(ptr_book *head)
{
    if (*head == NULL)
        printf("\nLa libreria e\' gia\' vuota!\n\n\n");
    else
    {
        ptr_book temp;
        while(head!=NULL){
            temp = *head;           // salva in temp il libro in testa
            *head=(*head)->next;    // fa puntare la testa al prossimo
            free(temp);             // cancella vecchio libro
        }
        printf("\nLa libreria e\' ora vuota!\n\n\n");
    }
}

/****************************** MENU ******************************/

int printMenu()
{
    int choice;

    printf("\n**** MENU\' DI GESTIONE LIBRERIA VIRTUALE ****\n\n");
    printf("1) Inserire un nuovo libro\n");
    printf("2) Cancellare un libro\n");
    printf("3) Visualizzare tutti i tuoi libri\n");
    printf("4) Visualizzare libri con una certa valutazione\n");
    printf("0) Esci dal programma\n");

    printf("\n\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice<0 && choice>4)
    {
        if(choice<0 || choice>4)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    system("cls");
    return choice;
}
