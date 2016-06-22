/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Joueur.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPCSI_JOUEUR_H
#define DPCSI_JOUEUR_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Joueur
{
private:
public:
    sf::Texture vaisseau, vaisseau_explose;
    sf::Sprite ajouterVaisseau(sf::Sprite sp, float posX, float posY);
    sf::Sprite vaisseauExplose(sf::Sprite sp, float posX, float posY);
    int getNbVie();
};


#endif //DPCSI_JOUEUR_H
