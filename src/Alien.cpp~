#include <iostream>
#include <SFML/Graphics.hpp>

#include "Alien.hpp"

sf::Sprite Alien::ajouterAlien1_1(sf::Sprite sp, float posAlienX, float posAlienY)
{
  
  if (!alien.loadFromFile("images/alien1_1.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }
}


sf::Sprite Alien::ajouterAlien1_2(sf::Sprite sp, float posAlienX, float posAlienY)
{
  if (!alien.loadFromFile("images/alien1_2.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }

}

sf::Sprite Alien::ajouterAlien2_1(sf::Sprite sp, float posAlienX, float posAlienY)
{
  
  if (!alien.loadFromFile("images/alien2_1.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }
}


sf::Sprite Alien::ajouterAlien2_2(sf::Sprite sp, float posAlienX, float posAlienY)
{
  if (!alien.loadFromFile("images/alien2_2.png", sf::IntRect(0, 0, 100,100))) //£¨x0, y0£©,(x1, y1)-->(left, top),(right, bottom)
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }
}

sf::Sprite Alien::ajouterAlien3_1(sf::Sprite sp, float posAlienX, float posAlienY)
{
  
  if (!alien.loadFromFile("images/alien3_1.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }
}


sf::Sprite Alien::ajouterAlien3_2(sf::Sprite sp, float posAlienX, float posAlienY)
{
  if (!alien.loadFromFile("images/alien3_2.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image alien"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(alien);
      sp.setScale(0.3f, 0.3f);    //setScale peut changer la taille
      sp.setColor(sf::Color(255,255,255));
      sp.setPosition(posAlienX, posAlienY);
      return sp;
    }
}

sf::Sprite Alien::supprimerAlien(sf::Sprite sp)
{
  sp.setScale(0.0f, 0.0f);
  sp.setPosition(0.0f, 0.0f);
  return sp;
}
sf::Vector2f Alien::getPosition(sf::Sprite sp)
{
  return sp.getPosition();
}
