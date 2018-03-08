#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste sup_rep_recu (liste L)
{
    if ((est_vide (L)) || (est_vide (reste (L))))
    {
        return (L) ; // dernier element, on le garde
    }

    if ( prem (L) == (prem (reste (L)))) // si les deux elements qui se suivent sont les memes
    {
        return (sup_rep_recu (reste (L))) ; // on continue en ignorant le premier
    }
    else // sinon, on garde le premier et on continue
    {
        return (cons (prem (L), sup_rep_recu (reste (L)))) ;
    }
}

liste sup_rep_iter (liste L)
{
    liste M, N ;

    M = l_vide () ;
    N = renverser (L) ;

    if (!est_vide (N)) // si N est vide on retourne direct liste nulle
    {
        while (!est_vide (reste (N))) // tant qu'il y a au moins deux elements dans la liste
        {
            if (!(prem (N) == prem (reste (N)))) // on regarde si ils sont differents
            {
                M = cons(prem (N), M) ; // si c'est le cas, on garde le premier
            }

            N = reste (N) ;
        }

        M = cons (prem (N), M) ; // ne pas oublier d'ajouter le dernier element
    }

    return (M) ;
}

void test_sup_rep_param (liste L)
{
    printf("\n") ;
    // test de la version récursive

    liste L_repetitions_supprimees_recu ;
    L_repetitions_supprimees_recu = sup_rep_recu (L) ;

    printf ("sup_rep_recu (") ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_repetitions_supprimees_recu) ;

    printf("\n") ;

    // test de la version itérative
    liste L_repetitions_supprimees_iter ;
    L_repetitions_supprimees_iter = sup_rep_iter (L) ;

    printf ("sup_rep_iter (") ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (L_repetitions_supprimees_iter) ;

    printf("\n\n") ;
}

void test_sup_rep ()
{
    liste L, M, N ;

    L = l_vide () ;

    test_sup_rep_param (L) ;

    M = cons (4, cons (4, L)) ;

    test_sup_rep_param (M) ;

    N = cons (3, cons (2, cons (2, M))) ;

    test_sup_rep_param (N) ;
}

int main (void)
{
    test_sup_rep () ;

    return EXIT_SUCCESS ;
}

/*

$ ./13_supprimer_repetitions

sup_rep_recu (()) = ()
sup_rep_iter (()) = ()


sup_rep_recu ((4, 4)) = (4)
sup_rep_iter ((4, 4)) = (4)


sup_rep_recu ((3, 2, 2, 4, 4)) = (3, 2, 4)
sup_rep_iter ((3, 2, 2, 4, 4)) = (3, 2, 4)

*/