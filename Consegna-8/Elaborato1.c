/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201204
 NOTE:    Text Ex01: Scrivere un programma C che prenda da riga di comando una frase e stampi a video la frase così modificata. Per ogni parola in ingresso:
                        1. Spostare la prima lettera alla fine.
                        2. Aggiungere le lettere "an" alla fine di ogni parola di tre lettere o meno, e "o" alla fine di ogni ALTRA parola.
                        3. Fare in modo che la nuova prima lettera della parola corrisponda al tipo (minuscola/maiuscola) della vecchia prima lettera della parola. Rendete minuscola la lettera che è stata spostata, se non è la prima lettera. Non modificare il tipo (minuscola/maiuscola) delle altre lettere.
                        4. Ogni carattere non isalpha deve rimanere inalterato.
                        5. Una parola si considera separata dalle altre quando c'è uno spazio bianco o un carattere non isalpha

                        Ad esempio, data come input la frase:
                        I *REALLY* like Yale's course-selection procedures.
                        il programma deve stampare in output:
                        Ian *EALLYro* ikelo Aleyo'san ourseco-electionso rocedurespo.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 500

void checkEachWord(char *, char *);
char *strsep(char **stringp, const char *delim);
void createNewWord(char *);

int main()
{
    char *sentence = (char*)malloc((MAX_LENGTH+1)*sizeof(char));
    char *newSentence = (char*)malloc((MAX_LENGTH+1)*sizeof(char));
    newSentence[0] = '\0';  // inizializzo la 2a stringa
    printf("Inserisci la frase: ");
    scanf(" %[^\n]%*c", sentence);

    checkEachWord(sentence, newSentence);

    printf("La nuova frase e':\n%s", newSentence);

    free(sentence);
    free(newSentence);

    system("pause");
    return 0;
}

void createNewWord(char *w){
    char firtsChar;
    char *nw = (char*)malloc((MAX_LENGTH+1)*sizeof(char)); nw[0] = '\0';


    strcpy(nw, w);

    // * 1 - 3 - 4
    firtsChar = nw[0];
    if(isalpha(firtsChar)){
        strcpy(&nw[0], &nw[1]);
        nw[strlen(w)-1] = tolower(firtsChar);
        nw[strlen(w)] = '\0';
        if(isupper(firtsChar)){
            nw[0] = toupper(nw[0]);
        }
    }

    // * 2
    if(strlen(nw) <= 3)
            strcat(nw, "an");
        else
            strcat(nw, "o");
    strcpy(w, nw);
}

void checkEachWord(char *s1, char *s2){
    char *word = (char*)malloc((MAX_LENGTH+1)*sizeof(char)); word[0] = '\0';
    int i = 0;
    int j;
    while(i < strlen(s1))
    {
        if(!isalpha(s1[i])){
            strncat(s2, &s1[i], 1);
            i++;
        }
        else{
            for (j = i; j < strlen(s1); j++)
            {
                if(isalpha(s1[j])){
                    strncat(word, &s1[j], 1);
                }
                else
                    break;
            }
            createNewWord(word);
            strncat(s2, word, strlen(word));
            word[0] = '\0';
            i = j;
            if(s1[j] == '\0')
                break;
        }
    }
}
