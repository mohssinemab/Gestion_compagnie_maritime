#include "Membre.h"
#include "Trajet.h"
#include<list>

//Constructeurs
Membre::Membre(string idd,string r)
{
    id=idd;
    renseignements= r;
}

//la methode de sort de la liste des trajets du membre
bool compareDate1(Trajet *t1, Trajet *t2)
{
    if (t1->getAnnee() == t2->getAnnee())
    {
    if (t1->getMois() == t2->getMois())
    {
    return (t1->getJour() < t2->getJour());
    }
    else return (t1->getMois()< t2->getMois());
    }
    else return (t1->getAnnee() < t2->getAnnee());
}

void Membre:: ajoutTrajet(Trajet * trajet){
    mesTrajets.push_back(trajet);

    //tri du liste des trajets [le plus ancien vers le plus récent]
    mesTrajets.sort(compareDate1);
}

void Membre::afficheTrajetsAnnee(int annee){

    //affichage des trajets d'un membre pour une année passé par parametre
    float nbHeure=0;
    list<Trajet *>:: iterator it;
    it=mesTrajets.begin();
    while(it!= mesTrajets.end()){
        if((*it)->getAnnee()==annee){
            (*it)->afficheInfo();
            //calcul des heures de navigation
            nbHeure+= ((*it)->getHarr()-(*it)->getHdep());
        }
        it++;
    }
    cout<<"--- Nombre total des heures de navigation : "<<nbHeure<<" heures."<<endl;


}

Capitain::Capitain(string idd,string rns, float t_max): Membre(idd,rns)
{
    role="Capitain";
    tonnage_max=t_max;
}

Second::Second(string idd,string rns, float t_max): Membre(idd,rns)
{
    role="Second";
    tonnage_max=t_max;
}

Matelot::Matelot(string idd,string rns): Membre(idd,rns)
{
    role="Matelot";
}


Membre::~Membre()
{
    //dtor
}

Capitain::~Capitain()
{
    //dtor
}

Second::~Second()
{
    //dtor
}

Matelot::~Matelot()
{
    //dtor
}
