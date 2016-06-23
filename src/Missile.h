//
// Created by tony on 21/06/16.
//

#ifndef DPSI_MISSILE_H
#define DPSI_MISSILE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Missile
{
private:
public:
    sf::Texture missile;
    sf::Sprite ajouterMissileVaisseau(sf::Sprite sp, float posMissileX, float posMissileY);
    sf::Sprite ajouterMissileAlien(sf::Sprite sp, float posMissileX, float posMissileY);
    sf::Sprite supprimerMissile(sf::Sprite sp);
};

#endif //DPSI_MISSILE_H
