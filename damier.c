#include "damier.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>

void damier(int* infos) {

	ChargerImageFond("images/ghotam_city.png");

	ChoisirCouleurDessin(CouleurParNom("black"));
	
	int TAILLE = infos[1];

	int longueur_rectangle = TAILLE*100;
	int hauteur_rectangle = TAILLE * 70;
	/* Calcul permettant de centrer la grille dans la fenêtre */
	int posx = 600 - (longueur_rectangle/2);
	int posy = 350 - (hauteur_rectangle/2);
	int x = 600 + (longueur_rectangle/2);
	int y = 350 + (hauteur_rectangle/2);

	DessinerRectangle(posx,posy,longueur_rectangle,hauteur_rectangle);
	
	ChoisirCouleurDessin(CouleurParNom("white"));
	RemplirRectangle(posx+1,posy+1,longueur_rectangle-1,hauteur_rectangle-1);
	
	ChoisirCouleurDessin(CouleurParNom("black"));
	/* Dessin de la grille (grâce à des segments horizontaux) */
	int i;
	for(i=1; i<TAILLE; i++) {
	posy = posy + 70;
	DessinerSegment(posx,posy,x,posy);
	}

	posy = 350 - (hauteur_rectangle/2);
 /* Dessin des segments verticaux */ 
	for(i=1; i<TAILLE; i++) {
	posx = posx + 100;
	DessinerSegment(posx,posy,posx,y);
	}
}

