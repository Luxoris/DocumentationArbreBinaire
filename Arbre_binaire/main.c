#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int nValeur;
    struct noeud *gauche;
    struct noeud *droite;
} noeud;

//Prototypes des fonctions
void ajouterNoeud(noeud **arbre, int nValeur);
int chercherNoeud(noeud *arbre, int nValeur);


//Programme principal (MAIN)
//BUT : Cr�er et g�rer un arbre binaire
//ENTREE : L'environnement
//SORTIE : L'environnement
int main()
{
    noeud *Arbre = NULL;
    ajouterNoeud(&Arbre, 30);

    if(chercherNoeud(Arbre, 1))
    {
        printf("Il y a la valeur 1 dans l'arbre !");
    }
    else
    {
        printf("Il n'y a pas la valeur 1 dans l'arbre !");
    }
    return 0;
}

//Impl�mentation de la m�thode
//BUT : Ajouter un noeud au sein de l'arbre
//ENTREE : L'arbre et la valeur � ins�rer dans le noeud
//SORTIE : L'arbre modifi�
//NOTE : Donc si l'�l�ment n'est pas le premier, on boucle (boucle do while) afin d'avancer de n�ud en n�ud jusqu'� atteindre un emplacement
//libre (pointeur � NULL) et � chaque n�ud on part � droite, si la cl� est sup�rieure � celle du n�ud courant, ou � gauche si elle est inf�rieure
//ou �gale � celle du n�ud courant.
void ajouterNoeud(noeud **arbre, int nValeur)
{
    noeud *tmpNoeud;
    noeud *tmpArbre = *arbre;

    noeud *elem = malloc(sizeof(noeud));
    elem->nValeur = nValeur;
    elem->gauche = NULL;
    elem->droite = NULL;

    if(tmpArbre)
    do
    {
        tmpNoeud = tmpArbre;
        if(nValeur > tmpArbre->nValeur )
        {
            tmpArbre = tmpArbre->droite;
            if(!tmpArbre) tmpNoeud->droite = elem;
        }
        else
        {
            tmpArbre = tmpArbre->gauche;
            if(!tmpArbre) tmpNoeud->gauche = elem;
        }
    } while(tmpArbre);
    else  *arbre = elem;
}


//Impl�mentation de la m�thode
//BUT : Chercher une valeur dans l'arbre
//ENTREE : L'arbre et la valeur
//SORTIE : Un bool�en
//NOTE : On suit le cheminement en partant � droite ou � gauche selon la valeur de la cl�. � chaque n�ud on v�rifie si on est en pr�sence
//de l'�l�ment recherch�, si oui on retourne la valeur 1. Quand on arrive au bout de la branche si on ne l'a pas trouv� on retourne 0.
int chercherNoeud(noeud *arbre, int nValeur)
{
    while(arbre)
    {
        if(nValeur == arbre->nValeur)
        {
            return 1;
        }

        if(nValeur > arbre->nValeur)
        {
            arbre = arbre->droite;
        }
        else
        {
            arbre = arbre->gauche;
        }
    }
    return 0;
}
