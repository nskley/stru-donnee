typedef struct
{
    float x;
    float y;
    float z;
}point;

typedef struct
{
    float vx;
    float vy;
    float vz;
}vecteur;

typedef struct 
{
    float coefs[4];
}Equation;


point demande_point(void);
point Creer_Point(float x,float y,float z);
point Creer_Point(float x,float y,float z);
vecteur Vectorise(point pt1,point pt2);
vecteur Produit_Vectoriel(vecteur V1,vecteur V2);
float Produit_Scalaire(vecteur v1,vecteur v2);
float Norme(vecteur v);
Equation Equation_Plan(point pt1,point pt2,point pt3);