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

/****************************** STRUTTURE ******************************/

typedef struct book {
}BOOK;

/****************************** PROTOTIPI ******************************/

int printMenu();

/****************************** MAIN ******************************/

int main()
{
    bool temp=true;

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
            case 0:
              temp=false;
              break;
        }
    }

    destroyer();
    return 0;
}

/****************************** FUNZIONI DEL MENU' ******************************/

/****************************** GESTIONE STRUTTURE ******************************/

void destroyer()
{
    free();
}

/****************************** MENU ******************************/

int printMenu()
{
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

    while(choice<0 && choice!>4)
    {
        if(choice<0 || choice!>4)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    system("cls");
    return choice;
}
