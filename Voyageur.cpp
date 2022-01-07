#include "Voyageur.h"

using namespace std;

list<Billet * > Voyageur::collBillets;


Voyageur::Voyageur(string nu, string pr, string no)
{
    num = nu;
    prenom=pr;
    nom =no;
}

Normal::Normal(string nu, string pr, string no) : Voyageur(nu,pr,no)
{
    //Tarif pour voyageur normal est 100%
    tarif_pref= 1;
}

Insulaire::Insulaire(string nu, string pr, string no): Voyageur(nu,pr,no)
{
    //Tarif pour voyageur insulaire est 25%
    tarif_pref= 0.25;
}

Insulaire_sec::Insulaire_sec(string nu, string pr, string no): Voyageur(nu,pr,no)
{
    //Tarif pour voyageur insulaire secondaire est 50%
    tarif_pref= 0.5;
}

list<Billet* >* ::Voyageur:: getcollBillets(){
    return &collBillets;
}

void Voyageur::acheterBillet(list<Trajet *> trajets){

    list<Trajet *>:: iterator it;
    it=trajets.begin();
    bool x=false;
    while(it!= trajets.end()){
            //verification de nombres des passagers
        if(*((*it)->get_np_actuel()) < (*it)->getNavire()->getNbrPassagers()){
            x=true;
        }else{
        x=false;
        }
        it++;
    }

    if(x){
    Billet* b=new Billet(this,trajets);


    //list des billets chaque voyageur
    mesBillets.push_back(b);

    //list static de toutes les billets
    collBillets.push_back(b);

    //incrementation des nombres actuels de passagers inscris en trajets
        it=trajets.begin();
        while(it!= trajets.end()){
        (*((*it)->get_np_actuel()))++;
        it++;
        }

    cout<<"Billet bien acheté - Prix total = "<<b->getPrixTotal()<<endl;

    }else{
    cout<<"Oups, un de vos trajets est complet"<<endl;
    }

}


Voyageur::~Voyageur()
{
    //dtor
}


Normal::~Normal()
{
    //dtor
}

Insulaire::~Insulaire()
{
    //dtor
}

Insulaire_sec::~Insulaire_sec()
{
    //dtor
}
