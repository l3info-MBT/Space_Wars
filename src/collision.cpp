/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   collision.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#include "collision.h"

sf::Vector2f Collision::getPosition(sf::Sprite sp)
{
    return sp.getPosition();
}

bool Collision::collisionBouclier(sf::Sprite sp1, sf::Sprite sp2)
{
    sf::Vector2f vec1, vec2;
    vec1 = getPosition(sp1);  // 1 -> bouclier  // bouclier x=20 y = 10
    vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y =8

    if(vec2.x+4 > vec1.x && vec2.x < vec1.x+20)
    if(vec2.y <= vec1.y+10 && vec2.y+8 >= vec1.y)
        return true;
    return false;
}

bool Collision::collisionVaisseau(sf::Sprite sp1, sf::Sprite sp2)
{
    sf::Vector2f vec1, vec2;
    vec1 = getPosition(sp1);  // 1 -> vaisseau  // vaisseau x=90 y=50
    vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y=8

    if(vec2.x+4 > vec1.x && vec2.x < vec1.x+45)
    if(vec2.y+8 > vec1.y && vec2.y < vec1.y+25)
        return true;
    return false;
}

bool Collision::collisionAlien(sf::Sprite sp1, sf::Sprite sp2)
{
    sf::Vector2f vec1, vec2;
    vec1 = getPosition(sp1);  // 1 -> Alien  // Alien x=100 y=80
    vec2 = getPosition(sp2);  // 2 -> missile   // missile x=4 y=8

    if(vec2.x+4 > vec1.x && vec2.x < vec1.x+40)
    if(vec2.y+8 > vec1.y && vec2.y < vec1.y+40)
        return true;
    return false;
}