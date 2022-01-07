#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<string>
#include<list>
#include"Trajet.h"
#include"Billet.h"


using namespace std;
class Billet;

class Voyageur
{
    public:
        Voyageur(string num, string prenom, string nom);
        list<Billet* >* getcollBillets();
        void acheterBillet(list<Trajet *> trajets);
        float getTarifPref(){ return tarif_pref;}
        string getNum(){ return num;}
        string getNom(){ return nom;}
        string getPrenom(){ return prenom;}
        virtual ~Voyageur();

    protected:
        //list de touts les billets crées
        static list<Billet * > collBillets;
        string num;
        string prenom;
        string nom;
        float tarif_pref;
        list<Billet * > mesBillets;


    private:

};

class Normal : public Voyageur
{
    public:
        Normal(string num, string prenom, string nom);
        virtual ~Normal();

    protected:


    private:
};

class Insulaire : public Voyageur
{
    public:
        Insulaire(string num, string prenom, string nom);
        virtual ~Insulaire();

    protected:


    private:
};

class Insulaire_sec : public Voyageur
{
    public:
        Insulaire_sec(string num, string prenom, string nom);
        virtual ~Insulaire_sec();

    protected:


    private:
};

#endif // VOYAGEUR_H
