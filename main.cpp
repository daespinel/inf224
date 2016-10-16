#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Groupe.h"
#include "GestionControl.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include "tcpserver.h"
#include <vector>

const int PORT = 3331;

using namespace std;
using namespace cppu;
using namespace std;

bool save(const string & fileName,const vector<shared_ptr<Multimedia>> &objects){
    cerr<<"Entering the save method"<<endl;
    ofstream f(fileName);
    if(!f){
        cerr<<"Can't open file "<<fileName <<endl;
        return false;
    }
    cerr<<"there are a file whos name is "<<fileName<<endl<<endl;
    shared_ptr<Multimedia> tempo(objects.at(0));
    tempo->print(cerr);
    cerr<<endl<<endl;

    for(auto it:objects) {
        cerr<<"entering the for save method"<<endl;
        it->print(cerr);
        it->write(f);
    }
    return true;
}

bool load(const string & fileName, vector <shared_ptr<Multimedia>> &objects){
    cerr<<"entro"<<endl;



    try{
        ifstream f(fileName);

        if(!f){
            cerr<<"Can't open file "<< fileName <<endl;
            return false;
        }

        while(f){
            shared_ptr<Multimedia> multi;
            multi->read(f);
            string temporal;
            getline(f,temporal);
            cout<<temporal<<endl;

            if(f.fail()){
                cerr<<"Read error in "<< fileName<<endl;

                return false;
            }
            else{
             //   objects.push_back(multi);
            }
        }
        return true;

    }
    catch(...){cerr<<"error"<<endl;}
    return false;

}


int main(int argc, char* argv[])
{
    /*
    //Multimedia * multi1 = new Multimedia();
    //Multimedia * multi2 = new Multimedia("objeto","route");


    cout<<"Bonjour bienvenue sur l'implementation"<<endl;

    //multi1->print(cout);
    //multi2->print(cout);

    //Multimedia * video1=new Video("nom","Unico.wmv",52);
    //Photo * photo1=new Photo("nomP","carte.png",100,100);

    shared_ptr<Multimedia> video1(new Video("nom","Unico.wmv",52));
    shared_ptr<Multimedia> photo1(new Photo("nomP","carte.png",100,100));


    video1->print(cout);
    //video1->jouer();
    //photo1->jouer();


    //delete multi2;
    //delete multi1;
    //delete video1;
    //delete photo1;

    Multimedia ** tableau = new Multimedia * [3];





    tableau[0]=new Photo("photo 1","fichier 1",50,50);
    tableau[1]=new Video("video 1","fichier video 1",50);
    tableau[2]=new Photo("photo 2","fichier 2",50,50);

    for(int i=0;i<3;i++){
        tableau[i]->print(cout);
    }


    delete * tableau;


    shared_ptr<Film> film1(new Film("film 1","qqc",10));

    //Film * film1 = new Film("film 1","qqc",10);

    int * temp= new int [3];
    temp[0]=3;
    temp[1]=2;
    temp[2]=5;

    film1->setNewTableau(temp,3);

    cout<<endl<<endl<<endl<<"affichage"<<endl<<endl;

    film1->print(cout);
    film1->affichageChapitres();



    int * temp2= new int[3];
    temp2[0]=5;
    temp2[1]=4;
    temp2[2]=5;

    film1->setNewTableau(temp2,3);

    cout<<endl<<endl<<endl<<"affichage 2"<<endl<<endl;

    film1->print(cout);
    film1->affichageChapitres();


    shared_ptr<Film> film2(new Film("film 2","qqc2",5));
    //Film * film2 = new Film("film 2","qqc2",5);

    int * temp3= new int [3];
    temp3[0]=2;
    temp3[1]=2;
    temp3[2]=2;

    film2->setNewTableau(temp3,3);

    cout<<endl<<endl<<endl<<"affichage 3"<<endl<<endl;

    film2->print(cout);
    film2->affichageChapitres();

    Film  film3(*film2);
    //Film* film3=film2;
    //Film* film3(film2);
    //Film* film3=Film(film2);


    cout<<endl<<endl<<endl<<"affichage 4: film 2 et film 3 "<<endl<<endl;

    film3.setNewTableau(temp,3);


    film2->print(cout);
    film2->affichageChapitres();

    cout<<endl<<endl<<endl<<"affichage 5"<<endl<<endl;

    film3.print(cout);
    film3.affichageChapitres();

    cout<<endl<<endl<<endl<<"affichage du groupe 1: "<<endl<<endl;


    shared_ptr<Groupe> groupe1(new Groupe("Groupe numero 1"));
    //Groupe * groupe1 =new Groupe("Groupe numero 1");
    groupe1->push_back(film1);

    Groupe * groupe2 =new Groupe("Groupe numero 2");
    groupe2->push_back(film1);
    groupe2->push_back(film2);



    film1->setNomFichier("change du nom en 1");
    //delete film1;
    //film1=nullptr;

    //delete groupe1;

    //groupe1->print(cout);

    film2->setNomFichier("Nouveau nom2");

    cout<<endl<<endl<<endl<<"affichage du groupe 2: "<<endl<<endl;

    groupe2->print(cout);

    */

    vector<shared_ptr<Multimedia>> objects;


    load("data.txt",objects);

    shared_ptr<Video> film5(new Video("video 5","path du 5",10));
    shared_ptr<Video> film6(new Video("video 6","path 6",10));
    shared_ptr<Video> film7(new Video("video 7","path 7",10));
    shared_ptr<Video> film8(new Video("video 8","path 8",10));

    shared_ptr<Photo> photo5(new Photo("photo 5","ventoux.jpg",50,50));
    shared_ptr<Photo> photo6(new Photo("photo 6","oe.jpg",60,60));
    shared_ptr<Photo> photo7(new Photo("photo 7","chinca.jpg",70,70));
    shared_ptr<Photo> photo8(new Photo("photo 8","canon.jpg",80,80));

    if(true==false){
        objects.push_back(film5);
        objects.push_back(film6);
        objects.push_back(film7);
        objects.push_back(film8);
        objects.push_back(photo5);
        objects.push_back(photo6);
        objects.push_back(photo7);
        objects.push_back(photo8);

    }

    shared_ptr<Groupe> groupe5(new Groupe("photos et videos 1"));
    shared_ptr<Groupe> groupe6(new Groupe("vacances"));
    shared_ptr<Groupe> groupe7(new Groupe("visite Paris"));


    groupe5->push_back(film5);
    groupe5->push_back(photo7);
    groupe5->push_back(film8);

    groupe6->push_back(film6);
    groupe6->push_back(photo6);
    groupe6->push_back(photo7);

    groupe7->push_back(photo8);
    groupe7->push_back(photo5);
    groupe7->push_back(film5);
    groupe7->push_back(film7);
    groupe7->push_back(film8);

    shared_ptr<GestionControl> gestion(new GestionControl());

    gestion->creer(*groupe5);
    gestion->creer(*groupe7);
    gestion->creer(*groupe6);

    gestion->creer(*photo8);
    gestion->creer(*film6);
    gestion->creer(*film5);
    gestion->creer(*photo6);
    gestion->creer(*film7);
    gestion->creer(*photo5);
    gestion->creer(*photo7);
    gestion->creer(*film8);

    cout<<endl<<endl;
    //gestion->rechercher("photo 7");
    cout<<endl<<endl;
    //groupe6->print(cout);
    //cout<<endl<<endl;

    //gestion->jouer("photo 5");
    //gestion->jouer("photo 7");

    //gestion->rechercher("vacances");

    //gestion->supprimer("film 5");

    cout<<endl<<endl;
    //gestion->rechercher("visite Paris");

    cout<<endl<<endl;
    //gestion->rechercher("film 5");

    //delete temp;
    //delete temp2;
    //delete temp3;


    //delete film1;
    //delete film2;
    //delete film3;

    save("data.txt",objects);


      // cree le TCPServer
      shared_ptr<TCPServer> server(new TCPServer());

      // cree l'objet qui gère les données
      //shared_ptr<MyBase> base(new MyBase());

      // le serveur appelera cette méthode chaque fois qu'il y a une requête
      server->setCallback(*gestion, &GestionControl::processRequest);

      // lance la boucle infinie du serveur
      cout << "Starting Server on port " << PORT << endl;
      int status = server->run(PORT);

      // en cas d'erreur
      if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
      }

      return 0;
    }






