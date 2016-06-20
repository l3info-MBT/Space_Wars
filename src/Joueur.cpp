#include <iostream>
#include <SFML/Graphics.hpp>

#include "Joueur.hpp"

int Joueur::getNbVie()
  {
    return 3;
  }

sf::Sprite Joueur::ajouterVaisseau(sf::Sprite sp, float posVaisseauX, float posVaisseauY)
{
  //sprite1 pour le vaisseau
  if (!vaisseau.loadFromFile("images/vaisseau.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image vaisseau"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(vaisseau);
      sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
      sp.setColor(sf::Color(0,255,0));
      sp.setPosition(posVaisseauX, posVaisseauY);
      return sp; // On ferme le programme
    }
}

sf::Sprite Joueur::vaisseauExplose(sf::Sprite sp, float posVaisseauX, float posVaisseauY)
{
  //sprite1 pour le vaisseau
  if (!vaisseau_explose.loadFromFile("images/vaisseauExplose.png", sf::IntRect(0, 0, 100,100)))
    {
      std::cout<<"Erreur durant le chargement de l'image vaisseau explose"<<std::endl;
      return sp; // On ferme le programme
    }
  else
    {
      sp.setTexture(vaisseau_explose);
      sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
      sp.setColor(sf::Color(0,255,0));
      sp.setPosition(posVaisseauX, posVaisseauY);
      return sp; // On ferme le programme
    }
}
