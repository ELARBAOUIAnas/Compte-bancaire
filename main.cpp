#include <iostream>
#include <string.h>
#include "compte.h"
#include "client.h"

using namespace std;

int main() {
    // Creation des deux clients et leurs comptes
    client client1("MJ1942", "ELARBAOUI", "Anas", "0123456789");
    compte compte1("MJ1942", 100000, "ELARBAOUI");

    client client2("MJ3534", "AARAB", "Mohammed", "0987654321");
    compte compte2("MJ3534", 200000, "AARAB");

    int code;
    int choix = 0;
    //int cmp;
    while (choix != 3){
    cout << "Bienvenue au systeme de gestion bancaire\n";
    cout << "1. ELARBAOUI Anas\n";
    cout << "2. AARAB Mohammed\n";
    cout << "3. Sortir\n";
    cout << "Choisissez votre compte: ";
    cin >> choix;

    if (choix == 1) {
        cout << "Entrez le code de securite pour ELARBAOUI Anas: ";
        cin >> code;
        if (code == 2006) {
            cout << "code bon\n";
            cout << "Bienvenue, ELARBAOUI Anas\n";
            compte1.affiche_menu(compte2);  
        } else {
            cout << "Code de securite incorrect.\n";
        }
    } else if (choix == 2) {
        cout << "Entrez le code de securite pour AARAB Mohammed: ";
        cin >> code;
        if (code == 2005) {
            cout << "code bon\n";
            cout << "Bienvenue, AARAB Mohammed\n";
            compte2.affiche_menu(compte1);  
        } else {
            cout << "Code de securite incorrect.\n";
        }
    } else if (choix == 3)
    {
        cout << "Au revoir\n";    }
    else
    {
        cout << "Choix de client invalide.\n";
    }

    
    }
    return 0;
}
