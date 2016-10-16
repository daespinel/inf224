#include"Multimedia.h"

using namespace std;


    Multimedia::Multimedia(){
        nomObjet="";
        nomFichier="";
    }

    Multimedia::Multimedia(string nomOb,string nomFi){
        nomObjet=nomOb;
        nomFichier=nomFi;
    }


    void Multimedia::setNomObjet(string nomO){
        nomObjet=nomO;
    }

    void Multimedia::setNomFichier(string nomF){
        nomFichier=nomF;
    }

    string Multimedia::getNomObjet() const{
        return nomObjet;
    }

    string Multimedia::getNomFichier() const{
        return nomFichier;
    }

    void Multimedia::print(ostream & s){
        s << getNomObjet() << ' ' << getNomFichier() <<endl;
    }




