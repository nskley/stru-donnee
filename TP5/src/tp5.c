#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"../include/maLibMath.h"

point demande_point(void){
    point p;
    scanf("%f",&p.x);
    scanf("%f",&p.y);
    scanf("%f",&p.z);
    return p;
}

point Creer_Point(float x,float y,float z){
    point p;
    p.x=x;
    p.y=y;
    p.z=z;
    return p;
}

vecteur Vectorise(point pt1,point pt2){
    vecteur v;
    v.vx=pt2.x-pt1.x;
    v.vy=pt2.y-pt1.y;
    v.vz=pt2.z-pt1.z;
    return v;
}

vecteur Produit_Vectoriel(vecteur V1,vecteur V2){
    vecteur v;
    v.vx=(V1.vy*V2.vz)-(V1.vz*V2.vy);
    v.vy=(V1.vz*V2.vx)-(V1.vx*V2.vz);
    v.vz=(V1.vx*V2.vy)-(V1.vy*V2.vx);
    return v;
}

float Produit_Scalaire(vecteur v1,vecteur v2){
    return v1.vx*v2.vx+v1.vy*v2.vy+v1.vz*v2.vz;
}

float Norme(vecteur v){
    return (sqrt(v.vx*v.vx+v.vy*v.vy+v.vz*v.vz));
}

Equation Equation_Plan(point G,point H,point I){
    vecteur A=Vectorise(H,G);
    vecteur B=Vectorise(I,G);
    vecteur n=Produit_Vectoriel(A,B);
    Equation eq;
    eq.coefs[0]=n.vx;
    eq.coefs[1]=n.vy;
    eq.coefs[2]=n.vz;
    eq.coefs[3]=-(n.vx*(G.x)+n.vy*(G.y)+n.vz*(G.z));
    printf("equation du plan: %.1fx + %.1fy + %.1fz + %.1f = 0\n",eq.coefs[0],eq.coefs[1],eq.coefs[2],eq.coefs[3]);
    return eq;
}