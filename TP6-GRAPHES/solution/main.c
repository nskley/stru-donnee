#include "Graphes.h"
#include <stdlib.h>
#include <stdio.h>



int main() {
	Graphe G;
	Arc a;
	printf("== Gestion du Graphe ==\n");
	G = initialiseGraphe();

	a = creerArc(1,2);
	ajouteArc(a,G);

	a = creerArc(2,1);
	ajouteArc(a,G);
	
	a = creerArc(2,2);
	ajouteArc(a,G);	
	
	afficheArc(a);
	printf("on affiche la liste des arcs\n");
	afficheArcs(G);

	return(1);
}
