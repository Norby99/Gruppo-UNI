/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201211
 NOTE:    Text Ex01: Realizzare un programma che gestisca la lista di tutti i libri letti in un anno.
          Per ognuno di essi, il programma deve memorizzare una serie di informazioni, ad esempio il titolo, l�autore,
          l�anno di pubblicazione, la casa editrice, la lunghezza, il genere, il codice identificativo, la valutazione.
          Il programma dovr� permettere di inserire un nuovo libro, cancellarne uno, visualizzarli tutti, visualizzare
          solo quelli con una certa valutazione. Il programma deve lavorare leggendo e scrivendo le informazioni da e su file binario.
          Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 50

//****************************** STRUTTURE ******************************/

typedef struct{
    char *title;
    char *author;
    int yearOfPublication;
    char *publishingHouse;
    int length;
    char *genre;
    int code;
    int rating;
}Book;

typedef struct{
    Book *collection;
    int len;
}Library;

Library newLibrary();
Book newBook();
void append2library(Library *, Book);
void showAllBooks(Library);
void showBooksByRating(Library);
void destroyer(Library*);
//****************************** PROTOTIPI ******************************/

int printMenu();
void getBookValues(Library*);

//****************************** MAIN ******************************/

int main(){
    bool temp=true;
    Library library = newLibrary();

    // TODO implementare funzione che legge da file

    while(temp){
        switch(printMenu()){
            case 1:
                getBookValues(&library);    // TODO implementare scrittura su file
                break;
            case 2:
                // TODO implementare funzione che elimina un libro dal file e dalla memoria;
                break;
            case 3:
                showAllBooks(library);
                break;
            case 4:
                showBooksByRating(library);
                break;
            case 0:
                temp=false;
                break;
            default:
                printf("Il valore inserito non e' corretto!\n");
                break;
        }
    }

    destroyer(&library);
    return 0;
}

//****************************** FUNZIONI DEL MENU' ******************************/

void getBookValues(Library *lib){   // * funzione che popola i valori di book e li inserisce nella libreria
    Book b = newBook();

    printf("Inserire il titolo del libro: ");
    scanf(" %s", b.title);
    printf("Inserire l'autore del libro: ");
    scanf(" %s", b.author);
    printf("Inserire l'anno di pubblicazione: ");    // ! inserire controllo sui valori
    scanf(" %d", &b.yearOfPublication);
    printf("Inserire la casa editrice: ");
    scanf(" %s", b.publishingHouse);
    printf("Inserire la lunghezza: ");    // ! inserire controllo sui valori
    scanf(" %d", &b.length);
    printf("Inserire il genere: ");
    scanf(" %s", b.genre);
    printf("Inserire la codice: ");
    scanf(" %d", &b.code);
    printf("Inserire la valutazione [1-10]: ");    // ! inserire controllo sui valori
    scanf(" %d", &b.length);

    append2library(lib, b);
}

//****************************** GESTIONE STRUTTURE ******************************/

Book newBook(){     // * funzione che inizializza l'stanza di Book
    Book b;
    b.title = malloc(sizeof(char)*MAX_STRING_LENGTH);
    b.author = malloc(sizeof(char)*MAX_STRING_LENGTH);
    b.publishingHouse = malloc(sizeof(char)*MAX_STRING_LENGTH);
    b.genre = malloc(sizeof(char)*MAX_STRING_LENGTH);
    return b;
}

Library newLibrary(){   // * funzione che inizializza l'stanza di Library
    Library lib;
    lib.collection = malloc(0*sizeof(Book));
    lib.len = 0;
    return lib;
}

void append2library(Library *lib, Book b){      // * funzione che aggiunge un libro alla libreria
    lib->collection = realloc(lib->collection, (lib->len+1)*sizeof(Book));
    lib->collection[lib->len++] = b;
}

void showAllBooks(Library lib){     // * funzione che mostra tutti i libri della libreria
    for (int i=0; i < lib.len; i++)
    {   
        printf("\nLibro %d:", (i+1));

        printf("\nTitolo: %s", lib.collection[i].title);
        printf("\nAutore: %s", lib.collection[i].author);
        printf("\nAnno di pubblicazione: %d", lib.collection[i].yearOfPublication);
        printf("\nCasa editrice: %s", lib.collection[i].publishingHouse);
        printf("\nAnno di pubblicazione: %d", lib.collection[i].length);
        printf("\nGenere: %s", lib.collection[i].genre);
        printf("\nCodice identificativo: %d", lib.collection[i].code);
        printf("\nValutazione: %d\n\n", lib.collection[i].rating);
    }
}

void showBooksByRating(Library lib){    // * funzione che mostra solo i libri con una certa valutazione
    int rating;

    printf("Inserire la valutazione da cercare: ");
    scanf(" %d", &rating);                          // ! inserire controllo sui valori

    for (int i=0; i < lib.len; i++)
    {   
        if(lib.collection[i].rating == rating){
            printf("\nLibro %d:", (i+1));

            printf("\nTitolo: %s", lib.collection[i].title);
            printf("\nAutore: %s", lib.collection[i].author);
            printf("\nAnno di pubblicazione: %d", lib.collection[i].yearOfPublication);
            printf("\nCasa editrice: %s", lib.collection[i].publishingHouse);
            printf("\nAnno di pubblicazione: %d", lib.collection[i].length);
            printf("\nGenere: %s", lib.collection[i].genre);
            printf("\nCodice identificativo: %d", lib.collection[i].code);
            printf("\nValutazione: %d\n\n", lib.collection[i].rating);
        }
    }
}

void destroyer(Library *lib){   // * funzione che distrugge una libreria
    for (size_t i = 0; i < lib->len; i++){
        free(lib->collection[i].title);
        free(lib->collection[i].author);
        free(lib->collection[i].publishingHouse);
        free(lib->collection[i].genre);
    }
    free(lib->collection);
}

//****************************** MENU ******************************/

int printMenu(){
    int choice;

    printf("\n**** MENU\' DI GESTIONE DELLA TUA LIBRERIA ****\n");
    printf("1) Inserire un nuovo libro\n");
    printf("2) Cancellare un libro\n");
    printf("3) Visualizzare tutti i tuoi libri\n");
    printf("4) Visualizzare libri con una certa valutazione\n");
    printf("0) Esci dal programma\n");

    printf("\n\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice<0 && choice>=4)
    {
        if(choice<0 || choice>=4)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    //system("cls");
    return choice;
}
