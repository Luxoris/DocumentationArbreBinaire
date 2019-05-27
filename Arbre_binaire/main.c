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
//BUT : Créer et gérer un arbre binaire
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

//Implémentation de la méthode
//BUT : Ajouter un noeud au sein de l'arbre
//ENTREE : L'arbre et la valeur à insérer dans le noeud
//SORTIE : L'arbre modifié
//NOTE : Donc si l'élément n'est pas le premier, on boucle (boucle do while) afin d'avancer de nœud en nœud jusqu'à atteindre un emplacement
//libre (pointeur à NULL) et à chaque nœud on part à droite, si la clé est supérieure à celle du nœud courant, ou à gauche si elle est inférieure
//ou égale à celle du nœud courant.
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


//Implémentation de la méthode
//BUT : Chercher une valeur dans l'arbre
//ENTREE : L'arbre et la valeur
//SORTIE : Un booléen
//NOTE : On suit le cheminement en partant à droite ou à gauche selon la valeur de la clé. À chaque nœud on vérifie si on est en présence
//de l'élément recherché, si oui on retourne la valeur 1. Quand on arrive au bout de la branche si on ne l'a pas trouvé on retourne 0.
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
