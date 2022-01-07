#ifndef FLOTTE_H
#define FLOTTE_H
#include<string>
#include<vector>
#include"Navire.h"

using namespace std;
class Navire;

class Flotte
{
    public:
        Flotte(string compagnie);
        void ajouterNavire( Navire * navire);
        virtual ~Flotte();

    protected:

    private:
        string compagnie;
        vector<Navire* > mesNavires;
};

#endif // FLOTTE_H
