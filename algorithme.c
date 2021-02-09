/*
typedef struct {

char pseudo[15];
int  score;}_joueur;


void fctexporter(_joueur player ){
  FILE *fichier;

  fichier=fopen("scorejoueur.txt","w");
  if (fichier != NULL){
  fprintf(fichier,"%s     %d",player.pseudo,player.score);}

  fclose(fichier);
}



void fcttridecroissant(){//_joueur player[n] variable global
  _joueur  change;
  for(int i=0;i<n;i++){    for(j=i+1;j<n;j++){
                       if(player[i].score > player[j].score){
                       change = player[i];
                       palyer[i] = player[j];
                        player[j]=change;}}}}*/
/*void affectationaleatoirecarte(int n){
    int valcarte[n];
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
    }*/

