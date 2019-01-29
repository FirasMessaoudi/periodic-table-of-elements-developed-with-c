#ifndef _LSTPRIM_H
#define _LSTPRIM_H
#include "LSTSDD.H"
#include "ELTPRIM.H"
NOEUD noeudCreer(ELEMENT_ATM);
void noeudDetruire(NOEUD);
int estVide(LISTE_ATM);
int estSaturee(LISTE_ATM);
int listeTaille(LISTE_ATM);
void inserer (LISTE_ATM, ELEMENT_ATM , int);
int supprimer (LISTE_ATM, int);
ELEMENT_ATM recuperer(LISTE_ATM, int);
LISTE_ATM listeCreer(void);
void listeDetruire(LISTE_ATM);
void listeAffichersymbole(LISTE_ATM );
void listeAffichermasse(LISTE_ATM );
void listeAffichernum(LISTE_ATM );
void listeAfficher(LISTE_ATM);
LISTE_ATM listeCopier(LISTE_ATM);
int listeComparer (LISTE_ATM,LISTE_ATM );
#endif
