#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int find_bigger(int t, int matrice[t][t]){
  
    //déclaration:
    int t_ph=t;
    int x=0;
    int y=0;
    int x2=0;
    int y2=0;
    int content=0;
    int temp_content=0;

    //allocation de la matrice carrée de controle:
    int **ph = (int**)malloc(t_ph *sizeof(int*));
    for(int i=0; i<t_ph; i++ ){
        ph[i] = (int*)malloc(t_ph *sizeof(int)); 
    }

    
    //boucle de controle avec pour condition d'arrêt que la taille de la matrice de controle est trop petite:
while(t_ph!=0){
    
    //printf("matrice pour y2=%d:\n",y2); 
    content=0;
    
    
    //remplissage de la matrice de controle:
    //le remplissage se fait avec une matrice de plus en plus petite afin de détecter automatiquement la plus grande matrice
    //
  for(x=x2; x<x2+t_ph; x++ ){
    for(y=y2; y<y2+t_ph; y++ ){
        ph[x][y]=matrice[x][y];
        
        content=content+ph[x][y];
        //printf("[%d]",ph[x][y]);
        }
          //printf("best_size = %d\n", best_size);
          //printf("\n");

        }
        if(content > temp_content && content==t_ph*t_ph) temp_content = content;

        //recherche d'une matrice de 1 sur l'axe des "x" et "y"
        if(y2<t-t_ph){
                y2++;        
        }
              
        else if(x2<t-t_ph){
                x2++;
                y2=0;
        }
            
        //réduction et reinitialisation de la matrice de recherche
        else{
            t_ph--;
            x2=0;
            y2=0;
        }
      }
      return temp_content;
}

void main(){
     srand(time(NULL));   
     int n=10;
    int matrice[n][n];
  for(int x=0; x<n ; x++ ){
    for(int y=0; y<n; y++ ){
      matrice[x][y]= rand() %2;
  }
}
  for(int i=0; i<n; i++ ){
    for(int j=0; j<n; j++ ){
      printf("%3d",matrice[i][j]);
  }
    printf("\n");
}
int size = find_bigger(n,matrice);
printf("bigger matrice : %d\n", size);

}
