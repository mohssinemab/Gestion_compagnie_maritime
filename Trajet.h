#ifndef TRAJET_H
#define TRAJET_H
#include<iostream>
#include<string>
#include<vector>
#include"Navire.h"
#include"Membre.h"
#include"Traversee.h"

using namespace std;
class Navire;
class Membre;
class Prix_base;

class Trajet
{
    public:
        Trajet(string port_dep, string port_arr,int an, int ms, int jr,float h_dep,float h_arr,Prix_base* prix_b);
        Prix_base* getPrixBase();
        virtual ~Trajet();
        void ajoutNavire(Navire* navire);
        void ajoutMembre(Membre* membre,string type);
        void ajoutTraversee(Traversee* traversee);
        int* get_np_actuel(){ return &np_actuel;};
        Navire* getNavire();
        int getHdep(){ return h_dep;}
        int getHarr(){ return h_arr;}
        int getAnnee(){ return annee;}
        int getMois(){ return mois;}
        int getJour(){ return jour;}
        void afficheInfo();

    protected:

    private:
        Navire * navire;
        vector<Membre *> membres;
        vector<Traversee *> traversees;
        Prix_base* prix_b;
        string port_dep;
        string port_arr;
        int annee;
        int mois;
        int jour;

        int h_dep;
        int h_arr;
        //nbr passagers actuel
        int np_actuel=0;
        //l'équipe qui s'occupe du trajet selon la navire
        int n_capitain;
        int n_second;
        int n_matelot;
};

#endif // TRAJET_H
