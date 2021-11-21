#include "menu.h"
#include "choix.h"
#include "damier.h"
#include "jeu.h"
#include "bot.h"
#include "end.h"
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(int argc , char * argv[]){
	
	InitialiserGraphique();
	int infos[2]; /* infos est un tableau qui stock les informations, infos[0] stock le nombre de joueurs et inofs[1] la taille du plateau de jeu */
	int loser; /* savoir quel joueur a perdu */
	int play_again = 1; /* savoir si on rejoue (dans ce cas la valeur est 1) ou si on arrête (dans ce cas la valeur est 0)) */

	/* chargement du menu principale */
	accueil();
	int mode = choix(infos);	/* fonction choix permet de récupérer les clics sur le menu principale */
	if(mode == 1) { /* mode == 1 équivaut à cliquer sur quitter sur le menu principale */
		FermerGraphique();
		printf("\nDommage, on aurait aimé vous voir jouer à notre jeu :'( \n\n");
		return EXIT_SUCCESS;
	} 
	if(mode == 2) { /* mode = 2 équivaut à lancer la partie */
	while(play_again != 0){ 
	if(infos[0] == 2){	
	damier(infos); /* damier est la fonction qui génère le plateau de jeu, il prend infos comme argument car il a besoin de savoir la taille du plateau */
	loser=jeu(infos); /* jeu est la fonction qui lance une partie en 2 vs 2, il prend infos comme argument car il a aussi besoin de la taille du plateau */
	play_again = fin(loser); /* la fonction fin permet d'afficher l'écran de fin, il prend loser en argument pour afficher un message indiquant le joueur qui a perdu */
	}
	else {
		damier(infos);
		loser=bot(infos); /* la fonction bot est assez similaire à la fonction jeu sauf qu'elle permet de jouer à 1 joueur contre un bot */
		play_again = fin(loser);
	}
	}
	}
	FermerGraphique();
	printf("\n---------------------\n");
	printf("Merci d'avoir jouer !\n\n");
		return EXIT_SUCCESS;
	}


