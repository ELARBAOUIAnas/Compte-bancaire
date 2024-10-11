#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
using namespace std;

class client {
    private:
        string CIN;
        string nom;
        string prenom;
        string num_tel;

    public:
        client(string, string, string, string);
        string getCIN();
        string getNom();
        string getPrenom();
        string getNumero();
        void modifierNumero();
};

#endif
