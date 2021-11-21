#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

void accueil() {
	CreerFenetre(300,175,1200,700);
	ChargerImageFond("images/background.png");
	couleur noir = CouleurParNom("black");
	ChoisirCouleurDessin(noir);
	EcrireTexte(400,50,"Choisissez la taille du plateau", 2);

	/* Positionnement d'avatar */
	ChargerSprite("images/batman.png");
	ChargerSprite("images/ironman.png");
	AfficherSprite(1,425,565);
	AfficherSprite(1,850,565);
	AfficherSprite(2,910,565);
	
	/* Fond blanc pour les futurs rectangles pour mettre en évidence les tailles disponibles */
	couleur gris = CouleurParNom("grey");
	ChoisirCouleurDessin(gris);
	
	RemplirRectangle(383,167,49,49);
	RemplirRectangle(583,167,49,49);
	RemplirRectangle(783,167,49,49);
	RemplirRectangle(383,267,49,49);
	RemplirRectangle(583,267,49,49);
	RemplirRectangle(783,267,49,49);
	RemplirRectangle(583,367,49,49);

	ChoisirCouleurDessin(noir);

	/* Différentes tailles du plateau */
	EcrireTexte(400,200,"3",2);
	EcrireTexte(600,200,"4",2);
	EcrireTexte(800,200,"5",2);
	EcrireTexte(400,300,"6",2);
	EcrireTexte(600,300,"7",2);
	EcrireTexte(800,300,"8",2);
	EcrireTexte(600,400,"9",2);
		
	/* Rectangle qui englobe toutes les tailles du plateau afin de séparer des fonctions propre au commencement de la partie */
	DessinerRectangle(300,15,625,420);
	
	DessinerSegment(400,60,820,60);
	
	/* Carree qui entoure chaque proposition de taille de plateau */
	DessinerRectangle(382,166,50,50);
	DessinerRectangle(582,166,50,50);
	DessinerRectangle(782,166,50,50);
	DessinerRectangle(382,266,50,50);
	DessinerRectangle(582,266,50,50);
	DessinerRectangle(782,266,50,50);
	DessinerRectangle(582,366,50,50);

	EcrireTexte(450,500,"Jouer",2);
	EcrireTexte(750,500,"Quitter",2);
	EcrireTexte(500,600,"1 joueur",2);
	EcrireTexte(700,600,"2 joueurs",2);

	/* Ligne 29 (pour se repérer) */

	/* Dessine des rectangles autour des Boutons créés ci-dessus */
	DessinerRectangle(425,470,135,40);
	DessinerRectangle(725,470,135,40);
	DessinerRectangle(485,570,135,40);
	DessinerRectangle(685,570,150,40);
}



