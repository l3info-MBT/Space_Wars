#include <iostream>
#include <SFML/Graphics.hpp>

#include "Collision.hpp"

sf::Vector2f Collision::getPosition(sf::Sprite sp)
{
  return sp.getPosition();
}

bool Collision::collisionBouclier(sf::Sprite sp1, sf::Sprite sp2)
{
  sf::Vector2f vec1, vec2;
  vec1 = getPosition(sp1);  // 1 -> bouclier  // bouclier x=20 y = 10
  vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y =8
  
  if(vec2.x+3 >= vec1.x && vec2.x <= vec1.x+19)
    if(vec1.y <= vec2.y+10 && vec2.y+7 >= vec1.y+10)
      return true;
  return false;  
}

bool Collision::collisionVaisseau(sf::Sprite sp1, sf::Sprite sp2)
{
  sf::Vector2f vec1, vec2;
  vec1 = getPosition(sp1);  // 1 -> vaisseau  // vaisseau x=90 y=50
  vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y=8
  
  if(vec2.x+3 >= vec1.x && vec2.x <= vec1.x+44)
    if(vec1.y <= vec2.y+8 && vec2.y+7 >= vec1.y)
      return true;
  return false;  
}

bool Collision::collisionAlien(sf::Sprite sp1, sf::Sprite sp2)
{
  sf::Vector2f vec1, vec2;
  vec1 = getPosition(sp1);  // 1 -> Alien  // Alien x=100 y=80
  vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y=8
  
  if(vec2.x+3 >= vec1.x && vec2.x <= vec1.x+25)
    if(vec1.y <= vec2.y+8 && vec2.y+7 >= vec1.y)
      return true;
  return false;  
}
