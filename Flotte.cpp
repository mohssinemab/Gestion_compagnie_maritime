#include "Flotte.h"

Flotte::Flotte(string compagnie)
{
    //ctor
}

void Flotte::ajouterNavire( Navire * navire){
    //Ajout du navire au flotte
    mesNavires.push_back(navire);
}

Flotte::~Flotte()
{
    //dtor
}
