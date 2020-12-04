#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 500

void checkEachWord(char *, char *);
char* reverse(char* ,int , int , int );
char** stringcut (char *, char *, int);
bool isIn (char*, char);

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

    system("pause");
    return 0;
}

bool isIn(char* s1, char s2)
{
    for(int i=0; i < strlen(s1); i++)
    {
        if(s1[i]==s2)
            return true;
    }
    return false;
}

char* reverse(char* str, int len, int l, int r)
{

    if (l < 0 || r >= len || l > r)
        return str;

    while (l < r) {

        char c = str[l];
        str[l] = str[r];
        str[r] = c;

        l++;
        r--;
    }

    return str;
}

char** stringcut (char *s1, char *s2, int n)
{
    char *word = (char*)malloc ((MAX_LENGTH+1)*sizeof(char)), *interract = (char*)malloc ((MAX_LENGTH+1)*sizeof(char));

    for(int i=n; i<strlen(s1)+1; i++)
    {

        if(isalpha(s1[i]) || isIn(s2,s1[i]))
        {
            strcat(interract,s1[i]);
            if()
        }
    }
}

void checkEachWord(char *s1, char *s2){
    char *word, *newWord = (char*) malloc((MAX_LENGTH+1)*sizeof(char));
    char firtsChar;

    word = strtok(s1," *',.-");
    while (word != NULL)
    {
        //printf("%s\n",word);
        strcpy(newWord, word);

        // * 1 - 3 - 4
        firtsChar = newWord[0];
        if(isalpha(firtsChar))
            {
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
