#include <stdio.h>
#include <gtk/gtk.h>

GtkBuilder *builder;


typedef struct {
    GtkWidget   *window;
    int          diff;
    int          nbrjoueur;
    GtkWidget   *carte[14];

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

void fctjeufacile(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *window7;
    GtkWidget *carte[6];
    GtkBuilder *builder;


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window7=GTK_WIDGET(gtk_builder_get_object(builder,"PLATEAUDEJEUFACILE"));
    carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte1"));
    carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte2"));
    carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte3"));
    carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte4"));
    carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte5"));
    carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte6"));


    gtk_widget_show_all(window7);


}

 void fctjeudifficile(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *window;
    GtkWidget *carte[14];
    GtkBuilder *builder;


    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"PLATEAUDEJEUDIFFICILE"));
    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte1"));
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
    g_widget->carte[13]=GTK_WIDGET(gtk_builder_get_object(builder,"carte14"));


    g_signal_connect(G_OBJECT( g_widget->carte[0]),"clicked",G_CALLBACK(gtk_main_quit),NULL );
        g_signal_connect(G_OBJECT( g_widget->carte[1]),"clicked",G_CALLBACK(gtk_main_quit),NULL );




    gtk_widget_show_all(window);
 }

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


  void fctpseudo(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *window5;
    GtkWidget *pseudo1;
    GtkWidget *pseudo2;
    GtkWidget *pseudo3;
    GtkWidget *pseudo4;
    GtkBuilder *builder;
    GtkWidget  *confirmation ;

    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window5=GTK_WIDGET(gtk_builder_get_object(builder,"INSERTIONS DES PSEUDO DES JOUEUR "));
    pseudo1=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR1"));
    pseudo2=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR2"));
    pseudo3=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR3"));
    pseudo4=GTK_WIDGET(gtk_builder_get_object(builder,"PSEUDOJOUEUR4"));
    confirmation=GTK_WIDGET(gtk_builder_get_object(builder,"CONFIRMATION"));



  /*switch(g_widget->diff){
        case 1 :*/
    g_signal_connect(G_OBJECT(confirmation),"clicked",G_CALLBACK(fctjeudifficile),g_widget );


    gtk_widget_show_all(window5);
  }



  void fctchoixdenbrjoueur(GtkWidget *ButtonExplore,_widgets *g_widget){
    //definir les variables local de la fct
    GtkWidget *window4;
    GtkWidget *unjoueur;
    GtkWidget *deuxjoueur;
    GtkWidget *troisjoueur;
    GtkWidget *quatrejoueur;
    GtkBuilder *builder;

    //affecter a chaque variable son champ qui lui correspond
    builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
    window4=GTK_WIDGET(gtk_builder_get_object(builder,"CHOIX NOMBRES DE JOUEUR"));
    unjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"UNJOUEUR"));
    deuxjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"DEUXJOUEUR"));
    troisjoueur=GTK_WIDGET(gtk_builder_get_object(builder,"TROISJOUEUR"));
    quatrejoueur=GTK_WIDGET(gtk_builder_get_object(builder,"QUATREJOUEUR"));

    //donner le signal a chaque variable et la fct qui doit la suivre
    g_signal_connect(G_OBJECT(unjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );
    g_signal_connect(G_OBJECT(deuxjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );
    g_signal_connect(G_OBJECT(troisjoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );
    g_signal_connect(G_OBJECT(quatrejoueur),"clicked",G_CALLBACK(fctpseudo),g_widget );

    //faire apparaitre la fenetre
    gtk_widget_show_all(window4);

  }


  void fctchoixdediffulte(GtkWidget *ButtonExplore, _widgets *g_widget){
    printf("nbr joeur %d",g_widget->nbrjoueur);
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

    g_signal_connect(G_OBJECT(facile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );               // a retenir de remplacer fctquittez
    g_signal_connect(G_OBJECT(moyen),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );
    g_signal_connect(G_OBJECT(difficile),"clicked",G_CALLBACK(fctchoixdenbrjoueur),g_widget );

    gtk_widget_show_all(window);
  }

  void fcttop10(GtkWidget *ButtonExplore, gpointer data){
    }



void fctnizar(){
      GtkBuilder *builder;
      builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");




      GtkWidget *Stack ;

      Stack= GTK_WIDGET(gtk_builder_get_object(builder,"main"));
gtk_stack_set_visible_child_full (Stack,"page2",GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);}









int main (int argc, char **argv)
{ /* Initialisation de GTK+ */gtk_init (&argc, &argv);
    GtkWidget *jouer;
    GtkWidget *score;
    GtkWidget *quittez;
    GtkBuilder *builder;
    GtkWidget  *window;
    GtkWidget  *image ;
    _widgets   *g_widget;


  /* Creation de la fenetre principale de notre application */


 builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");
 window=GTK_WIDGET(gtk_builder_get_object(builder,"AFFICHAGEDESCORE"));
 gtk_builder_connect_signals(builder,NULL);

/*GtkWidget *Stack = GTK_WIDGET(gtk_builder_get_object(builder,"main"));
gtk_stack_set_visible_child_full(GTK_STACK(Stack),"page1",GTK_STACK_TRANSITION_TYPE_SLIDE_UP);*/
/* window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
 jouer=GTK_WIDGET(gtk_builder_get_object(builder,"jouer"));
 score=GTK_WIDGET(gtk_builder_get_object(builder,"score"));
 quittez=GTK_WIDGET(gtk_builder_get_object(builder,"quittez"));*/

  jouer=GTK_WIDGET(gtk_builder_get_object(builder,"intam"));
  g_widget->nbrjoueur=5;
  g_signal_connect(G_OBJECT(jouer),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget);


  /* Creation du conteneur principal */


  /*g_signal_connect(G_OBJECT(score),"clicked",G_CALLBACK(gtk_main_quit),NULL );

  g_signal_connect(G_OBJECT(jouer),"clicked",G_CALLBACK(fctchoixdediffulte),NULL);
  g_signal_connect(G_OBJECT(quittez),"clicked",G_CALLBACK(fctquittez),NULL );*/



  /* Affichage de la fenetre principale */
  gtk_widget_show_all (window);
  /* Lancement de la boucle principale */
  gtk_main ();
  return 0;

}


