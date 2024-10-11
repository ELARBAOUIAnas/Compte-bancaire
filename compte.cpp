#include <iostream>
#include <string.h>
#include "compte.h"

compte::compte(string cin, double s, string n) { // constructeur pour initialiser les attributs
    ID = cin;
    solde = s;
    Nom = n;  
}

double compte::getSolde() { // fonction pour récupérer le solde du compte
    return solde;
}

string compte::getProprietaire() {  // Fonction pour récupérer le nom du proprietaire
    return Nom;
}

void compte::crediter(double montant) { // fonction pour créditer le compte
    if (montant > 0) {
        solde += montant;
        cout << "Montant credite. Nouveau solde: " << solde << " euros\n";
    } else {
        cout << "Montant invalide.\n";
    }
}

void compte::debiter(double montant) {  //fonction pour débiter le compte
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        cout << "Montant debite. Nouveau solde: " << solde << " euros\n";
    } else {
        cout << "Montant invalide ou solde insuffisant.\n";
    }
}

void compte::afficherInfos() {
    cout << "Proprietaire: " << Nom << endl;
    cout << "Solde: " << solde << " euros\n";
    
}

void compte::virement(compte &destinataire, double montant) { // fonction pour effectuer un virement d'un compte à l'autre 
    if (montant > 0 && montant <= solde) {
        debiter(montant);
        destinataire.crediter(montant);
        cout << "Virement de " << montant << " euros vers le compte de " << destinataire.getProprietaire() << ".\n";
    } else {
        cout << "Erreur: Montant invalide ou solde insuffisant.\n";
    }
}

void compte::affiche_menu(compte &autreCompte) {
    int choix;
    double montant;
    string nom_Destinataire;

    do {
        cout << "\n1. Consulter le solde\n";
        cout << "2. Crediter le compte\n";
        cout << "3. Debiter le compte\n";
        cout << "4. Afficher les infos du compte\n";
        cout << "5. Faire un virement\n";  // Nouvelle option pour virement
        cout << "6. Quitter\n";
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Votre solde est de: " << getSolde() << " euros\n";
                break;
            case 2:
                cout << "Entrez le montant a crediter: ";
                cin >> montant;
                crediter(montant);
                break;
            case 3:
                cout << "Entrez le montant a debiter: ";
                cin >> montant;
                debiter(montant);
                break;
            case 4:
                afficherInfos();
                break;
            case 5:
                cout << "Entrez le nom de famille du compte destinataire: ";  // Demande du nom
                cin >> nom_Destinataire;

                // Validation du nom
                if (nom_Destinataire == autreCompte.getProprietaire()) {
                    cout << "Entrez le montant du virement: ";
                    cin >> montant;
                    virement(autreCompte, montant);  // Virement vers l'autre compte
                } else {
                    cout << "Erreur: Nom de famille incorrect.\n";
                }
                break;
            case 6:
                cout << "Au revoir!\n";
                break;
            default:
                cout << "Choix invalide.\n";
            
        }
        system("pause");
    } while (choix != 6);
}
