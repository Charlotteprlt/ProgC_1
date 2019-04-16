#include "matrice.h"
#include "assert.h"

using namespace std;
int MAX_RAND=100;


//Le constructeur.
//dans ce constructeur on commence par créer un pointeur compteur qui pointe vers l'adresse 0 qui n'existe pas
//puis on alloue à ce pointeur la valeur 1.
Matrice::Matrice(int m1, int n1) {
    cout<<"Constructeur"<<endl;
    m=m1;
    n=n1;
    tab=new double[m1*n1];
    compteur=new int(0);
    *compteur = 1;
}

//Le destructeur.
//Dans cette méthode, on décrémente le compteur si il est strictement positif, donc on déplace le pointeur sur la copie précédente.
//Si le compteur vaut 0, ie s'il s'agit de la matrice originale, on la détruit ainsi que le compteur.
Matrice::~Matrice() {
    cout<<"Destructeur"<<endl;
    if(*compteur>0){
        *compteur=*compteur-1;
    }
    if(*compteur==0){
        delete [] tab;
        delete [] compteur;
    }
}

//Le constructeur par copie.
//On considère une matrice à copier et on crée une deuxième matrice à laquelle on donne les valeurs n et m de la matrice à copier.
//Puis on fait pointer tab de la nouvelle matrice vers celui de la matrice à copier.
//Enfin, on incrémente l'ancien pointeur compteur de 1 afin de comptabiliser le nombre de copies.

Matrice::Matrice(const Matrice &matriceACopier) {
     cout<<"Constructeur par copie"<<endl;
     m=matriceACopier.m;
     n=matriceACopier.n;
     tab=matriceACopier.tab;
     compteur=matriceACopier.compteur;
     *compteur+=1;
}

//Méthode d'accs à la valeur de la case (i,j).
//On s'assure au préalable que l'on se trouve bien dans les bornes de la matrice.
double Matrice::getTab(int i, int j) {
    assert((0<=i) && (i<n) && (0<=j) && (j<m));
    return tab[i*m+j];
}

//Méthode pour donner une valeur à la case (i,j) de la matrice.
//On s'assure au préalable que l'on se trouve bien dans les bornes de la matrice.
void Matrice::set(int i,int j,double x) {
    assert(0<=i && i<m && 0<=j && j<n);
    tab[i*m+j]=x;
}

//Méthode qui permet d'afficher la matrice.
void Matrice::affiche(){
    cout<<"La matrice est"<<endl;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            cout <<tab[i*m+j] << " ";
          }
        cout<<" "<<endl;
    }
}

//Méthode de multiplication de deux matrices entre elles.
//On effectue la multiplication d'une matrice appelée M par exemple par une matrice constante B.
Matrice Matrice::operator*(const Matrice& B) {
    assert(m==B.n);
    Matrice C(n,B.m);
    for (int i=0; i<C.n; i++){
        for (int j=0;j<C.m;j++) {
            // Cij=Mi0∗B0j+Mi1∗B1j +...
            C.tab[i*C.m+j]=0;
            for (int k=0;k<m;k++){
                C.tab[i*C.m+j] += tab[i*m+k]*B.tab[k*B.m+j];
            }
        }
    }
    return C;
}


//Définition d'un "shallow copy"
void Matrice::operator=(const Matrice& A) {
    cout<<"Shallow_copy"<<endl;
    *compteur=*compteur-1;
    if(*compteur==0){
        delete [] tab;
        delete [] compteur;
    }
    tab = A.tab;
    compteur = A.compteur;
    *compteur += 1;
}

//Méthode permettant de créer une matrice de taille (m0,n0) dont les coefficients sont aléatoires compris entre 0 et MAX_RAND exclu.
void Matrice::aleatoire() {
    int nombre_aleatoire = 0;
    //Initialisation de la fonction rand;
    srand(time(NULL));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            nombre_aleatoire= rand()%MAX_RAND;
            tab[i*m+j]=nombre_aleatoire;
        }
    }
}
