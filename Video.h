#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video:public Multimedia{

//declaration des variables
private:
    int duree;

public:
    // Declaration du constructeur
    Video(string nomOb,string nomF,int du):Multimedia(nomOb,nomF){
        duree=du;
    }

    // Declaration de la duree
    void setDuree(int du){
        duree=du;
    }

    // Retourne la duree du video
    int getDuree() const{
        return duree;
    }

    // Methode d'affichage des donnees
    void print(ostream & s) override{
        s <<"Nom video: "<<getNomObjet() << ' '<< ",Nom Fichier: "<<getNomFichier()<<" "
         <<",Duree: "<<getDuree() <<endl;
    }

    // Methode pour regarder la video
    void jouer() override{
        string paramVideo="mpv " + getNomFichier() + " &";
        system(paramVideo.c_str());
    }

    //~Video();

};

#endif // VIDEO_H
