#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "jeu.h"
#include <time.h>

int jeu(int* infos) {
	/* image du jeu (les croix et pions) */
	ChargerSprite("images/croix.png");
	ChargerSprite("images/croix_orange.png");
	ChargerSprite("images/pion.png"); /* sprite 5 */
	ChargerSprite("images/pion_orange.png");
	int TAILLE = infos[1]; /* récupère la taille du plateau */
	int longueur_rectangle = TAILLE*100; /*permet de connaitre la longueur de la grille */
	int hauteur_rectangle = TAILLE * 70; /* pareil pour la longueur de la grille */
	int coordonnee_x[TAILLE+1]; /* tableau qui stock les valeurs des cases de notre grille en X */
	int coordonnee_y[TAILLE+1]; /* pareil pour les Y */
	int j = 0,i; /* pour des boucles */
	int posx = 600 - (longueur_rectangle/2); /* permet de calculer la marge à gauche pour centrer la grille parfaitement en longueur */
	int posy = 350 - (hauteur_rectangle/2); /* pareil pour la largeur */

	for(i=0;i<TAILLE+1;i++){ /* on remplie ces tableaux avec les coordonnées en X et Y des différentes cases notre grille */
		coordonnee_x[i]=posx;
		coordonnee_y[i]=posy;
		posx = posx +100;
		posy = posy + 70;
	}
	/* Tableau du jeu (si case déjà remplie, permet de savoir si une case où on clique dans la grille est vide ou non) */
	int cases[TAILLE][TAILLE];
	for(i=0;i<TAILLE;i++){
		for(j=0;j<TAILLE;j++){
			cases[i][j]=0;
		}
	}
	/* comme on a modifier posx et posy alors on les calcule à nouveau */
	posx = 600 - (longueur_rectangle/2);
	posy = 350 - (hauteur_rectangle/2);
	
	int joueur; /* joueur bleu ou orange (joueur = 1 <-> joueur bleu |||||| joueur = 0 <-> joueur orange */
	int MAX = 1;
	int MIN = 0;
	/* choisi aléatoirement le joueur commençant la partie */
	joueur = rand() % (MAX-MIN+1)+MIN;
	
	int save=0;
	/* sauvegarde les coordonnées de la précédentes case où se trouvait notre pion */
	int save_coordx_bleu = 0;
	int save_coordy_bleu = 0;
	int save_coordx_orange = 0;
	int save_coordy_orange = 0;
	int g,h; /* pour des boucles */
	int pion = 0; /* permet de savoir si on bouge le pion on si on pose une croix, pion = 0 vuet dire qu'on doit bouger le pion */
	int countx=0; /* compte le nombre d'itération pour le tableau des x (des colonnes) */
	int county=0; /* pareil pour les y (des lignes) */
	/* sauvegarde des valeurs des itérations d'où on a placé notre pion dans la grille pour pouvoir remettre la case où était notre pion à 0 donc qu'on puisse rebouger notre pion dedans, en résumé ça vide la case précédente quand on bouge notre pion dans le tableau 2 dimensions "cases" de la grille */
	int save_countx_bleu=0;
	int save_county_bleu=0;
	int save_countx_orange=TAILLE-1;
	int save_county_orange=TAILLE-1;
	int nb_pion = 0;
	int comptage = 0;
	srand(time(NULL));
	int possibilities=0; /* compte si un déplacement est possible */
	int leaving = 0;
	int loser;
	int start = 0; /* pour commencer à réaliser une action pour les bleus */
	int start2 = 0;/* pareil mais pour les oranges */
	

	while(leaving != 1){
	
		/* Permet de check si les cases aux alentours de notre pion sont pleines où vides et donc savoir si on peut encore jouer ou non */
		if(pion==0 && joueur == 1){
						if((save_county_bleu!=0) && (cases[save_county_bleu-1][save_countx_bleu] == 0)){ /*county-1 = case au dessus de notre pion */
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
						if((save_county_orange!=0) && (cases[save_county_orange-1][save_countx_orange] == 0)){ /*county-1 = case au dessus de notre pion */
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



		if(SourisCliquee()){
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
	if(pion == 0){ /* test voir si c'est au tour de déplacer notre pion */
		if(joueur == 1){ /* test pour savoir à qui bouger son pion */
			/* le if juste en dessous permet de vérifier que notre clique est bien autour de notre position actuelle, si non alors on ne bouge pas le pion et on recommence */
			if(((save_countx_bleu-1<=countx && countx<=(save_countx_bleu+1)) && (save_county_bleu-1<=county && county<=(save_county_bleu+1))) || start==0) {
		AfficherSprite(5,25+posx+(countx*100),25+posy+(county*70));
		if(nb_pion != 0){ /* savoir si on pose notre pion pour la première où non car le reste permet de vider visuellement la case où était notre pion juste avant le nouvel emplacement */
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
		cases[county][countx]=1; /* remplie dans le tableau qui sauvegarde les emplacements dans la grille d'un 1 pour l'emplacement de notre pion */
		pion = 1; /* permet de dire qu'on passe au posage de la croix */
		}
	}
	else {
		/* le if juste en dessous permet de vérifier que notre clique est bien autour de notre position actuelle, si non alors on ne bouge pas le pion et on recommence */

		if(((save_countx_orange-1<=countx && countx<=(save_countx_orange+1)) && (save_county_orange-1<=county && county<=(save_county_orange+1))) || start2==0){
	 	AfficherSprite(6,25+posx+(countx*100),25+posy+(county*70));
		if(save != 0){ /* Une fois qu'on a joué au moins une fois cette condition s'active car comme celle d'avant, elle permet de vider la case précédent de notre pion visuellement */
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
		if(joueur == 1){ /* affichage de la croix pour le joueur 1 */
			AfficherSprite(3,25+posx+(countx*100),25+posy+(county*70));
			joueur = 0;
			}
			else {
	 			AfficherSprite(4,25+posx+(countx*100),25+posy+(county*70));
	 			joueur = 1;
					}
		cases[county][countx]=2;
		pion = 0; /* pion redevient 0 car on a finit de poser les croxi des 2 joueurs */
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
