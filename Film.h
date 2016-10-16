#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include<iostream>
#include<fstream>

using namespace std;

class Film : public Video
{
private:
    int tailleTableau;
    int * tableauDurees = new int [tailleTableau];


public:
    // Constructeur de Film
    Film(string nomOb,string nomF,int du);

    // Constructeur du copie en creation
    Film(const Film&);

    // Constructeur du copie avec l'operateur =
    Film& operator=(const Film&);

    // Methode modifieur de la taille du tableau
    void setTaille(int tail);

    // Methode modifieur pour passer un tableau de durees
    void setNewTableau(const int * tab, int tal);

    //Deuxieme mehode pour creer un nouveau tableau
    void setNewTableau( int *tab);

    // Methode accesseur de la taille du tableau
    int getTaille() const;

    // Methode accesseur du tableau de durees
    int * getTableau() const;

    // Methode d'affichage la durre de chaque chapitre
    void affichageChapitres() const;

    virtual ~Film(){delete [] tableauDurees;
                    //cout<<"elimination du Film"<<getNomObjet()<<endl;
                   }

    virtual void write(ostream & file) override{
        Video::write(file);
        file<<tailleTableau<<'\n';
        for(int i=0;i<tailleTableau;i++){
            file<<tableauDurees[i]<<'\n';
        }

    }

    virtual void read(ifstream &file)override{
        Video::read(file);
        string tailleTemp;
        getline(file,tailleTemp);
        tailleTableau=stoi(tailleTemp);


        for(int i=0;i<tailleTableau;i++){
            string dureeTemp;
            getline(file,dureeTemp);
            tableauDurees[i]=stoi(dureeTemp);

        }
    }


};

#endif // FILM_H
