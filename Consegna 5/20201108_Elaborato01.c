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
#include <stdlib.h>

int main(void)
{
    //
    printf("\"Random walk\"");
    system ("pause");
    return 0;
}
