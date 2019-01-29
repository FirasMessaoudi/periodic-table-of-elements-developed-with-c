#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.H"
void elementLire(ELEMENT_ATM*);
void elementAffichernum(ELEMENT_ATM);
void elementAffichermasse(ELEMENT_ATM);
void elementAffichersymbole(ELEMENT_ATM );
void elementAfficher(ELEMENT_ATM);
void elementAffecter(ELEMENT_ATM*,ELEMENT_ATM);
void elementCopier(ELEMENT_ATM*,ELEMENT_ATM);
int elementComparer(ELEMENT_ATM,ELEMENT_ATM);
ELEMENT_ATM elementCreer();
void elementDetruire(ELEMENT_ATM);
#endif
