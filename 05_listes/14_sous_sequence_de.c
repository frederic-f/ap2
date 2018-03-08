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
    liste M, N ;

    M = L1 ; // sous liste
    N = L2 ;

    while ( ! (est_vide (M) || est_vide (N))) // on ne retourne un résultat que si au moins une des deux listes est vide
    {
        if (prem (M) == prem (N))
        {
            M = reste (M) ;
        }

        N = reste (N) ;
    }

    return est_vide (M) ; // L1 est une sous-liste de L2 si L1 est vide a la fin des iterations
}

void test_sous_seq_param (liste L1, liste L2)
{
    printf("\n") ;
    // test de la version récursive

    bool L1_sous_seq_L2_recu ;
    L1_sous_seq_L2_recu = sous_seq_recu (L1, L2) ;

    printf ("bool sous_seq_recu (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;

    if (L1_sous_seq_L2_recu) { printf ("vrai") ; } else { printf ("faux") ; }

    printf("\n") ;

    // test de la version itérative
    bool L1_sous_seq_L2_iter ;
    L1_sous_seq_L2_iter = sous_seq_iter (L1, L2) ;

    printf ("bool sous_seq_iter (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;

    if (L1_sous_seq_L2_iter) { printf ("vrai") ; } else { printf ("faux") ; }

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

$ ./14_sous_sequence_de

bool sous_seq_recu ((), ()) = vrai
bool sous_seq_iter ((), ()) = vrai


bool sous_seq_recu ((), (3, 2, 2)) = vrai
bool sous_seq_iter ((), (3, 2, 2)) = vrai


bool sous_seq_recu ((3, 2), (3, 2, 2)) = vrai
bool sous_seq_iter ((3, 2), (3, 2, 2)) = vrai


bool sous_seq_recu ((3, 2, 2), (3, 2)) = faux
bool sous_seq_iter ((3, 2, 2), (3, 2)) = faux


bool sous_seq_recu ((3, 2, 2), (1, 180, 3, 2, 2)) = vrai
bool sous_seq_iter ((3, 2, 2), (1, 180, 3, 2, 2)) = vrai


bool sous_seq_recu ((4, 3, 2, 2), (1, 180, 3, 2, 2)) = faux
bool sous_seq_iter ((4, 3, 2, 2), (1, 180, 3, 2, 2)) = faux

 */