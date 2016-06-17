#ifndef MISSILE_HPP_
#define MISSILE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

//#include "type.h"

class Missile
{
private:
public:
  sf::Texture missile;
  sf::Sprite ajouterMissile(sf::Sprite sp, float posMissileX, float posMissileY);
  
  sf::Sprite supprimerMissile(sf::Sprite sp);
};

#endif
