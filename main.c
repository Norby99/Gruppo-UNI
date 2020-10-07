#include <stdio.h>

int main() {
	
    int min = 0;
    int max = 0;
    int iaGuess;
    char userResponse;

    printf("Inserisci il range [formato: min,max]: ");

    do{     // Controllo dei valori del range
        scanf("%d,%d", &min, &max);
    }while(!(0 < min && min < max));
    
    printf("Pensa ad un numero compreso nell'intervallo inserito\n\n");

    while(userResponse != '='){     // Ciclo finche' l'IA non ha indovinato il numero
        iaGuess = (max+min)/2;  // Calcolo il valore indovinato dalla IA
        printf("Il numero e’ minore (<) uguale (=) o maggiore (>) di %d? ", iaGuess);
        scanf(" %c", &userResponse);

        if(userResponse != '<' && userResponse != '=' && userResponse != '>'){  // Obbligo l'utene ad inserire uno dei tre valori
            printf("Valore non valido!\n");
        }
        
        /* Restrizzione del range dei valori */
        else if(userResponse == '<')
                max = iaGuess-1;
        else if(userResponse == '>')
                min = iaGuess+1;
    }

    printf("Il numero a cui hai pensato e' %d", iaGuess);

    return 0;

}