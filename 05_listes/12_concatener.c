#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste concatener_recu (liste L1, liste L2)
{
    if ((est_vide (L1)) && (est_vide (L2)))
    {
        return (l_vide ()) ;
    }

    if (est_vide (L1)) // L2 n'est pas vide, on prend ses elements
    {
        return (cons (prem (L2), concatener_recu (L1, reste (L2)))) ;
    }
    else // que L2 soit vide ou pas, on prend les elements de L1
    {
        return (cons (prem (L1), concatener_recu (reste (L1), L2))) ;
    }
}

liste concatener_iter (liste L1, liste L2)
{
    liste M, N1, N2 ;

    M = l_vide () ;
    N1 = renverser (L1) ;
    N2 = renverser (L2) ;

    while (!est_vide (N2)) // on commence par N2
    {
        M = cons (prem (N2), M) ;
        N2 = reste (N2) ;
    }

    while (!est_vide (N1))
    {
        M = cons (prem (N1), M) ;
        N1 = reste (N1) ;
    }

    return (M) ;
}

void test_concatener_param (liste L1, liste L2)
{
    printf("\n") ;
    // test de la version récursive

    liste L_concat_recu ;
    L_concat_recu = concatener_recu (L1, L2) ;

    printf ("concatener_recu (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    print_liste (L_concat_recu) ;

    printf("\n") ;

    // test de la version itérative
    liste L_concat_iter ;
    L_concat_iter = concatener_iter (L1, L2) ;

    printf ("concatener_iter (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    print_liste (L_concat_iter) ;

    printf("\n\n") ;
}

void test_concatener ()
{
    liste L, M, N, O ;

    L = l_vide () ;

    test_concatener_param (L, L) ;

    M = cons (2, L) ;

    test_concatener_param (L, M) ;

    test_concatener_param (M, L) ;

    test_concatener_param (M, M) ;

    N = cons (3, cons (6, M)) ;

    O = cons (189, M) ;

    test_concatener_param (N, O) ;

    test_concatener_param (O, N) ;
}

int main (void)
{
    test_concatener () ;

    return EXIT_SUCCESS ;
}

/*

$ ./12_concatener

concatener_recu ((), ()) = ()
concatener_iter ((), ()) = ()


concatener_recu ((), (2)) = (2)
concatener_iter ((), (2)) = (2)


concatener_recu ((2), ()) = (2)
concatener_iter ((2), ()) = (2)


concatener_recu ((2), (2)) = (2, 2)
concatener_iter ((2), (2)) = (2, 2)


concatener_recu ((3, 6, 2), (189, 2)) = (3, 6, 2, 189, 2)
concatener_iter ((3, 6, 2), (189, 2)) = (3, 6, 2, 189, 2)


concatener_recu ((189, 2), (3, 6, 2)) = (189, 2, 3, 6, 2)
concatener_iter ((189, 2), (3, 6, 2)) = (189, 2, 3, 6, 2)

 */