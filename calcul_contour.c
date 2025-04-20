#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include "calcul_contour.h"

void trouver_pixel_depart(Image I,UINT *a, UINT *b){
    UINT x, y;
	for (y=1;y<=hauteur_image(I);y++){
		for (x=1;x<=largeur_image(I);x++){
			if ((get_pixel_image(I, x, y) == NOIR) && (get_pixel_image(I, x, y-1) == BLANC)){
				(*a)=x;
                (*b)=y;
                return;
            }
        }
	}
}

Contour memoriser_position (Contour C1, UINT x,UINT y){
    C1=ajouter_element_liste_Point(C1, set_point(x,y));
    return C1;
}

void avancer(Robot *r){
    switch(r->o){
        case Nord :
            r->y--;
            break;

        case Sud :
            r->y++;
            break;

        case Est :
            r->x++;
            break;

        case West :
            r->x--;
            break;
    }
}

void nv_orientation (Robot *r,Image I){
    UINT x,y;
    Pixel pg,pd;
    x=r->x;
    y=r->y;
    switch(r->o){
        case Nord :
            pg = get_pixel_image(I, x, y);
            pd=get_pixel_image(I, x+1, y);
            if (pg==NOIR){
                r->o=West;
                }
            else if (pd==BLANC) {
                r->o=Est;
            }
            break;

        case Sud :
            pg = get_pixel_image(I, x+1, y+1);
            pd=get_pixel_image(I, x, y+1);
            if (pg==NOIR){
                r->o=Est;
                }
            else if (pd==BLANC){
                r->o=West;
            }
            break;

        case Est :
            pg = get_pixel_image(I, x+1, y);
            pd=get_pixel_image(I, x+1, y+1);
            if (pg==NOIR){
                r->o=Nord;
                }
            else if (pd==BLANC){
                r->o=Sud;
            }
            break;

        case West :
            pg = get_pixel_image(I, x, y+1);
            pd=get_pixel_image(I, x, y);
            if (pg==NOIR){
                r->o=Sud;
                }
            else if (pd==BLANC){
                r->o=Nord;
            }
            break;
    }
}

void creat_eps(Contour C, UINT h, UINT l, char* name){
    FILE* f;
    char fichier[256];
    strcpy(fichier,name);
    strcpy(fichier +(strlen(fichier)-3),"eps");
    f=fopen(fichier,"w");
    fprintf(f,"%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(f,"%%%%BoundingBox: 0 0 %u %u \n", l, h);
    Tableau_Point TP = sequence_points_liste_vers_tableau(C);
	int k;
	int nP = TP.taille;
    Point P = TP.tab[0]; /* recuperer le point d'indice 0 */
	fprintf( f,"%f %f moveto ",P.x, h-P.y);
	for (k = 1; k < nP; k++) {	
        P = TP.tab[k]; /* recuperer le point d'indice k */
		fprintf( f,"%f %f lineto ",P.x, h-P.y);
        } 
    fprintf(f,"\n");
    fprintf(f,"0 0 0 setrgbcolor 0 setlinewidth\n");
    fprintf(f, "stroke\n");
	fprintf(f,"showpage\n");
    fclose(f);
}


int main(int argc, char** argv){
    if (argc < 2) {
    printf("Usage: %s <fichier d'entree>\n", argv[0]);
    return 1;
    }
    Image I;
    Contour C1;
    C1 = creer_liste_Point_vide();
    UINT l,h;
    I=lire_fichier_image(argv[1]);
    l= largeur_image( I);
    h= hauteur_image( I);
    printf("la largeur est %u et la hauteur est %u\n", l, h);
    UINT a,b;
    trouver_pixel_depart(I,&a,&b);
    UINT a0,b0;
    Robot r;
    a0=a-1;
    b0=b-1;
    r.x = a0;// premiere position du notre robot
    r.y=b0; // premiere position du notre robot 
    r.o = Est;
    int flag=1;
    while (flag == 1){
        C1=memoriser_position(C1,r.x,r.y);
        avancer(&r);
        nv_orientation(&r,I);
        if ((r.x == a0) && (r.y== b0) && (r.o==Est)){
            flag=0;
        }
    }
    C1=memoriser_position(C1,r.x,r.y);
    printf("C1 : "); nb_segement(C1);
    creat_eps(C1, h, l, argv[1]);
    return 0;
}
