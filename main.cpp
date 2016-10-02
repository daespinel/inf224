#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Multimedia * multi1 = new Multimedia();
    //Multimedia * multi2 = new Multimedia("objeto","route");


    cout<<"Bonjour bienvenue sur l'implementation"<<endl;

    //multi1->print(cout);
    //multi2->print(cout);

    Multimedia * video1=new Video("nom","Unico.wmv",52);
    Photo * photo1=new Photo("nomP","carte.png",100,100);

    video1->print(cout);
    //video1->jouer();
    //photo1->jouer();




    //delete multi2;
    //delete multi1;
    delete video1;
    delete photo1;

    Multimedia ** tableau = new Multimedia * [3];

    tableau[0]=new Photo("photo 1","fichier 1",50,50);
    tableau[1]=new Video("video 1","fichier video 1",50);
    tableau[2]=new Photo("photo 2","fichier 2",50,50);

    for(int i=0;i<3;i++){
        tableau[i]->print(cout);
    }


    delete * tableau;

    Film * film1 = new Film("film 1","qqc",10);

    int * temp= new int [3];
    temp[0]=3;
    temp[1]=2;
    temp[2]=5;

    film1->setNewTableau(temp,3);

    cout<<endl<<endl<<endl<<"affichage"<<endl<<endl;

    film1->print(cout);
    film1->affichageChapitres();



    int * temp2= new int[3];
    temp[0]=5;
    temp[1]=4;
    temp[2]=5;

    film1->setNewTableau(temp2,3);

    cout<<endl<<endl<<endl<<"affichage 2"<<endl<<endl;

    film1->print(cout);
    film1->affichageChapitres();

    Film * film2 = new Film("film 2","qqc2",5);

    int * temp3= new int [3];
    temp3[0]=2;
    temp3[1]=2;
    temp3[2]=2;

    film2->setNewTableau(temp3,3);

    cout<<endl<<endl<<endl<<"affichage 3"<<endl<<endl;

    film2->print(cout);
    film2->affichageChapitres();

    Film* film3(film2);


    cout<<endl<<endl<<endl<<"affichage 4: film 2 et film 3 "<<endl<<endl;

    film3->setNewTableau(temp,3);


    film2->print(cout);
    film2->affichageChapitres();

    cout<<endl<<endl<<endl<<"affichage 5"<<endl<<endl;

    film3->print(cout);
    film3->affichageChapitres();


    delete temp;
    delete temp2;
    delete temp3;


    delete film1;
    delete film2;
    delete film3;

    return 0;


}
