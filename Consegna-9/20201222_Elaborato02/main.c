/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201222
 NOTE:    Text Ex02: Scrivere un programma contenente tutte le funzioni di gestione del tipo di dato astratto PILA,
          implementato sia tramite allocazione indicizzata (vettore statico e vettore dinamico) sia tramite strutture collegate.
    !!      Il programma deve visualizzare lo stato della pila ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
          Per la visualizzazione creare una funzione di appoggio in cui gli elementi letti non vengono eliminati.
          Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mypila.h"

/****************************** MAIN ******************************/

int main()
{
    //Dichirazione varibili
    bool temp=true, tmp = true;
    SACCHETTO_STATICO *ss;
    SACCHETTO_DINAMICO *sd;
    FRUTTALINKED *sc;


    while(tmp)
    {
        switch(print1Menu())
        {
            case 1: // Allocazione indicizzata (vettore statico)
            {
                ss=initPila_Sta(ss);  // init pos pila
                while(temp)
                {
                    switch(print2Menu())
                    {
                        case 1:
                            pushStatic(ss); //Funzione PUSH
                            break;
                        case 2:
                            topStatic(popStatic(ss)); //Funzione POP
                            break;
                        case 3:
                            topStatic(ss); //Funzione TOP
                            break;
                        case 4:
                            printAllStatic(ss); //Fuzione che stampoa tutti gli elementi
                            break;
                        case 0:
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
                }
            }
            case 2: // Allocazione indicizzata (vettore dinamico)
            {
                sd=initPila_Din(sd); //init pos pila
                while(temp)
                {
                    switch(print2Menu())
                    {
                        case 1:
                            pushDinamic(sd); //Funzione PUSH
                            break;
                        case 2:
                            topDinamic(popDinamic(sd)); //Funzione POP
                            break;
                        case 3:
                            topDinamic(sd); //Funzione TOP
                            break;
                        case 4:
                            printAllDinamic(sd); //Funzione che stampa tutti gli elementi
                            break;
                        case 0:
                            destroyerDinamic(sd);  //Funzione che libera la memoria allocata
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
                }
            }
            case 3: // Strutture collegate
            {
                sc=initPila(sc); //Inizializzazione della pila
                while(temp)
                {
                    switch(print2Menu())
                    {
                        case 1:
                            pushLinked(&sc); //Funzione PUSH
                            break;
                        case 2:
                            topLinked(popLinked(&sc)); //Funzione POP
                            break;
                        case 3:
                            topLinked(sc); //Funzione TOP
                            break;
                        case 4:
                            printAllLinked(sc); //Funzione che stampa tutti gli elementi
                            break;
                        case 0:
                            destroyerLinked(&sc); //Funzione che libera la memoria allocata
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
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

    return 0;
    system("pause");
}

/****************************** MENU' ******************************/

int print2Menu()
{
    int choice;

    printf("\n**** MENU\' ****\n");
    printf("1) Inserisci frutto in cima;\n");
    printf("2) Elimina frutto affiorante;\n");
    printf("3) Visualizza ultimo frutto aggiunto;\n");
    printf("4) Visualizza tutti gli elementi;\n"); // ??? FACOLTATIVA ???
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

int print1Menu()
{
    int choice;

    printf("\n**** MENU\' DI SCELTA TRA LE DUE VARIANTI ****\n");
    printf("1) Allocazione indicizzata (vettore statico)\n");
    printf("2) Allocazione indicizzata (vettore dinamico)\n");
    printf("3) Strutture collegate\n");
    printf("0) Esci dal programma\n");

    printf("\n\nScegli una tra le seguenti operazioni: ");
    scanf(" %d", &choice);
    fflush(stdin);

    while(choice<0 && choice>3)
    {
        if(choice<0 || choice>3)
        {
            printf("\nL'operazione inserita non e\' presente nel menu\' di scelta, riprova: ");
            scanf(" %d", &choice);
            fflush(stdin);
        }
    }
    system("cls");
    return choice;
}
