typedef  sommet *Sommet;
typedef struct s_arcs *Arc;
typedef struct s_graphe *Graphe;
void initialiseGraphe(Graphe G); // permet d’ajouter des sommets au graphe
void ajouteArc(Arc a, Graphe G); // ajoute l’arc a au graphe
void supprimeArc(Arc a, Graphe G); // supprime l’arc a du graphe
int existeSommet(Sommet s, Graphe G); // retourne 1 si le sommet s existe dans le graphe
int existeArc(Arc a, Graphe G); // retourne 1 si l’arc a existe dans le graphe
