/*AUTHOR: Cristina Zoccola(cristina.zoccola@studio.unibo.it)
          Denny Reggidori(denny.reggidori@studio.unibo.it)
          Norby Gabos(tiberiunorbert.gabos@studio.unibo.it)
          Sara Romeo(sara.romeo3@studio.unibo.it)
 DATE:    20201016
 NOTE:    Text Ex02: Scrivere un programma C che stampi il calendario di un anno,
          chiedendo all'utente di specificare l'anno in oggetto e il numero che identifica il primo giorno dell'anno
          (1=lunedì, 7=domenica).*/

#include <stdio.h>
#include <stdlib.h>


char* nomeMese(int num_Mese)
{
    char* mese;

     switch(num_Mese)
    {
        case 1:
        mese = "Gennaio";
        break;
        case 2:
        mese = "Febbraio";
        break;
        case 3:
        mese = "Marzo";
        break;
        case 4:
        mese = "Aprile";
        break;
        case 5:
        mese = "Maggio";
        break;
        case 6:
        mese = "Giugno";
        break;
        case 7:
        mese = "Luglio";
        break;
        case 8:
        mese = "Agosto";
        break;
        case 9:
        mese = "Settembre";
        break;
        case 10:
        mese = "Ottobre";
        break;
        case 11:
        mese = "Novembre";
        break;
        case 12:
        mese = "Dicembre";
        break;
    }
    return(mese);
}
int main()
{
    int anno, inizioAnno, i, j, num_Mese = 1, ggMese = 0, k = 0;
    char* mese;

    do
    {
        printf("L'anno di cui vuoi stampare il calendario e\': ");
        scanf("%d",&anno);
        fflush(stdin);
    }while(anno < 0);

    printf("Inserisci il primo giorno dell'anno (1=Lumedi\', 7=Domenica): ");
    scanf("%d",&inizioAnno);
    fflush(stdin);

    printf("\nCalendario dell'anno %d\n\n",anno);
    while(num_Mese <= 12)
    {
        mese = nomeMese(num_Mese);
        printf("\t%s",mese);
        printf("\n  L  MA ME G  V  S  D\n");

        switch(num_Mese)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            ggMese = 31;
            break;
            case 2:
            if((anno %4 == 0 && anno%100 != 0 )|| anno%400 == 0)
            {
                ggMese = 29;
            }
            else
            {
                ggMese = 28;
            }
            break;
            default:
            ggMese = 30;
        }

        for(i = 1;i < inizioAnno; i++)
        {
            printf("   ");
            k++;
        }
        for(j = 1; j <= ggMese; j++)
        {
            printf("%3d",j);
            k++;
            if((inizioAnno + j-1)%7 == 0)
            {
                printf("\n");
                if(k >= 7)
                {
                    k = 0;
                }
            }
        }
        inizioAnno = k+1;
        num_Mese++;
        printf("\n\n");
    }
    printf("\n\n");

    system("pause");
    return 0;
}
