#include <stdio.h>
#include <gtk/gtk.h>
#define FACILE 1
#define  MOYEN 2
#define  DIFFICILE 3


GtkBuilder *builder;
typedef struct {

char pseudo[15];
int  score;}_joueur;

typedef struct {
    GtkWidget   *window[8];
    int          diff;
    int          nbrjoueur;
    int          scorejoueur[4];
    const gchar *pseudojoueur1;
    const gchar *pseudojoueur2;
    const gchar *pseudojoueur3;
    const gchar *pseudojoueur4;
    GtkWidget   *carte[14];
    GtkWidget   *entrerpseudo[5];

}_widgets;




void ma (int argc, char **argv)
{ GtkWidget *button;
GtkBuilder *builder;
builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");

  GtkWidget *p_window = NULL;
  GtkWidget *p_main_box = NULL;
  GtkWidget *imageTop10 ;
  /* Initialisation de GTK+ */
  gtk_init (&argc, &argv);

  /* Creation de la fenetre principale de notre application */
  p_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (G_OBJECT (p_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);



  /* Creation du conteneur principal */
  button=gtk_button_new();
  gtk_window_set_default_size(p_window,1000,800);
  GtkWidget *image;
  button=gtk_button_new();
  imageTop10 = gtk_image_new_from_file("./background.png");
  gtk_container_add(GTK_CONTAINER(button),imageTop10);
  gtk_container_add(GTK_CONTAINER(p_window),button);
    gtk_layout_put(GTK_LAYOUT(p_window),imageTop10,0,0);

  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(gtk_main_quit),NULL );


   gtk_window_set_position(p_window,GTK_WIN_POS_CENTER);
  /* Affichage de la fenetre principale */
  gtk_widget_show_all (p_window);
  /* Lancement de la boucle principale */
  gtk_main ();
  return 0;

}

void fctexporter(_joueur player ){
  FILE *fichier;

  fichier=fopen("scorejoueur.txt","w");
  if (fichier != NULL){
  fprintf(fichier,"%s     %d",player.pseudo,player.score);}

  fclose(fichier);
}



void hide(GtkWidget *ButtonExplore,GtkWidget *carte){

     gtk_widget_destroy(carte);




}







void fctjeufacile(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_widget_hide(g_widget->window[0]);
    GtkWidget *window7;
    GtkWidget *carte[6];
    GtkBuilder *builder;
    GtkWidget  *player ;


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    g_widget->window[1]=GTK_WIDGET(gtk_builder_get_object(builder,"facile"));

    carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carteun"));
    carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte2"));
    carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte3"));
    carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte4"));
    carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte5"));
    carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte6"));
    player=GTK_WIDGET(gtk_builder_get_object(builder,"IMAGE1"));
    g_signal_connect(G_OBJECT(carte[0]),"clicked",G_CALLBACK(hide),carte[0]);

    gtk_widget_show_all(g_widget->window[1]);


}

 void fctjeudifficile(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *window;

    GtkBuilder *builder;
    GtkWidget  *player;

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"PLATEAUDEJEUDIFFICILE"));

    player=GTK_WIDGET(gtk_builder_get_object(builder,"PLAYER"));
    gtk_label_set_text(GTK_LABEL(player),g_widget->pseudojoueur1);

    /*g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte1"));
    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte2"));
    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte3"));
    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte4"));
    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte5"));
    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte6"));
    g_widget->carte[6]=GTK_WIDGET(gtk_builder_get_object(builder,"carte7"));
    g_widget->carte[7]=GTK_WIDGET(gtk_builder_get_object(builder,"carte8"));
    g_widget->carte[8]=GTK_WIDGET(gtk_builder_get_object(builder,"carte9"));
    g_widget->carte[9]=GTK_WIDGET(gtk_builder_get_object(builder,"carte10"));
    g_widget->carte[10]=GTK_WIDGET(gtk_builder_get_object(builder,"carte11"));
    g_widget->carte[11]=GTK_WIDGET(gtk_builder_get_object(builder,"carte12"));
    g_widget->carte[12]=GTK_WIDGET(gtk_builder_get_object(builder,"carte13"));
    g_widget->carte[13]=GTK_WIDGET(gtk_builder_get_object(builder,"carte14"));*/


    /*g_signal_connect(G_OBJECT( g_widget->carte[0]),"clicked",G_CALLBACK(gtk_main_quit),NULL );
    g_signal_connect(G_OBJECT( g_widget->carte[1]),"clicked",G_CALLBACK(gtk_main_quit),NULL );*/




    gtk_widget_show_all(window);
 };

void fctjeumoyen(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *window;
    GtkWidget *carte[10];
    GtkBuilder *builder;


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
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
    GtkWidget *window2;
    GtkWidget *confirmer;
    GtkWidget *rejet;
    GtkBuilder *builder;

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window2=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION DE QUITTEZ"));
    rejet=GTK_WIDGET(gtk_builder_get_object(builder,"REJET"));
    confirmer=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMER"));

    g_signal_connect(G_OBJECT(confirmer),"clicked",G_CALLBACK(gtk_main_quit),g_widget );
    g_signal_connect(G_OBJECT(rejet),"clicked",G_CALLBACK(gtk_main_quit),g_widget );

    gtk_widget_show_all(window2);

  }

  void retenirpseudo(GtkWidget *ButtonExplore,_widgets *g_widget){
      g_widget->pseudojoueur1=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[1]));
      g_widget->pseudojoueur2=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[2]));
      g_widget->pseudojoueur3=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[3]));
      g_widget->pseudojoueur4=gtk_entry_get_text(GTK_ENTRY(g_widget->entrerpseudo[4]));
  }





  void fctpseudo(GtkWidget *ButtonExplore,_widgets *g_widget){
    gtk_widget_hide(g_widget->window[2]);

    GtkWidget *pseudo1;
    GtkWidget *pseudo2;
    GtkWidget *pseudo3;
    GtkWidget *pseudo4;
    GtkBuilder *builder;
    GtkWidget  *confirmation ;

    printf("nbr joeur %d",g_widget->nbrjoueur);

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");

    switch(g_widget->nbrjoueur){
        case 1 : g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"UNPSEUDO"));break;

        case 2 : g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"DEUXPSEUDO "));break;

        case 3 : g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"TROISPSEUDO"));break;

        case 4 : g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"QUATREPSEUDO"));break;

        }


    g_widget->window[3]=GTK_WIDGET(gtk_builder_get_object(builder,"UNPSEUDO"));

   /* g_widget->entrerpseudo[1]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR1"));
    g_widget->entrerpseudo[2]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR2"));
    g_widget->entrerpseudo[3]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR3"));
    g_widget->entrerpseudo[4]=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR4"));
    confirmation=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION"));*/




    switch(g_widget->diff){

     case FACILE :     {g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(retenirpseudo),g_widget );
                        g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(fctjeufacile),g_widget );};break;

     case MOYEN:       {g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(retenirpseudo),g_widget );
                        g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(fctjeumoyen),g_widget );};break;

     case DIFFICILE:   {g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(retenirpseudo),g_widget );
                        g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(fctjeudifficile),g_widget );};break;

    }


    gtk_widget_show_all(g_widget->window[3]);
  }





  void ajoutnbrjoueur1(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=1;}

  void ajoutnbrjoueur2(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=2;}

  void ajoutnbrjoueur3(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=3;}

  void ajoutnbrjoueur4(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->nbrjoueur=4;}



  void fctchoixdenbrjoueur(GtkWidget *ButtonExplore,_widgets *g_widget){
    //definir les variables local de la fct
    gtk_widget_hide(g_widget->window[1]);

    GtkWidget *unjoueur;
    GtkWidget *deuxjoueur;
    GtkWidget *troisjoueur;
    GtkWidget *quatrejoueur;
    GtkBuilder *builder;
    GtkWidget  *goback;



    //affecter a chaque variable son champ qui lui correspond

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");

    g_widget->window[2]=GTK_WIDGET(gtk_builder_get_object(builder,"NBRJOUEURCHOICE"));

    unjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"UN JOUEUR"));
    deuxjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"DEUJOUEUR"));
    troisjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"TROIJOUEUR"));
    quatrejoueur=GTK_WIDGET(gtk_builder_get_object(builder,"QUATRE JOUEUR"));
    goback=GTK_WIDGET(gtk_builder_get_object(builder,"RETOUR"));



    //donner le signal a chaque variable et la fct qui doit la suivre

    g_signal_connect(G_OBJECT(unjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur1),g_widget );
    g_signal_connect(G_OBJECT(unjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );


    g_signal_connect(G_OBJECT(deuxjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur2),g_widget );
    g_signal_connect(G_OBJECT(deuxjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    g_signal_connect(G_OBJECT(troisjoueur),"clicked",G_CALLBACK(ajoutnbrjoueur3),g_widget );
    g_signal_connect(G_OBJECT(troisjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    g_signal_connect(G_OBJECT(quatrejoueur),"clicked",G_CALLBACK(ajoutnbrjoueur4),g_widget );
    g_signal_connect(G_OBJECT(quatrejoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    /*g_signal_connect(G_OBJECT(goback),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget );*/


    gtk_window_set_position(g_widget->window[2],GTK_WIN_POS_CENTER);
    //faire apparaitre la fenetre
    gtk_widget_show_all(g_widget->window[2]);

  }



   void ajoutfacile(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=FACILE;}



   void ajoutmoyen(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=MOYEN;}


   void ajoutdifficile(GtkWidget *ButtonExplore, _widgets *g_widget){g_widget->diff=DIFFICILE;}




   void fctchoixdediffulte(GtkWidget *ButtonExplore, _widgets *g_widget){


    gtk_widget_hide(g_widget->window[0]);

    GtkWidget *facile;
    GtkWidget *moyen;
    GtkWidget *difficile;
    GtkBuilder *builder;


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    g_widget->window[1]=GTK_WIDGET(gtk_builder_get_object(builder,"DIFFICULTCHOICE"));

    facile=GTK_WIDGET(gtk_builder_get_object(builder,"BTNFACILE"));
    moyen=GTK_WIDGET(gtk_builder_get_object(builder,"BTNMOYEN"));
    difficile=GTK_WIDGET(gtk_builder_get_object(builder,"BTNDIFFICILE"));

    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(ajoutfacile),g_widget );
    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(ajoutmoyen),g_widget );
    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );


    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(ajoutdifficile),g_widget );
    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    gtk_window_set_position(g_widget->window[1],GTK_WIN_POS_CENTER);

    gtk_widget_show_all(g_widget->window[1]);
  }

  void fcttop10(GtkWidget *ButtonExplore, gpointer data){
    }



void fctnizar(GtkWidget *ButtonExplore, _widgets *g_widget){
    gtk_widget_hide(g_widget->window);



    GtkWidget *facile;
    GtkWidget *moyen;
    GtkWidget *difficile;
    GtkBuilder *builder;
    GtkWidget *window ;

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"CHOIX DE DIFFUCLTE"));
    facile=GTK_WIDGET(gtk_builder_get_object(builder,"FACILE"));
    moyen=GTK_WIDGET(gtk_builder_get_object(builder,"MOYEN"));
    difficile=GTK_WIDGET(gtk_builder_get_object(builder,"DIFFICILE"));
    gtk_widget_destroy(facile);
    /*g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(ajoutfacile),g_widget );
    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(ajoutmoyen),g_widget );
    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );


    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(ajoutdifficile),g_widget );
    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );*/
    gtk_window_set_position(window,GTK_WIN_POS_CENTER);
    gtk_widget_show_all(window);}
      /*
      GtkWidget *Stack ;

      Stack= GTK_WIDGET(gtk_builder_get_object(builder,"main"));
      gtk_stack_set_visible_child_full (Stack,"page2",GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);}*/


GtkStack *stack;
GtkWidget *p1;
GtkWidget *p2;





void exemple(GtkWidget *ButtonExplore, _widgets *g_widget){


      gtk_stack_set_visible_child_full (stack,"page2",GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);


}




int main (int argc, char **argv)
{ /* Initialisation de GTK+ */
    gtk_init (&argc, &argv);
    GtkWidget *jouer;
    GtkWidget *score;
    GtkWidget *quittez;
    GtkBuilder *builder;
     _widgets *g_widget ;
    GtkWidget *window;
    _joueur player ;

    g_widget=g_slice_new(_widgets);
   /* player.pseudo="nizar";
    player.score=5820;
    fctexporter(player);*/

  /* Creation de la fenetre principale de notre application */


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");


    g_widget->window[0]=GTK_WIDGET(gtk_builder_get_object(builder,"ACCEUIL"));



    jouer=GTK_WIDGET(gtk_builder_get_object(builder,"BTNJOUER"));
    score=GTK_WIDGET(gtk_builder_get_object(builder,"BTNSCORE"));
    quittez=GTK_WIDGET(gtk_builder_get_object(builder,"BTNQUITTEZ"));



  /* Creation du conteneur principal */


    g_signal_connect(G_OBJECT(score),"clicked",G_CALLBACK(gtk_main_quit),g_widget );
    g_signal_connect(G_OBJECT(jouer),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget);
    g_signal_connect(G_OBJECT(quittez),"clicked",G_CALLBACK(fctquittez),g_widget );


   gtk_window_set_position(g_widget->window[0],GTK_WIN_POS_CENTER);

   /* Affichage de la fenetre principale */

   gtk_widget_show_all (g_widget->window[0]);





   /* Lancement de la boucle principale */

   gtk_main ();
   return 0;
}



