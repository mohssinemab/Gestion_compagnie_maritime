#ifndef MEMBRE_H
#define MEMBRE_H
#include<string>
#include"Trajet.h"
#include<list>

using namespace std;
class Trajet;

class Membre
{
    public:
        Membre(string id, string renseignements);
        string getId(){ return id;}
        string getRole(){ return role;}
        virtual ~Membre();
        virtual float getTonmax(){ }
        void ajoutTrajet(Trajet * trajet);
        void afficheTrajetsAnnee(int annee);

    protected:
        string id;
        string role;
        string renseignements;
        list<Trajet* > mesTrajets;

    private:
};

class Capitain : public Membre
{
    public:
        Capitain(string id,string renseignements,float tonnage_max);
        float getTonmax(){ return tonnage_max; }
        virtual ~Capitain();

    protected:


    private:
        float tonnage_max;
};

class Second : public Membre
{
    public:
        Second(string id,string renseignements,float tonnage_max);
        float getTonmax(){ return tonnage_max; }
        virtual ~Second();

    protected:

    private:
        float tonnage_max;

};

class Matelot : public Membre
{
    public:
        Matelot(string id,string renseignements);
        virtual ~Matelot();

    protected:


    private:
};

#endif // MEMBRE_H
