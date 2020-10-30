/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201030
 NOTE:    Text Ex01: Scrivete un programma che generi una “passeggiata aleatoria” (random walk) in un array bidimensionale di dimensione 10×10. L’array sarà riempito di caratteri (inizialmente da punti). Il programma dovrà muoversi di elemento in elemento spostandosi ogni volta di un passo in direzione su, giù, destra o sinistra. Gli elementi visitati andranno etichettati con le lettere dalla A alla Z, nell’ordine in cui vengono visitati. E’ importante controllare ad ogni passo che la passeggiata non esca dall’array e che non ritorni su posizioni già visitate. Quando si verifica una di queste condizioni, provate in altre direzioni. Se tutte e quattro le direzioni sono bloccate, il programma deve uscire.
          Ecco un esempio di funzionamento completo:
          A . . . . . . . . . .
          B C D . . . . . . .
          . F E . . . . . . .
          H G . . . . . . . .
          I . . . . . . . . .
          J . . . . . . . Z .
          K . . R S T U V Y .
          L M P Q . . . W X .
          . N O . . . . . . .
          . . . . . . . . . .
          Ecco un esempio di uscita prematura dal programma:
          A B G H I . . . . .
          . C F . J K . . . .
          . D E . M L . . . .
          . . . . N O . . . .
          . . W X Y P Q . . .
          . . V U T S R . . .
          . . . . . . . . . .
          . . . . . . . . . .
          . . . . . . . . . .
          . . . . . . . . . .
          Y è bloccata in tutte le direzioni quindi non c’è modo di inserire Z.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define X 10
#define Y 10

void initializeMatrix(char [X][Y]);
void printMatrix(char [X][Y]);
int randomInt(int,int);
bool getNextPos(int *, char [X][Y]);
bool isFree(int *, char [X][Y]);
bool isInRange(int *);
void remove_element(int *, int, int);


int main() {
    char matrix[X][Y];
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int position[2];

    initializeMatrix(matrix);

    for(int i; i<strlen(alphabet); i++){
        if(i==0){
            position[0] = randomInt(0, X); position[1] = randomInt(0, Y);
        }else{
            if(getNextPos(position, matrix) == false){
                printf("No free space detected!\n");
                break;
            }
        }
        matrix[position[0]][position[1]] = alphabet[i];
    }

    printMatrix(matrix);
    return 0;
}

bool getNextPos(int *pos, char m[X][Y]){     //returns the next matrix position
    int len = 4;
    int moves[4] = {0, 1, 2, 3};
    int move;
    int tryPos[2];

    while(len>0){
        move = rand() % len;

        switch (moves[move]) {
            case 0:
                tryPos[0] = pos[0] - 1; tryPos[1] = pos[1];
                break;
            case 1:
                tryPos[0] = pos[0]; tryPos[1] = pos[1] - 1;
                break;
            case 2:
                tryPos[0] = pos[0] + 1; tryPos[1] = pos[1];
                break;

            case 3:
                tryPos[0] = pos[0]; tryPos[1] = pos[1] + 1;
                break;
            default:
                break;
	    }
        if(isFree(tryPos, m)){
            pos[0] = tryPos[0]; pos[1] = tryPos[1];
            break;
        }else{
            remove_element(moves, move, len--);
        }
    }
    if(len == 0)
        return false;
    return true;
}

bool isFree(int *pos, char m[X][Y]){     //checks if the next pos is valid
    if(m[pos[0]][pos[1]] == '.' && isInRange(pos))
        return true;
    else
        return false;
}

bool isInRange(int *a)
{
    if((a[0]>=0 && a[0]<X) && (a[1]>=0 && a[1]<Y))
        return true;
    else
        return false;
}

void remove_element(int *array, int index, int array_length){   // removes an element from array
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

void initializeMatrix(char m[X][Y]){     // create an empty matrix filled by "."
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            m[i][j] = '.';
        }
    }

}

void printMatrix(char m[X][Y]){     //prints the 2D matrix
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

int randomInt(int minimum_number,int max_number){   //returns a random number in range
    srand(time(0));
    return rand() % (max_number + 1 - minimum_number) + minimum_number;
}

