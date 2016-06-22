/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Solo.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#ifndef DPCSI_SOLO_H
#define DPCSI_SOLO_H

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <unistd.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Joueur.h"
#include "Alien.h"
#include "Bouclier.h"
#include "Missile.h"
#include "collision.h"
#include <iostream>

class Solo {
public:
    Solo();
    ~Solo();
    void afficher(sf::RenderWindow& fenetre);
    void pause(sf::RenderWindow& fenetre);
    sf::Uint32 getMenuEtat() const {return m_solo;};

    enum Etat_Solo
    {
        m_joue,
        m_pause,
        m_fin,
        m_quitter
    };

private:
    static Etat_Solo m_solo;

};

#endif //DPCSI_SOLO_H
