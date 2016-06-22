/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   collision.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#ifndef DPSI_COLLISION_H
#define DPSI_COLLISION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Collision
{
private:
public:
    bool collisionBouclier(sf::Sprite sp, sf::Sprite sp2);
    bool collisionVaisseau(sf::Sprite sp, sf::Sprite sp2);
    bool collisionAlien(sf::Sprite sp, sf::Sprite sp2);
    sf::Vector2f getPosition(sf::Sprite sp);
};

#endif //DPSI_COLLISION_H
