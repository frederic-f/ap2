#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste snoc_recu (liste L, int a)
{
    if (est_vide (L))
    {
        return (cons (a, l_vide())) ;
    }
    else
    {
        return (cons (prem (L), snoc_recu (reste (L), a))) ;
    }
}

liste snoc_iter (liste L, int a)
{
    liste M, N ;

    M = cons (a, l_vide()) ;
    N = renverser (L) ;

    while (!est_vide (N))
    {
        M = cons (prem (N), M) ;
        N = reste (N) ;
    }

    return (M) ;
}

void test_snoc_param (liste L, int a)
{
    printf("\n") ;
    // test de la version récursive

    liste L_snoc_recu ;

    L_snoc_recu = snoc_recu (L, a) ;

    printf ("snoc_recu (") ;
    print_liste (L) ;
    printf (", %d) = ",  a) ;
    print_liste (L_snoc_recu) ;

    printf("\n") ;

    // test de la version itérative

    liste L_snoc_iter ;

    L_snoc_iter = snoc_iter (L, a) ;

    printf ("snoc_iter (") ;
    print_liste (L) ;
    printf (", %d) = ",  a) ;
    print_liste (L_snoc_iter) ;

    printf("\n\n") ;
}

void test_snoc ()
{
    liste M, N, O ;

    M = l_vide () ;

    test_snoc_param (M, 21) ;

    N = cons (31, cons (32, M)) ;

    test_snoc_param (N, 21) ;

    O = cons (1, cons (0, cons (123, N))) ;

    test_snoc_param (O, 21) ;

}

int main (void)
{
    test_snoc () ;

    return EXIT_SUCCESS ;
}

/*

$ ./11_snoc

snoc_recu ((), 21) = (21)
snoc_iter ((), 21) = (21)


snoc_recu ((31, 32), 21) = (31, 32, 21)
snoc_iter ((31, 32), 21) = (31, 32, 21)


snoc_recu ((1, 0, 123, 31, 32), 21) = (1, 0, 123, 31, 32, 21)
snoc_iter ((1, 0, 123, 31, 32), 21) = (1, 0, 123, 31, 32, 21)

*/