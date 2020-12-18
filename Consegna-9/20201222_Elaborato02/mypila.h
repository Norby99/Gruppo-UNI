#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_PILA 3

/****************************** STRUTTURE ******************************/

typedef struct {
    char *nome;
    int prezzo;
} FRUTTA;

// allocazione statica
typedef struct {
    FRUTTA spesa [MAX_PILA];
    int pos;
} SACCHETTO_STATICO;

// allocazione dinamica
typedef struct {
    FRUTTA *spesa;
    int pos, dim;
} SACCHETTO_DINAMICO;

/*typedef struct frutta{
    char *nome;
    struct frutta *next;
} FRUTTALINKED;
*/

/****************************** PROTOTIPI ******************************/

int print1Menu();
int print2Menu();

bool TestPilaVuota1 (SACCHETTO_STATICO);
bool TestPilaPiena1 (SACCHETTO_STATICO);
void pushStatic(SACCHETTO_STATICO *);
void topStatic(SACCHETTO_STATICO *);
SACCHETTO_STATICO *popStatic(SACCHETTO_STATICO *);

void initPila(SACCHETTO_DINAMICO *);
bool TestPilaVuota2 (SACCHETTO_DINAMICO);
void PilaPiena (SACCHETTO_DINAMICO *);
void pushDinamic(SACCHETTO_DINAMICO *);
void topDinamic(SACCHETTO_DINAMICO *);
void popDinamic(SACCHETTO_DINAMICO *);
