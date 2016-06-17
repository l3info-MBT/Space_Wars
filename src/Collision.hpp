#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Collision
{
private:
public:
  bool collisionBouclier(sf::Sprite sp, sf::Sprite sp2);//, sf::Vector2f vecReturn);
  sf::Vector2f getPosition(sf::Sprite sp);
};

#endif
