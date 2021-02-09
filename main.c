#include <stdio.h>
#include <gtk/gtk.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#define FACILE 6
#define  MOYEN 10
#define  DIFFICILE 14


GtkBuilder *builder;



typedef struct {

char pseudo[15];
int  score;}_joueur;

typedef struct {
    GtkWidget   *window[9];
    int          diff;
    int          nbrjoueur;
    int          scorejoueur[4];
    int          indicecarte[14];
    int          cartechoisit[2];
    int          compteur ;
    int          numcarte;
    int          findepartie;
    const gchar *pseudojoueur1;
    const gchar *pseudojoueur2;
    const gchar *pseudojoueur3;
    const gchar *pseudojoueur4;
    GtkWidget   *carte[14];
    GtkWidget   *carteimage[8];
    GtkWidget   *btncontrole[8];
    GtkWidget   *entrerpseudo[5];

}_widgets;


_joueur player[];



void fctacceuil(GtkWidget *ButtonExplore,_widgets *g_widget);
void fcttopscore(GtkWidget *ButtonExplore, _widgets *g_widget);
void fctchoixdediffulte(GtkWidget *ButtonExplore, _widgets *g_widget);
void fctchoixdenbrjoueur(GtkWidget *ButtonExplore,_widgets *g_widget);
void fctpseudo(GtkWidget *ButtonExplore,_widgets *g_widget);
void fctjeufacile(GtkWidget *ButtonExplore,_widgets *g_widget);
void getimage(_widgets *g_widget,GtkWidget *image);
void fctfindejeu(_widgets *g_widget);






void fctexporter(_joueur player ){
  FILE *fichier;

  fichier=fopen("scorejoueur.txt","w");
  if (fichier != NULL){
  fprintf(fichier,"%s     %d",player.pseudo,player.score);}

  fclose(fichier);
}


void affectationaleatoirecarte(int valcarte[],int n){

    int compteur[n/2];
    memset(compteur, 0, n/2 * sizeof(int));
    memset(valcarte, -1, n * sizeof(int));
    srand(time(0));

    int u=0, i=0;

    for(i=0;i<n/2;i++){
        //printf("Compteur : %d", compteur[i]);
        while(compteur[i] < 2){
            // Tirer une valeur aleatoire entre 0 et 5
            u = rand()%n;
            //printf("Valeur de U : %d", u);
            //printf("Iteration %d", i);
            if (valcarte[u] == -1){
                valcarte[u] = i;
                compteur[i]++;
            }
        }
    }

    }

void fctiniatiliser(GtkWidget *ButtonExplore,_widgets *g_widget){
   GtkWidget *Image[6];
   int i;
   for(i=0;i<6;i++){Image[i]=gtk_image_new();
                    gtk_image_set_from_file(GTK_IMAGE(Image[i]),"./Images Projet C/BUTTON/doscarte.png");
                    gtk_button_set_image( g_widget->carte[i],GTK_IMAGE(Image[i]));}



}



void fctverificationduchoix(_widgets *g_widget,GtkWidget *image){
    GtkWidget *doscarte=gtk_image_new();
    GtkWidget *doscarte2=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(doscarte),"./Images Projet C/BUTTON/doscarte.png");
    gtk_image_set_from_file(GTK_IMAGE(doscarte2),"./Images Projet C/BUTTON/doscarte.png");

   if(g_widget->cartechoisit[0]==-1){g_widget->cartechoisit[0]=g_widget->numcarte;}
     if(g_widget->cartechoisit[0]!=-1||g_widget->cartechoisit[1]==-1){
                                                                  g_widget->cartechoisit[1]=g_widget->numcarte;}

     getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[g_widget->numcarte],GTK_IMAGE(image));
     g_widget->compteur++;

     if(g_widget->compteur==2){
              if(g_widget->indicecarte[g_widget->cartechoisit[0]]==g_widget->indicecarte[g_widget->cartechoisit[1]]){
                  /*Sleep(500);*/
                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[0]]);
                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[1]]);
                  g_widget->findepartie ++;
                  if(g_widget->findepartie==g_widget->diff/2){g_widget->findepartie=0;
                                                              g_widget->compteur=0;
                                                               g_widget->indicecarte[0]=1;
                                                                g_widget->cartechoisit[0]=-1 ;
                                                                g_widget->cartechoisit[1]=-1 ;
                                                                fctfindejeu(g_widget);}

                  }
              else {/*Sleep(500);*/
                    gtk_button_set_image(g_widget->carte[g_widget->cartechoisit[0]],GTK_IMAGE(doscarte));
                    gtk_button_set_image(g_widget->carte[g_widget->cartechoisit[1]],GTK_IMAGE(doscarte2));}
               g_widget->compteur=0;
               g_widget->cartechoisit[0]=-1;
               g_widget->cartechoisit[1]=-1;

     }}



void getimage(_widgets *g_widget,GtkWidget *image){
    switch(g_widget->indicecarte[g_widget->numcarte]){
         case 0 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/tigre.png");break;
         case 1 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/panda.png");break;
         case 2 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/oiseau.png");break;
         case 3 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/singe.png");break;
         case 4 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/taureau.png");break;
         case 5 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/oiseau.png");break;
         case 6 : gtk_image_set_from_file(GTK_IMAGE(image),"./Images Projet C/BUTTON/souris.png");break;}
}


void flipcarte1(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();

     g_widget->numcarte=0;
   /* getimage(g_widget,image);
    gtk_button_set_image(g_widget->carte[0],GTK_IMAGE(image));*/
    fctverificationduchoix(g_widget,image);

    /* if(g_widget->cartechoisit[0]==0){g_widget->cartechoisit[0]=g_widget->numcarte;}
     if(g_widget->cartechoisit[0]!=0||g_widget->cartechoisit[1]==0){g_widget->cartechoisit[1]=g_widget->numcarte;}
     getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[0],GTK_IMAGE(image));
     g_widget->compteur++;

     if(g_widget->compteur==2){
              if(g_widget->indicecarte[g_widget->cartechoisit[0]]==g_widget->indicecarte[g_widget->cartechoisit[1]]){
                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[0]]);
                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[1]]);
                  compteur=0;}

     }*/

     }




void flipcarte2(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=1;
     /*getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[1],GTK_IMAGE(image));*/
     fctverificationduchoix(g_widget,image);
}




void flipcarte3(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=2;
    /* getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[2],GTK_IMAGE(image));*/
     fctverificationduchoix(g_widget,image);
}


void flipcarte4(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=3;
     /*getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[3],GTK_IMAGE(image));*/
     fctverificationduchoix(g_widget,image);
}

void flipcarte5(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=4;
     /*getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[4],GTK_IMAGE(image));*/
     fctverificationduchoix(g_widget,image);
}

void flipcarte6(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=5;
    /* getimage(g_widget,image);
     gtk_button_set_image(g_widget->carte[5],GTK_IMAGE(image));*/
     fctverificationduchoix(g_widget,image);

}

void flipcarte7(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[6],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[6]]));
}

void flipcarte8(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[7],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[7]]));
}

void flipcarte9(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[8],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[8]]));
}

void flipcarte10(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[9],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[9]]));
}

void flipcarte11(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[10],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[10]]));
}

void flipcarte12(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[11],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[11]]));
}


void flipcarte13(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[12],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[12]]));
}

void flipcarte14(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_button_set_image( g_widget->carte[13],GTK_IMAGE(g_widget->carteimage[g_widget->indicecarte[13]]));
}

void fctfindejeu(_widgets *g_widget){

gtk_widget_hide(g_widget->window[4]);



    GtkWidget *btn[2];
    GtkWidget *label[8];

    g_widget->window[8]=GTK_WIDGET(gtk_builder_get_object(builder,"findepartie"));

    btn[0]=GTK_WIDGET(gtk_builder_get_object(builder,"btnreccomencerpartie"));
    g_signal_connect(G_OBJECT(btn[0]),"clicked",G_CALLBACK(fctiniatiliser),g_widget);
    g_signal_connect(G_OBJECT(btn[0]),"clicked",G_CALLBACK(fctjeufacile),g_widget);


    btn[1]=GTK_WIDGET(gtk_builder_get_object(builder,"btnretouracceuil"));
    g_signal_connect(G_OBJECT(btn[1]),"clicked",G_CALLBACK(fctacceuil),g_widget);


    gtk_window_set_position(g_widget->window[8],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[8]);








}

void rejouez(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_widget_show(g_widget->window[3]);
    g_signal_connect(G_OBJECT(g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte3),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte4),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte5),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte6),g_widget);}






void fctjeufacile(GtkWidget *ButtonExplore,_widgets *g_widget){

    gtk_widget_hide(g_widget->window[3]);
    gtk_widget_hide(g_widget->window[8]);



    affectationaleatoirecarte(g_widget->indicecarte,FACILE);


    g_widget->window[4]=GTK_WIDGET(gtk_builder_get_object(builder,"facile"));

    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte11"));
    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte12"));
    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte13"));
    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte21"));
    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte22"));
    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte23"));

    g_signal_connect(G_OBJECT(g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte3),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte4),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte5),g_widget);
    g_signal_connect(G_OBJECT(g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte6),g_widget);

    gtk_window_set_position(g_widget->window[4],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[4]);


}

 void fctjeudifficile(GtkWidget *ButtonExplore,_widgets *g_widget){

    gtk_widget_hide(g_widget->window[3]);


    GtkWidget  *player;


    g_widget->window[5]=GTK_WIDGET(gtk_builder_get_object(builder,"difficile"));

    player=GTK_WIDGET(gtk_builder_get_object(builder,"playeringame3"));

    gtk_label_set_text(GTK_LABEL(player),g_widget->pseudojoueur1);

    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte311"));
    g_signal_connect(G_OBJECT( g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),NULL );

    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte312"));
    g_signal_connect(G_OBJECT( g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),NULL );

    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte321"));
    g_signal_connect(G_OBJECT( g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte322"));
    g_signal_connect(G_OBJECT( g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte323"));
    g_signal_connect(G_OBJECT( g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte324"));
    g_signal_connect(G_OBJECT( g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[6]=GTK_WIDGET(gtk_builder_get_object(builder,"carte325"));
    g_signal_connect(G_OBJECT( g_widget->carte[6]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[7]=GTK_WIDGET(gtk_builder_get_object(builder,"carte326"));
    g_signal_connect(G_OBJECT( g_widget->carte[7]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[8]=GTK_WIDGET(gtk_builder_get_object(builder,"carte331"));
    g_signal_connect(G_OBJECT( g_widget->carte[8]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[9]=GTK_WIDGET(gtk_builder_get_object(builder,"carte332"));
    g_signal_connect(G_OBJECT( g_widget->carte[9]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[10]=GTK_WIDGET(gtk_builder_get_object(builder,"carte333"));
    g_signal_connect(G_OBJECT( g_widget->carte[10]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[11]=GTK_WIDGET(gtk_builder_get_object(builder,"carte334"));
    g_signal_connect(G_OBJECT( g_widget->carte[11]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[12]=GTK_WIDGET(gtk_builder_get_object(builder,"carte335"));
    g_signal_connect(G_OBJECT( g_widget->carte[12]),"clicked",G_CALLBACK(flipcarte7),NULL );

    g_widget->carte[13]=GTK_WIDGET(gtk_builder_get_object(builder,"carte336"));
    g_signal_connect(G_OBJECT( g_widget->carte[13]),"clicked",G_CALLBACK(flipcarte7),NULL );


    gtk_window_set_position(g_widget->window[5],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[5]);





 };

void fctjeumoyen(GtkWidget *ButtonExplore,_widgets *g_widget){

    GtkWidget *window;
    GtkWidget *carte[10];




    window=GTK_WIDGET(gtk_builder_get_object(builder,"PLATEAUDEJEUMOYEN "));
    carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte1"));
    carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte2"));
    carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte3"));
    carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte4"));
    carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte5"));
    carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte6"));
    carte[6]=GTK_WIDGET(gtk_builder_get_object(builder,"carte7"));
    carte[7]=GTK_WIDGET(gtk_builder_get_object(builder,"carte8"));
    carte[8]=GTK_WIDGET(gtk_builder_get_object(builder,"carte9"));
    carte[9]=GTK_WIDGET(gtk_builder_get_object(builder,"carte10"));



    gtk_widget_show_all(window);
 }





  void fctquittez(GtkWidget *ButtonExplore, _widgets *g_widget){

    GtkWidget *confirmer;
    GtkWidget *rejet;



    g_widget->window[6]=GTK_WIDGET(gtk_builder_get_object(builder,"confirmationdequittez"));
    rejet=GTK_WIDGET(gtk_builder_get_object(builder,"non"));
    confirmer=GTK_WIDGET(gtk_builder_get_object(builder,"oui"));

    g_signal_connect(G_OBJECT(confirmer),"clicked",G_CALLBACK(gtk_main_quit),g_widget );
    g_signal_connect(G_OBJECT(rejet),"clicked",G_CALLBACK(fctacceuil),g_widget );

    gtk_window_set_position(g_widget->window[6],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[6]);

  }



  void retenirpseudo(GtkWidget *ButtonExplore,_widgets *g_widget){
      g_widget->pseudojoueur1=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[1]));
      g_widget->pseudojoueur2=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[2]));
      g_widget->pseudojoueur3=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[3]));
      g_widget->pseudojoueur4=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[4]));
  }




 void fctquatrepseudo(_widgets *g_widget){


    g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"QUATREPSEUDO"));

    g_widget->entrerpseudo[1]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO41"));
    g_widget->entrerpseudo[2]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO42"));
    g_widget->entrerpseudo[3]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO43"));
    g_widget->entrerpseudo[4]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO44"));

    g_widget->btncontrole[2]=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION4"));

     g_widget->btncontrole[4]=GTK_WIDGET(gtk_builder_get_object(builder,"goabck4"));




}




  void fctroispseudo(_widgets *g_widget){




    g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"TROISPSEUDO"));

    g_widget->entrerpseudo[1]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO31"));
    g_widget->entrerpseudo[2]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO32"));
    g_widget->entrerpseudo[3]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO33"));

    g_widget->btncontrole[2]=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION3"));
     g_widget->btncontrole[4]=GTK_WIDGET(gtk_builder_get_object(builder,"goabck3"));




}


void fctdeuxpseudo(_widgets *g_widget){


    g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"DEUXPSEUDO"));

    g_widget->entrerpseudo[1]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO21"));
    g_widget->entrerpseudo[2]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO22"));

   g_widget->btncontrole[2]=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION2"));
   g_widget->btncontrole[4]=GTK_WIDGET(gtk_builder_get_object(builder,"goabck2"));



}


void fctunpseudo(_widgets *g_widget){

    g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"UNPSEUDO"));

    g_widget->entrerpseudo[1]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDO11"));

    g_widget->btncontrole[2]=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION1"));

    g_widget->btncontrole[4]=GTK_WIDGET(gtk_builder_get_object(builder,"goabck1"));




}



  void fctpseudo(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_widget_hide(g_widget->window[2]);

    GtkWidget *pseudo1;
    GtkWidget *pseudo2;
    GtkWidget *pseudo3;
    GtkWidget *pseudo4;


    GtkWidget  *confirmation ;

    g_widget->compteur=0;
    g_widget->findepartie=0;




    g_widget->cartechoisit[0]=-1 ;
    g_widget->cartechoisit[1]=-1 ;


    printf("nbr joeur %d",g_widget->nbrjoueur);




    switch(g_widget->nbrjoueur){
        case 1 : fctunpseudo(g_widget);break;

        case 2 : fctdeuxpseudo(g_widget);break;

        case 3 : fctroispseudo(g_widget);break;

        case 4 : fctquatrepseudo(g_widget);break;

        }


    g_signal_connect(G_OBJECT( g_widget->btncontrole[4]),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    g_signal_connect(G_OBJECT(g_widget->btncontrole[2]),"clicked",G_CALLBACK(retenirpseudo),g_widget );

    switch(g_widget->diff){

       case FACILE :        g_signal_connect(G_OBJECT(g_widget->btncontrole[2]),"clicked",G_CALLBACK(fctjeufacile),g_widget );break;

       case MOYEN:          g_signal_connect(G_OBJECT(g_widget->btncontrole[2]),"clicked",G_CALLBACK(fctjeumoyen),g_widget );break;

       case DIFFICILE:       g_signal_connect(G_OBJECT(g_widget->btncontrole[2]),"clicked",G_CALLBACK(fctjeudifficile),g_widget );break;

    }



     gtk_window_set_position(g_widget->window[3],GTK_WIN_POS_CENTER);

     gtk_widget_show_all(g_widget->window[3]);
  }





  void ajoutnbrjoueur1(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=1;}

  void ajoutnbrjoueur2(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=2;}

  void ajoutnbrjoueur3(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=3;}

  void ajoutnbrjoueur4(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=4;}



  void fctchoixdenbrjoueur(GtkWidget *ButtonExplore,_widgets *g_widget){
    //definir les variables local de la fct
    gtk_widget_hide(g_widget->window[1]);
    gtk_widget_hide(g_widget->window[3]);


    GtkWidget *unjoueur;
    GtkWidget *deuxjoueur;
    GtkWidget *troisjoueur;
    GtkWidget *quatrejoueur;





    //affecter a chaque variable son champ qui lui correspond



    g_widget->window[2]=GTK_WIDGET(gtk_builder_get_object(builder,"NBRJOUEURCHOICE"));

    unjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"UN JOUEUR"));
    g_signal_connect(G_OBJECT(unjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur1),g_widget );
    g_signal_connect(G_OBJECT(unjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    deuxjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"DEUJOUEUR"));
    g_signal_connect(G_OBJECT(deuxjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur2),g_widget );
    g_signal_connect(G_OBJECT(deuxjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    troisjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"TROIJOUEUR"));
    g_signal_connect(G_OBJECT(troisjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur3),g_widget );
    g_signal_connect(G_OBJECT(troisjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    quatrejoueur=GTK_WIDGET(gtk_builder_get_object(builder,"QUATRE JOUEUR"));
    g_signal_connect(G_OBJECT(quatrejoueur),"clicked",G_CALLBACK(ajoutnbrjoueur4),g_widget );
    g_signal_connect(G_OBJECT(quatrejoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    g_widget->btncontrole[6]=GTK_WIDGET(gtk_builder_get_object(builder,"RETOUR"));
    g_signal_connect(G_OBJECT(g_widget->btncontrole[6]),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget );



    //donner le signal a chaque variable et la fct qui doit la suivre




    gtk_window_set_position(g_widget->window[2],GTK_WIN_POS_CENTER);
    //faire apparaitre la fenetre
    gtk_widget_show_all(g_widget->window[2]);

  }



   void ajoutfacile(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=FACILE;}



   void ajoutmoyen(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=MOYEN;}


   void ajoutdifficile(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=DIFFICILE;}




   void fctchoixdediffulte(GtkWidget *ButtonExplore, _widgets *g_widget){


    gtk_widget_hide(g_widget->window[0]);
    gtk_widget_hide(g_widget->window[2]);

    GtkWidget *facile;
    GtkWidget *moyen;
    GtkWidget *difficile;
    GtkWidget *goback;


    g_widget->window[1]=GTK_WIDGET(gtk_builder_get_object(builder,"DIFFICULTCHOICE"));

    facile=GTK_WIDGET(gtk_builder_get_object(builder,"BTNFACILE"));
    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(ajoutfacile),g_widget );
    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );


    moyen=GTK_WIDGET(gtk_builder_get_object(builder,"BTNMOYEN"));
    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(ajoutmoyen),g_widget );
    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    difficile=GTK_WIDGET(gtk_builder_get_object(builder,"BTNDIFFICILE"));
    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(ajoutdifficile),g_widget );
    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    goback=GTK_WIDGET(gtk_builder_get_object(builder,"retour1"));
    g_signal_connect(G_OBJECT(goback),"clicked",G_CALLBACK(fctacceuil),g_widget );


    gtk_window_set_position(g_widget->window[1],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[1]);
  }


void fctimporter(int nbrjoueurdansfichier ){FILE *fichier;

fichier=fopen("scorejoueur.txt","r");
int i=0;
while(fscanf(fichier,"%s %d",player[i].pseudo,&player[i].score)!=EOF){i++;}
nbrjoueurdansfichier=i ;
fclose(fichier);}


 void fcttridecroissant(int nbrjoueur){//_joueur player[n] variable global
  _joueur  change;
  int i,j;
  for(i=0;i<nbrjoueur;i++){    for(j=i+1;j<nbrjoueur;j++){
                       if(player[i].score < player[j].score){
                       change=player[i];
                       player[i] = player[j];
                       player[j]=change;}}}}



  void fcttopscore(GtkWidget *ButtonExplore, _widgets *g_widget){

       gtk_widget_hide(g_widget->window[0]);

       g_widget->window[7]=GTK_WIDGET(gtk_builder_get_object(builder,"TOPSCORE"));

       GtkWidget *label[10] ;
       char       labelscore[8];
       GtkWidget *goback;

       goback=GTK_WIDGET(gtk_builder_get_object(builder,"retouracceuil"));
       int nbrjoueurdansfichier ;

       fctimporter(nbrjoueurdansfichier);

       fcttridecroissant(nbrjoueurdansfichier);


       label[0]=GTK_WIDGET(gtk_builder_get_object(builder,"pseudo1"));
       gtk_label_set_text(label[0],player[0].pseudo);
       label[1]=GTK_WIDGET(gtk_builder_get_object(builder,"score1"));
       itoa(player[0].score,labelscore,10);
       gtk_label_set_text(label[1],labelscore);


       label[2]=GTK_WIDGET(gtk_builder_get_object(builder,"pseudo2"));
       gtk_label_set_text(label[2],player[1].pseudo);
       label[3]=GTK_WIDGET(gtk_builder_get_object(builder,"score2"));
       itoa(player[1].score,labelscore,10);
       gtk_label_set_text(label[3],labelscore);


       label[4]=GTK_WIDGET(gtk_builder_get_object(builder,"pseudo3"));
       gtk_label_set_text(label[4],player[2].pseudo);
       label[5]=GTK_WIDGET(gtk_builder_get_object(builder,"score3"));
       itoa(player[2].score,labelscore,10);
       gtk_label_set_text(label[5],labelscore);

       label[6]=GTK_WIDGET(gtk_builder_get_object(builder,"pseudo4"));
       gtk_label_set_text(label[6],player[3].pseudo);
       label[7]=GTK_WIDGET(gtk_builder_get_object(builder,"score4"));
       itoa(player[3].score,labelscore,10);
       gtk_label_set_text(label[7],labelscore);

       label[8]=GTK_WIDGET(gtk_builder_get_object(builder,"pseudo5"));
       gtk_label_set_text(label[8],player[4].pseudo);
       label[9]=GTK_WIDGET(gtk_builder_get_object(builder,"score5"));
       itoa(player[4].score,labelscore,10);
       gtk_label_set_text(label[9],labelscore);



       g_signal_connect(G_OBJECT(goback),"clicked",G_CALLBACK(fctacceuil),g_widget );


       gtk_window_set_position(g_widget->window[7],GTK_WIN_POS_CENTER);

       gtk_widget_show_all(g_widget->window[7]);

    }



void fctacceuil(GtkWidget *ButtonExplore,_widgets *g_widget){
    /*for(int i=0;i<9;i++){  if (g_widget->window[i]!=NULL||i!=0 ){
        gtk_widget_hide(g_widget->window[i]);}}*/

        gtk_widget_hide(g_widget->window[8]);

        gtk_widget_hide(g_widget->window[7]);
        gtk_widget_hide(g_widget->window[1]);

     GtkWidget *jouer;
    GtkWidget *score;
    GtkWidget *quittez;


    GtkWidget *window;
    _joueur player ;


   /* player.pseudo="nizar";
    player.score=5820;
    fctexporter(player);*/

  /* Creation de la fenetre principale de notre application */





    g_widget->window[0]=GTK_WIDGET(gtk_builder_get_object(builder,"ACCEUIL"));



    jouer=GTK_WIDGET(gtk_builder_get_object(builder,"BTNJOUER"));
    score=GTK_WIDGET(gtk_builder_get_object(builder,"BTNSCORE"));
    quittez=GTK_WIDGET(gtk_builder_get_object(builder,"BTNQUITTEZ"));



  /* Creation du conteneur principal */


    g_signal_connect(G_OBJECT(score),"clicked",G_CALLBACK(fcttopscore),g_widget );
    g_signal_connect(G_OBJECT(jouer),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget);
    g_signal_connect(G_OBJECT(quittez),"clicked",G_CALLBACK(fctquittez),g_widget );


   gtk_window_set_position(g_widget->window[0],GTK_WIN_POS_CENTER);

   /* Affichage de la fenetre principale */

   gtk_widget_show_all (g_widget->window[0]);






}














/*void getimage(_widgets *g_widget){

    g_widget->carteimage[1]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[1]),"./Images Projet C/BUTTON/tigre.png");

    g_widget->carteimage[2]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[2]),"./Images Projet C/BUTTON/panda.png");

    g_widget->carteimage[3]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[3]),"./Images Projet C/BUTTON/souris.png");

    g_widget->carteimage[4]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[4]),"./Images Projet C/BUTTON/singe.png");

    g_widget->carteimage[5]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[5]),"./Images Projet C/BUTTON/serpent.png");

    g_widget->carteimage[6]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[6]),"./Images Projet C/BUTTON/taureau.png");

    g_widget->carteimage[7]=gtk_image_new();
    gtk_image_set_from_file(GTK_IMAGE(g_widget->carteimage[1]),"./Images Projet C/BUTTON/oiseau.png");
}*/















int main (int argc, char **argv)
{ /* Initialisation de GTK+ */
    gtk_init (&argc, &argv);


     _widgets *g_widget ;

     GtkWidget *ButtonExplore;
     g_widget=g_slice_new(_widgets);


     builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");

     fctacceuil(ButtonExplore,g_widget);





   /* Lancement de la boucle principale */

   gtk_main ();

   return 0;
}



