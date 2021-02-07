typedef struct{
     int score;
     char pseudo[10] ;
}_joueur;

typedef struct {
    GtkWidget   *window;
    GtkWidget   *carte[14];

    int          diff;
    int          nbrjoueur;



}_widgets;


