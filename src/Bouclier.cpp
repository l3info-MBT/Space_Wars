
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bouclier.hpp"

sf::Sprite Bouclier::ajouterBouclier(sf::Sprite sp, float posBouclierX, float posBouclierY)
{
  
  if (!bouclier.loadFromFile("images/bouclier.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image bouclier"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(bouclier);
      sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
      sp.setColor(sf::Color(0,0,255));
      sp.setPosition(posBouclierX, posBouclierY);
      return sp;
    }
}


sf::Sprite Bouclier::supprimerBouclier(sf::Sprite sp)
{
  sp.setScale(0.0f, 0.0f);
  sp.setPosition(0.0f, 0.0f);
  return sp;
}

sf::Vector2f Bouclier::getPosition(sf::Sprite sp)
{
  return sp.getPosition();
}

