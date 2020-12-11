/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201222
 NOTE:    Text Ex02: Scrivere un programma contenente tutte le funzioni di gestione del tipo di dato astratto PILA,
          implementato sia tramite allocazione indicizzata (vettore statico e vettore dinamico) sia tramite strutture collegate.
          Il programma deve visualizzare lo stato della pila ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
          Per la visualizzazione creare una funzione di appoggio in cui gli elementi letti non vengono eliminati.
          Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/****************************** STRUTTURE ******************************/

typedef struct {
};

/****************************** PROTOTIPI ******************************/

int print1Menu();
int print2Menu();

/****************************** MAIN ******************************/

int main()
{
    bool temp=true, tmp = true;

    while(tmp)
    {
        switch(print1Menu())
        {
            case 1: // Allocazione indicizzata
                while(temp)
                {
                    switch(print2Menu())
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
            case 2: // Strutture collegate
                while(temp)
                {
                    switch(print2Menu())
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

    destroyer();
    return 0;
}

/****************************** FUNZIONI DEL MENU' ******************************/

/****************************** GESTIONE STRUTTURE ******************************/

void destroyer()
{
    free();
}

/****************************** MENU' ******************************/

int print2Menu()
{
    int choice;

    printf("\n**** MENU\' ****\n");
    printf("1) \n");
    printf("2) \n");
    printf("3) \n");
    printf("4) \n");
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

int print1Menu()
{
    int choice;

    printf("\n**** MENU\' DI SCELTA TRA LE DUE VARIANTI ****\n");
    printf("1) Allocazione indicizzata\n");
    printf("2) Strutture collegate\n");
    printf("0) Esci dal programma\n");

    printf("\n\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice<0 && choice!>2)
    {
        if(choice<0 || choice!>2)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    system("cls");
    return choice;
}
