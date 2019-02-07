#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"complexe.h"
enum form{cartesien,polaire}

typedef struct{
    float a;
    float b;
}complexe_cartesien;

typedef struct{
    float rho;
    float theta;
}complexe_polaire;


typedef union{
    complexe_cartesien car;
    complexe_polaire pol;
}type;

typedef struct{
    type t;
    form f;
}complexe;

void poltocart(complexe c){
    complexe temp;
    temp.f=cartesien;
    (temp.t).car.a=(c.t).pol.rho*cos((c.t).pol.theta);
    (temp.t).car.b=(c.t).pol.rho*sin((c.t).pol.theta);
    c=temp;
}
void carttopol(complexe c){
    complexe temp;
    temp.f=polaire;
    (temp.t).pol.rho=aqrt((c.t).car.a**2+(c.t).car.b**2);
    (temp.t).theta.theta=arctan((c.t).car.b/(c.t).car.a);
    c=temp;
}

void entrecart(float a, float b){
    complexe c;
    (c.t).car.a=a;
    (c.t).car.b=b;
    c.f=cartesien;
}

void affiche(complexe c){
    if(c.f==polaire)
        printf("%f + i%f",(c.t).car.a,(c.t).car.b);
    else
        printf("%fexp(i%f)",(c.t).pol.rho,(c.t).pol.theta);
}

int main(){
    complexe c;
    c.f=cartesien;
    (c.t).car.a=1
    (c.t).car.b=1
    affiche(c);
    return 0;
}