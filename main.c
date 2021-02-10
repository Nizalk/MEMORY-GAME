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
    /*GtkWidget   *ni[5];*/
    int          diff;
    int          nbrjoueur;
    int          scorejoueur[4];
    int          indicecarte[14];
    int          cartechoisit[2];
    int          compteur ;
    int          numcarte;
    int          findepartie;
    int          joueurjoue;
    const gchar *pseudojoueur1;
    const gchar *pseudojoueur2;
    const gchar *pseudojoueur3;
    const gchar *pseudojoueur4;
    GtkWidget   *carte[14];
    GtkWidget   *carteimage[8];
    GtkWidget   *btncontrole[8];
    GtkWidget   *entrerpseudo[5];
    GtkWidget   *label;

}_widgets;


_joueur player[];


void fctjeumoyen(GtkWidget *ButtonExplore,_widgets *g_widget);
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

  if (fichier != NULL){fprintf(fichier,"%s   %d",player.pseudo,player.score);}

  fclose(fichier);

}


void affectationaleatoirecarte(int valcarte[],int n){

    int compteur[n/2];
    //affecte n zeros au tableaux compteur et des -1 pour tableau valcarte
    memset(compteur, 0, n/2 * sizeof(int));
    memset(valcarte, -1, n * sizeof(int));
    srand(time(0));

    int u=0, i=0;

    for(i=0;i<n/2;i++){

        while(compteur[i] < 2){
            // Tirer une valeur aleatoire entre 0 et 5
            u = rand()%n;

            if (valcarte[u] == -1){
                valcarte[u] = i;
                compteur[i]++;
            }
        }
    }

    }

/*void fctiniatiliser(_widgets *g_widget){

    for(int i=0;i<g_widget->diff;i++){
   GtkWidget *Image[g_widget->diff];
   Image[i]=gtk_image_new();
                    gtk_image_set_from_file(GTK_IMAGE(Image[i]),"./Images Projet C/BUTTON/doscarte.png");
                    gtk_button_set_image( g_widget->carte[i],GTK_IMAGE(Image[i]));}



}*/



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
               if(g_widget->indicecarte[g_widget->cartechoisit[0]]==g_widget->indicecarte[g_widget->cartechoisit[1]]){    //le joueur a eu juste sur le choix ddes cartes

                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[0]]);
                  gtk_widget_hide(g_widget->carte[g_widget->cartechoisit[1]]);

                  g_widget->findepartie ++;
                  g_widget->scorejoueur[g_widget->joueurjoue]++;


                  if(g_widget->findepartie==g_widget->diff/2){g_widget->findepartie=0;
                                                              g_widget->compteur=0;
                                                               g_widget->indicecarte[0]=1;
                                                              /*_joueur gameur ;
                                                                strcpy(gameur.pseudo,"hello");
                                                               itoa(gameur.score,g_widget->scorejoueur[0],10);


                                                               fctexporter(gameur);*/


                                                                   fctfindejeu(g_widget);}}


              else {/*Sleep(500);*/  //le joueur a eu faux sur le choix ddes cartes



                    gtk_button_set_image(g_widget->carte[g_widget->cartechoisit[0]],GTK_IMAGE(doscarte));

                    gtk_button_set_image(g_widget->carte[g_widget->cartechoisit[1]],GTK_IMAGE(doscarte2));

                    if(g_widget->nbrjoueur==g_widget->joueurjoue+1){gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur1);g_widget->nbrjoueur=0;}

                   else{ g_widget->joueurjoue++;
                    if(g_widget->joueurjoue<g_widget->nbrjoueur+1){ switch (g_widget->joueurjoue){

                                    case 1 :    {gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur2);g_widget->joueurjoue=2;};break;
                                    case 2 :    {gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur3);g_widget->joueurjoue=3;};break;
                                    case 3 :    {gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur4);g_widget->joueurjoue=4;};break;}}}


                       /*else{ gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur1);*/
                       g_widget->joueurjoue=0;}
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

    fctverificationduchoix(g_widget,image);}




void flipcarte2(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=1;

     fctverificationduchoix(g_widget,image);
}




void flipcarte3(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=2;

     fctverificationduchoix(g_widget,image);
}


void flipcarte4(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=3;

     fctverificationduchoix(g_widget,image);
}

void flipcarte5(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=4;

     fctverificationduchoix(g_widget,image);
}

void flipcarte6(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=5;

     fctverificationduchoix(g_widget,image);

}

void flipcarte7(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *image=gtk_image_new();
    g_widget->numcarte=6;
    fctverificationduchoix(g_widget,image);}





void flipcarte8(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=7;

     fctverificationduchoix(g_widget,image);
    }



void flipcarte9(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=8;

     fctverificationduchoix(g_widget,image);
}

void flipcarte10(GtkWidget *ButtonExplore,_widgets *g_widget){
     GtkWidget *image=gtk_image_new();
     g_widget->numcarte=9;

     fctverificationduchoix(g_widget,image);
}

void flipcarte11(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *image=gtk_image_new();
     g_widget->numcarte=10;

     fctverificationduchoix(g_widget,image);
}

void flipcarte12(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *image=gtk_image_new();
     g_widget->numcarte=11;

     fctverificationduchoix(g_widget,image);
}


void flipcarte13(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *image=gtk_image_new();
     g_widget->numcarte=12;

     fctverificationduchoix(g_widget,image);
}

void flipcarte14(GtkWidget *ButtonExplore,_widgets *g_widget){
    GtkWidget *image=gtk_image_new();
     g_widget->numcarte=13;

     fctverificationduchoix(g_widget,image);
}

void fctfindejeu(_widgets *g_widget){

    gtk_widget_hide(g_widget->btncontrole[0]);
    gtk_widget_hide(g_widget->window[4]);
    gtk_widget_hide(g_widget->window[5]);
    char labelscore[8];
    int transition;

    GtkWidget *btn[2];
    GtkWidget *label[8];

    g_widget->window[8]=GTK_WIDGET(gtk_builder_get_object(builder,"findepartie"));

    btn[0]=GTK_WIDGET(gtk_builder_get_object(builder,"btnreccomencerpartie"));



    switch (g_widget->diff){
        case FACILE :  g_signal_connect(G_OBJECT(btn[0]),"clicked",G_CALLBACK(fctjeufacile),g_widget);break;
        case MOYEN  :  g_signal_connect(G_OBJECT(btn[0]),"clicked",G_CALLBACK(fctjeumoyen),g_widget);break;

        case DIFFICILE :g_signal_connect(G_OBJECT(btn[0]),"clicked",G_CALLBACK(fctchoixdediffulte),g_widget);break;}


    btn[1]=GTK_WIDGET(gtk_builder_get_object(builder,"btnretouracceuil"));
    g_signal_connect(G_OBJECT(btn[1]),"clicked",G_CALLBACK(fctacceuil),g_widget);

    label[0]=GTK_WIDGET(gtk_builder_get_object(builder,"j1"));//pseudo
    gtk_label_set_text(GTK_LABEL(label[0]),g_widget->pseudojoueur1);



    label[1]=GTK_WIDGET(gtk_builder_get_object(builder,"s1"));  //score
    itoa(g_widget->scorejoueur[0],labelscore,10);
    gtk_label_set_text(GTK_LABEL(label[1]),labelscore);

    label[2]=GTK_WIDGET(gtk_builder_get_object(builder,"j2"));
    gtk_label_set_text(GTK_LABEL(label[2]),g_widget->pseudojoueur2);//pseudo

    label[3]=GTK_WIDGET(gtk_builder_get_object(builder,"s2"));  //score
    itoa(g_widget->scorejoueur[2],labelscore,10);
    gtk_label_set_text(GTK_LABEL(label[3]),labelscore);

    label[4]=GTK_WIDGET(gtk_builder_get_object(builder,"j3"));
    gtk_label_set_text(GTK_LABEL(label[4]),g_widget->pseudojoueur3);//pseudo

    label[5]=GTK_WIDGET(gtk_builder_get_object(builder,"s3"));  //score
    itoa(g_widget->scorejoueur[1],labelscore,10);
    gtk_label_set_text(GTK_LABEL(label[5]),labelscore);

    label[6]=GTK_WIDGET(gtk_builder_get_object(builder,"j4"));  //pseudo
    gtk_label_set_text(GTK_LABEL(label[6]),g_widget->pseudojoueur4);


    label[7]=GTK_WIDGET(gtk_builder_get_object(builder,"s4"));  //score
    itoa(g_widget->scorejoueur[3],labelscore,10);
    gtk_label_set_text(GTK_LABEL(label[7]),labelscore);




    gtk_window_set_position(g_widget->window[8],GTK_WIN_POS_CENTER);



    gtk_widget_show_all(g_widget->window[8]);
}








void fctjeufacile(GtkWidget *ButtonExplore,_widgets *g_widget){

    gtk_widget_hide(g_widget->window[3]);
    gtk_widget_hide(g_widget->window[8]);

    g_widget->cartechoisit[0]=-1 ;
    g_widget->cartechoisit[1]=-1 ;
    g_widget->compteur=0;
    g_widget->findepartie=0;
    g_widget->joueurjoue=0;

    for(int i=0;i<g_widget->nbrjoueur;i++){g_widget->scorejoueur[i]=0;}



    affectationaleatoirecarte(g_widget->indicecarte,FACILE);

    g_widget->window[4]=GTK_WIDGET(gtk_builder_get_object(builder,"facile"));

    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte11"));
    g_signal_connect(G_OBJECT(g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),g_widget);

    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte12"));
    g_signal_connect(G_OBJECT(g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),g_widget);

    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte13"));
    g_signal_connect(G_OBJECT(g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte3),g_widget);

    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte21"));
    g_signal_connect(G_OBJECT(g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte4),g_widget);

    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte22"));
    g_signal_connect(G_OBJECT(g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte5),g_widget);

    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte23"));
    g_signal_connect(G_OBJECT(g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte6),g_widget);

    g_widget->label=GTK_WIDGET(gtk_builder_get_object(builder,"joueurquijoue"));
    gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur1);

    gtk_window_set_position(g_widget->window[4],GTK_WIN_POS_CENTER);



    gtk_widget_show_all(g_widget->window[4]);


}

 void fctjeudifficile(GtkWidget *ButtonExplore,_widgets *g_widget){

    gtk_widget_hide(g_widget->window[3]);
    gtk_widget_hide(g_widget->window[8]);

    GtkWidget  *player;
    g_widget->cartechoisit[0]=-1 ;
    g_widget->cartechoisit[1]=-1 ;
    g_widget->compteur=0;
    g_widget->findepartie=0;
    g_widget->joueurjoue=0;

    for(int i=0;i<g_widget->nbrjoueur;i++){g_widget->scorejoueur[i]=0;}

    affectationaleatoirecarte(g_widget->indicecarte,DIFFICILE);


    g_widget->window[5]=GTK_WIDGET(gtk_builder_get_object(builder,"difficile"));

    player=GTK_WIDGET(gtk_builder_get_object(builder,"playeringame3"));



    gtk_label_set_text(GTK_LABEL(player),g_widget->pseudojoueur1);

    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte311"));
    g_signal_connect(G_OBJECT( g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),g_widget );

    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte312"));
    g_signal_connect(G_OBJECT( g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),g_widget );

    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte321"));
    g_signal_connect(G_OBJECT( g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte3),g_widget);

    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte322"));
    g_signal_connect(G_OBJECT( g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte4),g_widget );

    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte323"));
    g_signal_connect(G_OBJECT( g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte5),g_widget );

    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte324"));
    g_signal_connect(G_OBJECT( g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte6),g_widget );

    g_widget->carte[6]=GTK_WIDGET(gtk_builder_get_object(builder,"carte325"));
    g_signal_connect(G_OBJECT( g_widget->carte[6]),"clicked",G_CALLBACK(flipcarte7),g_widget );

    g_widget->carte[7]=GTK_WIDGET(gtk_builder_get_object(builder,"carte326"));
    g_signal_connect(G_OBJECT( g_widget->carte[7]),"clicked",G_CALLBACK(flipcarte8),g_widget );

    g_widget->carte[8]=GTK_WIDGET(gtk_builder_get_object(builder,"carte331"));
    g_signal_connect(G_OBJECT( g_widget->carte[8]),"clicked",G_CALLBACK(flipcarte9),g_widget );

    g_widget->carte[9]=GTK_WIDGET(gtk_builder_get_object(builder,"carte332"));
    g_signal_connect(G_OBJECT( g_widget->carte[9]),"clicked",G_CALLBACK(flipcarte10),g_widget );

    g_widget->carte[10]=GTK_WIDGET(gtk_builder_get_object(builder,"carte333"));
    g_signal_connect(G_OBJECT( g_widget->carte[10]),"clicked",G_CALLBACK(flipcarte11),g_widget );

    g_widget->carte[11]=GTK_WIDGET(gtk_builder_get_object(builder,"carte334"));
    g_signal_connect(G_OBJECT( g_widget->carte[11]),"clicked",G_CALLBACK(flipcarte12),g_widget );

    g_widget->carte[12]=GTK_WIDGET(gtk_builder_get_object(builder,"carte335"));
    g_signal_connect(G_OBJECT( g_widget->carte[12]),"clicked",G_CALLBACK(flipcarte13),g_widget );

    g_widget->carte[13]=GTK_WIDGET(gtk_builder_get_object(builder,"carte336"));
    g_signal_connect(G_OBJECT( g_widget->carte[13]),"clicked",G_CALLBACK(flipcarte14),g_widget );




    gtk_window_set_position(g_widget->window[5],GTK_WIN_POS_CENTER);



    gtk_widget_show_all(g_widget->window[5]);





 };

void fctjeumoyen(GtkWidget *ButtonExplore,_widgets *g_widget){

    gtk_widget_hide(g_widget->window[3]);
    gtk_widget_hide(g_widget->window[8]);

    //inialiser les valeurs

    g_widget->cartechoisit[0]=-1 ;
    g_widget->cartechoisit[1]=-1 ;
    g_widget->compteur=0;
    g_widget->findepartie=0;
    g_widget->joueurjoue=0;

    for(int i=0;i<g_widget->nbrjoueur;i++){g_widget->scorejoueur[i]=0;}


    affectationaleatoirecarte(g_widget->indicecarte,MOYEN);

    g_widget->btncontrole[0]=GTK_WIDGET(gtk_builder_get_object(builder,"moyen"));

    g_widget->carte[0]=GTK_WIDGET(gtk_builder_get_object(builder,"carte211"));
    g_signal_connect(G_OBJECT(g_widget->carte[0]),"clicked",G_CALLBACK(flipcarte1),g_widget);

    g_widget->carte[1]=GTK_WIDGET(gtk_builder_get_object(builder,"carte212"));
    g_signal_connect(G_OBJECT(g_widget->carte[1]),"clicked",G_CALLBACK(flipcarte2),g_widget);

    g_widget->carte[2]=GTK_WIDGET(gtk_builder_get_object(builder,"carte213"));
    g_signal_connect(G_OBJECT(g_widget->carte[2]),"clicked",G_CALLBACK(flipcarte3),g_widget);

    g_widget->carte[3]=GTK_WIDGET(gtk_builder_get_object(builder,"carte214"));
    g_signal_connect(G_OBJECT(g_widget->carte[3]),"clicked",G_CALLBACK(flipcarte4),g_widget);

    g_widget->carte[4]=GTK_WIDGET(gtk_builder_get_object(builder,"carte215"));
    g_signal_connect(G_OBJECT(g_widget->carte[4]),"clicked",G_CALLBACK(flipcarte5),g_widget);

    g_widget->carte[5]=GTK_WIDGET(gtk_builder_get_object(builder,"carte221"));
    g_signal_connect(G_OBJECT(g_widget->carte[5]),"clicked",G_CALLBACK(flipcarte6),g_widget);

    g_widget->carte[6]=GTK_WIDGET(gtk_builder_get_object(builder,"carte222"));
    g_signal_connect(G_OBJECT(g_widget->carte[6]),"clicked",G_CALLBACK(flipcarte7),g_widget);

    g_widget->carte[7]=GTK_WIDGET(gtk_builder_get_object(builder,"carte223"));
    g_signal_connect(G_OBJECT(g_widget->carte[7]),"clicked",G_CALLBACK(flipcarte8),g_widget);

    g_widget->carte[8]=GTK_WIDGET(gtk_builder_get_object(builder,"carte224"));
    g_signal_connect(G_OBJECT(g_widget->carte[8]),"clicked",G_CALLBACK(flipcarte9),g_widget);

    g_widget->carte[9]=GTK_WIDGET(gtk_builder_get_object(builder,"carte225"));
    g_signal_connect(G_OBJECT(g_widget->carte[9]),"clicked",G_CALLBACK(flipcarte10),g_widget);

    g_widget->label=GTK_WIDGET(gtk_builder_get_object(builder,"joueurjou"));

    gtk_label_set_text(GTK_LABEL(g_widget->label),g_widget->pseudojoueur1);

    gtk_window_set_position(g_widget->btncontrole[0],GTK_WIN_POS_CENTER);


    gtk_widget_show_all(g_widget->btncontrole[0]);



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


    system("cls");
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


void fctimporter(int nbrjoueurdansfichier ){

         FILE *fichier;

         fichier=fopen("scorejoueur.txt","r");

         int i=0;

         while(fscanf(fichier,"%s %d",player[i].pseudo,&player[i].score)!=EOF){i++;}

         nbrjoueurdansfichier=i ;

         fclose(fichier);}


 void fcttridecroissant(/*int nbrjoueur*/){
     //_joueur player[n] variable global
                 _joueur  change;
                  int i,j;

                  for(i=0;i<60;i++){
                        for(j=i+1;j<60;j++){
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

       fcttridecroissant(/*nbrjoueurdansfichier*/);


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


        gtk_widget_hide(g_widget->window[6]);

        gtk_widget_hide(g_widget->window[7]);
        gtk_widget_hide(g_widget->window[1]);
        gtk_widget_hide(g_widget->window[4]);

        GtkWidget *jouer;
        GtkWidget *score;
        GtkWidget *quittez;


        GtkWidget *window;
        _joueur player ;

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


int main (int argc, char **argv){

    /* Initialisation de GTK+ */
     gtk_init (&argc, &argv);

     _widgets *g_widget ;

     GtkWidget *ButtonExplore;


     g_widget=g_slice_new(_widgets);                    //allouer de l'espace pour g_widget


     builder=gtk_builder_new_from_file("INTERFACEDUJEU.glade");   //importer notre builder du glade

     fctacceuil(ButtonExplore,g_widget);

    /* Lancement de la boucle principale */

      gtk_main ();

   return 0;
}




