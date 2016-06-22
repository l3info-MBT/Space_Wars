/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Intro.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#ifndef DPCSI_INTRO_H
#define DPCSI_INTRO_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Intro {
public:
    Intro();
    ~Intro();

    void afficher(sf::RenderWindow& window);
    const sf::Uint32 getIntroEtat() const {return m_intro_etat;};

    enum Intro_Etat
    {
        m_non_initialiser,
        m_lecture
    };

private:
    static sf::Uint32 m_intro_etat;
};

#endif //DPCSI_INTRO_H
