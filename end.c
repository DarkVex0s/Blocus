#include "end.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int fin(int loser) {

	int again = 0; /* variable qui permet de retourner si on veut rejouer ou quitter */

	ChargerImageFond("images/background.png");

	ChoisirCouleurDessin(CouleurParNom("grey"));
	/* fond gris aux boutons "Recommencer" et "Quitter" */
	RemplirRectangle(426,456,299,69);
	RemplirRectangle(471,556,199,69);

	ChoisirCouleurDessin(CouleurParNom("black"));

	EcrireTexte(475,500,"recommencer",2);
	EcrireTexte(520,600,"quitter",2);
	/* contour des 2 boutons */
	DessinerRectangle(425,455,300,70);
	DessinerRectangle(470,555,200,70);
	
	if(loser == 1){ /* loser est renvoyée par la fonction jeu ou bot, ça permet d'afficher le gagnant de la partie */
		EcrireTexte(400,50,"Victoire : joueur orange",2);
	}
	else {
		EcrireTexte(400,50,"Victoire : joueur bleu",2);
	}
	int leaving;

	while(leaving==0) { /* tant qu'on a pas bien cliqué sur quelque chose alors on quitte pas */
		SourisCliquee();
		if((_X>425 && _X<725) && (_Y>455 && _Y<525)) {
		leaving=1;
		again = 1; /* 1 alors on veut rejouer */
		}
		
		if((_X>470 && _X<670) && (_Y>555 && _Y<625)){
			leaving=2;
			again = 0; /* 0 pour dire quitter (dans blocus.c, la valeur 0 sera comprise comme le fait de quitter le jeu */
		}
	}
	return again;
}


