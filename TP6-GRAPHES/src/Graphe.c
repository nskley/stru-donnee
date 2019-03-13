#include<stdio.h>
#include<stdlib.h>
#include"../include/Graphe.h"

typedef struct sommet
{
    int s;
} sommet;
typedef struct s_arcs
{
    sommet s1;
    sommet s2;
}s_arcs;

typedef struct s_graphe
{
    char **mat;
    int taille;
}s_graphe;





void initialiseGraphe(Graphe G){
    G=malloc(sizeof(s_graphe));
    printf("entrer le nobre de sommet" );
    int nbsommets;
    scanf("%d", &nbsommets);
    G->mat=(char **)malloc(nbsommets*sizeof(char *));
    for(int i=0; i<nbsommets; i++){
        G->mat[i]=(char *)malloc(nbsommets*sizeof(char));
    }
    G->taille=nbsommets;
    char *tab=malloc(G->taille*sizeof(char));
    for(int i=0; i< G->taille; i++){
        printf("entrer le %d ieme sommet",i);
        scanf("%d",tab+i);
    }
    
    for(int i = 0; i < G->taille; i++)
    {
        for(int j = 0; j < G->taille; j++)
        {
            if(tab[i]%tab[j]==0)
                G->mat[i][j]='1';
            else
                 G->mat[i][j]=' ';
            printf("%c |",G->mat[i][j]);    
        }
        printf("\n");
    }
    
}

void ajouteArc(Arc a, Graphe G){
    G->mat[a->s1.s-1][a->s2.s-1]=1;
}

void supprimeArc(Arc a, Graphe G){
    G->mat[a->s1.s-1][a->s2.s-1]=0;
}