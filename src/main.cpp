/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Main.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

//Incluision des bibliothéques
#include <iostream>
#include <exception>

//Inclusion des Headers
#include "Jeu.h"
#include "config.h"

//Pour éviter d'écrire std::
using namespace std;

int main()
{
    try
    {
        Jeu::initialiserApp();
    }
    catch(exception& erreur)
    {
        cout<<"Une erreure est survenu, le code erreure est le suivant:"<<endl;
        cout<<erreur.what()<<endl;
        cout<<"\nLe programme va maintenant quitter"<<endl;
    }
    return 0;
}
