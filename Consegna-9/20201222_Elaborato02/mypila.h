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

//strutture collegate
typedef struct frutta{
    char *nome;
    int prezzo;
    struct frutta *next;
} FRUTTALINKED;

typedef FRUTTALINKED *ptr_frutta;


/****************************** PROTOTIPI ******************************/

int print1Menu();
int print2Menu();

SACCHETTO_STATICO* initPila_Sta (SACCHETTO_STATICO *);
bool TestPilaVuota1 (SACCHETTO_STATICO);
bool TestPilaPiena1 (SACCHETTO_STATICO);
void pushStatic(SACCHETTO_STATICO *);
void topStatic(SACCHETTO_STATICO *);
SACCHETTO_STATICO *popStatic(SACCHETTO_STATICO *);
void printAllStatic(SACCHETTO_STATICO *);

SACCHETTO_DINAMICO* initPila_Din(SACCHETTO_DINAMICO *);
bool TestPilaVuota2 (SACCHETTO_DINAMICO);
void PilaPiena (SACCHETTO_DINAMICO *);
void pushDinamic(SACCHETTO_DINAMICO *);
void topDinamic(SACCHETTO_DINAMICO *);
SACCHETTO_DINAMICO* popDinamic(SACCHETTO_DINAMICO *);
void printAllDinamic(SACCHETTO_DINAMICO *);

FRUTTALINKED *initPila(FRUTTALINKED *);
bool TestPilaVuota3(ptr_frutta );
void pushLinked(ptr_frutta *);
void topLinked (ptr_frutta);
ptr_frutta *popLinked(ptr_frutta*);
void printAllLinked(ptr_frutta);


