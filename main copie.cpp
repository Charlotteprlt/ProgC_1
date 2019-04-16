#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;

#include "matrice.h"

// Ecriture de deux fonctions experience1() et experience2() permettant de tester et utiliser la classe Matrice et ses méthodes.

void experience1(){
    Matrice A(2,2);
    A.aleatoire();
    Matrice B(2,2);
    B.set(0,0,3);
    B.set(0,1,4);
    B.set(1,0,2);
    B.set(1,1,3);
    Matrice C(A);
    A.affiche();
    B.affiche();
    C.affiche();
    Matrice D(2,2);
    D=A*B;
    D.affiche();
}

void experience2(){
    Matrice F(3,3);
    F.aleatoire();
    F.affiche();
    Matrice G(3,3);
    G.aleatoire();
    G.affiche();
    Matrice H(3,3);
    G=F*H;
    G.affiche();
    Matrice J(F);
    J.affiche();
}


int main(){
    experience1();
    //experience2();
    return 0;
}
