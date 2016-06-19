#include <iostream>
#include <SFML/Graphics.hpp>

#include "Joueur.hpp"
//#include "type.h"

/*
  int getNbVie()
  {
  return Joueur::getNbVie;
  }

  void setNbVie(int a)
  {
  Joueur::getNbVie = a;
  }

  int getEnVie()
  {
  if(Joueur::getNbVie == 0)
  return 0;
  return 1;
  }
*/

sf::Sprite Joueur::ajouterVaisseau(sf::Sprite sp, float posVaisseauX, float posVaisseauY)
{
  //sprite1 pour le vaisseau
  if (!vaisseau.loadFromFile("images/vaisseau.png", sf::IntRect(0, 0, 100,100))) //£šx0, y0£©,(x1, y1)-->(left, top),(right, bottom)
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
      return sp;
    }
  
}

