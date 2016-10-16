#include"Film.h"

using namespace std;


    // Constructeur de Film
    Film::Film(string nomOb,string nomF,int du):Video(nomOb,nomF,du){
        //cout<<"constructeur "<<endl;
        tailleTableau = 0;
    }

    // Constructeur du copie avec l'operateur =
    Film::Film(const Film& from):Video(from){
        setTaille(from.getTaille());
        setDuree(from.getDuree());
        setNomObjet(from.getNomObjet());
        setNomFichier(from.getNomFichier());

        //cout<<"constructeur 1   "<<from.getNomFichier()<<endl;

        if(from.getTableau())
            tableauDurees=new int(*from.tableauDurees);
        else
            setNewTableau(nullptr);
    }

    // Constructeur du copie avec l'operateur =
    Film& Film::operator=(const Film& from){
        Video::operator=(from);
        setTaille(from.getTaille());
        setDuree(from.getDuree());
        setNomObjet(from.getNomObjet());
        setNomFichier(from.getNomFichier());

        //cout<<"constructeur 2   "<<from.getNomFichier()<<endl;

        if(getTableau() && from.getTableau())
            *tableauDurees=*from.tableauDurees;
        else{
            delete tableauDurees;
            if(from.tableauDurees)
                tableauDurees = new int(*from.tableauDurees);
            else
                tableauDurees=nullptr;
        }

        return *this;
    }

    // Methode modifieur de la taille du tableau
    void Film::setTaille(int tail){
        tailleTableau=tail;
    }

    // Methode modifieur pour passer un tableau de durees
    void Film::setNewTableau(const int * tab, int tal){
        setTaille(tal);
        for(int i=0;i<tailleTableau;i++){
            tableauDurees[i]=tab[i];
        }
    }

    void Film::setNewTableau( int *tab){
        tableauDurees=tab;
    }


    // Methode accesseur de la taille du tableau
    int Film::getTaille() const{
        return tailleTableau;
    }

    // Methode accesseur du tableau de durees
    int * Film::getTableau() const{
        return tableauDurees;
    }

    // Methode d'affichage la durre de chaque chapitre
    void Film::affichageChapitres() const{
        for(int i=0;i<tailleTableau;i++){
            cout<<"Chapitre: "<<i+1<<" ,durée: "<<tableauDurees[i]<<endl;
        }
    }
