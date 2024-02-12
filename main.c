#include "entreeSortieLC.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


int main(int argc, char **argv) {
	Biblio* a = charger_n_entrees(argv[1], atoi(argv[2]));
	// afficher_biblio(a);
	enregistrer_biblio(a, "biblioEcrit.txt");

	return 1;
}
