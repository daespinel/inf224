#ifndef GESTIONCONTROL_H
#define GESTIONCONTROL_H


#include "Multimedia.h"
#include "Groupe.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include <map>
#include <iostream>
#include <sstream>
#include "tcpserver.h"

using namespace std;
using namespace cppu;
using namespace std;

class GestionControl
{
private:
    map<string,shared_ptr<Multimedia>> mapObjets;
    map<string,shared_ptr<Groupe>> mapGroupes;

public:

    GestionControl();

    // Methode de creation d'une video
    void creer(Video video);

    // Methode de creation d'une photo
    void creer(Photo photo);

    // Methode de creation d'un film
    void creer(Film film);

    // Methode de creation d'un groupe
    void creer(Groupe groupe);

    // Methode pour supprimer un objet multimedia ou un groupe en donnant le nom
    void supprimer(string nom);

    // Mehtode pour rechercher un objet multimedia ou un groupe en donnant le nom
    void rechercher(string nom,stringstream &text);

    // Methode pour jouer un objet multimedia
    void jouer(string nom);

    virtual ~GestionControl(){cout<<"Elimination du GestionControl"<<endl;}

    // Methode pour acceder aux données de la classe et les envoyer au client
    bool processRequest(TCPConnection& cnx, const string& request, string& response);

};


#endif // GESTIONCONTROL_H
