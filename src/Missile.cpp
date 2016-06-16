#include <iostream>
#include <SFML/Graphics.hpp>

#include "Missile.hpp"
//#include "type.h"

sf::Sprite Missile::ajouterMissile(sf::Sprite sp, float posMissileX, float posMissileY)
{
  
  if (!missile.loadFromFile("images/missile.png", sf::IntRect(0, 0, 100,100))) //£¨x0, y0£©,(x1, y1)-->(left, top),(right, bottom)
    {
      std::cout<<"Erreur durant le chargement de l'image missile"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(missile);
      sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255, 255, 255));
      sp.setPosition(posMissileX, posMissileY);
      return sp;
    }
}
