#ifndef TRAVERSEE_H
#define TRAVERSEE_H
#include<string>
#include<vector>

using namespace std;
class Traversee
{
    public:
        Traversee(string n);
        string getNom(){return nom;}
        void setNom(string n){nom=n;}

        virtual ~Traversee();

    protected:

    private:
        string nom;

};

#endif // TRAVERSEE_H
