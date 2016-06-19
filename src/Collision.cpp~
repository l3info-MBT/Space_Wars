#include <iostream>
#include <SFML/Graphics.hpp>

#include "Collision.hpp"
//#include "type.h"

sf::Vector2f Collision::getPosition(sf::Sprite sp)
{
  return sp.getPosition();
}

bool Collision::collisionBouclier(sf::Sprite sp1, sf::Sprite sp2)//, sf::Vector2f vecReturn)
{
  sf::Vector2f vec1, vec2;
  vec1 = getPosition(sp1);
  vec2 = getPosition(sp2);

  // position y de bouclier et missile pour suppréssion missile.
  // vecReturn.y = vec1.y;
  //vecReturn.x = vec2.y;
  
  if(vec2.x >= vec1.x-3 && vec2.x <= vec1.x+19)
    if(vec1.y <= vec2.y+10 && vec2.y >= vec1.y)
      return true;
  return false;


  /////////////////////////
  // missile x=2 y = 4
  /////////////////////////
  // bouclier x=20 y = 10
  /////////////////////////
  // alien x=_ y=_
  /////////////////////////
  
}
