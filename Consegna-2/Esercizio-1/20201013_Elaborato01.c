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
    /*sizeof()
    X   casting
    */

     //usiamo l'operatore di assegnamento nella dichiarazione delle variabili
    int num1=5,num2=15,risultato;
    printf("Le variabili sono le seguenti:\n");
    printf("TIPO\t\t\tNOME\t\t\tVALORE\n");
    printf("Int\t\t\tnum1\t\t\t%2d\n",num1);
    printf("Int\t\t\tnum2\t\t\t%d\n",num2);
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
    printf("\nOperazioni con gli operatori aritmetici:\n");
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

    //Effetti collaterali
    int x = 1;

    x = x++;
    printf("\nIl valore di x con side effect e\' %d\n\n",x);
    x = 1;
    x = ++x;
    printf("Il valore di x e\' %d\n\n",x);


    //qui usiamo gli operatori aritmetici unari, incremento e decrementano il valore di una variabile
    printf("\nvalori iniziali delle variabili:  %d  %d\n", num1, num2);
    printf("incrementi e decrementi:\t  %d  %d\n", num1++, --num2);//num1 invariato perchè assume il valore prima dell'incremento
    printf("\t\t\t\t  %d  %d\n", ++num1, num2++);//num1 varia perchè assume prima gli incrementi
    printf("\t\t\t\t  %d  %d\n", --num1, num2--);
    printf("\t\t\t\t  %d  %d\n", num1++, --num2);
    printf("valori finali:\t\t\t  %d  %d\n", ++num1, --num2);
    printf("valori finali cambiati di segno: %d %d\n", -num1, -num2);

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
    int num3,num4,num5;

    printf("Dammi il primo valore ");
    scanf("%d",&num3);
    fflush(stdin);
    printf("Dammi il secondo valore ");
    scanf("%d",&num4);
    fflush(stdin);
    printf("Dammi il terzo valore ");
    scanf("%d",&num5);
    fflush(stdin);

    printf("Avviamo il confronto");
    if(num3 != num4 && num4!= num5 && num3 != num5)
    {
        printf("I numeri sono tutti diversi tra loro, stampati in ordine crescente risultano ");
        if(num3 < num4 && num4 < num5)
        {
            printf("%d<%d<%d",num3,num4,num5);
        }
        else if(num3 < num5 && num5 < num4)
        {
            printf("%d<%d<%d",num3,num5,num4);
        }
        else if(num4 < num3 && num3 < num5)
        {
            printf("%d<%d<%d",num4,num3,num5);
        }
        else if(num4 < num5 && num5 < num3)
        {
            printf("%d<%d<%d",num4,num5,num3);
        }
        else if(num5 < num4 && num4 < num3)
        {
            printf("%d<%d<%d",num5,num4,num3);
        }
        else
        {
            printf("%d<%d<%d",num5,num3,num4);
        }
    }
    else if(num3 == num4 && num4 == num5)
    {
        printf("I numeri inseriti sono tutti uguali fra loro");
    }
    else
    {
        printf("Almeno 2 valori sono uguali tra loro");
        if(num3 == num4)
        {
            if(num3 > num5)
            {
                printf("num3 e num4 sono > di num5, %d e %d > %d",num3,num4,num5);
            }
            else
            {
                printf("num3 e num4 sono < di num5, %d e %d < %d",num3,num4,num5);
            }
        }
        else if(num4 == num5)
        {
             if(num4 > num3)
            {
                printf("num4 e num5 sono > di num3, %d e %d > %d",num4,num5,num3);
            }
            else
            {
                printf("num4 e num5 sono < di num3, %d e %d < %d",num4,num5,num3);
            }
        }
        else
        {
             if(num5 > num4)
            {
                printf("num3 e num5 sono > di num4, %d e %d > %d",num3,num5,num4);
            }
            else
            {
                printf("num3 e num5 sono < di num4, %d e %d < %d",num3,num5,num3);
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
