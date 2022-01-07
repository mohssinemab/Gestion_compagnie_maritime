/*   Réalisé par :
        MOHSSINE AIT BOUKDIR
        MOHAMMED ALOUT
*/

#include <iostream>
#include"Flotte.h"
#include"Navire.h"
#include"Voyageur.h"
#include"Prix_base.h"
#include"Trajet.h"
#include<list>

using namespace std;

int main()
{
    //creation d'une flotte
    Flotte f("PENN AR BED");

    //creation de deux navires
    Navire_Mixte RoPax(&f,"RoPax",5000,2000,2,3,4,1000);
    Navire_Fret  FreJax(&f,"FreJax",7000,5000,2,3,4);

    //Prix base selon l'annee
    Prix_base pb (400,2022);
    Prix_base pb2 (600,2022);

    //Des mesmbres d'équipage
    Capitain c1 ("Mohssine","La conduite",10000),c2("Mohammed","Sécurité",9000);
    Second s1("Julien","Gestion de la marchandise",8000),s2("Alex","Gestion des passagers",10000),s3("HAKIM","Gestio secondaire",12000);
    Matelot m1("Mark","Meteorologie"),m2("Antoine","Services télephoniques");

    //Creation des escales
    Traversee tv1("Segal");
    Traversee tv2("Wrach");
    Traversee tv3("Ushant");

    //Creation des Trajets
    Trajet t1("Ile Ouessant","Ile Batz",2022,2,12,14,19,&pb);
    Trajet t2("Ile Sein","Ile Vierge",2022,3,15,3,9,&pb2);
    Trajet t3("Ile Callot","Ile Molene",1994,3,15,6,9,&pb2);
    Trajet t4("Ile Tristan","Ile Hoedic",2012,3,15,11,22,&pb2);
    Trajet t5("Ile Houat","Ile Brehat",1999,2,28,11,15,&pb2);
    Trajet t6("Ile Groix","Ile Glenan",2022,3,15,16,18,&pb2);
    Trajet t7("Ile Archipel","Ile Mer",1999,2,15,9,19,&pb2);

    //Ajout d'une traversée a un trajet
    t1.ajoutTraversee(&tv1);
    t1.ajoutTraversee(&tv2);
    t1.ajoutTraversee(&tv3);

    //Ajout de navire pour le trajet
    t1.ajoutNavire(&RoPax);
    t2.ajoutNavire(&RoPax);

    //L'ajout des membres d'equipage
    t1.ajoutMembre(&c1,"Capitain");
    t1.ajoutMembre(&c2,"Capitain");
    t1.ajoutMembre(&s1,"Second");
    t1.ajoutMembre(&s2,"Second");
    t1.ajoutMembre(&s3,"Second");
    t1.ajoutMembre(&m1,"Matelot");
    t1.ajoutMembre(&m2,"Matelot");

    t2.ajoutMembre(&c1,"Capitain");
    t2.ajoutMembre(&s3,"Second");
    t2.ajoutMembre(&m1,"Matelot");

    t3.ajoutNavire(&RoPax);
    t3.ajoutMembre(&c1,"Capitain");
    t3.ajoutMembre(&s3,"Second");
    t3.ajoutMembre(&m1,"Matelot");


    t4.ajoutNavire(&RoPax);
    t4.ajoutMembre(&c1,"Capitain");
    t4.ajoutMembre(&s3,"Second");
    t4.ajoutMembre(&m1,"Matelot");


    t5.ajoutNavire(&RoPax);
    t5.ajoutMembre(&c1,"Capitain");
    t5.ajoutMembre(&s3,"Second");
    t5.ajoutMembre(&m1,"Matelot");


    t6.ajoutNavire(&RoPax);
    t6.ajoutMembre(&c1,"Capitain");
    t6.ajoutMembre(&s3,"Second");
    t6.ajoutMembre(&m1,"Matelot");


    t7.ajoutNavire(&RoPax);
    t7.ajoutMembre(&c1,"Capitain");
    t7.ajoutMembre(&s3,"Second");
    t7.ajoutMembre(&m1,"Matelot");


    Normal vn1("1","MOHSSINE","AIT BOUKDIR");
    Insulaire vn2("2","MOHAMMED","ALOUT");
    Insulaire_sec vn3("3","ALI","ABOUALI");

    //liste des trajets du billet
    list<Trajet* > lbill;

    lbill.push_back(&t1);
    vn1.acheterBillet(lbill);

    vn2.acheterBillet(lbill);

    lbill.push_back(&t2);

    //achat du billet
    vn3.acheterBillet(lbill);

    cout<<"################################### AFFICHAGE DES TRAJETS ######################"<<endl;

    t1.afficheInfo();
    cout<<"--------------"<<endl;
    t2.afficheInfo();
    cout<<"--------------"<<endl;
    t3.afficheInfo();
    cout<<"--------------"<<endl;
    t4.afficheInfo();
    cout<<"--------------"<<endl;
    t5.afficheInfo();
    cout<<"--------------"<<endl;
    t6.afficheInfo();
    cout<<"--------------"<<endl;
    t7.afficheInfo();

    cout<<"################################### AFFICHAGE DES TRAJETS DU MEMBRE POUR L ANNEE 1999 ######################"<<endl;

    c1.afficheTrajetsAnnee(1999);

    cout<<"################################### AFFICHAGE DES NOMBRE DES PASSAGERS POUR L'ANNEE EN COURS ######################"<<endl;
    RoPax.afficheNbPassageresAnneeEnCours();

    return 0;

}
