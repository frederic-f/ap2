#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

int dernier_recu (liste L)
{
    if (est_vide (L))
    {
        printf ("<<< Erreur_typelt >>> \n") ;
        return (0) ;
    }

    if (est_vide (reste (L)))
    {
        return (prem (L)) ;
    }
    else
    {
        return (dernier_recu (reste (L))) ;
    }
}

int dernier_iter (liste L)
{
    liste M ;

    M = L ;

    if (est_vide (M))
    {
        printf ("<<< Erreur_typelt >>> \n") ;
        return (0) ;
    }

    while (!est_vide (reste (M)))
    {
        M = reste (M) ;
    }

    return (prem (M)) ;
}

void test_dernier_param (liste L)
{
    printf("\n") ;
    // test de la version récursive

    int dernier_element_recu ;

    dernier_element_recu = dernier_recu (L) ;

    printf ("dernier_recu (") ;
    print_liste (L) ;
    printf (") = ") ;
    printf ("%d", dernier_element_recu) ;

    printf("\n") ;

    // test de la version itérative

    int dernier_element_iter ;

    dernier_element_iter = dernier_iter (L) ;

    printf ("dernier_iter (") ;
    print_liste (L) ;
    printf (") = ") ;
    printf ("%d", dernier_element_iter) ;

    printf("\n\n") ;
}

void test_dernier ()
{
    liste L, M, N, O ;

    L = l_vide ();

    test_dernier_param (L) ;

    M = cons (3, L) ;

    test_dernier_param (M) ;

    N = cons (2, M) ;

    test_dernier_param (N) ;

    O = cons (1, N) ;

    test_dernier_param (O) ;
}

int main (void)
{
    test_dernier () ;

    return EXIT_SUCCESS ;
}

/*

$ ./09_dernier

<<< Erreur_typelt >>>
dernier_recu (()) = 0
<<< Erreur_typelt >>>
dernier_iter (()) = 0


dernier_recu ((3)) = 3
dernier_iter ((3)) = 3


dernier_recu ((2, 3)) = 3
dernier_iter ((2, 3)) = 3


dernier_recu ((1, 2, 3)) = 3
dernier_iter ((1, 2, 3)) = 3

*/