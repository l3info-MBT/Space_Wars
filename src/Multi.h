/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Solo.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPSI_MULTI_H
#define DPSI_MULTI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Client.h"

class Multi {
public:
    Multi();
    ~Multi();
    void afficher(sf::RenderWindow& fenetre);
    sf::Uint32 getMenuEtat() const {return m_multi;};

    enum Etat_Multi
    {
        m_joue,
        m_fin,
        m_quitter
    };

private:
    static Etat_Multi m_multi;
};

#endif //DPSI_MULTI_H
