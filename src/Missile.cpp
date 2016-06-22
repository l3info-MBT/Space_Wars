//
// Created by tony on 21/06/16.
//

#include "Missile.h"
sf::Sprite Missile::ajouterMissileVaisseau(sf::Sprite sp, float posMissileX, float posMissileY)
{

    if (!missile.loadFromFile("ressource/missile.png", sf::IntRect(0, 0, 100,100)))
    {
        std::cout<<"Erreur durant le chargement de l'image missile"<<std::endl;
        return sp; // On ferme le programme
    }
    else
    {
        sp.setTexture(missile);
        sp.setScale(0.5f, 0.5f);    //setScale peut changer la taille
        sp.setColor(sf::Color(0, 255, 0));
        sp.setPosition(posMissileX, posMissileY);
        return sp;
    }
}

sf::Sprite Missile::ajouterMissileAlien(sf::Sprite sp, float posMissileX, float posMissileY)
{

    if (!missile.loadFromFile("ressource/missile.png", sf::IntRect(0, 0, 100,100)))
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

sf::Sprite Missile::supprimerMissile(sf::Sprite sp)
{
    sp.setScale(0.0f, 0.0f);
    sp.setPosition(0.0f, 0.0f);
    return sp;
}