//
// Created by tony on 22/06/16.
//

#ifndef DPSI_MULTI_H
#define DPSI_MULTI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Multi {
public:
    Multi();
    ~Multi();
    void afficher(sf::RenderWindow& fenetre);
    const sf::Uint32 getMenuEtat() const {return m_multi;};

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