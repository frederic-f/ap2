#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "liste.h"


unsigned int longueur_rec (liste L)
{
    if (est_vide (L))
    {
        return 0 ;
    }

    return (1 + longueur_rec (reste (L))) ;
}


unsigned int longueur_ite (liste L)
{
    unsigned int l ;
    liste M ;

    l = 0 ;
    M = L ;

    while (!est_vide (M))
    {
        l += 1 ;
        M = reste (M) ;
    }

    return (l) ;
}


void test_longueur_param (liste L)
{
    unsigned int l_rec ;
    l_rec = longueur_rec (L) ;

    printf("longueur_rec ");
    print_liste(L) ;
    printf(" = %u\n", l_rec);


    unsigned int l_ite ;
    l_ite = longueur_ite (L) ;

    printf("longueur_ite ");
    print_liste(L) ;
    printf(" = %u\n", l_ite);


    printf("\n") ;
}


void test_longueur ()
{
    liste L, M, N ;

    test_longueur_param (l_vide()) ;

    L = cons (3, l_vide());

    test_longueur_param (L) ;

    M = cons (3, L) ;

    test_longueur_param (M) ;

    N = cons(4, (cons(6, M))) ;

    test_longueur_param (N) ;
}


int main ()
{
    test_longueur () ;

    return EXIT_SUCCESS ;
}

/*
 $ ./01_longueur
longueur_rec () = 0
longueur_ite () = 0

longueur_rec (3) = 1
longueur_ite (3) = 1

longueur_rec (3, 3) = 2
longueur_ite (3, 3) = 2

longueur_rec (4, 6, 3, 3) = 4
longueur_ite (4, 6, 3, 3) = 4
 */