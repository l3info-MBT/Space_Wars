/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Intro.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#include "Intro.h"
Intro::Intro() {
}

Intro::~Intro() {
}

void Intro::afficher(sf::RenderWindow &fenetre) {
    //On quitte si l'état est différent de non initialiser
    if(!m_intro_etat == m_non_initialiser)  return;
    m_intro_etat = m_lecture;
    //On crée un timer
    sf::Clock clock;

    //Création d'une texture
    sf::Texture intro_texture;
    if(!intro_texture.loadFromFile("ressource/intro.png"))
    {
        std::cerr<<"L'image d'intro n'as pas pu être charger."<<std::endl;
    }

    //On crée un sprite
    sf::Sprite sprite_intro;
    intro_texture.setSmooth(true);
    intro_texture.setRepeated(true);
    //on applique la texture
    sprite_intro.setTexture(intro_texture);
    //On place le sprite au millieur de la fenêtre
    sprite_intro.setPosition(0, 0);

    while(m_intro_etat == m_lecture && clock.getElapsedTime().asSeconds() < 3.f)
    {
        fenetre.clear();

        fenetre.draw(sprite_intro);

        fenetre.display();
    }
    return;

}

sf::Uint32 Intro::m_intro_etat = m_non_initialiser;