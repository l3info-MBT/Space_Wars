#ifndef MISSILE_HPP_
#define MISSILE_HPP_

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

#endif
