#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bouclier.hpp"
//#include "type.h"

sf::Sprite Bouclier::ajouterBouclier(sf::Sprite sp, float posBouclierX, float posBouclierY)
{
  
  if (!bouclier.loadFromFile("images/bouclier.png", sf::IntRect(0, 0, 100,100))) //£¨x0, y0£©,(x1, y1)-->(left, top),(right, bottom)
    {
      std::cout<<"Erreur durant le chargement de l'image bouclier"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(bouclier);
      sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
      sp.setColor(sf::Color(128,128,0));
      sp.setPosition(posBouclierX, posBouclierY);
      return sp;
    }
}
