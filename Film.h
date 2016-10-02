#ifndef FILM_H
#define FILM_H

#include "Video.h"

using namespace std;

class Film : public Video
{
private:
    int tailleTableau;
    int * tableauDurees = new int [tailleTableau];


public:
    // Constructeur de Film
    Film(string nomOb,string nomF,int du);

    Film(const Film&);

    Film& operator=(const Film&);

    // Methode modifieur de la taille du tableau
    void setTaille(int tail);

    // Methode modifieur pour passer un tableau de durees
    void setNewTableau(int * tab, int tal);

    //Deuxieme mehode pour creer un nouveau tableau
    void setNewTableau(int *tab);

    // Methode accesseur de la taille du tableau
    int getTaille() const;

    // Methode accesseur du tableau de durees
    int * getTableau() const;

    // Methode d'affichage la durre de chaque chapitre
    void affichageChapitres() const;


};

#endif // FILM_H
