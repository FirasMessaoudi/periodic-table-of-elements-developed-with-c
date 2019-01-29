#ifndef LSTATM_H_INCLUDED
#define LSTATM_H_INCLUDED
#include "ELTPRIM.H"
typedef struct structNoeud {
ELEMENT_ATM info;
struct structNoeud * suivant;
} structNoeud, * NOEUD;
typedef struct {
NOEUD tete;
int lg;
}laStruct,*LISTE_ATM;
#endif

