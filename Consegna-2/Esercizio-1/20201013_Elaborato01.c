/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201009
 NOTE:    Text Ex01: Scrivere un programma C che mostri l’utilizzo di tutti gli operatori studiati.
          Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi non appropriati
          alla dimensione delle variabili, quello che si ottiene usando più operatori con side effects
          all’interno della stessa istruzione, quello che si ottiene quando le regole di conversione implicita sono applicate
          e quando si supera il range dei valori disponibili per un tipo di dato.
          Il programma deve poi mostrare l’utilizzo di tutte le funzioni matematiche della libreria math.h.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showbits (unsigned int);
int main()
{
    //usiamo l'operatore di assegnamento nella dichiarazione delle variabili
    int num1=5,num2=15,risultato;
    printf("Le variabili sono le seguenti:\n");
    printf("TIPO\t\t\tNOME\t\t\tVALORE\n");
    printf("Int (%d byte)\t\tnum1\t\t\t%2d\n", sizeof(int), num1); //uso l'operatore sizeof()
    printf("Int (%d byte)\t\tnum2\t\t\t%d\n", sizeof(int), num2); //uso l'operatore sizeof()
    printf("Convertite in numeri binari:\n");
    printf("num1(%d)\t\t\t", num1);
    showbits(num1);
    printf("\nnum2(%d)\t\t", num2);
    showbits(num2);

    //operatori bitwise
    printf("\n\n\nOperazioni con gli operatori bitwise tra num1(%d) e num2(%d):\n", num1, num2);
    printf("\nAND logico bit a bit tra i due operandi:\n  ");
    showbits(num1);
    printf("\n& ");
    showbits(num2);
    risultato=num1&num2;
    printf("\n= ");
    showbits(risultato);

    printf("\n\nOR logico bit a bit tra i due operandi:\n  ");
    showbits(num1);
    printf("\n| ");
    showbits(num2);
    risultato=num1|num2;
    printf("\n= ");
    showbits(risultato);

    printf("\n\nXOR logico bit a bit tra i due operandi:\n  ");
    showbits(num1);
    printf("\n^ ");
    showbits(num2);
    risultato=num1^num2;
    printf("\n= ");
    showbits(risultato);

    printf("\n\nOperazioni con gli operatori bitwise su num1(%d):\n  ", num1);
    printf("\nComplemento a 1 dell'operando:\n~ ");
    showbits(num1);
    risultato=~num1;
    printf("\n= ");
    showbits(risultato);

    printf("\n\nShifta destra del primo operando per un numero di bit pari a 2:\n>>2 ");
    showbits(num1);
    risultato=num1>>2;
    printf("\n=   ");
    showbits(risultato);

    printf("\n\nShifta sinistra del primo operando per un numero di bit pari a 2:\n<<2 ");
    showbits(num1);
    risultato=num1<<2;
    printf("\n=   ");
    showbits(risultato);


    //uso degli operatori aritmetici
    printf("\n\n\nOperazioni con gli operatori aritmetici:\n");
    int sum = num1 + num2;
    int sub = num1 - num2;
    int prod = num1 * num2;
    float div =(float)num1 / num2; //conversione esplicita da int a float usando il casting
    int mod = num1 % num2;
    printf("Somma:\t\t\t%3d\n",sum);
    printf("Sottrazione:\t\t%d\n",sub);
    printf("Prodotto:\t\t%3d\n",prod);
    printf("Divisione:\t\t%f\n",div);
    printf("Modulo:\t\t\t%3d\n\n",mod);

    //da qui usiamo operatori  di  assegnamento  compatti per modificare il valore di num1
    printf("num1 iniziale =\t%3d\n\n",num1);
    printf("num1 = num1(%d) + num2(%d)\t",num1, num2);
    num1+=num2;
    printf("num1 = %3d\n",num1);
    printf("num1 = num1(%d) - num2(%d)\t",num1, num2);
    num1-=num2;
    printf("num1 = %3d\n",num1);
    printf("num1 = num1(%d) * num2(%d)\t",num1, num2);
    num1*=num2;
    printf("num1 = %3d\n",num1);
    printf("num1 = num1(%d) / num2(%d)\t",num1, num2);
    num1/=num2;
    printf("num1 = %3d\n",num1);
    printf("num1 = num1(%d) % num2(%d)\t",num1, num2);
    num1%=num2;
    printf("num1 = %3d\n\n",num1);
    printf("num1 finale =\t%3d\n",num1);

    //dimostrazione di side effects
    printf("\n\nSide effects nell'uso di una variabile x:");
    int x = 2;
    x = x++;
    printf("\nIl valore di x con side effect e\' %d\n",x);
    x = 2;
    x = ++x;
    printf("Il valore di x e\' %d",x);

    //effetti di conversione implicita e assegnamento inappropriato di valore per il tipo di variabile
    printf("\n\nApplicando conversioni implicite si ottiene:");
    int y=7.89, z=10;
    printf("\nLa variabile in input sarebbe 7.89, ma in quanto int l'output e' %d", y);
    div=z/x;
    printf("\nLa divisione tra z(%d) e x(%d) e': %f", z, x, div);
    div=z/4.0;
    printf("\nLa divisione tra z(%d) e 4 e': %f", z, div);

    //effetti del superamento dei range di memorizzazione del tipo di variabile
    short int var1=10000, var2=30000, somma;
    printf("\n\n\nVengono assegnati 2 valori (%d e %d):", var1, var2);
    printf("\nSi ottiene come risultato:\t%d + %d = %d\n!oltre il range di memorizzazione!", var1, var2, somma=var1+var2);

    //qui usiamo gli operatori aritmetici unari, incremento e decrementano il valore di una variabile
    printf("\n\n\nValori iniziali delle variabili:  %d  %d\n", num1, num2);
    printf("Incrementi e decrementi:\t  %d  %d\n", num1++, --num2); //num1 invariato perchè assume il valore prima dell'incremento
    printf("\t\t\t\t  %d  %d\n", ++num1, num2++); //num1 varia perchè assume prima gli incrementi
    printf("\t\t\t\t  %d  %d\n", --num1, num2--);
    printf("\t\t\t\t  %d  %d\n", num1++, --num2);
    printf("Valori finali:\t\t\t  %d  %d\n", ++num1, --num2);
    printf("Valori finali cambiati di segno: %d %d\n", -num1, -num2);

    //qui usiamo le funzione matematiche

    printf("\nFunzioni matematiche per il num1(%d)\n", num1);
    printf("1. Radice quadrata:\t\t\t%lf\n", sqrt(num1));
    printf("2. e elevato alla num1:\t\t\t%lf\n", exp(num1));
    printf("3. Logaritmo in base e:\t\t\t%lf\n", log(num1));
    printf("4. Logaritmo in base 10:\t\t%lf\n", log10(num1));
    printf("5. Resto num1/num2:\t\t\t%lf\n", fmod(num1, num2));
    printf("6. Potenza num1^num2:\t\t\t%lf\n", pow(num1, num2));
    float num6=0.5;
    printf("\nFunzioni matematiche per il num6(%f)\n", num6);
    printf("7. Coseno in radianti:\t\t\t%lf\n",  cos(num6));
    printf("8. Seno in radianti:\t\t\t%lf\n",  sin(num6));
    printf("9. Arc coseno in radianti:\t\t%lf\n",  acos(num6));
    printf("10. Arc seno in radianti:\t\t%lf\n",  asin(num6));
    printf("11. Arc tangente in radianti:\t\t%lf\n",  atan(num6));
    printf("12. Coseno iperbolico in radianti:\t%lf\n",  cosh(num6));
    printf("13. Seno iperbolico in radianti:\t%lf\n",  sinh(num6));
    printf("14. Tangente iperbolica in radianti:\t%lf\n",  tanh(num6));
    printf("15. Minor valore intero >= num6:\t%lf\n",  ceil(num6));
    printf("16. Maggior valore intero <= num6:\t%lf\n",  floor(num6));



    //operatori logici e relazionali applicati con l'istruzione di selezione if
    printf("\n\"Confronto tra 3 numeri\"\n");
    int num3,num4,num5;
    printf("Inserire il primo valore ");
    scanf("%d",&num3);
    fflush(stdin);
    printf("Inserire il secondo valore ");
    scanf("%d",&num4);
    fflush(stdin);
    printf("Inserire il terzo valore ");
    scanf("%d",&num5);
    fflush(stdin);
    if(num3 != num4 && num4!= num5 && num3 != num5)
    {
        printf("\nI numeri sono tutti diversi tra loro, stampati in ordine crescente risultano: ");
        if(num3 < num4 && num4 < num5)
        {
            printf("%d<%d<%d.\n\n",num3,num4,num5);
        }
        else if(num3 < num5 && num5 < num4)
        {
            printf("%d<%d<%d.\n\n",num3,num5,num4);
        }
        else if(num4 < num3 && num3 < num5)
        {
            printf("%d<%d<%d.\n\n",num4,num3,num5);
        }
        else if(num4 < num5 && num5 < num3)
        {
            printf("%d<%d<%d.\n\n",num4,num5,num3);
        }
        else if(num5 < num4 && num4 < num3)
        {
            printf("%d<%d<%d.\n\n",num5,num4,num3);
        }
        else
        {
            printf("%d<%d<%d.\n\n",num5,num3,num4);
        }
    }
    else if(num3 == num4 && num4 == num5)
    {
        printf("\nI numeri inseriti sono tutti uguali fra loro.\n\n");
    }
    else
    {
        printf("\nDue valori sono uguali tra loro e sono: ");
        if(num3 == num4)
        {
            if(num3 > num5)
            {
                printf("%d e %d > %d.\n\n",num3,num4,num5);
            }
            else
            {
                printf("%d e %d < %d.\n\n",num3,num4,num5);
            }
        }
        else if(num4 == num5)
        {
             if(num4 > num3)
            {
                printf("%d e %d > %d.\n\n",num4,num5,num3);
            }
            else
            {
                printf("%d e %d < %d.\n\n",num4,num5,num3);
            }
        }
        else
        {
             if(num5 > num4)
            {
                printf("%d e %d > %d.\n\n",num3,num5,num4);
            }
            else
            {
                printf("%d e %d < %d.\n\n",num3,num5,num3);
            }
        }
    }
    system("pause");
    return 0;
}

void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
}
