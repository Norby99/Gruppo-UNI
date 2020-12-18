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
#include "mypila.h"

/****************************** MAIN ******************************/

int main()
{
    bool temp=true, tmp = true;
    SACCHETTO_STATICO *ss;
    SACCHETTO_DINAMICO *sd;

    while(tmp)
    {
        switch(print1Menu())
        {
            case 1: // Allocazione indicizzata (vettore statico)
            {
                ss->pos=-1;  // init pos pila
                while(temp)
                {
                    switch(print2Menu())
                    {
                        case 1:
                            pushStatic(ss);
                            break;
                        case 2:
                            topStatic(popStatic(ss));
                            break;
                        case 3:
                            topStatic(ss);
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
                initPila(sd);
                while(temp)
                {
                    switch(print2Menu())
                    {
                        case 1:
                            pushDinamic(sd);
                            break;
                        case 2:
                            //topDinamic(sd);
                            break;
                        case 3:
                            //popDinamic(sd);
                            break;
                        case 0:
                            temp = false;
                            break;
                        default:
                            printf("!!Valore inserito non valido!! Riprova.\n");
                            break;
                    }
                }
            case 3: // Strutture collegate
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
    }

//    destroyer();
    return 0;
}

/****************************** MENU' ******************************/

int print2Menu()
{
    int choice;

    printf("\n**** MENU\' ****\n");
    printf("1) Inserisci frutto in cima;\n");
    printf("2) Elimina frutto affiorante;\n");
    printf("3) Visualizza ultimo frutto aggiunto;\n");
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
    //system("cls");
    return choice;
}
