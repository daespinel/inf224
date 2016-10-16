#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
#include<iostream>
#include<fstream>


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
         <<",Latitude: "<<getLatitude()<<" "<<",Longitude: "<<getLongitude();
    }

    //dans mon ordi j'utilise display, cepedant dans l'ecole c'est imagej

    // Methode pour regarder la photo
    void jouer() override{
        string paramPhoto="display " + getNomFichier() + " &";
        system(paramPhoto.c_str());
    }

    // Destructeur
    virtual ~Photo(){//cout<<"elimination du Photo "<<getNomObjet()<<endl;
    }


    virtual void write(ostream & file) override {
        Multimedia::write(file);
        file<<latitude<<'\n'<<longitude<<'\n';
    }

    virtual void read(ifstream &file) override {
        Multimedia::read(file);
        string latitudeTemp;
        getline(file,latitudeTemp);
        latitude=stoi(latitudeTemp);
        cerr<<"aqui esta la latitud"<<endl;

        string longitudeTemp;
        getline(file,longitudeTemp);
        longitude=stoi(longitudeTemp);

    }


};

#endif // PHOTO_H
