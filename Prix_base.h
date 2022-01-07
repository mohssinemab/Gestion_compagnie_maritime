#ifndef PRIX_BASE_H
#define PRIX_BASE_H
#include<string>

using namespace std;

class Prix_base
{
    public:
        Prix_base(float prix, int annee);
        float getPrix(){ return prix;}
        virtual ~Prix_base();

    protected:

    private:
        float prix;
        int annee;
};

#endif // PRIX_BASE_H
