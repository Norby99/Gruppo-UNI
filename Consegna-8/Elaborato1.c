#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 500

void checkEachWord(char *, char *);

int main()
{
    char *sentence = (char*) malloc((MAX_LENGTH+1)*sizeof(char));
    char *newSentence;
    newSentence[0] = '\0';  // inizializzo la 2a stringa
    printf("Inserisci la frase: ");
    scanf(" %[^\n]%*c", sentence);

    checkEachWord(sentence, newSentence);

    printf("La nuova frase e':\n%s", newSentence);

    free(sentence);
    free(newSentence);
    return 0;
}

void checkEachWord(char *s1, char *s2){
    char *word, *newWord = (char*) malloc((MAX_LENGTH+1)*sizeof(char));
    char firtsChar;

    word = strtok (s1," ,.-");
    while (word != NULL)
    {
        strcpy(newWord, word);

        // * 1 - 3 - 4
        firtsChar = newWord[0];
        if(isalpha(firtsChar)){
            strcpy(&newWord[0], &newWord[1]);
            newWord[strlen(word)-1] = tolower(firtsChar);
            newWord[strlen(word)] = '\0';
            if(isupper(firtsChar)){
                newWord[0] = toupper(newWord[0]);
            }
        }

        // * 2
        if(strlen(newWord) <= 3)
            strcat(newWord, "an");
        else
            strcat(newWord, "o");

        strcat(s2, newWord);
        strcat(s2, " ");
        word = strtok(NULL, " ");
    }
    s2[strlen(s2)-1] = '\0';
}