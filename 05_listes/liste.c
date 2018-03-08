#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

/* IMPLEMENTATION DES OPERATIONS PRIMITIVES */

/* Constructeurs */

liste l_vide ()
{
    return NULL ;
}

liste cons (int x, liste L)
{
    liste M ;
    /* Réservation de la mémoire nécessaire */
    M = malloc (sizeof (*M)) ;
    M->premier = x ;
    M->suivant = L ;
    return M ;
}

/* Accès */
bool est_vide (liste L)
{
    return L == NULL ;
}

int prem (liste L)
{
    if (est_vide (L))
    {
        printf ("Calcul de prem sur liste vide !\n") ;
        exit (0) ;
    }
    return L->premier ;
}

liste reste (liste L)
{
    return L->suivant ;
}

// impression de la liste en ITERATIF
// TODO - impression de la liste en RECURSIF
// TODO - fonction retourne une chaine de caracteres plutot que d'imprimer directement
int print_liste (liste L)
{
    liste M ;
    M = L ;

    if (!est_vide (M)) // si la liste n'est PAS vide
    {
        printf ("(%d", prem (M)) ; // affichage '(' et premiere valeur // (1
        M = reste (M) ;

        while (!est_vide (M))
        {
            printf (", %d", prem (M)) ; // affichage ',' et valeurs suivantes// (1, 2
            M = reste (M) ;
        }

        printf (")") ; // on referme la parenthese // (1, 2)
    }
    else // si la liste est vide
    {
        printf ("()") ;
    }

    return EXIT_SUCCESS;
}

void liberer_liste (liste L)
{
    if (est_vide(L))
    {
        return ;
    }
    liberer_liste (reste (L)) ;
    free (L);
}


int longueur (liste L)
{
    if (est_vide (L))
    {
        return 0 ;
    }

    return (1 + longueur (reste (L))) ;
}

int neme_element (int a, liste L)
{
    if ( (a == 0) || (est_vide (L)))
    {
        return (0) ;
    }

    if (a == 1)
    {
        return prem (L) ;
    }
    else
    {
        return (neme_element (a - 1, reste (L))) ;
    }
}

liste renverser (liste L) // version itérative
{
    liste M, N ;

    M = l_vide () ;
    N = L ;

    while (!est_vide (N))
    {
        M = cons (prem (N), M) ;
        N = reste (N) ;
    }

    return (M) ;
}