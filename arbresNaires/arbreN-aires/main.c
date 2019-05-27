#include "noeud.h"

int main()
{
    noeud *racine;//noeud à la base de tout
    racine = (noeud *) malloc (sizeof (noeud));

    noeud *pere;//noeud servie pour selectionner un pere qui n'est pas la racine
    pere = (noeud *) malloc (sizeof (noeud));

    initRacine(racine, 5);

    addNoeud(racine, 9);
    addNoeud(racine, 8);
    addNoeud(racine, 0);
    addNoeud(racine, 15);
    addNoeud(racine, 6);

    //pere = racine->enfant = premier enfant de racine = 9
    pere = racine->enfant;
    addNoeud(pere, 1);
    addNoeud(pere, 5);
    addNoeud(pere, 2);

    //pere = racine->enfant->frere = deuxieme enfant de racine = 8
    pere = racine->enfant->frere;
    addNoeud(pere, 22);

    //pere = racine->enfant->enfant->frere = deuxieme enfant du premier enfant de la racine = 5
    pere = racine->enfant->enfant->frere;
    addNoeud(pere, 12);
    addNoeud(pere, 7);

    affichageArbre(racine);

    free(racine);
    free(pere);
    return 0;
}
