/****************************************************************************** 
  Interface du module de calcul geometrique en dimenson 2
******************************************************************************/

typedef struct Vecteur_{
    double x,y;
} Vecteur;

typedef struct Point_{
    double x,y;
} Point;


Point set_point( double x , double y );

Point add_point( Point p1 , Point p2 );

Vecteur vec_bispoint( Point p1 , Point p2 );

Vecteur add_vecteur(Vecteur v1, Vecteur v2);

Vecteur homothetie( Vecteur v , double m );

double produit_scalaire(Vecteur v1, Vecteur v2);

double norme(Vecteur v);

double distance_2points(Point x , Point y);
