#include "Billet.h"
#include "Prix_base.h"
#include "Trajet.h"
#include <fstream>


using namespace std;

//la methode de tri de la liste des trajets du billet
bool compareDate(Trajet *t1, Trajet *t2)
{
    if (t1->getAnnee() == t2->getAnnee())
    {
    if (t1->getMois() == t2->getMois())
    {
    return (t1->getJour() < t2->getJour());
    }
    else return (t1->getMois()< t2->getMois());
    }
    else return (t1->getAnnee() < t2->getAnnee());
}


Billet::Billet(Voyageur * voyageur, list<Trajet *> tr)
{
    //Production d'un billet
    id= voyageur->getcollBillets()->size();
    trajets= tr;

    list<Trajet *>:: iterator it;
    it=trajets.begin();
    prix_total=0;
    while(it!= trajets.end()){
        prix_total+=(*it)->getPrixBase()->getPrix();
        it++;
    }
    // calcul du prix total selon le tarif preferentiel par categorie du voyageur
    prix_total*=voyageur->getTarifPref();
    //Le tri de la liste des trajets par la methode CompareDate [le plus ancien vers le plus récent]
    trajets.sort(compareDate);


    //L'archivage de tous les billets dans un fichier
    //ouvrir le fichier
    //On ouvre le fichier en mode « append » pour écrire à la fin du fichier et garder l’historique.

    ofstream billetArchive("BilletArchive.txt", fstream::app);
    //ouverture du fichier (succés)
    if(billetArchive)
    {
        billetArchive<< "\n --- BILLET : "<<id<<" [\n Voyageur : "<<voyageur->getNom()<<" "<<voyageur->getPrenom()<<" \n Tarif Pref : "<< voyageur->getTarifPref()<<"\n Prix total : "<<prix_total<<" € \n] \n \n";
        billetArchive.close();
    }
    else{
        //ouverture du fichier (erreur)
        cerr<<"Erreur a l'ouverture du fichier..." ;
    }

}



Billet::~Billet()
{
    //dtor
}
