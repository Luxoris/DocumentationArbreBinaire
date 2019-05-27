#include "noeud.h"

//initialise la racine
void initRacine(noeud *racine, int valeurInit){
    racine->valeur = valeurInit;
    racine->frere = NULL;
    racine->enfant = NULL;
}

//ajoute un noeud
void addNoeud(noeud *pere, int valeur){
    noeud *newNoeud;
    newNoeud = (noeud *) malloc (sizeof (noeud));

    newNoeud->valeur = valeur;
    newNoeud->frere = NULL;
    newNoeud->enfant = NULL;

    if(pere->enfant == NULL){
        pere->enfant = newNoeud;
    } else {
        noeud *grandFrere;
        grandFrere = (noeud *) malloc (sizeof (noeud));
        grandFrere = pere->enfant;
        while (grandFrere->frere != NULL){
            grandFrere = grandFrere->frere;
        }
        grandFrere->frere = newNoeud;
    }
}

//affiche l'arbre
void affichageArbre(noeud *monNoeud){
    printf("%d",monNoeud->valeur);
    if(monNoeud->frere!=NULL){
        printf(" -- ");
        affichageArbre(monNoeud->frere);
    }
    if(monNoeud->enfant!=NULL){
        printf("\nEnfant de %d :",monNoeud->valeur);
        affichageArbre(monNoeud->enfant);
    }
}
