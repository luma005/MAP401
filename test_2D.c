#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"geometrie_2D.h"

int main(int argc, char** argv){
    double x,y,m;
    double z,n;
    Point a,b,c;
    Vecteur u,d,s;
    Vecteur v={0,5};

    printf("entrer les coordonnee d'un point a : x et y\n");
    scanf("%lf%lf", &x, &y);
    a=set_point( x , y );

    printf("entrer les coordonnee d'un autre point b : z et n \n");
    scanf("%lf%lf", &z, &n);
    b=set_point( z , n );

    c= add_point( a , b);
    printf("\nles corrdonnees de la somme de ces deux points (a+b) est :x= %lf, y=%lf\n\n", c.x,c.y);

    u=vec_bispoint( a, b);
    printf("les coordonnes du vecteur u cree a partir de ces deux points (a et b) est :x=%lf, y=%lf\n\n", u.x,u.y);

    s=add_vecteur(u, v);
    printf("la somme de deux vecteurs u (x=%lf, y=%lf) et v(0,5) est : x=%lf et y=%lf\n\n",u.x, u.y, s.x, s.y);

    printf("entrer un entier pour faire l'homothetie du vecteur u\n");
    scanf("%lf", &m);
    d=homothetie( u, m );
    printf("les coordonnes de l'homothetie du vecteur u avec l'entier %lf est : x=%lf et y=%lf\n\n", m,d.x,d.y);

    printf("le produit scalaire entre u et v est : %lf\n\n", produit_scalaire(u,v));

    printf("la norme du vecteur u est : %lf\n\n",  norme(u));

    printf("la distance entre les points a et b est : %lf\n\n", distance_2points(a, b));

    return 0;
}
  