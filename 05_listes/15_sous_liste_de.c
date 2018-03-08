#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"


bool sous_liste_recu_FA (liste L1, liste L2)
{
    if (est_vide (L1)) { return (true) ; } // on a vidé L1, c'est bien une sous-liste
    if (est_vide (L2)) { return (false) ; } // on a vidé L2 avant L1, L1 n'est pas une sous-liste

    if (prem (L1) == prem (L2)) // si les deux premiers éléments sont égaux, ça peut etre une sous-liste qui continue
    {
        return (sous_liste_recu_FA (reste (L1), reste (L2))) ; // on passe a l'élement suivant
    }
    else // ça n'est pas une sous-liste, retour à la fonctin principale
    {
        return false ;
    }


}

bool sous_liste_recu (liste L1, liste L2)
{
    if (est_vide (L1)) { return (true) ; }
    if (est_vide (L2)) { return (false) ; }

    // aucune des deux listes n'est vide
    if ((prem (L1) == prem (L2))) // c'est peut etre une sous-liste qui commence
    {
        // on passe les deux listes à la fonction auxiliaire qui va le vérifier
        if (sous_liste_recu_FA (reste (L1), reste (L2)))
        {
            return (true) ;
        }
    }

    return sous_liste_recu (L1, reste (L2)) ;
 }

bool sous_liste_iter (liste L1, liste L2)
{
    return false ;
}

void test_sous_liste_param (liste L1, liste L2)
{
    printf("\n") ;
    // test de la version récursive

    bool L_sous_liste_recu ;
    L_sous_liste_recu = sous_liste_recu (L1, L2) ;


    printf ("sous_liste_recu (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    if (L_sous_liste_recu) { printf ("vrai") ; } else { printf ("faux") ; }

    printf("\n") ;

    // test de la version itérative


    printf("\n\n") ;
}

void test_sous_liste ()
{
    liste L, M, N ;

    L = l_vide () ;

    test_sous_liste_param (L, L) ;

    M = cons (4, cons(3, cons (2, cons (2, L)))) ;

    test_sous_liste_param (L, M) ;

    N = cons (2, cons (2, L)) ;

    test_sous_liste_param (N, M) ;
    test_sous_liste_param (M, N) ;
}

int main (void)
{
    test_sous_liste () ;

    return EXIT_SUCCESS ;
}

/*

 fonction.c

 */