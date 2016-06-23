/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Alien.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPCSI_ALIEN_H
#define DPCSI_ALIEN_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Alien
{
private:
public:
    sf::Texture alien;
    sf::Sprite ajouterAlien1_1(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite ajouterAlien1_2(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite ajouterAlien2_1(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite ajouterAlien2_2(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite ajouterAlien3_1(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite ajouterAlien3_2(sf::Sprite sp, float posAlienX, float posAlienY);
    sf::Sprite supprimerAlien(sf::Sprite sp);
    sf::Vector2f getPosition(sf::Sprite sp);
};

#endif //DPCSI_ALIEN_H
