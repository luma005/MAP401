/****************************************************************************** 
  Implementation du module geometrei_2D
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"geometrie_2D.h"

Point set_point( double x , double y ){
    Point P ={x,y};
    return P;
}

Point add_point( Point p1 , Point p2){
    return set_point(p1.x+p2.x,p1.y+p2.y);
}

Vecteur vec_bispoint( Point p1 , Point p2 ){
    Vecteur v = {p2.x-p1.x,p2.y-p1.y};
    return v;
}

Vecteur add_vecteur(Vecteur v1, Vecteur v2){
    Vecteur v = {v1.x+v2.x,v1.y+v2.y};
    return v;
}

Vecteur homothetie( Vecteur v , double m ){
    Vecteur mv={v.x*m,v.y*m};
    return mv;
}

double produit_scalaire(Vecteur v1, Vecteur v2){
    return v1.x*v2.x+v1.y*v2.y;
}

double norme(Vecteur v){
    return sqrt(pow(v.x,2)+pow(v.y,2));
}

double distance_2points(Point p1 , Point p2){
    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}