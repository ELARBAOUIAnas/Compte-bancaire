#include <iostream>
#include <string.h>
#include "client.h"

client::client(string c, string n, string p, string num) {
    CIN = c;
    nom = n;
    prenom = p;
    num_tel = num;
}

string client::getCIN() {
    return CIN;
}

string client::getNom() {
    return nom;
}

string client::getPrenom() {
    return prenom;
}

string client::getNumero() {
    return num_tel;
}

void client::modifierNumero() {
    string nv_tel;
    cout << "Entrez le nouveau numero de telephone: ";
    cin >> nv_tel;
    num_tel = nv_tel;
    cout << "Le numero de telephone a ete modifie.\n";
}
