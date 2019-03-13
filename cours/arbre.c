#include<stdio.h>
#define err -1

typedef enum {vrai,faux}boolean;

typedef struct s_noeud
{
    int val;
    struct s_noeud *gauche;
    struct s_noeud *droit;

}noeud;


typedef noeud *arbre;

arbre creer_arbre(void){
    return NULL;
}

boolean estVide(arbre a){
    return a==NULL;
}

int racine(arbre a){
    if(estVide(a)){
        printf("erreur");
        exit(err);
    }
    else{
        return a->val;
    }  
}

arbre enracine(int v,arbre ag, arbre ad){
    arbre a=creer_arbre();
    a=malloc(sizeof(arbre));
    a->val=v;
    a->gauche=ag;
    a->droit=ad;
    return a;
}

int hauteur(arbre a){
    if(estVide(a))
        return 0;
    int d=hauteur(a->droit);
    int g=hauteur(a->gauche);
    if(d>g)
        g=d;
    return g+1;
}

arbre fils_droit(arbre a){
    assert(estVide(a)==faux);
    return a->droit;
}

arbre fils_gauche(arbre a){
    assert(estVide(a)==faux);
    return a->gauche;
}

void parcours(arbre a){
    if(!estVide(a)){
        printf("%d\t",racine(a));
        parcours(fils_droit(a));
        parcours(fils_gauche(a));
    }
}

arbre generer_arbre_parfait(int hauteur){
    arbre g,d,res;
    int v;
    if(hauteur==0)
        return creer_arbre();
    else{
        g=generer_arbre_parfait(hauteur-1);
        d=generer_arbre_parfait(hauteur-1);
        //v=ran();
        res=enracine(v,g,d);
        return res;
    }
}