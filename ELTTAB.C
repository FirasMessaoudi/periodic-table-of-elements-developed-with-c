#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "TABPRIM.H"
#include "LSTPRIM.H"
#include "ELTPRIM.H"
#include <windows.h>
void Couleur(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

ELEMENT_TAB tabCreer()
{
	int i,j;
	ELEMENT_TAB E=(ELEMENT_TAB)(malloc(sizeof(TAB)));
	for(i=0;i<7;i++)
	for(j=0;j<18;j++)
	E->T[i][j]=listeCreer();
	return E;
}
void tabAfficher(ELEMENT_TAB E)
{
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<18;j++){
		if(i==2 && j==4)
		printf("          ");
		if(i==0 && j==4)
		printf("                 ");
	    if(i==1 && j==4)
		printf("            ");

        if(estVide(E->T[i][j]))
		 printf("       ");
		 else if(i==5 && j==2)
		 {
		 	Couleur(8,0);
		 printf("57-71  ");
		 Couleur(15,0);
	    }
		 else if(i==6 && j==2)
		 {
	     Couleur(3,0);
		 printf("89-103 ");
		 Couleur(15,0);
	     }
		 else
		listeAffichernum(E->T[i][j]);
	}
		printf("\n");

	    	for(j=0;j<18;j++){
	     if(i==1 && j==4)
		printf("            ");
			if(i==2 && j==4)
		printf("          ");
			if(i==0 && j==4)
		printf("                 ");
         if(estVide(E->T[i][j]))
		 printf("       ");
		 else if(i==5 && j==2)
		 {
		Couleur(8,0);
		 printf("La-Lu  ");
		 Couleur(8,0);
	    }
		 else if(i==6 && j==2)
		 {
	    Couleur(3,0);
		 printf("Ac-Lr  ");
		 Couleur(15,0);
	    }
		 else
		listeAffichersymbole(E->T[i][j]);
	}
		printf("\n");

	    	for(j=0;j<18;j++){
	     if(i==1 && j==4)
		printf("            ");
	    		if(i==2 && j==4)
		printf("          ");
		if(i==0 && j==4)
		printf("                 ");

         if(estVide(E->T[i][j]))
		 printf("       ");
		 else{
		 	if(i==5 && j==2)
		     printf("     ");
		     else if(i==6 && j==2)
		     printf("       ");
		     else
		listeAffichermasse(E->T[i][j]);
	}
	}
		printf("\n");

   printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}
   printf("            ");
   listeAffichernum(E->T[5][2]);
   printf("\n");
   Couleur(9,0);
   printf("LANTHANIDES ");
   Couleur(15,0);
   listeAffichersymbole(E->T[5][2]);
   printf("\n");
   printf("            ");
   listeAffichermasse(E->T[5][2]);
   printf("\n\n");


   printf("            ");
   listeAffichernum(E->T[6][2]);
   printf("\n");
   Couleur(9,0);
   printf("ACTINIDES   ");
   Couleur(15,0);
   listeAffichersymbole(E->T[6][2]);
   printf("\n");
   printf("            ");
   listeAffichermasse(E->T[6][2]);
   printf("\n\n");
   Couleur(3,0);
   printf("\nSolide    ");
   Couleur(2,0);
   printf("Gaz      ");
   Couleur(4,0);
   printf("Liquide     ");
   Couleur(15,0);
   printf("Synthetique\n\n");
}
void tabDetruire(ELEMENT_TAB E)
{
   int i,j;
   for(i=0;i<7;i++)
   for(j=0;j<18;j++)
   listeDetruire(E->T[i][j]);
   free(E);
}

