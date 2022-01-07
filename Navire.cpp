#include<iostream>
#include"Flotte.h"
#include "Navire.h"

using namespace std;

//Constructeurs
Navire::Navire(Flotte * f,string nm,float ton,float cpM,int n_c,int n_s,int n_m)
{
    flotte=f; flotte->ajouterNavire(this);
    nom=nm; tonnage=ton; capaciteMarch=cpM; n_capitain= n_c; n_second=n_s; n_matelot=n_m;
}

Navire_Fret::Navire_Fret(Flotte * f,string nm,float ton,float cpM,int n_c,int n_s,int n_m) : Navire(f,nm,ton,cpM,n_c,n_s,n_m)
{
    //ctor
}

Navire_Mixte::Navire_Mixte(Flotte * f,string nm,float ton,float cpM,int n_c,int n_s,int n_m,int nbP) : Navire(f,nm,ton,cpM,n_c,n_s,n_m)
{
    nbrPassagers=nbP;
}

void Navire::afficheNbPassageresAnneeEnCours(){

    //affichage des nombre des passagers d'une navire pour l'année en cours(2022)
    int nbPassg=0;
    list<Trajet *>:: iterator it;
    it = mesTrajets.begin();
    while(it!= mesTrajets.end()){
        if((*it)->getAnnee()==2022){
            //calcul des passagers
            nbPassg+= *((*it)->get_np_actuel());
        }
        it++;
    }
    cout<<"--- Le nombre des passagers de la navire["<<nom<<"] pour l'annee en cours est : "<<nbPassg<<" passagers.."<<endl;


}


int ::Navire_Mixte::getNbrPassagers(){
    return nbrPassagers;
}

void :: Navire::ajoutTrajet(Trajet* t){
    //ajout dun trajet a la liste des trajets du navire
    mesTrajets.push_back(t);
}



Navire_Mixte::~Navire_Mixte()
{
    //dtor
}

Navire_Fret::~Navire_Fret()
{
    //dtor
}

Navire::~Navire()
{
    //dtor
}
