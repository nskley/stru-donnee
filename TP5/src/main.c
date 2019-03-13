#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"../include/maLibMath.h"


int main(void){
    point p1={2,0,0};
    point p2={0,2,0};
    point p3={0,0,2};
    vecteur v=Vectorise(p1,p2);
    printf("%f\n",Norme(v));
    Equation eq=Equation_Plan(p1,p2,p3);
    return 0;
}