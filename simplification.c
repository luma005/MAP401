#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include "simplification.h"


Contour douglas_peucker(Contour c, int j1, int j2, double d){

    Tableau_Point TP = sequence_points_liste_vers_tableau(c);
	Point  P1, P2, Pj;
    P1=TP.tab[j1];
    P2=TP.tab[j2]; // before pb here because i passed a j2 > c.taille

    Contour l, l1, l2;
    l=creer_liste_Point_vide();
    

    double dmax=0;
    double dj; 
    int k=j1;


    for (int j=j1+1; j<=j2; j++){
        Pj=TP.tab[j];
        dj=distance_seg(Pj, P1, P2);
        if (dmax<dj){
            dmax=dj;
            k=j;
        }
    }

    if (dmax<=d){
        l=ajouter_element_liste_Point(l,P1);
        l=ajouter_element_liste_Point(l,P2);
    }
    else{

        l1=douglas_peucker(c,j1,k,d);
        l2=douglas_peucker(c,k,j2,d);
        //l2 = supprimer_premier_element_liste_Point(l2); //pour eviter les double points
        l=concatener_liste_Point(l1,l2);
        //plusieurs points vers (0,0) non souhaite ???
    }
    //ecrire_contour(l);
    free(TP.tab);
    return l;
}

/*
int main()
{
	Contour l,c;
    int j1,j2;
    double d;
    j1= 0;
    j2= 5;
    d=1;
	c= creer_liste_Point_vide();
	c = ajouter_element_liste_Point(c, set_point(0,0));
	c = ajouter_element_liste_Point(c, set_point(1,2));
	c = ajouter_element_liste_Point(c, set_point(2,1));
	c = ajouter_element_liste_Point(c, set_point(3,3));
	c = ajouter_element_liste_Point(c, set_point(4,2));
	c = ajouter_element_liste_Point(c, set_point(5,0));
	ecrire_contour(c);

	l=douglas_pecker(c, j1,j2,d);
	ecrire_contour(l);
	
}
*/
