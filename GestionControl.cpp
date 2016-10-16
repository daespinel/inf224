#include "GestionControl.h"
#include <vector>

using namespace std;

    GestionControl::GestionControl(){}

    // Methode de creation d'une video
    void GestionControl::creer(Video video){
        mapObjets[video.getNomObjet()]=shared_ptr<Multimedia>(new Video(video));

    }

    // Methode de creation d'une photo
    void GestionControl::creer(Photo photo){
       mapObjets[photo.getNomObjet()]=shared_ptr<Multimedia>(new Photo(photo));
    }

    // Methode de creation d'un film
    void GestionControl::creer(Film film){
       mapObjets[film.getNomObjet()]=shared_ptr<Multimedia>(new Film(film));
    }

    // Methode de creation d'un groupe
    void GestionControl::creer(Groupe groupe){
       mapGroupes[groupe.getNomGroup()]=shared_ptr<Groupe>(new Groupe(groupe));
    }

    // Methode pour supprimer un objet multimedia ou un groupe en donnant le nom
    void GestionControl::supprimer(string nom){

        if(mapObjets.count(nom)!=0){
            map<string,shared_ptr<Groupe>>::const_iterator iter;
            for(iter = mapGroupes.begin();iter!=mapGroupes.end();iter++){
                shared_ptr<Groupe> groupeTest= (*iter).second;
                groupeTest->deleteListElement(nom);
            }
            mapObjets.erase(nom);
        }
        else{
            if(mapGroupes.count(nom)!=0){
                mapGroupes.erase(nom);
            }
            else{
                cout<<"Il n'y a pas objet/groupe avec le nom donnée"<<endl;
            }
        }
    }

    // Mehtode pour rechercher un objet multimedia ou un groupe en donnant le nom
    void GestionControl::rechercher(string nom,stringstream & text){

        if(mapObjets.count(nom)!=0){
            mapObjets.at(nom)->print(text);
        }
        else{
            if(mapGroupes.count(nom)!=0){
                mapGroupes.at(nom)->print(text);
            }
            else{
                cout<<"Il n'y a pas objet/groupe avec le nom donnée"<<endl;
            }
        }
    }

    // Methode pour jouer un objet multimedia
    void GestionControl::jouer(string nom){
        if(mapObjets.count(nom)!=0){
            mapObjets.at(nom)->jouer();
        }
        else{
            cout<<"Il n'y a pas un objet avec le nom donné"<<endl;
        }
    }


    // Methode pour acceder aux données de la classe et les envoyer au client
    bool GestionControl::processRequest(TCPConnection& cnx, const string& request, string& response)
    {
      cerr << "\nRequest: '" << request << "'" << endl;

      // 1) pour decouper la requête:
      // on peut par exemple utiliser stringstream et getline()

      stringstream commande(request);
      stringstream total;
      string text;
      getline(commande,text,' ');


      if(text=="chercher")
      {


            string subText = request.substr (9,request.size());     // get from "live" to the end
            //cerr<<"commande chercher utilisé: "<<endl;
            response="commande chercher utilisé: ";
            this->rechercher(subText,total);

            response = response + total.str();
      }
      else{
          if(text=="jouer"){
                cerr<<"commande jouer utilisé: "<<endl;
                response="commande jouer utilisé: ";
                string subText = request.substr (6,request.size());     // get from "live" to the end
                //cerr<<"commande chercher utilisé: "<<endl;
                response="commande chercher utilisé: ";
                this->jouer(subText);
          }else{
              if(text=="exit"){
                return false;
              }else{
                cerr<<"commande non trouvé. Veuillez inserer une autre commande"<<endl;
                response="commande non trouvé. Veuillez inserer une autre commande";
                }
           }
      }

      TCPLock lock(cnx);
      cerr << "response: " << response << endl;

      // renvoyer false si on veut clore la connexion avec le client
      return true;
    }






