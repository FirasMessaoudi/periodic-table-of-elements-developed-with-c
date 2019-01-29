#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include <windows.h>
#include "ELTPRIM.H"
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
ELEMENT_ATM elementCreer()
{
	ELEMENT_ATM e=(ELEMENT_ATM)(malloc(sizeof(atome)));
	e->num=0;
	e->masse=0;
	strcpy(e->symbole,"\0");
	(e->etat)=NULL;
	return e;
}
void elementLire(ELEMENT_ATM *e){
	printf("donner le numero atomique du noyau pere : \n");
	scanf("%d",&((*e)->num));
	printf("donner la masse molaire : \n");
	scanf("%lf",&((*e)->masse));
	printf("donner son symbole : \n");
	scanf("%s",(*e)->symbole);
	fflush(stdin);
	printf("donner son etat : \n");
	scanf("%c",&((*e)->etat));
}
void elementAfficher(ELEMENT_ATM e)
{
	if(e->etat=='G'){
		color(2,0);
	if(e->masse==(int)e->masse)
	printf("%d %s [%.0lf] \n",e->num,e->symbole,e->masse);
	else
		printf("%d %s %.4lf \n",e->num,e->symbole,e->masse);
	color(15,0);
	}
	
	if(e->etat=='S'){
		color(3,0);
	if(e->masse==(int)e->masse)
	printf("%d %s [%.0lf] \n",e->num,e->symbole,e->masse);
	else
		printf("%d %s %.4lf \n",e->num,e->symbole,e->masse);
	color(15,0);
	}
	
	if(e->etat=='L'){
		color(4,0);
	if(e->masse==(int)e->masse)
	printf("%d %s [%.0lf] \n",e->num,e->symbole,e->masse);
	else
		printf("%d %s %.4lf \n",e->num,e->symbole,e->masse);
	color(15,0);
	}
	if(e->etat=='Y'){
		color(15,0);
	if(e->masse==(int)e->masse)
	printf("%d %s [%.0lf] \n",e->num,e->symbole,e->masse);
	else
		printf("%d %s %.4lf \n",e->num,e->symbole,e->masse);
	color(15,0);
	}
}





void elementAffichernum(ELEMENT_ATM e)
{

	if(e->num<10 && strlen(e->symbole)==1 && e->masse<10)
	printf("%d      ",e->num);
	
	
	else if(e->num<10 && strlen(e->symbole)==2 && e->masse<10)
	printf("%d      ",e->num);
	
	
    else if(e->num<10 && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf("%d       ",e->num);
	
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf("%d      ",e->num); 
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100))
	if((int)e->masse !=e->masse)
	printf("%d       ",e->num);
	else
	printf("%d    ",e->num);
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse<100 && e->masse>=10))
	if((int)e->masse!=e->masse)
	printf("%d      ",e->num);
	else
	printf("%d   ",e->num);
	
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=100))
	printf("%d       ",e->num);
	
	
	else if((e->num>99) && strlen(e->symbole)==3 && (e->masse>=100))
	printf("%d   ",e->num);
	
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf("%d       ",e->num);
	
	
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf("%d     ",e->num);
	
	
	else if((e->num>=100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf("%d   ",e->num);
	
	
}

void elementAffichersymbole(ELEMENT_ATM e)
{

	
	if(e->num<10 && strlen(e->symbole)==1 && e->masse<10)
	printf(" %s     ",e->symbole);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf(" %s      ",e->symbole);//hedhi zyeda


	else if(e->num<10 && strlen(e->symbole)==2 && e->masse<10)
	printf(" %s    ",e->symbole);


    else if(e->num<10 && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf(" %s      ",e->symbole);



	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100) )
	if((int)e->masse !=e->masse)
	printf(" %s      ",e->symbole);
    else
   	printf(" %s   ",e->symbole);
     
     
	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse<100 && e->masse>=10))
	if((int)e->masse!=e->masse)
	printf(" %s     ",e->symbole);
	else
	printf(" %s  ",e->symbole);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=100))
	printf(" %s       ",e->symbole);


	else if((e->num>99) && strlen(e->symbole)==3 && (e->masse>=100))
	printf(" %s  ",e->symbole);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf(" %s      ",e->symbole);


	else if((e->num>=100) && strlen(e->symbole)==2 && ( e->masse>=100))
	printf(" %s   ",e->symbole);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && ( e->masse<100 && e->masse>=10))
	printf(" %s   ",e->symbole);

}

void elementAffichermasse(ELEMENT_ATM e)
{

    if(e->num<10 && strlen(e->symbole)==1 && e->masse<10)
	printf("%.4lf ",e->masse);


	else if(e->num<10 && strlen(e->symbole)==2 && e->masse<10)
	printf("%.4lf ",e->masse);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf("%.4lf ",e->masse);


    else if(e->num<10 && strlen(e->symbole)==1 && (e->masse>=10 && e->masse<100))
	printf("%.4lf ",e->masse);



	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100) )
	if((int)e->masse !=e->masse)
	printf("%.4lf ",e->masse);
    else
    printf("[%.0lf] ",e->masse);
    

	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse<100 && e->masse>=10) )
	if((int)e->masse!=e->masse)
	printf("%.4lf ",e->masse);
	else
	printf("[%.0lf] ",e->masse);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==1 && (e->masse>=100))
	printf("%.4lf ",e->masse);


	else if((e->num>99) && strlen(e->symbole)==3 && (e->masse>=100))
	printf("[%.0lf] ",e->masse);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf("%.4lf ",e->masse);



	else if((e->num>=100) && strlen(e->symbole)==2 && (e->masse>=100))
	printf("[%.0lf] ",e->masse);


	else if((e->num>9 && e->num<100) && strlen(e->symbole)==2 && (e->masse<100 && e->masse>=10))
	printf("[%.0lf] ",e->masse);
	
	
	
}








void elementDetruire(ELEMENT_ATM e)
{
	free(e);
}
int elementComparer(ELEMENT_ATM e,ELEMENT_ATM e1)
{
	return((e->num)-(e1->num));
}
void elementAffecter(ELEMENT_ATM *e,ELEMENT_ATM e1)
{
	*e=e1;
}
void elementCopier(ELEMENT_ATM *e,ELEMENT_ATM e1)
{
memcpy(*e,e1,sizeof(atome));
}



