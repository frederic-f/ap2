#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

int neme_recu (int a, liste L)
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
        return (neme_recu (a - 1, reste (L))) ;
    }
}

int neme_iter (int a, liste L)
{
    liste M ;
    int nb ;

    M = L ;
    nb = a ;

    if ( (nb == 0) || (est_vide (M)))
    {
        return (0) ;
    }

    while ((nb > 1) && (!est_vide (M)))
    {
        M = reste (M) ;
        nb -= 1 ;
    }
    // arrivé ici, nb = 1

    if (est_vide (M)) { return (0) ; } else { return (prem (M)) ; }
}

void test_neme_param (int a, liste L)
{
    // test de la version récursive de la fonction

    int el_recu ;
    el_recu = neme_recu (a, L) ;

    printf ("neme_recu (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = ") ; // fonction_ (1, (0, 3, 3))
    if (el_recu > 0) { printf ("%d", el_recu) ; } else { printf ("Erreur_typelt") ; }

    printf("\n") ;

    // test de la version itérative de la fonction

    int el_iter ;
    el_iter = neme_iter (a, L) ;

    printf ("neme_iter (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = ") ; // fonction_ (1, (0, 3, 3))
    if (el_iter > 0) { printf ("%d\n", el_iter) ; } else { printf ("Erreur_typelt") ; }

    printf("\n\n") ;
}

void test_neme ()
{
    liste L, M ;

    test_neme_param (0, l_vide()) ;

    test_neme_param (1, l_vide());

    L = cons (8, l_vide());

    test_neme_param (1, L) ;

    test_neme_param (0, L) ;

    M = cons (2, cons (4, L)) ;

    test_neme_param (2, M) ;

    test_neme_param (0, M) ;

    test_neme_param (3, M) ;

    test_neme_param (4, M) ;

    test_neme_param (14, M) ;
}

int main (void)
{
    test_neme () ;

    return EXIT_SUCCESS ;
}

/*

$ ./03_neme_element
neme_recu (0, ()) = Erreur_typelt
neme_iter (0, ()) = Erreur_typelt

neme_recu (1, ()) = Erreur_typelt
neme_iter (1, ()) = Erreur_typelt

neme_recu (1, (8)) = 8
neme_iter (1, (8)) = 8


neme_recu (0, (8)) = Erreur_typelt
neme_iter (0, (8)) = Erreur_typelt

neme_recu (2, (2, 4, 8)) = 4
neme_iter (2, (2, 4, 8)) = 4


neme_recu (0, (2, 4, 8)) = Erreur_typelt
neme_iter (0, (2, 4, 8)) = Erreur_typelt

neme_recu (3, (2, 4, 8)) = 8
neme_iter (3, (2, 4, 8)) = 8


neme_recu (4, (2, 4, 8)) = Erreur_typelt
neme_iter (4, (2, 4, 8)) = Erreur_typelt

neme_recu (14, (2, 4, 8)) = Erreur_typelt
neme_iter (14, (2, 4, 8)) = Erreur_typelt



 */