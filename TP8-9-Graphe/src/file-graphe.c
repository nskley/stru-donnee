#include <stdint.h>
#include <stdlib.h>
#include "../include/file-graphe.h"
#include "../../TP6-GRAPHES/solution/Graphes.h"
#include "../../TP6-GRAPHES/solution/Graphes_LC.c"

typedef enum boolean{vrai,faux}boolean;

typedef struct s_file{
    Sommet* tabsommets;
    int prem;
    int der;
    int taille;
}s_file;

boolean contient(Sommet s, File f){
    int i=0;
    while(i<f->taille && f->tabsommets[i]!=s){
        i++;
    }
    return i==f->taille;
}

Descendants (Graphe G, Sommet s, File f){
    Sommet sm=trouve_sommet(s,G);
    f=malloc(sizeof(s_file));
    int n=G->nb_sommets;
    
}
