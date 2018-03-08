#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

bool sous_seq_recu (liste L1, liste L2)
{
    return (true) ;
}

bool sous_seq_iter (liste L1, liste L2)
{
    return (true) ;
}

void test_sous_seq_param (int a, liste L)
{
    printf("\n") ;
    // test de la version récursive

    bool L1_sous_seq_L2 ;
    L1_sous_seq_L2 = sous_seq_recu (L1, L2) ;

    printf ("bool sous_seq_recu (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;

    if (L1_sous_seq_L2) { printf ("vrai") ; } else { printf ("faux") ; }

    printf("\n") ;

    // test de la version itérative


    printf("\n\n") ;
}

void test_sous_seq ()
{
    liste L, M, N, O ;

    L = l_vide () ;

    test_sous_seq_param (L, L) ;

    M = cons (3, cons (2, cons (2, L))) ;

    test_sous_seq_param (L, M) ;

    N = cons (3, cons (2, L)) ;

    test_sous_seq_param (N, M) ;
    test_sous_seq_param (M, N) ;

    O = cons (1, cons (180, M))

    test_sous_seq_param (M, O) ;

}

int main (void)
{
    test_sous_seq () ;

    return EXIT_SUCCESS ;
}

/*

 fonction.c

 */