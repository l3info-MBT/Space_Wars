/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Jeu.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPCSI_JEU_H
#define DPCSI_JEU_H

    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include "Intro.h"
    #include "Menu.h"
    #include "Solo.h"
    #include "Reseau.h"

class Jeu {
public:
    Jeu();
    ~Jeu();

    /*
     * Fonction qui initialise une nouvelle fenêtre si cette dernière n'est pas déjà initialiser dans notre programmes.
     */
    static void initialiserApp();

private:
    static void lancerApp();
    static void chargerInto();
    static void chargerMenuPrincipal();
    static void chargerSolo();
    static void chargerMenuReseau();

    static bool quitterApp();

    enum etat
    {
        m_non_initialiser,
        m_intro,
        m_menu_principale,
        m_solo,
        m_menu_reseau,
        m_quitter
    };

    static sf::Uint32 m_etat;
    static sf::RenderWindow m_fenetre;
};

#endif //DPCSI_JEU_H
