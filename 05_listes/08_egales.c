#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

bool egales_rec (liste L, liste M)
{
    if (est_vide (L) && est_vide (M))
    {
        return true ;
    }

    if (est_vide (L) || est_vide (M))
    {
        return false ;
    }

    if (prem (L) == prem (M))
    {
        return (egales_rec (reste (L), reste (M))) ;
    }
    else
    {
        return false ;
    }
}

bool egales_ite (liste L, liste M)
{
    liste N, O ;
    N = L ;
    O = M ;

    while ((!est_vide (N)) && (!est_vide (O))) // aucune des listes n'est vide
    {
        if ((prem (N)) == (prem (O))) // si pour l'instant il n'y a pas de différences
        {
            N = reste (N) ; // on continue la comparaison avec les élements suivants
            O = reste (O) ;
        }
        else // si une difference apparait : les listes ne sont pas egales
        {
            return false ;
        }
    }

    // arrivé ici : au moins une des deux listes est vide
    // si les deux listes sont vides : elles sont égales. Sinon, non.
    return (est_vide (N) && est_vide (O)) ;
}

void test_egales_param (liste L, liste M)
{
    // test de la version récursive de la fonction
    bool ega_rec ;
    ega_rec = egales_rec (L, M) ;

    printf ("egales_rec ( ") ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf(", ") ;
    print_liste (M) ; //
    printf (" ) = ") ; // fonction_ (1, (0, 3, 3))
    if (ega_rec) { printf ("vrai") ; } else { printf ("faux") ; }

    /* -------------------- */
    printf("\n") ;
    /* -------------------- */

    // test de la version itérative de la fonction
    bool ega_ite ;
    ega_ite = egales_ite (L, M) ;

    printf ("egales_ite ( ") ; // fonction_ (1,
    print_liste (L) ; // fonction_ (1, (0, 3, 3)
    printf(", ") ;
    print_liste (M) ; //
    printf (" ) = ") ; // fonction_ (1, (0, 3, 3))
    if (ega_ite) { printf ("vrai") ; } else { printf ("faux") ; }


    /* -------------------- */
    printf("\n\n") ;
    /* -------------------- */

}

void test_egales ()
{
    test_egales_param (l_vide (), l_vide ()) ;

    test_egales_param (cons (3, l_vide ()), l_vide ()) ;

    test_egales_param (l_vide (), cons (3, l_vide ())) ;

    test_egales_param (cons ( 3, l_vide ()), (cons (3, l_vide ()))) ;

    liste L, M, N, O ;

    M = cons (3, cons (2, l_vide ())) ;
    L = cons (3, cons (2, l_vide ())) ;

    test_egales_param (M, L);

    N = cons(5, M) ;

    test_egales_param (N, L) ;

    O = cons (0, L) ;

    test_egales_param (N, O) ;
    test_egales_param (O, N) ;
}

int main (void)
{
    test_egales () ;

    return EXIT_SUCCESS ;
}

/*

$ ./08_egales
egales_rec ( (), () ) = vrai
egales_ite ( (), () ) = vrai

egales_rec ( (3), () ) = faux
egales_ite ( (3), () ) = faux

egales_rec ( (), (3) ) = faux
egales_ite ( (), (3) ) = faux

egales_rec ( (3), (3) ) = vrai
egales_ite ( (3), (3) ) = vrai

egales_rec ( (3, 2), (3, 2) ) = vrai
egales_ite ( (3, 2), (3, 2) ) = vrai

egales_rec ( (5, 3, 2), (3, 2) ) = faux
egales_ite ( (5, 3, 2), (3, 2) ) = faux

egales_rec ( (5, 3, 2), (0, 3, 2) ) = faux
egales_ite ( (5, 3, 2), (0, 3, 2) ) = faux

egales_rec ( (0, 3, 2), (5, 3, 2) ) = faux
egales_ite ( (0, 3, 2), (5, 3, 2) ) = faux



 */