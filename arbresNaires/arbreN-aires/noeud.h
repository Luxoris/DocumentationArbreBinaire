#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *enfant;
    struct noeud *frere;
}noeud;

extern void initRacine(noeud *noeudInit, int valeurInit);
extern void addNoeud(noeud *pere, int valeur);
extern void affichageArbre(noeud *monNoeud);

#endif // NOEUD_H_INCLUDED
