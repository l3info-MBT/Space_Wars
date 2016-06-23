/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Menu.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#ifndef DPCSI_MENU_H
#define DPCSI_MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu {
public:
    Menu();
    ~Menu();
    void afficher(sf::RenderWindow& window);
    sf::Uint32 getMenuEtat() const {return m_choix_menu;};

    enum Choix_Menu
    {
        m_non_initialiser,
        m_indecis,
        m_menu_solo,
        m_menu_reseau,
        m_quitter
    };

private:
    static Choix_Menu m_choix_menu;

};

#endif //DPCSI_MENU_H
