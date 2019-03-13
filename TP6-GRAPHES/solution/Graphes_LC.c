/*
 * Graphes_LC.c
 */
#include "Graphes.h"
#include <stdlib.h>
#include <stdio.h>

struct _sommet {
	int indice;
	char nom;
	Sommet suivant;
};

struct _arc {
	int Ix;
	int Iy;
	Arc suivant;
};

struct _graphe {
	Sommet liste_sommets;
	Arc liste_arcs;
	int nb_arcs;
	int nb_sommets;
};

/**    Fonctions    */

/** Initialisation de Graphe */
Graphe initialiseGraphe() {
	Graphe G = (Graphe) malloc (sizeof(Graphe));
	G->liste_sommets = NULL;
	G->liste_arcs = NULL;
	G->nb_arcs=0;
	G->nb_sommets=0;
	return(G);
}

int existeArc(Arc a, Graphe G) {
	int Egal = -1; // boolean 
	
	if (G->liste_arcs == NULL)
		return(-1);
	else {
		Arc b = G->liste_arcs;
		
		while ((b!= NULL) || (Egal == -1))
		{
			if ((a->Ix == b->Ix) && (a->Iy == b->Iy)) 
				Egal = 1;
			b = b->suivant;
		}
	}
	return(Egal);
}


/** Ajout d'un Arc */
void ajouteArc(Arc a, Graphe G) {
	if(! existeArc(a,G)){
		if (G->liste_arcs == NULL) {
		G->liste_arcs = a;
		}	
		else { // ajouter l'arc à la fin des arcs 
			// aller au bout de la chaîne
			Arc  ac;
			ac = G->liste_arcs;	
			while (ac->suivant != NULL) {
				ac = ac->suivant; // passer au suivant
			}
			// ajouter l'arc
			ac->suivant = a;
		}
		G->nb_arcs++;
	}

}

void supprimeArc(Arc a, Graphe G) {
	if (existeArc(a,G)) { // si l'arc existe dans le Graphe
		Arc ac;
		ac = G->liste_arcs;	
		while ( ac->suivant->Ix!=a->suivant->Ix && ac->suivant->Iy!=a->suivant->Iy){
			ac = ac->suivant;
		}
		if(ac->suivant->suivant != NULL){
			Arc temp= ac->suivant;
			ac->suivant=ac->suivant->suivant;
			free(temp);
		}
		else{
			ac->suivant = NULL;
		}
		G->nb_arcs--;
	}
	else
	{
		printf("Arc inexistant");
	}
	
}


/** Créer un arc */
Arc creerArc(int Ix, int Iy) {
	Arc a = (Arc) malloc(sizeof(Arc));
	a->Ix = Ix;
	a->Iy = Iy;
	a->suivant = NULL;
	return(a);
}

void afficheArc(Arc a) {
	printf("___Arc___\n");
	printf("(%d,%d)\n",a->Ix,a->Iy);
}

/** Affiche les arcs */
void afficheArcs(Graphe G) {	
	if (G->liste_arcs == NULL)
		printf("Pas d'arcs dans le graphe !\n");
	else {
		Arc a = G->liste_arcs;
		printf("Liste des arcs dans le graphe\n");
		while (a!= NULL)
		{
			printf("\tArc (%d,%d)\n",a->Ix,a->Iy);
			a = a->suivant;
		}
	}
	printf("------------------------\n");
}

Sommet trouve_sommet(int indice,Graphe G){
	if(G==NULL)
		return NULL;
	
	if(G->nb_sommets>=indice){
		Sommet sm=G->liste_sommets;
		while(sm->indice!=indice){
			sm->suivant;
		}
		return sm;
	}
}

