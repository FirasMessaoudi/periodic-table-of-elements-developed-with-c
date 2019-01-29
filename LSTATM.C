#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include "LSTPRIM.H"
#include <windows.h>
void Col(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

NOEUD noeudCreer(ELEMENT_ATM e)
{NOEUD n ;
n =(NOEUD)malloc(sizeof(structNoeud));
if(!n)
printf ("\nPlus d'espace");
else
{
elementAffecter(&n->info, e);
n->suivant = NULL;
}                                                                 //LISTE_ATM
return n;
}




void noeudDetruire(NOEUD n){
elementDetruire(n->info);
free(n);
}




int estVide(LISTE_ATM L) {
return (L->lg == 0);
}





int estSaturee(LISTE_ATM L) {
NOEUD temp;
int saturee = 1; /* on suppose mémoire saturée */
temp = (NOEUD) malloc ( sizeof ( structNoeud ) );
if(temp != NULL) {
saturee = 0; /* mémoire non saturée */
free(temp);
}
return saturee;
}






int listeTaille(LISTE_ATM L) {
return (L->lg);
}







void inserer (LISTE_ATM L, ELEMENT_ATM e, int pos){
int i;
NOEUD n, p, q; // c des pointeurs sur noeud c equivalent à: // structNoeud * n
if (estSaturee(L)){
printf ("\nListe saturée");
}
else if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
}
else {
n=noeudCreer (e); /*on est sûr que la réservation va se faire car la mémoire n'est pas saturée*/
if (pos == 1) /*insertion en tête de liste*/
{
n->suivant=L->tete;
L->tete = n;
}
else /*cas général (pos > 1) */
{
q= L->tete;
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
// q désigne l’élément de rang pos et p son prédécesseur
p->suivant=n;
n->suivant=q;
}
(L->lg)++;
}
}










int supprimer (LISTE_ATM L, int pos ){
int i;
int succee=1;
NOEUD p, q;
if (estVide(L)) {
printf ("\nListe vide");
succee=0;
}
else {
if ((pos < 1) || (pos > L->lg))
{
printf ("\nPosition invalide");
succee=0;
}
else
{
q = L->tete;
/*suppression en tête de liste*/
if (pos == 1) L->tete=L->tete->suivant;
else { /*cas général (pos > 1) */
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
p->suivant=q->suivant;
}
// q désigne l’élément de rang pos et p son prédécesseur
noeudDetruire(q);
(L->lg)--;
}
}
return succee;
}








ELEMENT_ATM recuperer(LISTE_ATM L, int pos) {
/* s'il ya une erreur on affiche un message et on retourne un element vide */
ELEMENT_ATM elt= elementCreer();
int i;
NOEUD p;
if (estVide(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");
else {
p= L->tete;
for (i=1; i<pos; i++)
p = p->suivant;
elementAffecter(&elt,p->info);
}
}
return(elt);
}








LISTE_ATM listeCreer(void) {
LISTE_ATM L;
L=(LISTE_ATM)malloc(sizeof(laStruct));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg = 0;
L->tete = NULL; /* initialiser la tête */
}
return(L);
}








void listeDetruire(LISTE_ATM L){
int i;
NOEUD p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->suivant;
noeudDetruire(p);
}
free(L);
}

void listeAfficher(LISTE_ATM L){
int i;
NOEUD p=L->tete;
for(i=1;i<=listeTaille(L);i++)
{
	elementAfficher(p->info);
	printf("\n\n");
	p=p->suivant;
}
}



void listeAffichernum(LISTE_ATM L){
int i;
NOEUD p=L->tete;
for(i=1;i<=listeTaille(L);i++)
{
	if(p->info->etat=='G'){
	Col(2,0);
	elementAffichernum(p->info);
	Col(15,0);
    }
  if(p->info->etat=='S')
  {
  	Col(3,0);
	elementAffichernum(p->info);
	Col(15,0);
  }
  if(p->info->etat=='L')
  {
  	Col(4,0);
	elementAffichernum(p->info);
	Col(15,0);
  }
  if(p->info->etat=='Y')
  {
  	Col(15,0);
	elementAffichernum(p->info);
	Col(15,0);
  }
	p=p->suivant;
}
}

void listeAffichermasse(LISTE_ATM L){
int i;
NOEUD p=L->tete;
for(i=1;i<=listeTaille(L);i++)
{
if(p->info->etat=='G'){
	Col(2,0);
	elementAffichermasse(p->info);
	Col(15,0);
    }
if(p->info->etat=='S')
  {
  	Col(3,0);
	elementAffichermasse(p->info);
	Col(15,0);
  }
  if(p->info->etat=='L')
  {
  	Col(4,0);
	elementAffichermasse(p->info);
	Col(15,0);
  }
  if(p->info->etat=='Y')
  {
  	Col(15,0);
	elementAffichermasse(p->info);
	Col(15,0);
  }
	p=p->suivant;
}
}

void listeAffichersymbole(LISTE_ATM L){
int i;
NOEUD p=L->tete;
for(i=1;i<=listeTaille(L);i++)
{
	if(p->info->etat=='G'){
	Col(2,0);
	elementAffichersymbole(p->info);
	Col(15,0);
    }
   if(p->info->etat=='S')
  {
  	Col(3,0);
	elementAffichersymbole(p->info);
	Col(15,0);
  }
  if(p->info->etat=='L')
  {
  	Col(4,0);
	elementAffichersymbole(p->info);
	Col(15,0);
  }
  if(p->info->etat=='Y')
  {
  	Col(15,0);
	elementAffichersymbole(p->info);
	Col(15,0);
  }
	p=p->suivant;
}
}


LISTE_ATM listeCopier(LISTE_ATM L){
LISTE_ATM LR = listeCreer();
int i;
ELEMENT_ATM elt;
for(i = 1;i <= listeTaille(L); i++) {
elt=elementCreer();
elementCopier(&elt, recuperer(L,i));
inserer(LR,elt, i);
}
return LR;
}







int listeComparer (LISTE_ATM L1,LISTE_ATM L2 )
{
int test= 1;
int i=1;
if (listeTaille(L1) != listeTaille(L2)) test= 0;
while ((i<=listeTaille(L1)) && (test)) {
if (elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
test=0;
i++;
}
return test;
}

