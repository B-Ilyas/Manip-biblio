#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


Biblio *charger_n_entrees(char *nomfic, int n) {
	FILE *f = fopen(nomfic,"r");
	
	if (f == NULL){
		printf("Erreur ouverture fichier\n");
		return 0;
	}
	
	printf("Lecture du fichier...\n");
	char buff[256];
	fgets(buff,256,f);
	assert(strncmp(buff, "0 WLRBBMQBHCDARZOWK yhidd ",(long unsigned int) 26) == 0);
	int num;
	char auteur[128];
	char titre[128];
	Biblio *b = creer_biblio();
	int i = 0;
	
	while ((i < n) && (strncmp(buff, "99999 YTIPEGBOCWJAEUOO ysj ",(long unsigned int) 27) != 0)){
		sscanf(buff, "%d %s %s \n", &num , titre, auteur);
		inserer_en_tete(b, num, titre, auteur);
		fgets(buff,256,f);
		i++;
	}
	
	fclose(f);
	printf("Succès de la lecture du fichier !\n");
	
	return b;
}


void enregistrer_biblio(Biblio *b, char *nomfic) {
	FILE *f = fopen(nomfic,"w");
	
	if (f == NULL){
		printf("Erreur ouverture fichier\n");
		return;
	}
	
	assert(b->L);
	Livre *tmp = (Livre*)malloc(sizeof(Livre));
	tmp = b->L;
	assert(tmp);
	
	printf("Ecriture du fichier...\n");
	while (tmp) {
		fprintf(f, "%d %s %s \n", tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;
	}

	fclose(f);
	printf("Succès de l'écriture du fichier !\n");
}

