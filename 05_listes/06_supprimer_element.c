#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste supp_elem_recu (int x, liste L)
{
    if (est_vide (L))
    {
        return (L) ;
    }

    if (x == prem (L)) // element a supprimer
    {
        return (supp_elem_recu (x, reste (L)) ) ;
    }
    else // element a garder
    {
        return (cons (prem (L), supp_elem_recu (x, reste (L)))) ;
    }
}

liste supp_elem_iter (int x, liste L)
{
    int position ;
    int element ;
    liste M ;

    M = l_vide () ;

    for (position = longueur (L) ; position > 0 ; position -= 1)
    {
        element = neme_element (position, L) ;

        if (x != element)
        {
            M = cons (element, M) ;
        }
    }

    return (M) ;
}

void test_supp_elem_param (int x, liste L)
{
    printf("\n") ;

    // test de la version récursive

    liste L_elem_supp_recu ;

    L_elem_supp_recu = supp_elem_recu (x, L) ;

    printf ("supp_elem_recu (%d, ", x) ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_elem_supp_recu) ;

    printf("\n") ;

    // test de la version itérative

    liste L_elem_supp_iter ;

    L_elem_supp_iter = supp_elem_iter (x, L) ;

    printf ("supp_elem_iter (%d, ", x) ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_elem_supp_iter) ;

    printf("\n") ;
}

void test_supp_elem ()
{
    liste L, M, N, O ;

    L = l_vide () ;
    M = cons (3, L) ;
    N = cons (2, cons (6, M)) ;
    O = cons(6, cons(5, cons(6, cons (2, cons (6, M))))) ;

    test_supp_elem_param (6, L) ;

    test_supp_elem_param (6, M) ;

    test_supp_elem_param (6, N) ;

    test_supp_elem_param (6, O) ;
}

int main (void)
{
    test_supp_elem () ;

    return EXIT_SUCCESS ;
}

/*

$ ./06_supprimer_element

supp_elem_recu (6, ()) = ()
supp_elem_iter (6, ()) = ()

supp_elem_recu (6, (3)) = (3)
supp_elem_iter (6, (3)) = (3)

supp_elem_recu (6, (2, 6, 3)) = (2, 3)
supp_elem_iter (6, (2, 6, 3)) = (2, 3)

supp_elem_recu (6, (6, 5, 6, 2, 6, 3)) = (5, 2, 3)
supp_elem_iter (6, (6, 5, 6, 2, 6, 3)) = (5, 2, 3)

 */