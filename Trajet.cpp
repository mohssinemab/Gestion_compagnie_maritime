#include "Trajet.h"
#include"Navire.h"
#include"Membre.h"
#include"Prix_base.h"
#include<type_traits>
#include <fstream>



using namespace std;
class Prix_base;

Trajet::Trajet(string p_dep, string p_arr,int an, int ms, int jr,float h_dp,float h_ar,Prix_base* pb)
{
    port_dep=p_dep;
    port_arr=p_arr;
    annee=an;
    mois = ms;
    jour =jr;
    h_dep=h_dp;
    h_arr=h_ar;
    prix_b=pb;
}

void :: Trajet::ajoutNavire(Navire* nav){
    //ajout d'une navire pour passer le trajet
    navire=nav;
    navire->ajoutTrajet(this);
    n_capitain=navire->getNcap();
    n_second=navire->getNsec();
    n_matelot=navire->getNmat();

}

void :: Trajet:: ajoutTraversee(Traversee* traversee){
    traversees.push_back(traversee);

}

void :: Trajet::ajoutMembre(Membre* mem,string type){
    if(type=="Capitain" && n_capitain>0){
    //ajout d'un capitain apres verificatin du nombre des capitains
    if(navire->getCapMarch()<= mem->getTonmax()){
    membres.push_back(mem);
    mem->ajoutTrajet(this);
    n_capitain--;
    }else{
    cout<<"Le tonnage de ce capitain est insuffisant ( il n'a pas l'accréditation )"<<endl;
    }

    }else if(type=="Second" && n_second>0){
    //ajout d'un Second apres verificatin du nombre des Second
    if(navire->getCapMarch()<= mem->getTonmax()){
    membres.push_back(mem);
    mem->ajoutTrajet(this);
    n_second--;
    }else{
    cout<<"Le tonnage de ce Second est insuffisant ( il n'a pas l'accréditation )"<<endl;
    }
    }else if(type=="Matelot" && n_matelot>0){
    //ajout d'un Matelot apres verificatin du nombre des Matelot
    membres.push_back(mem);
    mem->ajoutTrajet(this);
    n_matelot--;

    }else{
    cout<<" L'equipe est complete ou le type est erroné"<<endl;
    }
}

void :: Trajet::afficheInfo(){
    //affichage des information du trajet
    cout<<" -----Le trajet [ "<<port_dep<<" VERS "<<port_arr<<" ] : "<<endl;
    cout<<"DATE : "<<jour<<"/"<<mois<<"/"<<annee<<endl;
    cout<<"NAVIRE : "<<navire->getNom()<<endl;
    cout<<"MEMBRES : "<<endl;

    vector<Membre *>:: iterator it;
    it=membres.begin();
    while(it!= membres.end()){
       cout<<" - "<<(*it)->getId()<<endl;
       it++;
    }

    cout<<"TRAVERSEES : "<<endl;

    vector<Traversee *>:: iterator it2;
    it2=traversees.begin();
    while(it2!= traversees.end()){
       cout<<" - "<<(*it2)->getNom()<<endl;
       it2++;
    }
    cout<<"]"<<endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Apres l'affichage on archive les infos du trajet dans le fichier d'archivage
    //ouvrir le fichier
    //On ouvre le fichier en mode « append » pour écrire à la fin du fichier et garder l’historique.
    ofstream trajetArchive("TrajetArchive.txt", fstream::app);

    //ouverture du fichier (succés)
    if(trajetArchive)
    {
        //ecriture en fichier
        trajetArchive<< "\n --- TRAJET : DE "<<port_dep<<" VERS "<<port_arr<<"[\n Navire : "<<navire->getNom()<<"\n Date : "<<jour<<"/"<<mois<<"/"<<annee<<"\n Heure depart : "<<h_dep<<" h\n Heure d'arrivé : "<<h_arr<<" h\n Nombre des passagers : "<<np_actuel<<"\n Prix base : "<<prix_b->getPrix()<<"\n Traversées : \n";

        vector<Traversee *>:: iterator it2;
        it2=traversees.begin();
        while(it2!= traversees.end()){
        trajetArchive<<"  - "<<(*it2)->getNom()<<endl;
        it2++;
        }
        trajetArchive<<" Membres : \n";
        vector<Membre *>:: iterator it;
        it=membres.begin();
        while(it!= membres.end()){
        trajetArchive<<"  - Id : "<<(*it)->getId()<<", role : "<<(*it)->getRole()<<endl;
        it++;
        }
        trajetArchive<<"] \n \n ";
        trajetArchive.close();
    }
    else{
        //ouverture du fichier (erreur)
        cerr<<"Erreur a l'ouverture du fichier..." ;
    }

}


Prix_base* ::Trajet:: getPrixBase(){
    return prix_b;
}


Navire* :: Trajet:: getNavire(){
    return navire;
}


Trajet::~Trajet()
{
    //dtor
}
