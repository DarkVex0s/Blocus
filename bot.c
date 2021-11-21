#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "bot.h"
#include <time.h>

int bot(int* infos) {
	
	ChargerSprite("images/croix.png");
	ChargerSprite("images/croix_orange.png");
	ChargerSprite("images/pion.png"); /* sprite 5 */
	ChargerSprite("images/pion_orange.png");
	int TAILLE = infos[1];
	int longueur_rectangle = TAILLE*100;
	int hauteur_rectangle = TAILLE * 70;
	int coordonnee_x[TAILLE+1];
	int coordonnee_y[TAILLE+1];
	int j = 0,i;
	int posx = 600 - (longueur_rectangle/2);
	int posy = 350 - (hauteur_rectangle/2);

	for(i=0;i<TAILLE+1;i++){
		coordonnee_x[i]=posx;
		coordonnee_y[i]=posy;
		posx = posx +100;
		posy = posy + 70;
	}
	/* Tableau du jeu (si case déjà remplie */
	int cases[TAILLE][TAILLE];
	for(i=0;i<TAILLE;i++){
		for(j=0;j<TAILLE;j++){
			cases[i][j]=0;
		}
	}
	posx = 600 - (longueur_rectangle/2);
	posy = 350 - (hauteur_rectangle/2);
	
	int joueur;
	int MAX = 1;
	int MIN = 0;

	joueur = rand() % (MAX-MIN+1)+MIN;
	
	int save=0;
	int save_coordx_bleu = 0;
	int save_coordy_bleu = 0;
	int save_coordx_orange = 0;
	int save_coordy_orange = 0;
	int g,h;
	int pion = 0;
	int countx=0;
	int county=0;
	int save_countx_bleu=0;
	int save_county_bleu=0;
	int save_countx_orange=TAILLE-1;
	int save_county_orange=TAILLE-1;
	int nb_pion = 0;
	int comptage = 0;
	srand(time(NULL));
	int possibilities=0;
	int leaving = 0;
	int loser;
	int start = 0;
	int start2 = 0;

	while(leaving != 1){
	/* test si on peut jouer ou si on a perdu */
		if(pion==0 && joueur == 1){
						if((save_county_bleu!=0) && (cases[save_county_bleu-1][save_countx_bleu] == 0)){ 
						possibilities++;
			}	
					else {
						if((save_county_bleu!=TAILLE-1) &&(cases[save_county_bleu+1][save_countx_bleu] == 0)){
							possibilities++;
						}
						else {
							if((save_countx_bleu!=0)&&(cases[save_county_bleu][save_countx_bleu-1] == 0)){
								possibilities++;		
							}
								else {
									if((save_countx_bleu!=TAILLE-1)&&(cases[save_county_bleu][save_countx_bleu+1] == 0)){
										possibilities++;	
										}
									}								
								}
						}
							
		if(possibilities == 0){
			leaving=1;
			loser = 1;
			printf("Joueur bleu a perdu !\n");
		}
		else {
			possibilities = 0;
		}
	}
	/* pareil pour le pion orange */
		if(pion==0 && joueur == 0){
						if((save_county_orange!=0) && (cases[save_county_orange-1][save_countx_orange] == 0)){ 
						possibilities++;
			}	
					else {
						if((save_county_orange!=TAILLE-1) &&(cases[save_county_orange+1][save_countx_orange] == 0)){
							possibilities++;
						}
						else {
							if((save_countx_orange!=0)&&(cases[save_county_orange][save_countx_orange-1] == 0)){
								possibilities++;		
							}
								else {
									if((save_countx_orange!=TAILLE-1)&&(cases[save_county_orange][save_countx_orange+1] == 0)){
										possibilities++;	
									}								
								}
						}
					}
		
		if(possibilities == 0){
			leaving=1;
			loser = 0;
			printf("Joueur orange a perdu !\n");
		}
		else { 
				possibilities = 0;
		}
	}


		if(SourisCliquee() || joueur == 0){ /*joueur == 0 équivaut au tour du bot */

			if(joueur == 0){ /*si c'est au bot, alors on prend des valeurs aléatoires de déplacement autour de lui, il va se déplacer uniquement sur les cases à côté de lui */
			_X = rand() % (((posx+TAILLE*100)-posx+1)+posx);
			_Y = rand() % (((posy+TAILLE*70)-posy+1)+posy);
			}

			/* le reste du code est le même que sur jeu.c où j'ai expliqué en détail les différentes lignes de mon programme */

																				/* Test si on clique bien dans la grille et pas en dehors */
			if((_X>posx && _X<posx+TAILLE*100) && (_Y>posy && _Y<posy+TAILLE*70)){
				
				for(i=0;i<TAILLE;i++){
					/* Je compare les coordonnées du clic avec celle stockées dans mes tableaux de coordonnées qui contiennent les coordonnées de chaque case de la grille */
	if(_X>coordonnee_x[i] && _X<coordonnee_x[i+1]) {
		countx=i;
	}
	if(_Y>coordonnee_y[i] && _Y<coordonnee_y[i+1]) {
		county=i;
	}
}
					/* Si case vide alors on peut jouer et on échange les tours (le joueur qui joue*/
	if(cases[county][countx] == 0) {
	if(pion == 0){
		if(joueur == 1){
			if(((save_countx_bleu-1<=countx && countx<=(save_countx_bleu+1)) && (save_county_bleu-1<=county && county<=(save_county_bleu+1))) || start==0) {
		AfficherSprite(5,25+posx+(countx*100),25+posy+(county*70));
		if(nb_pion != 0){
			ChoisirCouleurDessin(CouleurParNom("white"));
			RemplirRectangle(save_coordx_bleu,save_coordy_bleu,50,40);
			ChoisirCouleurDessin(CouleurParNom("black"));
			cases[save_county_bleu][save_countx_bleu] = 0;
		}
		nb_pion = 1;
		start = 1;
		save_coordx_bleu = 25+posx+(countx*100);
		save_coordy_bleu = 25+posy+(county*70);
		save_countx_bleu = countx;
		save_county_bleu = county;
		cases[county][countx]=1;
		pion = 1;
		}
	}
	else {
		if(((save_countx_orange-1<=countx && countx<=(save_countx_orange+1)) && (save_county_orange-1<=county && county<=(save_county_orange+1))) || start2==0){
	 	AfficherSprite(6,25+posx+(countx*100),25+posy+(county*70));
		if(save != 0){
			ChoisirCouleurDessin(CouleurParNom("white"));
			RemplirRectangle(save_coordx_orange,save_coordy_orange,50,40);
			ChoisirCouleurDessin(CouleurParNom("black"));
			cases[save_county_orange][save_countx_orange] = 0;
		}
			save = 1;
			start2 = 1;
			save_coordx_orange = 25+posx+(countx*100);
			save_coordy_orange = 25+posy+(county*70);
			save_countx_orange = countx;
			save_county_orange = county;
			cases[county][countx]=1;
			pion = 1;
		}
	}
		}
	else {
		if(joueur == 1){
			AfficherSprite(3,25+posx+(countx*100),25+posy+(county*70));
			joueur = 0;
			}
			else {
	 			AfficherSprite(4,25+posx+(countx*100),25+posy+(county*70));
	 			joueur = 1;
					}
		cases[county][countx]=2;
		pion = 0;
	}
			}

/* Affichage pour voir les cases remplies et vides dans ma grille */
	for(g=0;g<TAILLE;g++){
		for(h=0;h<TAILLE;h++){
			printf("%d\t", cases[g][h]);
			if(cases[g][h] == 1){
				comptage++;
			}
		}
				printf("\n");
 }
	printf("------------------------------\n");
}
}
}
	return loser;
}
