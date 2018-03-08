#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

int nb_occ_rec (int a, liste L)
{

    if (est_vide (L))
    {
        return (0) ;
    }

    if (a == prem (L))
    {
        return (1 + nb_occ_rec (a, reste (L))) ;
    }
    else
    {
        return (nb_occ_rec (a, reste (L))) ;
    }
}

int nb_occ_ite (int a, liste L)
{
    liste M ;
    int nb ;

    M = L ;
    nb = 0 ;

    while (! est_vide (M))
    {
        if (a == prem (M))
        {
            nb += 1 ;
        }

        M = reste (M) ;
    }

    return (nb) ;
}

void test_nb_occ_param (int a, liste L)
{
    // test de la version récursive de la fonction
    int nb_rec ;
    nb_rec = nb_occ_rec (a, L) ;

    printf ("nb_occ_rec (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = %d", nb_rec) ; // fonction_ (1, (0, 3, 3))


    /* -------------------- */
    printf("\n") ;
    /* -------------------- */

    // test de la version itérative de la fonction
    int nb_ite ;
    nb_ite = nb_occ_ite (a, L) ;

    printf ("nb_occ_ite (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = %d", nb_ite) ; // fonction_ (1, (0, 3, 3))


    /* -------------------- */
    printf("\n\n") ;
    /* -------------------- */

}

void test_nb_occ ()
{
    liste L, M, N ;

    test_nb_occ_param (1, l_vide ()) ;

    L = cons (2, l_vide());

    test_nb_occ_param (2, L) ;

    M = cons (2, L) ;

    test_nb_occ_param (2, M) ;

    N = cons (3, cons (4, M)) ;

    test_nb_occ_param (2, N) ;

    test_nb_occ_param (0, N) ;
}

int main (void)
{
    test_nb_occ () ;

    return EXIT_SUCCESS ;
}

/*

$ ./03_nb_occurrences
nb_occ_rec (1, ()) = 0
nb_occ_ite (1, ()) = 0

nb_occ_rec (2, (2)) = 1
nb_occ_ite (2, (2)) = 1

nb_occ_rec (2, (2, 2)) = 2
nb_occ_ite (2, (2, 2)) = 2

nb_occ_rec (2, (3, 4, 2, 2)) = 2
nb_occ_ite (2, (3, 4, 2, 2)) = 2

nb_occ_rec (0, (3, 4, 2, 2)) = 0
nb_occ_ite (0, (3, 4, 2, 2)) = 0

 */