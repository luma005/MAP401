#include<stdio.h> 
#include<stdlib.h> 
#include "image.h"
#include "exemple_sequence_point.h"

typedef enum {Nord, Est, Sud, West} Orientation;
typedef struct {
  UINT x, y;
  Orientation o;
} Robot;

void trouver_pixel_depart(Image I, UINT *a, UINT *b);

Contour memoriser_position (Contour C1, UINT x,UINT y);

void avancer(Robot *r);

void nv_orientation(Robot *r,Image I);

void creat_eps(Contour C, UINT h, UINT l, char* name);
