#ifndef GROUPE_H
#define GROUPE_H

#include"Multimedia.h"
#include <list>
#include <memory>

//class Groupe:public list <Multimedia>
class Groupe:public list <shared_ptr<Multimedia>>
{

//attributes du classe
private:
    string nomGroup;
   // list<Multimedia> listObjets;


public:

    // Methode constructeur
    Groupe(string nomG){
        setNomGroup(nomG);
    }

    // Methode d'imppresion du nom
    const string getNomGroup() {
        return nomGroup;
    }

    // Methode setter du nom
    void setNomGroup(string nomG){
        nomGroup=nomG;
    }


    // Methode qui permette donnant un nom, effacer l'element avec le nom
    bool deleteListElement(string nom){

        for(list<shared_ptr<Multimedia>>::iterator iter=begin();iter!=end();iter++){
            if((*iter)->getNomObjet()==nom){
                this->erase(iter);
                return true;
            }
        }
        return false;
    }

    void print(ostream & s){

        s<<"List d'objets du groupe: "<<getNomGroup();
        //for(list<Multimedia>::iterator iter=begin();iter!=end();iter++){
        for(list<shared_ptr<Multimedia>>::iterator iter=begin();iter!=end();iter++){
            (*iter)->print(s);
        }

    }

    virtual ~Groupe(){//cout<<"elimination de groupe "<<getNomGroup()<<endl;
    }


};

#endif // GROUPE_H
