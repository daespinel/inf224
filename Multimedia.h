#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include<iostream>
#include<fstream>

using namespace std;

class Multimedia{

    //Declaration des variables
private:
    string nomObjet;
    string nomFichier;

public:

    // Constructeur vide
    Multimedia();

    // Declaration de constructeur avec parametres
    Multimedia(string nomObjet,string nomFichier);

    // Retourne le nom de l'objet
    string getNomObjet() const;

    // Retourne le nom du fichier
    string getNomFichier() const;

    // Declarer le nom de l'objet
    void setNomObjet(string nomOb);

    // Declarer le nom du fichier
    void setNomFichier(string nomFi);

    // Declaration du destructeur
    virtual ~Multimedia(){}

    // Declaration methode d'affichage
    virtual void print(ostream & s);

    // Declaration methode de jouer l'objet
    virtual void jouer()=0;

};

#endif // MULTIMEDIA_H
