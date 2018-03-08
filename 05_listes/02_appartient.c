#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

bool appartient_rec (int a, liste L)
{
    if (est_vide (L))
    {
        return false ;
    }

    if (a == prem (L))
    {
        return true ;
    }

    return appartient_rec (a, reste (L)) ;
}

bool appartient_ite (int a, liste L)
{
    int x = a ;
    liste M = L ;

    while (!est_vide (M))
    {
        if (a == prem (M))
        {
            return true ;
        }

        M = reste (M) ;
    }

    return false ;
}

void test_appartient_param (int a, liste L)
{
    // test de la version récursive de la fonction
    bool app_rec ;
    app_rec = appartient_rec (a, L) ;

    printf ("appartient_rec (%d, ", a) ; // appartient_rec (1,
    print_liste (L) ; // appartient_rec (1, (0, 3, 3)
    printf (") = ") ; // appartient_rec (1, (0, 3, 3))

    if (app_rec) { printf("vrai") ; } else { printf("faux") ; } // appartient_rec (1, (0, 3, 3)) = faux

    /* -------------------- */
    printf("\n") ;
    /* -------------------- */

    // test de la version itérative de la fonction
    bool app_ite ;
    app_ite = appartient_ite (a, L) ;


    printf ("appartient_ite (%d, ", a) ; // appartient_ite (1,
    print_liste (L) ; // appartient_ite (1, (0, 3, 3)
    printf (") = ") ; // appartient_ite (1, (0, 3, 3))

    if (app_ite) { printf ("vrai") ; } else { printf ("faux") ; } // appartient_ite (1, (0, 3, 3)) = faux

    /* -------------------- */
    printf("\n\n") ;
    /* -------------------- */

}

void test_appartient ()
{
    liste L, M ;

    test_appartient_param (1, l_vide());

    L = cons (1, l_vide());

    test_appartient_param (1, L) ;

    test_appartient_param (0, L) ;

    M = cons (4, L) ;

    test_appartient_param (1, M) ;

    test_appartient_param (0, M) ;

    test_appartient_param (4, M) ;

}

int main (void)
{
    test_appartient () ;

    return EXIT_SUCCESS ;
}

/*
$ ./02_appartient
appartient_rec (1, ()) = faux
appartient_ite (1, ()) = faux

appartient_rec (1, (1)) = vrai
appartient_ite (1, (1)) = vrai

appartient_rec (0, (1)) = faux
appartient_ite (0, (1)) = faux

appartient_rec (1, (4, 1)) = vrai
appartient_ite (1, (4, 1)) = vrai

appartient_rec (0, (4, 1)) = faux
appartient_ite (0, (4, 1)) = faux

appartient_rec (4, (4, 1)) = vrai
appartient_ite (4, (4, 1)) = vrai
 */