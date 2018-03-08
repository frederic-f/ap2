#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"

liste inserer_element_recu (int x, int n, liste L)
{
    if (n == 0)
    {
        printf ("Erreur_liste");
        return (l_vide ()) ;
    }
    if ((n == 1) || (est_vide (L)))
    {
        return (cons (x, L)) ;
    }
    else // n > 1 et !est_vide L
    {
        return (cons (prem (L), inserer_element_recu (x, n - 1, reste (L)))) ;
    }
}

liste inserer_element_iter (int x, int n, liste L)
{
    int rang_insertion ;
    rang_insertion = n ;

    // processus different du recursif
    // on doit commencer par la fin
    // on part du dernier element
    int position ;
    position = longueur (L) ;

    // on construit à partir d'une liste vide
    liste M ;
    M = l_vide () ;

    // si rang de placement est 0 : erreur et exit
    if (rang_insertion == 0)
    {
        printf ("Erreur_liste");
        return (l_vide ()) ;
    }

    // tant que l'on est au-dessus de n, on ajoute le position-eme element
    // et on decremente position a chaque fois
    while (position >= rang_insertion)
    {
        M = cons (neme_element (position, L), M) ;
        position -= 1 ;
    }

    // nous sommes a la position d'insertion
    M = cons (x, M) ;

    // on reprend la liste d'orgine les élements jusqu'a 0
    while (position > 0)
    {
        M = cons (neme_element (position, L), M) ;
        position -= 1 ;
    }

    return (M) ;
}

void test_inserer_element_param (int x, int n, liste L)
{
    // test de la version récursive de la fonction

    liste inseree_recu ;
    inseree_recu = inserer_element_recu (x, n, L) ;

    printf ("inserer_element_recu (%d, %d, ", x, n) ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (inseree_recu);

    printf("\n") ;

    // test de la version itérative de la fonction

    liste inseree_iter ;
    inseree_iter = inserer_element_iter (x, n, L) ;

    printf ("inserer_element_iter (%d, %d, ", x, n) ;
    print_liste (L) ;
    printf (") = ") ;
    print_liste (inseree_iter);

    printf("\n\n") ;
}

void test_inserer_element ()
{
    liste L, M ;

    test_inserer_element_param (8, 2, l_vide()) ;

    L = cons (13, l_vide());

    test_inserer_element_param (8, 1, L) ;

    M = cons (1, cons (12, L)) ;

    test_inserer_element_param (0, 0, M) ;

    test_inserer_element_param (8, 2, M) ;

    test_inserer_element_param (8, 3, M) ;

    test_inserer_element_param (8, 4, M) ;

    test_inserer_element_param (8, 7, M) ;
}

int main (void)
{
    test_inserer_element () ;

    return EXIT_SUCCESS ;
}

/*



 */