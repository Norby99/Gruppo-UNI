/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)

 DATE:   20201017

 NOTE:   Text Ex02: Pensa a un numero. L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.
	 L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max). Se i valori inseriti non rispettano il vincolo 0<min≤max,
	 l’operazione di lettura va ripetuta. L’utente pensa ad un numero compreso tra min e max.
	 Il programma cerca di indovinare la scelta dell’utente e propone un numero. A seconda della situazione l’utente deve dire al programma se
	 il numero da indovinare è più piccolo; il numero da indovinare è più grande; ha indovinato. Non poniamo limite al numero di tentativi 

	 Due possibili alternative di gioco:
	 	 1)
	 	 Inserisci l’intervallo di ricerca (min max): 23 89
	 	 Pensa ad un numero compreso tra 23 e 89
	 	 Hai pensato a 56? (s/n) n
	 	 il numero viene prima (<) o dopo (>) di 56? >
	 	 Hai pensato a 73? (s/n) n
	 	 il numero viene prima (<) o dopo (>) di 73? >
	 	 Hai pensato a 81? (s/n) n
	 	 il numero viene prima (<) o dopo (>) di 81? <
	 	 Hai pensato a 77? (s/n) n
	 	 il numero viene prima (<) o dopo (>) di 77? <
	 	 Hai pensato a 75? (s/n) s
	 	 Ho indovinato!!

	 	 2)
	 	 Inserisci l’intervallo di ricerca (min max): 45 124
	 	 Pensa ad un numero compreso tra 45 e 124
	 	 Il numero e’ minore (<) uguale (=) o maggiore (>) di 84? >
	 	 Il numero e’ minore (<) uguale (=) o maggiore (>) di 104? <
	 	 Il numero e’ minore (<) uguale (=) o maggiore (>) di 94? >
	 	 Il numero e’ minore (<) uguale (=) o maggiore (>) di 99? <Il numero e’ minore (<) uguale (=) o maggiore (>) di 96? >
	 	 Il numero e’ minore (<) uguale (=) o maggiore (>) di 97? =
	 	 Hai pensato a 97!*/
 
 
#include<stdio.h>
#include<stdlib.h>

int main() {
	
    int min = 0;
    int max = 0;
    int iaGuess;
    char userResponse;

    printf("Inserisci il range [formato: min max]: ");

    do{     // Obbligo l'utente ad inserire i valori nel formato corretto
        scanf("%d %d", &min, &max);
	if(!(0 < min && min <= max)) printf("I valori inseriti non rispettano la sintassi corretta [0 < min <= max]! Per favore reinserisci i dati:\n");
    }while(!(0 < min && min <= max));
    
    printf("Pensa ad un numero compreso nell'intervallo inserito\n\n");

    while(userResponse != '='){     // Ciclo finche' l'IA non ha indovinato il numero
        iaGuess = (max+min)/2;  // Calcolo il valore indovinato dalla IA
        printf("Il numero e\' minore (<) uguale (=) o maggiore (>) di %d? ", iaGuess);
        scanf(" %c", &userResponse);

        if(userResponse != '<' && userResponse != '=' && userResponse != '>'){  // Obbligo l'utente ad inserire uno dei tre valori
            printf("Valore non valido!\n");
        }
        
        /* Restrizione del range dei valori */
        else if(userResponse == '<')
                max = iaGuess-1;
        else if(userResponse == '>')
                min = iaGuess+1;
    }

    printf("Il numero a cui hai pensato e' %d\n\n", iaGuess);
	
    system("pause");
    return 0;

}
