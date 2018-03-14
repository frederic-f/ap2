#ifndef CODE_LISTE_H
#define CODE_LISTE_H

/* Definitions des types */

typedef struct Liste *liste ; // (*liste) est un pointeur sur (struct Liste)

struct Liste {
    int premier ;
    liste suivant ; // c'est un pointeur
};

/* SIGNATURES DES OPERATIONS PRIMITIVES */

liste l_vide () ;

liste cons (int x, liste L) ;

bool est_vide (liste L) ;

int prem (liste L) ;

liste reste (liste L) ;

int print_liste (liste L) ;

void liberer_liste (liste L) ;

int longueur (liste L) ;

int neme_element (int a, liste L) ;

liste renverser (liste L) ;

#endif //CODE_LISTE_H
