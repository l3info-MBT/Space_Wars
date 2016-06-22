/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Jeu.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#include "Jeu.h"
//Constructeur par défaut
Jeu::Jeu(){

}

//Destructeur
Jeu::~Jeu(){

}

void Jeu::initialiserApp() {
    //Si la fenêtre est déjà initialiser on sort de la fonction
    if(!Jeu::m_etat == m_non_initialiser) return;
    sf::VideoMode mon_ecran = sf::VideoMode::getDesktopMode();

    //Si notre résolution est petite on lance le jeu en pleine écran, sinon on lance en fenêtré 800x600 placer au millieu de l'écran
    if (mon_ecran.width <= 800 && mon_ecran.height <=600)
    {
        m_fenetre.create(sf::VideoMode(mon_ecran.width,mon_ecran.height,mon_ecran.bitsPerPixel), "Space Wars", sf::Style::Fullscreen);
    }
    else
    {
        m_fenetre.create(sf::VideoMode(800, 600), "Space Wars", sf::Style::Close | sf::Style::Titlebar);
        m_fenetre.setPosition(sf::Vector2i(((mon_ecran.width/2)-400), ((mon_ecran.height/2)-300)));
    }
    //Quelque option sur la fenêtre en génèrale:
    m_fenetre.setVerticalSyncEnabled (true);
    m_fenetre.setKeyRepeatEnabled(true);
    m_fenetre.setFramerateLimit(120);
    m_fenetre.setMouseCursorVisible(true);
    //On passe notre état à intro
    m_etat = m_intro;

    //Boucle d'affichage
    while(!quitterApp())
    {
        lancerApp();
    }
    std::cout<<"Fermeture de la fenetre..."<<std::endl;
    m_fenetre.close();
}

void Jeu::lancerApp() {
    switch (m_etat){
        case m_intro:
            chargerInto();
            m_etat=m_menu_principale;
            break;
        case m_menu_principale:
            chargerMenuPrincipal();
            break;
        case m_solo:
            chargerSolo();
            break;
        case m_menu_reseau:
            chargerMenuReseau();
            break;
        default:
            std::cout<<"Cas impossible"<<std::endl;
            break;
    }
}

void Jeu::chargerInto(){
    std::cout<<"Chargement de l'intro..."<<std::endl;
    m_fenetre.setTitle("Space Wars - Introduction");
    Intro AppIntro;
    AppIntro.afficher(m_fenetre);
}

void Jeu::chargerMenuPrincipal(){
    std::cout<<"Chargement du menu..."<<std::endl;
    m_fenetre.setTitle("Space Wars - Menu");
    Menu AppMenu;
    AppMenu.afficher(m_fenetre);
    if(AppMenu.getMenuEtat() == Menu::m_menu_solo)
        m_etat = m_solo;
    else if(AppMenu.getMenuEtat() == Menu::m_menu_reseau)
        m_etat = m_menu_reseau;
    else if(AppMenu.getMenuEtat() == Menu::m_quitter)
        m_etat = m_quitter;
}

void Jeu::chargerSolo(){
    std::cout<<"Chargement du menu..."<<std::endl;
    m_fenetre.setTitle("Space Wars - Solo");

    Solo partie_solo;
    partie_solo.afficher(m_fenetre);
    if(partie_solo.getMenuEtat() == Solo::m_fin)
        m_etat = m_menu_principale;
    else if(partie_solo.getMenuEtat() == Solo::m_quitter)
        m_etat = m_quitter;
}

void Jeu::chargerMenuReseau(){
    std::cout<<"Chargement du menu..."<<std::endl;
    m_fenetre.setTitle("Space Wars - Menu Reseaux");

    Reseau partie_multi;
    partie_multi.afficher(m_fenetre);
    if(partie_multi.getMenuEtat() == Reseau::m_retour)
        m_etat = m_menu_principale;
    else if(partie_multi.getMenuEtat() == Reseau::m_quitter)
        m_etat = m_quitter;
}


bool Jeu::quitterApp(){
    return m_etat == m_quitter;
}

sf::Uint32 Jeu::m_etat = m_non_initialiser;
sf::RenderWindow Jeu::m_fenetre;