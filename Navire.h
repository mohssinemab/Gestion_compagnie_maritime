#ifndef NAVIRE_H
#define NAVIRE_H
#include"Flotte.h"
#include"Trajet.h"
#include<list>
#include<string>

using namespace std;
class Flotte;
class Trajet;

class Navire
{
    public:
        Navire(Flotte * flotte,string nom,float tonnage,float capaciteMarch,int n_cap,int n_sec,int n_mat);
        void ajoutTrajet(Trajet* t);
        string getNom(){ return nom;}
        int getNcap(){ return n_capitain;}
        int getNsec(){ return n_second;}
        int getNmat(){ return n_matelot;}
        float getCapMarch(){ return capaciteMarch;}
        virtual int getNbrPassagers(){};
        //le nombre de passager par navire pour l'année en cours
        void afficheNbPassageresAnneeEnCours();
        virtual ~Navire();


    protected:
        Flotte * flotte;
        string nom;
        float tonnage;
        float capaciteMarch;
        int n_capitain;
        int n_second;
        int n_matelot;
        list<Trajet * > mesTrajets ;

    private:

};

class Navire_Fret : public Navire
{
    public:
        Navire_Fret(Flotte * flotte,string nom,float tonnage,float capaciteMarch,int n_cap,int n_sec,int n_mat);
        virtual ~Navire_Fret();

    protected:

    private:

};

class Navire_Mixte : public Navire
{
    public:
        Navire_Mixte(Flotte * flotte,string nom,float tonnage,float capaciteMarch,int n_cap,int n_sec,int n_mat,int nbrPassagers);
        int getNbrPassagers();
        virtual ~Navire_Mixte();

    protected:

    private:
        int nbrPassagers;
};

#endif // NAVIRE_H
