#include "biblioLC.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Livre *creer_livre(int num, char *titre, char *auteur) {
	Livre *l = (Livre *)malloc(sizeof(Livre));
	l->num = num;
	l->titre = strdup(titre);
	l->auteur = strdup(auteur);
	l->suiv = NULL;
	
	return l;
}


void liberer_livre(Livre *l) {
	if (l) {
		free(l->titre);
		free(l->auteur);
		free(l);
	}
}


Biblio *creer_biblio() {
	Biblio *b = (Biblio *)malloc(sizeof(Biblio));
	b->L = NULL;
	
	return b;
}


void liberer_biblio(Biblio *b) {
	if (b) {
		Livre *prec = NULL;
		while (b->L) {
			prec = b->L;
			b->L = b->L->suiv;
			liberer_livre(prec);
		}
	
		free(b);
	}
}


void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur) {
	Livre *l = creer_livre(num , titre, auteur);
	l->suiv = b->L;
	b->L = l;
}


void afficher_livre(Livre *l) {
	
}


void afficher_biblio(Biblio *b) {
	Livre *tmp = b->L;
	while (tmp) {
		printf("%d %s\n", tmp->num, tmp->auteur);
		tmp = tmp->suiv;
	}
	
}




