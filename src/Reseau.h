/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Reseau.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#ifndef DPCSI_RESEAU_H
#define DPCSI_RESEAU_H



#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Client.h"
#include "Cadre.h"


class Reseau {
public:
    Reseau();
    ~Reseau();
    void afficher(sf::RenderWindow& fenetre);
    const sf::Uint32 getMenuEtat() const {return m_choix_reseau;};

    enum Choix_Reseau
    {
        m_initialiser,
        m_creer_partie,
        m_rejoindre,
        m_joue,
        m_fin,
        m_retour,
        m_quitter
    };

private:
    static Choix_Reseau m_choix_reseau;

};

#endif //DPCSI_RESEAU_H
