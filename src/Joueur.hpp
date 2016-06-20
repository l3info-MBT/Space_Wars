#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Joueur
{
private:
public:
  sf::Texture vaisseau, vaisseau_explose;
  sf::Sprite ajouterVaisseau(sf::Sprite sp, float posX, float posY);
  sf::Sprite vaisseauExplose(sf::Sprite sp, float posX, float posY);
  int getNbVie();
};

#endif
