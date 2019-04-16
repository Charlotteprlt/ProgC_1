#pragma once
#include <iostream>

class Matrice {
    //paramètres privés de la matrice : son nombre de lignes, de colonnes et les deux pointeurs tab et compteur.
    int m,n;
    double* tab ;
    //Création d'un compteur qui permet de compter le nombre de copies de la matrice effectuées.
    int* compteur;
public:
    //Constructeur d'une matrice de taille (m1,n1)
    Matrice(int m1,int n1);
    //Constructeur de copie
    Matrice(const Matrice &matriceACopier);
    //Destructeur
    ~Matrice();
    //méthode permettant d'accéder à la valeur de la case (i,j) de la matrice.
    double getTab(int i, int j);
    //méthode permettant d'attribuer la valeur x à la case (i,j) de la matrice.
    void set(int i,int j,double x);
    //méthode permettant d'afficher la matrice.
    void affiche();
    //méthode permettant de multiplier entre elles deux matrices.
    Matrice operator*(const Matrice& B);
    //Constructeur de "shallow copy"
    void operator=(const Matrice& A);
    //méthode permettant de générer une matrice aléatoire.
    void aleatoire();
};
