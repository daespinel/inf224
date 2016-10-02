#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo:public Multimedia{

//Declaration des variables
private:
    double latitude;
    double longitude;

public:

    // Constructeur avec parametres
    Photo(string nomOb,string nomF,double lat,double lon):Multimedia(nomOb,nomF){
        latitude=lat;
        longitude=lon;
    }

    // Declaration de la latitude
    void setLatitude(int la){
        latitude=la;
    }

    // Declaration de la longitude
    void setLongitude(int lo){
        longitude=lo;
    }

    // Retourne la latitude
    int getLatitude() const{
       return latitude;
    }

    // Retourne la longitude
    int getLongitude() const{
        return longitude;
    }

    // Methode d'affichage des donnees
    void print(ostream & s) override{
        s <<"Nom objet: "<<getNomObjet() << ' '<< ",Nom Fichier: "<<getNomFichier()<<" "
         <<",Latitude: "<<getLatitude()<<" "<<",Longitude: "<<getLongitude() <<endl;
    }

    //dans mon ordi j'utilise display, cepedant dans l'ecole c'est imagej

    // Methode pour regarder la photo
    void jouer() override{
        string paramPhoto="display " + getNomFichier() + " &";
        system(paramPhoto.c_str());
    }

    // Destructeur
    //~Photo();


};

#endif // PHOTO_H
