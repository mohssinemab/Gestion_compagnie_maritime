#ifndef BILLET_H
#define BILLET_H
#include<list>
#include<string>
#include"Trajet.h"
#include"Voyageur.h"

using namespace std;

class Voyageur;

class Billet
{
    public:
        Billet(Voyageur * voyageur, list<Trajet *> tr);
        float getPrixTotal(){ return prix_total;}
        void setId(int idd){ id=idd;}
        virtual ~Billet();

    protected:

    private:
        int id;
        list<Trajet * > trajets;
        Voyageur* voyageur;
        float prix_total;
};

#endif // BILLET_H
