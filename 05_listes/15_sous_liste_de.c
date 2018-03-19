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


bool sous_liste_recu_NONFA (liste L1, liste L2)
{
    if (est_vide (L1)) { return (true) ; }
    if (est_vide (L2)) { return (false) ; }

    if (est_vide(reste(L1))) // L1 n'a qu'un seul Ã©lÃ©ment
        return (prem(L1) == prem(L2)) || sous_liste_recu(L1,reste(L2));

    if (prem(L1) != prem(L2))
        return sous_liste_recu(L1,reste(L2));

    return sous_liste_recu(reste(L1),reste(L2)) || sous_liste_recu(L1,reste(L2));
}


bool sous_liste_iter (liste L1, liste L2)
{
    liste M, N, O, P ;

    M = L1 ;
    N = L2 ;

    if (est_vide (M))
    {
        return true ;
    }

    // boucle 1 : on epuise la liste N

    while ( ! est_vide (N))
    {
        if (prem (M) == prem (N)) // peut etre une sous liste
        {
            P = reste (M) ;
            O = reste (N) ;

            // boucle 2 de verification de sous-liste

            while ( ! (est_vide (P) || est_vide (O)))
            {
                if (prem (P) == prem (O)) // tant que les élements sont egaux
                {
                    P = reste (P) ;
                    O = reste (O) ;
                }
            }
            // sortie de boucle : une des deux listes est vide

            if (est_vide (P)) // si c'est P alors c'était une sous liste
            {
                return true ;
            }
            // ce n'etait pas P on reprend la sous liste de départ pour continuer la comparaison
        }

        N = reste (N) ;
    }
    // sortie de boucle : N est vide, M n'etait pas une sous-liste

    return false ;
}

void test_sous_liste_param (liste L1, liste L2)
{
    printf("\n") ;
    // test de la version récursive

    bool is_sous_liste_recu ;
    is_sous_liste_recu = sous_liste_recu (L1, L2) ;


    printf ("sous_liste_recu (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    if (is_sous_liste_recu) { printf ("vrai") ; } else { printf ("faux") ; }


    printf("\n") ;
    // test de la version récursive NON FA

    bool is_sous_liste_recu_NONFA ;
    is_sous_liste_recu_NONFA = sous_liste_recu_NONFA (L1, L2) ;


    printf ("sous_liste_recu_NONFA (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    if (is_sous_liste_recu_NONFA) { printf ("vrai") ; } else { printf ("faux") ; }

    printf("\n") ;

    // test de la version itérative
    bool is_sous_liste_iter ;
    is_sous_liste_iter = sous_liste_iter (L1, L2) ;


    printf ("sous_liste_iter (") ;
    print_liste (L1) ;
    printf (", ") ;
    print_liste (L2) ;
    printf (") = ") ;
    if (is_sous_liste_iter) { printf ("vrai") ; } else { printf ("faux") ; }

    printf("\n\n") ;
}

void test_sous_liste ()
{
    liste L, M, N, O, P ;

    L = l_vide () ;

    test_sous_liste_param (L, L) ;

    M = cons (4, cons(3, cons (2, cons (2, L)))) ;

    test_sous_liste_param (L, M) ;




    N = cons (2, cons (2, L)) ;

    test_sous_liste_param (N, M) ;


    P = cons (4, cons(3, cons (2, cons (2, cons (1, L))))) ;

    test_sous_liste_param (N, P) ;

    test_sous_liste_param (M, N) ;

    O = cons (4, cons (2, L)) ;

    test_sous_liste_param (O, M) ;
    test_sous_liste_param (O, N) ;



}

int main (void)
{
    test_sous_liste () ;

    return EXIT_SUCCESS ;
}

/*

$ ./15_sous_liste_de

sous_liste_recu ((), ()) = vrai
sous_liste_iter ((), ()) = vrai


sous_liste_recu ((), (4, 3, 2, 2)) = vrai
sous_liste_iter ((), (4, 3, 2, 2)) = vrai


sous_liste_recu ((2, 2), (4, 3, 2, 2)) = vrai
sous_liste_iter ((2, 2), (4, 3, 2, 2)) = vrai


sous_liste_recu ((4, 3, 2, 2), (2, 2)) = faux
sous_liste_iter ((4, 3, 2, 2), (2, 2)) = faux

 */