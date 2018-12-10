#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "save.h"
#include "parc.h"
#include "rdvmedecin.h"
#include "dite.h"





void
on_button5_clicked   (GtkWidget *objet_graphique,  gpointer  user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input8;
GtkWidget *input7;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char nom[100],prenom[100],objectif [100];
char t[10],poid[10],ddn[20];
char nom2[100],prenom2[100],objectif2 [100];
char t2[10],poid2[10],ddn2[20];
input1=lookup_widget(objet_graphique,"entry7");
output1=lookup_widget(objet_graphique,"label42");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nom2,nom);
gtk_label_set_text(GTK_LABEL(output1),nom);

input2=lookup_widget(objet_graphique,"entry8");
output2=lookup_widget(objet_graphique,"label43");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prenom2,prenom);
gtk_label_set_text(GTK_LABEL(output2),prenom);

input3=lookup_widget(objet_graphique,"entry9");
output3=lookup_widget(objet_graphique,"label44");
strcpy(ddn,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ddn2,ddn);
gtk_label_set_text(GTK_LABEL(output3),ddn);

input4=lookup_widget(objet_graphique,"entry10");
output4=lookup_widget(objet_graphique,"label45");
strcpy(poid,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(poid2,poid);
gtk_label_set_text(GTK_LABEL(output4),poid);

input5=lookup_widget(objet_graphique,"entry11");
output5=lookup_widget(objet_graphique,"label46");
strcpy(t,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(t2,t);
gtk_label_set_text(GTK_LABEL(output5),t);

input6=lookup_widget(objet_graphique,"entry12");
output6=lookup_widget(objet_graphique,"label47");
strcpy(objectif,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(objectif2,objectif);
gtk_label_set_text(GTK_LABEL(output6),objectif);

save(nom2,prenom2,ddn2,t2,poid2,objectif2);
}





void
on_button6_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget *combobox4;
combobox4=lookup_widget(objet_graphique,"combobox4");

FILE *f;
f=fopen("scure.txt","r");
char donnee[100];

rewind(f);

while(fscanf(f,"%s",donnee)!=EOF)
 gtk_combo_box_append_text(GTK_COMBO_BOX(combobox4),(donnee));

}


void
on_button8_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *combobox4;
GtkWidget *label85;
GtkWidget *label87;
int c=0;
combobox4=lookup_widget(objet_graphique,"combobox4");
GtkWidget *output1;
GtkWidget *output2;
output1=lookup_widget(objet_graphique,"label85");

label85=lookup_widget(objet_graphique,"label85");
label87=lookup_widget(objet_graphique,"label87");
FILE*d;
char donnee[100];
char donnee_r[100];
strcpy(donnee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

FILE*s;
s=fopen("creserver.txt","a+");
while(fscanf(s,"%s\n",donnee_r)!=EOF)
	if(strcmp(donnee_r,donnee)==0) c=1;

if (c==0){
 fprintf(s,"%s\n",donnee);
gtk_label_set_text(GTK_LABEL(label85),"reservation reusite");
}
else gtk_label_set_text(GTK_LABEL(label87),"Cette séance n'est plus disponible. Veuillez SVP choisir une autre");

fclose(s);
}
void
on_button9_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *combobox5;
combobox5=lookup_widget(objet_graphique,"combobox5");

FILE *f;
f=fopen("sentr.txt","r");
char donne[100];

rewind(f);

while(fscanf(f,"%s",donne)!=EOF)
 gtk_combo_box_append_text(GTK_COMBO_BOX(combobox5),(donne));

}

void
on_button7_clicked (GtkWidget  *objet_graphique,  gpointer  user_data)
{
GtkWidget *combobox5;
GtkWidget *label86;
combobox5=lookup_widget(objet_graphique,"combobox5");
GtkWidget *output1;
output1=lookup_widget(objet_graphique,"label86");
label86=lookup_widget(objet_graphique,"label86");

char donne[100];

char lu[100];
FILE *source, *destination; 
 
source=fopen("sentr.txt","r" ); 
destination=fopen("entreserver.txt","a" ); 
 
strcpy(lu,donne);
fprintf(destination,"%s\n",lu);
 
fclose(source); 
fclose(destination); 
 

gtk_label_set_text(GTK_LABEL(label86),"reservation reusite");


}


gboolean
on_combobox5_popdown                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

  return FALSE;
}
/*rdvmedecin*/
void
on_button10_clicked   (GtkWidget  *objet_graphique,  gpointer  user_data)
{GtkWidget *combobox6;

combobox6=lookup_widget(objet_graphique,"combobox6");
FILE *f;
f=fopen("rdvmedecin.txt","r");
char donnee[100];

rewind(f);

while(fscanf(f,"%s",donnee)!=EOF)
 gtk_combo_box_append_text(GTK_COMBO_BOX(combobox6),(donnee));

}

void
on_button11_clicked (GtkWidget  *objet_graphique,  gpointer  user_data
)
{
GtkWidget *combobox6;
GtkWidget *label92;
GtkWidget *label93;
int c=0;
combobox6=lookup_widget(objet_graphique,"combobox6");
GtkWidget *output3;
GtkWidget *output4;
output3=lookup_widget(objet_graphique,"label92");

label92=lookup_widget(objet_graphique,"label92");
label93=lookup_widget(objet_graphique,"label93");
FILE*d;
char donnee[100];
char donnee_r[100];
strcpy(donnee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox6)));

FILE*s;
s=fopen("rdvmedecinreserver.txt","a+");
while(fscanf(s,"%s\n",donnee_r)!=EOF)
	if(strcmp(donnee_r,donnee)==0) c=1;

if (c==0){
 fprintf(s,"%s\n",donnee);
gtk_label_set_text(GTK_LABEL(label93),"reservation reusite");
}
else gtk_label_set_text(GTK_LABEL(label92),"Ce RDV n'est plus disponible. Veuillez SVP choisir une autre");

fclose(s);

}



/*diététicien*/
void
on_button12_clicked (GtkWidget  *objet_graphique,  gpointer  user_data)
{
GtkWidget *combobox7;
combobox7=lookup_widget(objet_graphique,"combobox7");

FILE *f;
f=fopen("rdvdite.txt","r");
char donnee[100];

rewind(f);

while(fscanf(f,"%s",donnee)!=EOF)
 gtk_combo_box_append_text(GTK_COMBO_BOX(combobox7),(donnee));

}

void
on_button13_clicked   (GtkWidget *objet_graphique,  gpointer  user_data)
{GtkWidget *combobox7;
GtkWidget *label95;
GtkWidget *label96;
int c=0;
combobox7=lookup_widget(objet_graphique,"combobox7");
GtkWidget *output5;
GtkWidget *output6;
output5=lookup_widget(objet_graphique,"label95");
output6=lookup_widget(objet_graphique,"label96");

label95=lookup_widget(objet_graphique,"label95");
label96=lookup_widget(objet_graphique,"label96");
FILE*d;
char donnee[100];
char donnee_r[100];
strcpy(donnee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));

FILE*s;
s=fopen("rdvditereserver.txt","a+");
while(fscanf(s,"%s\n",donnee_r)!=EOF)
	if(strcmp(donnee_r,donnee)==0) c=1;

if (c==0){
 fprintf(s,"%s\n",donnee);
gtk_label_set_text(GTK_LABEL(label96),"reservation reusite");
}
else gtk_label_set_text(GTK_LABEL(label95),"Ce RDV n'est plus disponible. Veuillez SVP choisir une autre");

fclose(s);


}


/*kiné*/


void
on_button14_clicked   (GtkWidget  *objet_graphique,  gpointer  user_data)
{
GtkWidget *combobox8;
combobox8=lookup_widget(objet_graphique,"combobox8");

FILE *f;
f=fopen("rdvkine.txt","r");
char donnee[100];

rewind(f);

while(fscanf(f,"%s",donnee)!=EOF)
 gtk_combo_box_append_text(GTK_COMBO_BOX(combobox8),(donnee));

}


void
on_button15_clicked  (GtkWidget  *objet_graphique,  gpointer  user_data)
{
GtkWidget *combobox8;
GtkWidget *label98;
GtkWidget *label99;
int c=0;
combobox8=lookup_widget(objet_graphique,"combobox8");
GtkWidget *output1;
GtkWidget *output2;
output1=lookup_widget(objet_graphique,"label98");
output2=lookup_widget(objet_graphique,"label99");

label98=lookup_widget(objet_graphique,"label98");
label99=lookup_widget(objet_graphique,"label99");
FILE*d;
char donnee[100];
char donnee_r[100];
strcpy(donnee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));

FILE*s;
s=fopen("rdvkinereserver.txt","a+");
while(fscanf(s,"%s\n",donnee_r)!=EOF)
	if(strcmp(donnee_r,donnee)==0) c=1;

if (c==0){
 fprintf(s,"%s\n",donnee);
gtk_label_set_text(GTK_LABEL(label99),"reservation reusite");
}
else gtk_label_set_text(GTK_LABEL(label98),"Ce RDV n'est plus disponible. Veuillez SVP choisir une autre");

fclose(s);

}







void
on_button17_clicked  (GtkWidget      *objet_graphique,  gpointer         user_data)
{
char donnee[50];

FILE *f1;
GtkWidget *label104;

label104=lookup_widget(objet_graphique,"label104");


f1=fopen("rdvkinereserver.txt","w+");
rewind(f1);
fclose(f1);
gtk_label_set_text(GTK_LABEL(label104),"");
}


void
on_button20_clicked   (GtkWidget      *objet_graphique,  gpointer         user_data)
{
char donnee[50];

FILE *f1;
GtkWidget *label105;

label105=lookup_widget(objet_graphique,"label105");


f1=fopen("rdvditereserver.txt","w+");
rewind(f1);
fclose(f1);
gtk_label_set_text(GTK_LABEL(label105),"");
}


void
on_button21_clicked       (GtkWidget      *objet_graphique,  gpointer         user_data)
{
char donnee[50];

FILE *f1;
GtkWidget *label106;

label106=lookup_widget(objet_graphique,"label106");


f1=fopen("rdvmedecinreserver.txt","w+");
rewind(f1);
fclose(f1);
gtk_label_set_text(GTK_LABEL(label106),"");
}


void
on_button16_clicked     (GtkWidget      *objet_graphique,  gpointer         user_data)
{
char donnee[50];
char donnee2[50];
char donnee3[50];
FILE *f1,*f2,*f3;
GtkWidget *label104;
GtkWidget *label105;
GtkWidget *label106;



label104=lookup_widget(objet_graphique,"label104");
label105=lookup_widget(objet_graphique,"label105");
label106=lookup_widget(objet_graphique,"label106");

f1=fopen("rdvkinereserver.txt","a+");
f2=fopen("rdvditereserver.txt","a+");
f3=fopen("rdvmedecinreserver.txt","a+");
rewind(f1);
rewind(f2);
rewind(f3);

while(fscanf(f1,"%s\n",donnee)!=EOF)
	{
		 if(strcmp(donnee,"")==0) gtk_label_set_text(GTK_LABEL(label104),"aucun rdv");
		else gtk_label_set_text(GTK_LABEL(label104),donnee);
	}
while(fscanf(f2,"%s\n",donnee2)!=EOF)
	{
		if (strcmp(donnee2,"")==0) gtk_label_set_text(GTK_LABEL(label105),"aucun rdv");
		else gtk_label_set_text(GTK_LABEL(label105),donnee2);
	}
while(fscanf(f3,"%s\n",donnee3)!=EOF) 
	{
		if(strcmp(donnee3,"")==0) gtk_label_set_text(GTK_LABEL(label106),"aucun rdv");
		else gtk_label_set_text(GTK_LABEL(label106),donnee3);
	}
fclose(f1);
fclose(f2);
fclose(f3);	

}

