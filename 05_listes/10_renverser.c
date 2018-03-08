#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"


liste renverser_recu_FA (liste L, liste M)
{
    if (est_vide (L))
    {
        return (M) ;
    }
    else
    {
        return (renverser_recu_FA (reste (L), cons (prem (L), M))) ;
    }
}

liste renverser_recu (liste L)
{
    return renverser_recu_FA (L, l_vide ()) ;
}

liste renverser_iter (liste L)
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

void test_renverser_param (liste L)
{
    printf("\n") ;
    // test de la version récursive

    liste L_renv_recu = renverser_recu (L) ;

    printf ("renverser_recu (") ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_renv_recu) ;

    printf("\n") ;

    // test de la version itérative

    liste L_renv_iter = renverser_iter (L) ;

    printf ("renverser_iter (") ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_renv_iter) ;

    printf("\n\n") ;
}

void test_renverser ()
{
    liste L, M, N, O ;

    L = l_vide ();

    test_renverser_param (L) ;

    M = cons (3, L) ;

    test_renverser_param (M) ;

    N = cons (2, M) ;

    test_renverser_param (N) ;

    O = cons (1, N) ;

    test_renverser_param (O) ;
}

int main (void)
{
    test_renverser () ;

    return EXIT_SUCCESS ;
}

/*

$ ./10_renverser

renverser_recu (()) = ()
renverser_iter (()) = ()


renverser_recu ((3)) = (3)
renverser_iter ((3)) = (3)


renverser_recu ((2, 3)) = (3, 2)
renverser_iter ((2, 3)) = (3, 2)


renverser_recu ((1, 2, 3)) = (3, 2, 1)
renverser_iter ((1, 2, 3)) = (3, 2, 1)

*/