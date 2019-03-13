#include<stdio.h>
#define err -1

typedef enum {vrai,faux}bool;

typedef struct s_noeud
{
    int val;
    struct s_noeud *gauche;
    struct s_noeud *droit;

}noeud;

typedef noeud *arbre;

bool cherche(arbre a, int valeur){
    if(estVide(a))
        return faux;
    if(a->val==valeur){
        return vrai;
    }
    else
    {
        if(valeur<a->val){
            cherche(fils_gauche(a),valeur);
        }
        else
        {
            cherche(fils_droit(a),valeur);
        }   
    }   
}

int insert(arbre a, int val){
    if(a==NULL){
        a=enracine(val,NULL,NULL);
        return 0;
    }
    if(cherche(a,val)){
        return -1;
    }
    else{
        if(a->val>val){
            insert(fils_droit(a),val);
        }
        else{
            insert(fils_gauche(a),val);
        }
    }
}

/*
suppresson:
l'element n'existe pas-> rien
l'element est une feuille ->suppression
l'"l"ment a un seul fils -> remplacement
........................ -> remplacement par son prédecesseur ou successeur
*/

int supprime(arbre a,int val){
    if(estVide(a)){
        return -1;
    }
    else
    {
        if(a->val==val){
            if(a->droit==NULL && a->gauche==NULL){//if(hauteur(a)==1)
                free(a);
            }
            if(fils_droit(a)==NULL && fils_gauche(a)!=NULL){
                arbre temp=a;
                a=fils_droit(a);
                free(temp);
            }
            if(fils_gauche(a)==NULL && fils_droit(a)!=NULL){
                arbre temp=a;
                a=fils_gauche(a);
                free(temp);
            }
            else{
                a->val=max(fils_gauche(a));
                supprime(fils_gauche(a),a->val);
            }
        }
        else{
            if(a->val<a){
                supprime(fils_gauche(a),val);
            }
            else
            {
                supprime(fils_droit(a),val);
            }
        }
    }
    
}


int minimum(arbre a){
    int min=0;
    if(estVide(a))
        return faux;

}