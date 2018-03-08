#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste neme_reste_recu (int n, liste L)
{
    if ((est_vide (L)) || (n == 0))
    {
        return (L) ;
    }

    if (n == 1)
    {
        return (reste (L)) ;
    }
    else // n > 1 et L non vide, on part dans la récurrence
    {
        return neme_reste_recu (n - 1, reste (L)) ;
    }
}

liste neme_reste_iter (int n, liste L)
{
    int nb ;
    liste M;

    nb = n ;
    M = L ;

    while ((nb >= 1) && (! est_vide (M)))
    {
        M = reste (M) ;
        nb -= 1 ;
    }

    return M ;
}

void test_neme_reste_param (int a, liste L)
{
    // test de la version récursive de la fonction

    liste reste_recu ;
    reste_recu = neme_reste_recu (a, L) ;

    printf ("neme_reste_recu (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = ") ; // fonction_ (1, (0, 3, 3))
    print_liste (reste_recu);

    printf("\n") ;

    // test de la version itérative de la fonction

    liste reste_iter ;
    reste_iter = neme_reste_iter (a, L) ;

    printf ("neme_reste_iter (%d, ", a) ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf (") = ") ; // fonction_ (1, (0, 3, 3))
    print_liste (reste_iter);

    printf("\n\n") ;
}

void test_neme_reste ()
{
    liste L, M ;

    test_neme_reste_param (0, l_vide()) ;

    test_neme_reste_param (1, l_vide());

    L = cons (8, l_vide());

    test_neme_reste_param (1, L) ;

    test_neme_reste_param (0, L) ;

    M = cons (2, cons (4, L)) ;

    test_neme_reste_param (0, M) ;

    test_neme_reste_param (1, M) ;

    test_neme_reste_param (2, M) ;

    test_neme_reste_param (14, M) ;
}

int main (void)
{
    test_neme_reste () ;

    return EXIT_SUCCESS ;
}

/*

$ ./04_neme_reste
neme_reste_recu (0, ()) = ()
neme_reste_iter (0, ()) = ()

neme_reste_recu (1, ()) = ()
neme_reste_iter (1, ()) = ()

neme_reste_recu (1, (8)) = ()
neme_reste_iter (1, (8)) = ()

neme_reste_recu (0, (8)) = (8)
neme_reste_iter (0, (8)) = (8)

neme_reste_recu (0, (2, 4, 8)) = (2, 4, 8)
neme_reste_iter (0, (2, 4, 8)) = (2, 4, 8)

neme_reste_recu (1, (2, 4, 8)) = (4, 8)
neme_reste_iter (1, (2, 4, 8)) = (4, 8)

neme_reste_recu (2, (2, 4, 8)) = (8)
neme_reste_iter (2, (2, 4, 8)) = (8)

neme_reste_recu (14, (2, 4, 8)) = ()
neme_reste_iter (14, (2, 4, 8)) = ()

 */