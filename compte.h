#include <iostream>
#include <string.h>
using namespace std;
#ifndef COMPTE_H
#define COMPTE_H

class compte {
    private:
        string ID;
        double solde;
        string Nom;  // Nom du proprietaire

    public:
        compte(string, double, string);
        double getSolde();
        string getProprietaire();  // Methode pour obtenir le nom du proprietaire
        void crediter(double montant);
        void debiter(double montant);
        void afficherInfos();
        void virement(compte &destinataire, double montant);  
        void affiche_menu(compte &autreCompte);  
};

#endif
