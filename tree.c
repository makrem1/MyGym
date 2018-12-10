#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>


#include "tree.h"
#include "utilisateurs.h"

enum
{
	NOM,
	PRENOM,
	NOM_UTILISATEUR,
	SEXE,
	TELEPHONE,
	EMAIL,
	ID,
	COLUMNS
};
	
void afficher_utilisateur(GtkWidget *liste,int r)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	char nom[50];
	char prenom[50];
	char mot_de_passe[50];
	char nom_utilisateur[50];
	char sexe [50];
	char telephone[50];
	char email[100];
	char id[50];
	int j,m,a,ro,i;
	store=NULL;

	FILE *f;
	FILE *f1;
	char rol[20];
	role(r,rol);
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom utilisateur", renderer, "text", NOM_UTILISATEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	  
	       
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" sexe", renderer, "text", SEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" telephone", renderer, "text", TELEPHONE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" email", renderer, "text", EMAIL, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" identifiant", renderer, "text",ID, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	

		
	}
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen(rol,"r");
	f1 = fopen("authentification.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else
	{
		f = fopen(rol, "a+");
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %d %s\n",nom,prenom,nom_utilisateur,mot_de_passe,sexe,&j,&m,&a,telephone,email,&ro,id)!=EOF)
		{	
			i=rechercher_actif(id);
			if(i==1)
			{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,NOM,nom,PRENOM,prenom,NOM_UTILISATEUR,nom_utilisateur,SEXE,sexe,TELEPHONE,telephone,EMAIL,email,ID,id, -1);
			}
		}
		fclose(f);
		
	}
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}


