#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

bool sous_seq_recu (liste L1, liste L2)
{
    if (est_vide (L1))
    {
        return true ;
    }

    if (est_vide (L2))
    {
        return false ;
    }

    if ((prem (L1) == prem (L2))) // si le premier elément de chaque liste est commun
    {
        return (sous_seq_recu (reste (L1), reste (L2))) ; // on retire l'élement de L1, et continue avec reste de L2
    }
    else
    {
        return (sous_seq_recu (L1, reste (L2))) ; // otherwise we do not touch L1, and go with the next element of L2
    }
}

bool sous_seq_iter (liste L1, liste L2)
{
    return (true) ;
}

void test_sous_seq_param (liste L1, liste L2)
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
    liste L, M, N, O, P ;

    L = l_vide () ;

    test_sous_seq_param (L, L) ;

    M = cons (3, cons (2, cons (2, L))) ;

    test_sous_seq_param (L, M) ;

    N = cons (3, cons (2, L)) ;

    test_sous_seq_param (N, M) ;
    test_sous_seq_param (M, N) ;

    O = cons (1, cons (180, M)) ;

    test_sous_seq_param (M, O) ;

    P = cons (4, M) ;

    test_sous_seq_param (P, O) ;

}

int main (void)
{
    test_sous_seq () ;

    return EXIT_SUCCESS ;
}

/*

 fonction.c

 */