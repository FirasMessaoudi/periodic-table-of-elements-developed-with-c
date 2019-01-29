#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "TABPRIM.H"
#include "LSTPRIM.H"
#include "ELTPRIM.H"
#include <windows.h>
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
ELEMENT_TAB E;
char *recherche_atome(ELEMENT_TAB E, int z){
	char *res=(char*)(malloc(sizeof(char)));
	int i=0,j,trouve=0;
	while(i<7 && trouve==0)
	{
		j=0;
		while(j<18 && trouve==0)
		{
		NOEUD p=NULL;
		p=E->T[i][j]->tete;
		while(p!=NULL && trouve==0)
		{
			if(z==p->info->num){
			trouve=1;
			strcpy(res,p->info->symbole);
			}
			else
			p=p->suivant;
		}
		j++;

	}
	i++;
}
return res;
}
ELEMENT_ATM help(int a,const char *b,double c, char d)
{
	ELEMENT_ATM e=elementCreer();
		e->num=a;
	strcpy(e->symbole,b);
	e->masse=c;
	e->etat=d;
	return e;
}
LISTE_ATM Gaz(ELEMENT_TAB E) //LIstes des molecules instables
{
	LISTE_ATM lg=listeCreer();
	int i,j,pos=1;
	for(i=0;i<7;i++)
	for(j=0;j<18;j++)
	{
		NOEUD p=E->T[i][j]->tete;
		while(p!=NULL)
		{

			if('G'==p->info->etat)
			{
				ELEMENT_ATM e=elementCreer();
				elementCopier(&e,p->info);
				inserer(lg,e,pos);
				pos++;
			}
			p=p->suivant;
		}
	}
	return lg;
}


LISTE_ATM lourd(ELEMENT_TAB E) //LIstes des molecules instables
{
	LISTE_ATM lo=listeCreer();
	int i,j,pos=1;
	for(i=0;i<7;i++)
	for(j=0;j<18;j++)
	{
		NOEUD p=E->T[i][j]->tete;
		while(p!=NULL)
		{

			if(p->info->num>104)
			{
				ELEMENT_ATM e=elementCreer();
				elementCopier(&e,p->info);
				inserer(lo,e,pos);
				pos++;
			}
			p=p->suivant;
		}
	}
	return lo;
}


LISTE_ATM radioactif(ELEMENT_TAB E) //LIstes des molecules instables
{
	LISTE_ATM lrad=listeCreer();
	int i,j,pos=1;
	for(i=0;i<7;i++)
	for(j=0;j<18;j++)
	{
		NOEUD p=E->T[i][j]->tete;
		while(p!=NULL)
		{

			if(strcmp("Tc",p->info->symbole)==0 || strcmp("Pm",p->info->symbole)==0 || p->info->num>=84)
			{
				ELEMENT_ATM e=elementCreer();
				elementCopier(&e,p->info);
				inserer(lrad,e,pos);
				pos++;
			}
			p=p->suivant;
		}
	}
	return lrad;
}

LISTE_ATM Instables(ELEMENT_TAB E) //LIstes des molecules instables
{
	LISTE_ATM li=listeCreer();
	int i,j,pos=1;
	for(i=0;i<7;i++)
	for(j=0;j<18;j++)
	{
		NOEUD p=E->T[i][j]->tete;
		while(p!=NULL)
		{
			int tmp=(int)(p->info->masse);
			if(tmp==p->info->masse)
			{
				ELEMENT_ATM e=elementCreer();
				elementCopier(&e,p->info);
				inserer(li,e,pos);
				pos++;
			}
			p=p->suivant;
		}
	}
	return li;
}


double Ar(ELEMENT_TAB E, char * s)
{
	  	int i=0,j,trouve=0;
	double mol=0;
	while(i<7 && trouve==0)
	{
		j=0;
		while(j<18 && trouve==0)
		{
		NOEUD p=NULL;
		p=E->T[i][j]->tete;
		while(p!=NULL && trouve==0)
		{
			if(strcmp(s,p->info->symbole)==0){
			trouve=1;
			mol=p->info->masse;
			}
			else
			p=p->suivant;
		}
		j++;

	}
	i++;
}

 return mol;
}














double M_C8H10N4O2 (ELEMENT_TAB E) //masse molaire de la molecule du cafeine
{
	/*char c[3],h[3],n[3],o[3];
	strcpy(c,"C");
	strcpy(h,"H");
	strcpy(n,"N");
	strcpy(o,"O");*/
double mol=(Ar(E,"C")*8+Ar(E,"H")*10+Ar(E,"N")*4+Ar(E,"O")*2);
return mol;
}




double n_C8H10N4O2() //nombre de mol dans la molecule de cafeine
{
	double x=M_C8H10N4O2(E);
	return (10/x);
}




double M (ELEMENT_TAB E, char * molecule) //masse molaire d'une molecule quleconque
{
	int i=0,coef;
	double mol=0;
	while(i<strlen(molecule))
	{
		char atome[5]={0};
		int c=0;
		if(molecule[i]>='A'&& molecule[i]<='Z')
		{
			if((molecule[i+1]>='a'&&molecule[i+1]<='z') && (molecule[i+2]>='a'&&molecule[i+2]<='z')){
			atome[c]=molecule[i];
			c++;
			atome[c]=molecule[i+1];
			c++;
			atome[c]=molecule[i+2];
			c++;
			}
			else if(molecule[i+1]>='a'&&molecule[i+1]<='z')
		{
			atome[c]=molecule[i];
			c++;
			atome[c]=molecule[i+1];
			c++;
		}
		else
		{
			atome[c]=molecule[i];
			c++;
		}
			if(strlen(atome)==1)
			{
	            int	j=i+1;
				 int cp=0,trouve=0;
				char nb[5]={0};
				while(j<strlen(molecule)&&trouve==0)
				{
					if(molecule[j]>='0'&&molecule[j]<='9')
					{
						nb[cp]=molecule[j];
						cp++;
						j++;
					}
					else
					trouve=1;
				}
				coef=atoi(nb);
				mol+=Ar(E,atome)*coef;
			   i=i+strlen(nb)+1;
			}
			else if(strlen(atome)==2){
		    int j=i+2;
				 int cp=0,trouve=0;
				char nb[5]={0};
				while(j<strlen(molecule)&&trouve==0)
				{
					if(molecule[j]>='0'&&molecule[j]<='9')
					{
						nb[cp]=molecule[j];
						cp++;
						j++;
					}
					else
					trouve=1;
				}
				coef=atoi(nb);
				mol+=Ar(E,atome)*coef;
			   i=i+strlen(nb)+2;
			}
			else{
			int j=i+3;
				 int cp=0,trouve=0;
				char nb[5]={0};
				while(j<strlen(molecule)&&trouve==0)
				{
					if(molecule[j]>='0'&&molecule[j]<='9')
					{
						nb[cp]=molecule[j];
						cp++;
						j++;
					}
					else
					trouve=1;
				}
				coef=atoi(nb);
				mol+=Ar(E,atome)*coef;
			   i=i+strlen(nb)+3;
			}
		}
	}
	return mol;
}


ELEMENT_ATM noyauFils(ELEMENT_ATM X,ELEMENT_TAB E,int type_radio)
{
	double A;
	int Z;
		ELEMENT_ATM Y=elementCreer();
	if(type_radio==1)
	{
		A=(X->masse)-4;
		Z=(X->num)-2;
		Y->num=Z;
		Y->masse=A;
		strcpy(Y->symbole,recherche_atome(E,Z));
	}
	else if(type_radio==2)
	{
		A=(X->masse);
		Z=(X->num)+1;
		Y->num=Z;
		Y->masse=A;
    strcpy(Y->symbole,recherche_atome(E,Z));
	}
	else{
		A=(X->masse);
		Z=(X->num)-1;
		Y->num=Z;
		Y->masse=A;
	strcpy(Y->symbole,recherche_atome(E,Z));
	}
	return Y;
}






int main(int argc, char** argv) {



		E=tabCreer();


	ELEMENT_ATM e1=elementCreer();
	e1=help(1,"H",1.0079,'G');
	inserer(E->T[0][0],e1,1);

     	ELEMENT_ATM e2=elementCreer();
	e2=help(2,"He",4.0025,'G');
	inserer(E->T[0][17],e2,1);



    	ELEMENT_ATM e3=elementCreer();
	e3->num=3;
	strcpy(e3->symbole,"Li");
	e3->masse=6.941;
	e3->etat='S';
	inserer(E->T[1][0],e3,1);


		ELEMENT_ATM e4=elementCreer();
	e4->num=4;
	strcpy(e4->symbole,"Be");
	e4->masse=9.0122;
	e4->etat='S';
	inserer(	E->T[1][1],e4,1);


		ELEMENT_ATM e5=elementCreer();
	e5->num=5;
	strcpy(e5->symbole,"B");
	e5->masse=10.811;
	e5->etat='S';
	inserer(	E->T[1][12],e5,1);


		ELEMENT_ATM e6=elementCreer();
	e6->num=6;
	strcpy(e6->symbole,"C");
	e6->masse=12.011;
	e6->etat='S';
	inserer(	E->T[1][13],e6,1);



		ELEMENT_ATM e7=elementCreer();
	e7->num=7;
	strcpy(e7->symbole,"N");
	e7->masse=14.007;
	e7->etat='G';
	inserer(	E->T[1][14],e7,1);


		ELEMENT_ATM e8=elementCreer();
	e8->num=8;
	strcpy(e8->symbole,"O");
	e8->masse=15.999;
	e8->etat='G';
	inserer(E->T[1][15],e8,1);



		ELEMENT_ATM e9=elementCreer();
	e9->num=9;
	strcpy(e9->symbole,"F");
	e9->masse=18.998;
	e9->etat='G';
	inserer(E->T[1][16],e9,1);


		ELEMENT_ATM e10=elementCreer();
	e10->num=10;
	strcpy(e10->symbole,"Ne");
	e10->masse=20.180;
	e10->etat='G';
	inserer(E->T[1][17],e10,1);


		ELEMENT_ATM e11=elementCreer();
	e11->num=11;
	strcpy(e11->symbole,"Na");
	e11->masse=22.990;
	e11->etat='S';
	inserer(E->T[2][0],e11,1);


		ELEMENT_ATM e12=elementCreer();
	e12->num=12;
	strcpy(e12->symbole,"Mg");
	e12->masse=24.305;
	e12->etat='S';
	inserer(E->T[2][1],e12,1);



		ELEMENT_ATM e13=elementCreer();
	e13->num=13;
	strcpy(e13->symbole,"Al");
	e13->masse=26.982;
	e13->etat='S';
	inserer(E->T[2][12],e13,1);


		ELEMENT_ATM e14=elementCreer();
	e14->num=14;
	strcpy(e14->symbole,"Si");
	e14->masse=28.086;
	e14->etat='S';
	inserer(E->T[2][13],e14,1);



		ELEMENT_ATM e15=elementCreer();
	e15->num=15;
	strcpy(e15->symbole,"P");
	e15->masse=30.974;
	e15->etat='S';
	inserer(E->T[2][14],e15,1);


		ELEMENT_ATM e16=elementCreer();
	e16->num=16;
	strcpy(e16->symbole,"S");
	e16->masse=32.065;
	e16->etat='S';
	inserer(E->T[2][15],e16,1);


		ELEMENT_ATM e17=elementCreer();
	e17->num=17;
	strcpy(e17->symbole,"Cl");
	e17->masse=35.453;
	e17->etat='G';
	inserer(E->T[2][16],e17,1);


		ELEMENT_ATM e18=elementCreer();
	e18->num=18;
	strcpy(e18->symbole,"Ar");
	e18->masse=39.948;
	e18->etat='G';
	inserer(E->T[2][17],e18,1);



	ELEMENT_ATM e19=elementCreer();
	e19=help(19,"K",39.098,'S');
	inserer(E->T[3][0],e19,1);


	ELEMENT_ATM e20=elementCreer();
	e20=help(20,"Ca",40.078,'S');
	inserer(E->T[3][1],e20,1);


	ELEMENT_ATM e21=elementCreer();
	e21=help(21,"Sc",40.956,'S');
	inserer(E->T[3][2],e21,1);


	ELEMENT_ATM e22=elementCreer();
	e22=help(22,"Ti",47.867,'S');
	inserer(E->T[3][3],e22,1);


	ELEMENT_ATM e23=elementCreer();
	e23=help(23,"V",50.9415,'S');
	inserer(E->T[3][4],e23,1);


	ELEMENT_ATM e24=elementCreer();
	e24=help(24,"Cr",51.9961,'S');
	inserer(E->T[3][5],e24,1);


	ELEMENT_ATM e25=elementCreer();
	e25=help(25,"Mn",54.938049,'S');
	inserer(E->T[3][6],e25,1);


	ELEMENT_ATM e26=elementCreer();
	e26=help(26,"Fe",55.845,'S');
	inserer(E->T[3][7],e26,1);


	ELEMENT_ATM e27=elementCreer();
	e27=help(27,"Co",58.9332,'S');
		inserer(E->T[3][8],e27,1);


	ELEMENT_ATM e28=elementCreer();
	e28=help(28,"Ni",58.6934,'S');
	inserer(E->T[3][9],e28,1);


	ELEMENT_ATM e29=elementCreer();
	e29=help(29,"Cu",63.546,'S');
	inserer(E->T[3][10],e29,1);


	ELEMENT_ATM e30=elementCreer();
	e30=help(30,"Zn",65.409,'S');
	inserer(E->T[3][11],e30,1);


	ELEMENT_ATM e31=elementCreer();
	e31=help(31,"Ga",69.723,'S');
	inserer(E->T[3][12],e31,1);


	ELEMENT_ATM e32=elementCreer();
	e32=help(32,"Ge",72.64,'S');
	inserer(E->T[3][13],e32,1);


	ELEMENT_ATM e33=elementCreer();
	e33=help(33,"As",74.9216,'S');
	inserer(E->T[3][14],e33,1);


	ELEMENT_ATM e34=elementCreer();
	e34=help(34,"Se",78.96,'S');
	inserer(E->T[3][15],e34,1);


	ELEMENT_ATM e35=elementCreer();
	e35=help(35,"Br",79.904,'L');
	inserer(E->T[3][16],e35,1);


	ELEMENT_ATM e36=elementCreer();
	e36=help(36,"Kr",83.798,'G');
	inserer(E->T[3][17],e36,1);


		ELEMENT_ATM e37=elementCreer();
	e37=help(37,"Rb",85.4678,'S');
	inserer(E->T[4][0],e37,1);


		ELEMENT_ATM e38=elementCreer();
	e38=help(38,"Sr",87.62,'S');
	inserer(E->T[4][1],e38,1);


		ELEMENT_ATM e39=elementCreer();
	e39=help(39,"Y",88.90585,'S');
	inserer(E->T[4][2],e39,1);


		ELEMENT_ATM e40=elementCreer();
	e40=help(40,"Zr",91.224,'S');
	inserer(E->T[4][3],e40,1);


		ELEMENT_ATM e41=elementCreer();
	e41=help(41,"Nb",92.90638,'S');
	inserer(E->T[4][4],e41,1);


		ELEMENT_ATM e42=elementCreer();
	e42=help(42,"Mo",95.94,'S');
	inserer(E->T[4][5],e42,1);


		ELEMENT_ATM e43=elementCreer();
	e43=help(43,"Tc",98,'Y');
	inserer(E->T[4][6],e43,1);


		ELEMENT_ATM e44=elementCreer();
	e44=help(44,"Ru",101.07,'S');
	inserer(E->T[4][7],e44,1);


		ELEMENT_ATM e45=elementCreer();
	e45=help(45,"Rh",102.9055,'S');
	inserer(E->T[4][8],e45,1);


		ELEMENT_ATM e46=elementCreer();
	e46=help(46,"Pd",106.42,'S');
	inserer(E->T[4][9],e46,1);


		ELEMENT_ATM e47=elementCreer();
	e47=help(47,"Ag",107.8682,'S');
	inserer(E->T[4][10],e47,1);


		ELEMENT_ATM e48=elementCreer();
	e48=help(48,"Cd",112.411,'S');
	inserer(E->T[4][11],e48,1);


		ELEMENT_ATM e49=elementCreer();
	e49=help(49,"In",114.818,'S');
	inserer(E->T[4][12],e49,1);


		ELEMENT_ATM e50=elementCreer();
	e50=help(50,"Sn",118.71,'S');
	inserer(E->T[4][13],e50,1);


		ELEMENT_ATM e51=elementCreer();
	e51=help(51,"Sb",121.76,'S');
	inserer(E->T[4][14],e51,1);


		ELEMENT_ATM e52=elementCreer();
	e52=help(52,"Te",127.6,'S');
	inserer(E->T[4][15],e52,1);


		ELEMENT_ATM e53=elementCreer();
	e53=help(53,"I",126.90447,'S');
	inserer(E->T[4][16],e53,1);


		ELEMENT_ATM e54=elementCreer();
	e54=help(54,"Xe",131.293,'G');
	inserer(E->T[4][17],e54,1);

		ELEMENT_ATM e55=elementCreer();
	e55=help(55,"Cs",132.91,'S');
	inserer(E->T[5][0],e55,1);


	ELEMENT_ATM e56=elementCreer();
	e56=help(56,"Ba",137.327,'S');
	inserer(E->T[5][1],e56,1);


    ELEMENT_ATM e57=elementCreer();
	e57=help(57,"La",138.9055,'S');
	inserer(E->T[5][2],e57,1);

    ELEMENT_ATM e58=elementCreer();
	e58=help(58,"Ce",140.116,'S');
	inserer(E->T[5][2],e58,2);


	 ELEMENT_ATM e59=elementCreer();
	e59=help(59,"Pr",140.91,'S');
	inserer(E->T[5][2],e59,3);


    ELEMENT_ATM e60=elementCreer();
	e60=help(60,"Nd",144.24,'S');
	inserer(E->T[5][2],e60,4);

	ELEMENT_ATM e61=elementCreer();
	e61=help(61,"Pm",145,'Y');
	inserer(E->T[5][2],e61,5);


	ELEMENT_ATM e62=elementCreer();
	e62=help(62,"Sm",150.36,'S');
	inserer(E->T[5][2],e62,6);


	ELEMENT_ATM e63=elementCreer();
	e63=help(63,"Eu",151.964,'S');
	inserer(E->T[5][2],e63,7);


	ELEMENT_ATM e64=elementCreer();
	e64=help(64,"Gd",157.25,'S');
	inserer(E->T[5][2],e64,8);


	ELEMENT_ATM e65=elementCreer();
	e65=help(65,"Tb",158.93,'S');
	inserer(E->T[5][2],e65,9);


	ELEMENT_ATM e66=elementCreer();
	e66=help(66,"Dy",162.5,'S');
	inserer(E->T[5][2],e66,10);


	ELEMENT_ATM e67=elementCreer();
	e67=help(67,"Ho",164.94,'S');
	inserer(E->T[5][2],e67,11);


	ELEMENT_ATM e68=elementCreer();
	e68=help(68,"Er",167.259,'S');
	inserer(E->T[5][2],e68,12);


	ELEMENT_ATM e69=elementCreer();
	e69=help(69,"Tm",168.94,'S');
	inserer(E->T[5][2],e69,13);


	ELEMENT_ATM e70=elementCreer();
	e70=help(70,"Yb",173.04,'S');
	inserer(E->T[5][2],e70,14);

	ELEMENT_ATM e71=elementCreer();
	e71=help(71,"Lu",174.967,'S');
	inserer(E->T[5][2],e71,15);


	ELEMENT_ATM e72=elementCreer();
	e72=help(72,"Hf",178.49,'S');
	inserer(E->T[5][3],e72,1);


	ELEMENT_ATM e73=elementCreer();
	e73=help(73,"Ta",180.9479,'S');
	inserer(E->T[5][4],e73,1);


	ELEMENT_ATM e74=elementCreer();
	e74=help(74,"W",183.84,'S');
	inserer(E->T[5][5],e74,1);


	ELEMENT_ATM e75=elementCreer();
	e75=help(75,"Re",186.207,'S');
	inserer(E->T[5][6],e75,1);


	ELEMENT_ATM e76=elementCreer();
	e76=help(76,"Os",190.23,'S');
	inserer(E->T[5][7],e76,1);


	ELEMENT_ATM e77=elementCreer();
	e77=help(77,"Ir",192.217,'S');
	inserer(E->T[5][8],e77,1);


	ELEMENT_ATM e78=elementCreer();
	e78=help(78,"Pt",195.078,'S');
	inserer(E->T[5][9],e78,1);



	ELEMENT_ATM e79=elementCreer();
    e79=help(79,"Au",196.97,'S');
    inserer(E->T[5][10],e79,1);


   ELEMENT_ATM e80=elementCreer();
   e80=help(80,"Hg",200.59,'L');
   inserer(E->T[5][11],e80,1);



  ELEMENT_ATM e81=elementCreer();
  e81=help(81,"TI",204.38,'S');
  inserer(E->T[5][12],e81,1);



  ELEMENT_ATM e82=elementCreer();
  e82=help(82,"Pb",207.2,'S');
  inserer(E->T[5][13],e82,1);




  ELEMENT_ATM e83=elementCreer();
  e83=help(83,"Bi",208.98,'S');
  inserer(E->T[5][14],e83,1);



  ELEMENT_ATM e84=elementCreer();
  e84=help(84,"Po",209,'S');
  inserer(E->T[5][15],e84,1);




  ELEMENT_ATM e85=elementCreer();
  e85=help(85,"At",210,'S');
  inserer(E->T[5][16],e85,1);



	ELEMENT_ATM e86=elementCreer();
	e86=help(86,"Rn",222,'G');
	inserer(E->T[5][17],e86,1);


    	ELEMENT_ATM e87=elementCreer();
	e87=help(87,"Fr",223,'S');
	inserer(E->T[6][0],e87,1);

    	ELEMENT_ATM e88=elementCreer();
	e88=help(88,"Ra",226,'S');
	inserer(E->T[6][1],e88,1);

    ELEMENT_ATM e89=elementCreer();
	e89=help(89,"Ac",227,'S');
	inserer(E->T[6][2],e89,1);

	 ELEMENT_ATM e90=elementCreer();
	e90=help(90,"Th",232.04,'S');
	inserer(E->T[6][2],e90,2);

	 ELEMENT_ATM e91=elementCreer();
	e91=help(91,"Pa",231.04,'S');
	inserer(E->T[6][2],e91,3);

	 ELEMENT_ATM e92=elementCreer();
	e92=help(92,"U",238.03,'S');
	inserer(E->T[6][2],e92,4);


	 ELEMENT_ATM e93=elementCreer();
	e93=help(93,"Np",237,'Y');
	inserer(E->T[6][2],e93,5);


	 ELEMENT_ATM e94=elementCreer();
	e94=help(94,"Pu",244,'Y');
	inserer(E->T[6][2],e94,6);


	 ELEMENT_ATM e95=elementCreer();
	e95=help(95,"Am",243,'Y');
	inserer(E->T[6][2],e95,7);


	 ELEMENT_ATM e96=elementCreer();
	e96=help(96,"Cm",247,'Y');
	inserer(E->T[6][2],e96,8);


	 ELEMENT_ATM e97=elementCreer();
	e97=help(97,"Bk",247,'Y');
	inserer(E->T[6][2],e97,9);


	 ELEMENT_ATM e98=elementCreer();
	e98=help(98,"Cf",251,'Y');
	inserer(E->T[6][2],e98,10);

	 ELEMENT_ATM e99=elementCreer();
	e99=help(99,"Es",252,'Y');
	inserer(E->T[6][2],e99,11);

	 ELEMENT_ATM e100=elementCreer();
	e100=help(100,"Fm",257,'Y');
	inserer(E->T[6][2],e100,12);


	 ELEMENT_ATM e101=elementCreer();
	e101=help(101,"Md",258,'Y');
	inserer(E->T[6][2],e101,13);


	 ELEMENT_ATM e102=elementCreer();
	e102=help(102,"No",259,'Y');
	inserer(E->T[6][2],e102,14);


	 ELEMENT_ATM e103=elementCreer();
	e103=help(103,"Lr",262,'Y');
	inserer(E->T[6][2],e103,15);

	ELEMENT_ATM e104=elementCreer();
	e104=help(104,"Rf",267,'Y');
	inserer(E->T[6][3],e104,1);

	ELEMENT_ATM e105=elementCreer();
	e105=help(105,"Db",268,'Y');
	inserer(E->T[6][4],e105,1);

	ELEMENT_ATM e106=elementCreer();
	e106=help(106,"Sg",271,'Y');
	inserer(E->T[6][5],e106,1);

	ELEMENT_ATM e107=elementCreer();
	e107=help(107,"Bh",272,'Y');
	inserer(E->T[6][6],e107,1);

	ELEMENT_ATM e108=elementCreer();
	e108=help(108,"Hs",277,'Y');
	inserer(E->T[6][7],e108,1);


	ELEMENT_ATM e109=elementCreer();
	e109=help(109,"Mt",276,'Y');
	inserer(E->T[6][8],e109,1);


	ELEMENT_ATM e110=elementCreer();
	e110=help(110,"Ds",281,'Y');
	inserer(E->T[6][9],e110,1);


	ELEMENT_ATM e111=elementCreer();
	e111=help(111,"Rg",280,'Y');
	inserer(E->T[6][10],e111,1);

		ELEMENT_ATM e112=elementCreer();
	e112=help(112,"Cn",285,'Y');
	inserer(E->T[6][11],e112,1);


	ELEMENT_ATM e113=elementCreer();
	e113=help(113,"Uut",284,'Y');
	inserer(E->T[6][12],e113,1);


		ELEMENT_ATM e114=elementCreer();
	e114=help(114,"Fl",284,'Y');
	inserer(E->T[6][13],e114,1);

		ELEMENT_ATM e115=elementCreer();
	e115=help(115,"Uup",288,'Y');
	inserer(E->T[6][14],e115,1);

		ELEMENT_ATM e116=elementCreer();
	e116=help(116,"Lv",291,'Y');
	inserer(E->T[6][15],e116,1);

		ELEMENT_ATM e117=elementCreer();
	e117=help(117,"Uus",294,'Y');
	inserer(E->T[6][16],e117,1);


		ELEMENT_ATM e118=elementCreer();
	e118=help(118,"Uuo",294,'Y');
	inserer(E->T[6][17],e118,1);





	int choix;
	char Menu;
	printf("\n        -----------LES ELEMENTS CHIMIQUES----------\n\n\n");
	printf("1-Afficher le tableau periodique des elements chimiques \n\n");
	printf("2-Afficher les elements qui sont a l'etat gazeux \n\n");
	printf("3-Afficher les elements chimiques lourds \n\n");
	printf("4-Afficher les atomes radioactifs \n\n");
	printf("5-Afficher les atomes instables \n\n");
	printf("6-Chercher la masse molaire d'un atome quelconque \n\n");
    printf("7-La masse molaire de la molecule du cafeiine C8H10N4O2 \n\n");
	printf("8-Le nombre de mole dans 10.0 g du cafeiine \n\n");
	printf("9-Calculer la masse molaire d'une molecule quelconque \n\n");
	printf("10-Trouver le noyau fils issu de la desintegration d'un noyau pere \n\n");
	    do{
	do{
		printf("Votre choix : ");
	scanf("%d",&choix);
    if(choix<1 || choix>10)
    printf("\nChoix incorrecte\n\n");
    }while(choix<1 || choix>10);
	if(choix==1){
		printf("\n");
		Color(12,0);
		printf("\t\t\t\t\t\tTABLEAU PERIODIQUE DES ELEMENTS\n\n");
		Color(15,0);
		  tabAfficher(E);
	}
	if(choix==2){
		printf("\nLes elements gazeux sont : \n\n");
			listeAfficher(Gaz(E));
	}
	if(choix==3){
		printf("\nLes elements lourds sont : \n\n");
			listeAfficher(lourd(E));
	}
	if(choix==4){
		printf("\nLes atomes radioactifs sont : \n\n");
			listeAfficher(radioactif(E));
	}
	if(choix==5){
		printf("\nLes atomes instables sont : \n\n");
			listeAfficher(Instables(E));
	}
	if(choix==6){
	char atm[5];
	printf("\ndonner un atome : ");
	scanf("%s",atm);
	if(Ar(E,atm)==0)
        printf("Atome introuvable!!!\n");
    else
        printf("\nla masse molaire de l'atome %s est %.4lf g/mol\n",atm,Ar(E,atm));
	}

	if(choix==7){
		printf("\nla masse molaire de molecule du cafeiine est %.4lf g/mol\n",M_C8H10N4O2(E));
	}
	if(choix==8){
			printf("\nLe nombre de mole dans la molecule du cafeiine est %.4lf mol\n",n_C8H10N4O2());
	}
    if(choix==9){
	char molec[12];
	printf("\ndonner une molecule pour calculer sa masse \n");
	scanf("%s",molec);
	printf("\nla masse molaire de cette molecule est %.4lf g/mol\n",M(E,molec));
	}
	if(choix==10){
		int type;
	ELEMENT_ATM X=elementCreer();
	elementLire(&X);
	printf("\ndonner le type du radioactivite : ");
	scanf("%d",&type);
	printf(" \nle noyau fils issu de la desintegration du noyau pere est : \n");
	elementAfficher(noyauFils(X,E,type));
	}
	printf("\n\n");



printf("\nRevenir au menu?\n\n");
printf("Oui (o/O)\n\n");
printf("Non(n/N)\n\n");
fflush(stdin);
scanf("%c",&Menu);

}while(Menu=='o' || Menu=='O');
	tabDetruire(E);
	return 0;
}
