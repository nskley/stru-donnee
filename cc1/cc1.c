#include<stdio.h>
#include<math.h>
#include<stdlib.h>


enum form{cartesien,polaire};

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
    enum form f;
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
    (temp.t).pol.rho=sqrt((c.t).car.a*(c.t).car.a+(c.t).car.b*(c.t).car.b);
    (temp.t).pol.theta=atan((c.t).car.b/(c.t).car.a);
    c=temp;
}

void entrecart(float a, float b){
    complexe c;
    (c.t).car.a=a;
    (c.t).car.b=b;
    c.f=cartesien;
}

void affiche(complexe c){
    if(c.f==cartesien)
        printf("%f + i%f\n",(c.t).car.a,(c.t).car.b);
    else
        printf("%fexp(i%f)\n",(c.t).pol.rho,(c.t).pol.theta);
}

complexe additionne(complexe c1, complexe c2){
    complexe c;
    c.f=cartesien;
    if(c1.f==cartesien && c2.f==cartesien){
        (c.t).car.a=(c1.t).car.a+(c2.t).car.a;
        (c.t).car.b=(c1.t).car.b+(c2.t).car.b;
    }
    if(c1.f==polaire && c2.f==polaire){
        poltocart(c1);
        poltocart(c2);
        (c.t).car.a=(c1.t).car.a+(c2.t).car.a;
        (c.t).car.b=(c1.t).car.b+(c2.t).car.b;
    }
    if(c1.f==cartesien&& c2.f==polaire){
        poltocart(c2);
        (c.t).car.a=(c1.t).car.a+(c2.t).car.a;
        (c.t).car.b=(c1.t).car.b+(c2.t).car.b;
    }
    else{
        poltocart(c1);
        (c.t).car.a=(c1.t).car.a+(c2.t).car.a;
        (c.t).car.b=(c1.t).car.b+(c2.t).car.b;
    }
    return c;
}

int main(int argc, char *argv[]){
    complexe c1,c2;
    c1.f=cartesien;
    (c1.t).car.a=1;
    (c1.t).car.b=1;
    affiche(c1);
    c2.f=polaire;
    (c2.t).pol.rho=1;
    (c2.t).pol.theta=0;
    affiche(c2);
    complexe c=additionne(c1,c2);
    affiche(c);
    return 0;
}

