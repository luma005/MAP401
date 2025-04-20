L'objectif de ce projet est de simplifier des images au format PBM et de les convertir en images EPS. 
Chaque branche comporte deux tâches consécutives. 
L'architecture du projet est modulaire, avec plusieurs fichiers .c et .h, afin de bien séparer les différents types de données et les traitements associés. 

Les fichiers du projet sont organisés comme suit :

- geometrie_2D.c / .h : Ce module contient les définitions des types géométriques, tels que les points et les vecteurs, ainsi que les opérations associées (addition de vecteurs, calcul de distances, etc.).

- calcul_contour.c / .h : Ce fichier est responsable du calcul des contours à partir de l'image PBM. Il génère également les fichiers EPS et coordonne l'ensemble du programme.

- exemple_sequence_point.c / .h : Ce module gère les séquences de points et manipule les courbes de Bézier de degré 2 et 3, en permettant l'ajout, l'affichage et la gestion dynamique des points.

- simplification.c / .h : Ce fichier implémente l'algorithme de simplification de Douglas-Peucker, utilisé pour simplifier les segments de ligne et les courbes de Bézier.


Manuels utilisateurs : 
Compilation avec make
Cela crée l’exécutable calcul_contour : ./calcul_contour nom_image.pbm
Le programme vous demandera ensuite d’entrer un seuil.
Une fois ce seuil validé, les contours de l’image seront extraits, simplifiés et convertis (selon le cas) en segments
ou en courbes de Bézier.
