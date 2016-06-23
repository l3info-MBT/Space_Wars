/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Bouclier.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPCSI_BOUCLIER_H
#define DPCSI_BOUCLIER_H


#include <iostream>
#include <SFML/Graphics.hpp>

class Bouclier
{
private:
public:
    sf::Texture bouclier;
    sf::Sprite ajouterBouclier(sf::Sprite sp, float posBouclierX, float posBouclierY);
    sf::Sprite supprimerBouclier(sf::Sprite sp);
    sf::Vector2f getPosition(sf::Sprite sp);
};


#endif //DPCSI_BOUCLIER_H
