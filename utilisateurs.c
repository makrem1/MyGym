#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utilisateurs.h"
#include <gtk/gtk.h>



 //toutes les fonctions sont communes à tous les utlisateurs 
 
void role(int r,char rol[])
{ 	
	// cette fonction retourne selon le role de l'utilisateur le nom du fichier correspondant

	switch(r)
	{	case 1: strcpy(rol,"administrateur.txt"); break;
		case 2: strcpy(rol,"adhérents.txt"); break;
		case 3: strcpy(rol,"coachs.txt"); break;
		case 4: strcpy(rol,"kinésithérapeute.txt"); break;
		case 5: strcpy(rol,"médecins_nutritionnistes.txt"); break;
		case 6: strcpy(rol,"diététiciens.txt"); break;
		default: break;
	}
	
}
int ajouter(utilisateur P,int r)
{
	// cette fonction permet d'ajouter un utlisateur selon son role. Elle renvoit 0 si l'ajout s'est bien effectué et 1 sinon. 
	
	FILE *f;
	FILE *f1;
	utilisateur C;
	int c=0;
	char rol[100];
	role(r,rol);
	f=fopen(rol,"a+");
	f1=fopen("authentification.txt","a+");

	rewind(f);
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
		{
		if (strcmp(P.nom,C.nom)==0 && strcmp(P.prenom,C.prenom)==0) c=1;
		}
	if(c==0)
	{
	fseek(f,0,SEEK_END);
fprintf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",P.nom,P.prenom,P.nom_utilisateur,P.mot_de_passe,P.sexe,P.date.jour,P.date.mois,P.date.annee,P.telephone,P.email,P.role,P.id);
fprintf(f1,"%s %s %s %s %d %s\n",P.nom,P.prenom,P.nom_utilisateur,P.mot_de_passe,P.role,P.id);
	}
	
	fclose(f1);
	fclose(f);
	return(c);
}
	

int verifier(char login[], char password[])
{
	// cette fonction permet d'authentifier l'utilisateur et retourne son role.
	
	FILE *f;
	utilisateur P;
	int n;
	int p;
	int r=0;
	f=fopen("authentification.txt","r+");
	rewind(f);
	while (fscanf(f,"%s %s %s %s %d %s\n",P.nom,P.prenom,P.nom_utilisateur,P.mot_de_passe,&P.role,P.id)!=EOF)
	{
		n=strcmp(login,P.nom_utilisateur);
		p=strcmp(password,P.mot_de_passe);
		if(n==0 && p==0)
			r=P.role;
	}
	fclose(f);
	return r;
} 
void modifier(utilisateur P,int r)
{ 	
	// cette fonction permet de modifier un utilisateur selon role
	
	FILE *f;
	FILE *f_t;
	FILE *f2;
	FILE *f3;
	utilisateur C;
	char rol[100];
	int i,c=0;
	role(r,rol);
	f=fopen(rol,"r+");
	f_t=fopen("modification.txt","a+");
	f2=fopen("authentification.txt","r+");
	f3=fopen("mod.txt","a+");
	rewind(f);
	
		//Modification du fichier utilisateur
		
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
		{
			//on ajoute l'utilisateur au nouveau fichier 
			if (strcmp(C.id,P.id)==0) 
			{	fprintf(f_t,"%s %s %s %s %s %d %d %d %s %s %d %s\n",P.nom,P.prenom,P.nom_utilisateur,P.mot_de_passe,P.sexe,P.date.jour,P.date.mois,P.date.annee,P.telephone,P.email,P.role,P.id);

			}
			// on ajoute le reste des utilisateurs du meme role dans le nouveau fichier
			else 
			{ fprintf(f_t,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,C.date.jour,C.date.mois,C.date.annee,C.telephone,C.email,C.role,C.id);

			}
		}
		
		//Modification du fichier de l'authentification
		
	while(fscanf(f2,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
		{
		//on ajoute l'utilisateur au nouveau fichier 
		if (strcmp(C.id,P.id)==0) fprintf(f3,"%s %s %s %s %d %s\n",P.nom,P.prenom,P.nom_utilisateur,P.mot_de_passe,P.role,P.id);
		// on ajoute le reste des utilisateurs du meme role dans le nouveau fichier
		else fprintf(f3,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
		}
		
	fclose(f);
	fclose(f_t);
	fclose(f2);
	fclose(f3);
	remove(rol);
	remove("authentification.txt");
	rename("modification.txt",rol);
	rename("mod.txt","authentification.txt");
	
}


utilisateur* afficher(char ide[],int r)
{	
	//cette fonction renvoit un pointeur sur un utilisateur afin d'afficher les données de ce dernier
	
	FILE *f;
	utilisateur *P;// declaration du pointeur
	utilisateur C; // declaration de la structure pour le parcours du fichier utilisateur
	utilisateur R; // declaration de la structure qui contiendra les données de l'utilisateur 
	P=&R;
	
	char rol[100];
	role(r,rol);
	f=fopen(rol,"r+");
	rewind(f);
	
	// Si l'utilisateur existe, ses données sont stockées
	
	while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
	{ 
	if (strcmp(ide,C.id)==0)
		R=C;
	}
	fclose(f);
	return (P);
	
}

int desactiver(char ide[])
{ 
	/* cette fonction permet de desactiver un utilisateur en le deplacant du fichier authentification vers le fichier desactivation de sorte à ce qu'il ne puisse pas se connecter étant introuvable dans le fichier authentification. Elle retourne 1 si la desactivation a été faite, 0 sinon*/
	
	FILE *f;
	FILE *f1;
	FILE *f2;
	utilisateur C;
	int i=0;
	f=fopen("authentification.txt","r+");
	f1=fopen("desactivation.txt","a+");
	f2=fopen("des_temp.txt","a+");
	
	rewind(f);
	while(fscanf(f,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,&C.role,C.id)!=EOF)
	{ 		

	if (strcmp(C.id,ide)==0)
	{fseek(f1,0,SEEK_END);
	fprintf(f1,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
	i=1;}
	else  fprintf(f2,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
	}
	
	fclose(f2);
	fclose(f1);
	fclose(f);
	remove("authentification.txt");
	rename("des_temp.txt","authentification.txt");
	return(i);
}
	
void supprimer(char ide[],int r)
{
	//cette fonction permet de supprimer definitivement un utilisateur
	
	FILE *f;
	FILE *f2;
	FILE *f3;
	FILE *f4;
	char rol[30];
	role(r,rol);
	utilisateur C;
	f=fopen("authentification.txt","r+");
	f2=fopen("sup_temp.txt","a+");
	f3=fopen(rol,"r");
	f4=fopen("new.txt","a+");
	rewind(f);
	rewind(f3);
	while(fscanf(f,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,&C.role,C.id)!=EOF)
	{ 		

	if (strcmp(C.id,ide)!=0) fprintf(f2,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
	}

	while(fscanf(f3,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
	{ 		

	if (strcmp(C.id,ide)!=0) fprintf(f4,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,C.date.jour,C.date.mois,C.date.annee,C.telephone,C.email,C.role,C.id);
	}
	
	fclose(f2);
	fclose(f);
	fclose(f3);
	fclose(f4);
	remove("authentification.txt");
	rename("sup_temp.txt","authentification.txt");
	remove(rol);
	rename("new.txt",rol);
}
		
int activer(char ide[])
{
	//cette fonction permet de activer un utilisateur 
	
	FILE *f;
	FILE *f1;
	FILE *f2;
	utilisateur C;
	int i=0;
	f=fopen("authentification.txt","a+");
	f1=fopen("desactivation.txt","r+");
	f2=fopen("act_temp.txt","a+");
	
	rewind(f1);
	while(fscanf(f1,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,&C.role,C.id)!=EOF)
	{ 		

	if (strcmp(C.id,ide)==0){
 fprintf(f,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
i=1;}
	else fprintf(f2,"%s %s %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.role,C.id);
	}
	fclose(f2);
	fclose(f1);
	fclose(f);
	remove("desactivation.txt");
	rename("act_temp.txt","desactivation.txt");
return (i);
}

int rechercher(char ide[],int r)
{
	//cette fonction permet de verifier l'existence d'un identifiant. Elle retourne 1 si il existe  et 0 ou 2 sinon.  
	FILE *f;
	char rol[50];
	role(r,rol);
	int i=0;
	utilisateur C;
	f=fopen(rol,"r+");
	if (f!=NULL) {
	rewind(f);
	while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",C.nom,C.prenom,C.nom_utilisateur,C.mot_de_passe,C.sexe,&C.date.jour,&C.date.mois,&C.date.annee,C.telephone,C.email,&C.role,C.id)!=EOF)
	{ 
		if (strcmp(C.id,ide)==0)
			i=1;
		
	}
	fclose(f);
	}
	else i=2;
	return(i);
}

int rechercher_actif(char ide[])
{
//cette fonction permet de verifier si un utilisateur est actif. Elle retourne 1 si il existe  et 0.  
	FILE *f;
	int i=0;
	utilisateur C;
	char nom[20];
	char prenom[20];
	char nom_utilisateur[20];
	char mot_de_passe[20];
	char id[20];
	int role;
	f=fopen("authentification.txt","r");

	rewind(f);
	while(fscanf(f,"%s %s %s %s %d %s\n",nom,prenom,nom_utilisateur,mot_de_passe,&role,id)!=EOF)
	{ 
		if (strcmp(id,ide)==0)
			i=1;
	}
	fclose(f);
	return(i);
}

int chaine(char ch[])
{ //cette fonction verifie si l'entrée est une chaine de caractère
int i,c=1;
for(i=0;i<strlen(ch);i++)
	if(!isalpha(ch[i])) c=0;
return(c);
}

int num(char ch[])
{
	int i,c=1;
	for(i=0; i<strlen(ch);i++)
		if(!isdigit(ch[i])) c=0;
	return(c);
}
