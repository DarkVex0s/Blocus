#include "choix.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int choix(int* infos) {
	
	couleur noir = CouleurParNom("black");
	couleur bleu = CouleurParNom("blue");
	int quitter = 0; /* savoir si on sort du jeu ou non */
	int nombre_joueur = 0;
	int taille_plateau = 0,ready = 0;
	infos[1] = 0; 
	infos[0] = 0;
	while(quitter<1) {
	SourisCliquee();
	
	/* Test appuie sur quitter en concordant les coordonnées du clic et du bouton quitter */
	if ((_X>725 && _X<860)&&(_Y>470 && _Y<510)) {
	quitter=1;
		}
	
	/* Nombre de joueurs choisis en concordant les coordonnées du clic et des boutons sur le nombre de joueur */
	if ((_X>485 && _X<620) && (_Y>570 && _Y<610)){
	nombre_joueur=1;
	if(infos[0] == 0){
		infos[0]=1;
		ChoisirCouleurDessin(bleu);
		DessinerRectangle(485,570,135,40);
		ChoisirCouleurDessin(noir);
		EcrireTexte(500,600,"1 joueur",2);
	}
	}
	if ((_X>685 && _X<835) && (_Y>570 && _Y<610)){
	nombre_joueur=1;
	if(infos[0] == 0){
		infos[0]=2;
		ChoisirCouleurDessin(bleu);
		DessinerRectangle(685,570,150,40);
		ChoisirCouleurDessin(noir);
		EcrireTexte(700,600,"2 joueurs",2);
	}
	}
	
	/* Choix taille plateau en concordant les coordonnées du clic et des différents boutons des tailles */
	if ((_X>382 && _X<432) && (_Y>166 && _Y<216)) {
		taille_plateau=1;
		if(infos[1]==0){
		infos[1]=3;
		/* Permet de créer un fond bleu dans le rectangle où on a cliqué */
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(383,167,49,49);
	  ChoisirCouleurDessin(noir);
	  EcrireTexte(400,200,"3",2);
	 }
	}
	if ((_X>582 && _X<632) && (_Y>166 && _Y<216)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=4;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(583,167,49,49);
	 	ChoisirCouleurDessin(noir);
 	  EcrireTexte(600,200,"4",2);
	 }
	}
	if ((_X>782 && _X<832) && (_Y>166 && _Y<216)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=5;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(783,167,49,49);
	 	ChoisirCouleurDessin(noir);
	 	EcrireTexte(800,200,"5",2);
	 }
	}
	if ((_X>382 && _X<432) && (_Y>266 && _Y<316)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=6;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(383,267,49,49);
	  ChoisirCouleurDessin(noir);
	  EcrireTexte(400,300,"6",2); 
	 }
	}
	if ((_X>582 && _X<632) && (_Y>266 && _Y<316)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=7;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(583,267,49,49);
		ChoisirCouleurDessin(noir);
	 	EcrireTexte(600,300,"7",2);
	 }
	}
	if ((_X>782 && _X<832) && (_Y>266 && _Y<316)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=8;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(783,267,49,49);
		ChoisirCouleurDessin(noir);
	  EcrireTexte(800,300,"8",2);
	 }
	}
	if ((_X>582 && _X<632) && (_Y>366 && _Y<416)) {
		taille_plateau=1;
		if(infos[1] == 0){
		infos[1]=9;
		ChoisirCouleurDessin(bleu);
		RemplirRectangle(583,367,49,49);
	 	ChoisirCouleurDessin(noir);
		EcrireTexte(600,400,"9",2);
	 }
	}	
	
	/* Test appuie sur jouer en concordant les coordonnées d'un clic et celles du bouton jouer */
	if ((_X>425 && _X<560)&&(_Y>470 && _Y<510)) {
		ready=taille_plateau+nombre_joueur; /* cette variable permet de lancer la partie uniquement si on a choisi une taille de plateau ET le mode de jeu */
		if(ready==2) {
	quitter=2; /* permet de sortir de la boucle */
	printf("Vos choix : %d joueur(s) et taille du plateau : %d\n", infos[0],infos[1]);
	}	
}
}
		return quitter; /* retourne la valeur de quitter (entre 1 ou 2) : 1 si on a cliqué sur "quitter" sinon 2 pour "jouer" */
}


