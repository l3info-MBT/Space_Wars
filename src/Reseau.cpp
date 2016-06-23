/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Reseau.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#include "Reseau.h"

Reseau::Reseau() {

}

Reseau::~Reseau(){

}

void Reseau::afficher(sf::RenderWindow& fenetre) {
    if (m_choix_reseau != m_initialiser) m_choix_reseau=m_initialiser;

    Client monclient;
    monclient.seConnecter();
    Cadre mon_cadre = monclient.recupererListePartie();
    std::cout<<mon_cadre.getNbCadre()<<std::endl;
    //Cadre mon_cadre2("FERMER");
    //std::cout<<mon_cadre2.getNbCadre()<<std::endl;
    //Cadre mon_cadre3("FERMER");
    //std::cout<<mon_cadre3.getNbCadre()<<std::endl;

    sf::Texture fond;
    if(!fond.loadFromFile("ressource/fond.png")){
        std::cout<<"Erreur! Impossible de charger l'image de fond"<<std::endl;
        return;
    }
    fond.setSmooth(true);
    fond.setRepeated(false);

    sf::Sprite fond_menu;
    fond_menu.setPosition(0,0);
    fond_menu.setTexture(fond);

    sf::RectangleShape cadre_general;
    cadre_general.setPosition(100,100);
    cadre_general.setSize(sf::Vector2f(600,400));
    cadre_general.setFillColor(sf::Color(0,0,0,105));
    cadre_general.setOutlineThickness(2);
    cadre_general.setOutlineColor(sf::Color(255,255,255,255));

    sf::Text Titre;
    sf::Text Retour;
    sf::Text Creer;
    sf::Text sousTitre;

    sf::Font font;
    if (!font.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur ! Police introuvable"<<std::endl;
        return;
    }

    Titre.setFont(font);
    Titre.setString("MultiJoueur");
    Titre.setOrigin(Titre.getGlobalBounds().width/2.f, Titre.getGlobalBounds().height/2.f);
    Titre.setCharacterSize(50);
    Titre.setPosition(350,10);
    Titre.setColor(sf::Color(255,255,255));
    Titre.setStyle(sf::Text::Bold);

    sousTitre.setFont(font);
    sousTitre.setString("Positioner le cadre sur une partie et appuyer sur Entrer");
    sousTitre.setOrigin(Titre.getGlobalBounds().width/2.f, Titre.getGlobalBounds().height/2.f);
    sousTitre.setCharacterSize(20);
    sousTitre.setPosition(220,80);
    sousTitre.setColor(sf::Color(255,255,255));
    sousTitre.setStyle(sf::Text::Italic);

    Retour.setFont(font);
    Retour.setOrigin(Retour.getGlobalBounds().width/2.f, Retour.getGlobalBounds().height/2.f);
    Retour.setString("R pour Retour");
    Retour.setCharacterSize(20);
    Retour.setPosition(400,550);
    Retour.setColor(sf::Color(255,255,255));

    Creer.setFont(font);
    Creer.setOrigin(Creer.getGlobalBounds().width/2.f, Creer.getGlobalBounds().height/2.f);
    Creer.setString("C pour Creer");
    Creer.setCharacterSize(20);
    Creer.setPosition(200,550);
    Creer.setColor(sf::Color(255,255,255));

    sf::RectangleShape cadre_select;
    cadre_select.setPosition(102,102);
    cadre_select.setSize(sf::Vector2f(596,396/3.f));
    cadre_select.setFillColor(sf::Color(0,0,0,80));
    cadre_select.setOutlineThickness(2);
    cadre_select.setOutlineColor(sf::Color(255,255,255,255));

    sf::SoundBuffer menu_son_selection;
    if(!menu_son_selection.loadFromFile("ressource/son_selection.ogg"))
    {
        std::cerr<<"Impossible de charger la son de selection du menu! "<<std::endl;
    }
    sf::Sound menu_son;
    menu_son.setBuffer(menu_son_selection);
    menu_son.setVolume(30);

    sf::Music menu_musique;
    if(!menu_musique.openFromFile("ressource/musique.ogg"))
    {
        std::cout<<"Musique d'ambiance introuvable"<<std::endl;
    }
    menu_musique.setVolume(50);
    menu_musique.setLoop(true);
    menu_musique.play();

    sf::Event event;
    while (fenetre.isOpen()) {

        fenetre.clear();
        fenetre.draw(fond_menu);
        fenetre.draw(cadre_general);
        fenetre.draw(cadre_select);
        fenetre.draw(Titre);
        fenetre.draw(sousTitre);

        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                fenetre.close();
                return;
            }

            int keyghosting =0;
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape: {
                        m_choix_reseau = m_quitter;
                        return;
                        break;
                    }

                    case sf::Keyboard::BackSpace: {
                        m_choix_reseau = m_retour;
                        return;
                        break;
                    }

                    case sf::Keyboard::Up: {
                        keyghosting++;
                        if (keyghosting%2) {
                            if (cadre_select.getPosition().y > 132) cadre_select.move(sf::Vector2f(0,-132));
                            menu_son.play();
                        }
                        break;
                    }
                    case sf::Keyboard::Down: {
                        keyghosting++;
                        if (keyghosting%2) {
                            if (cadre_select.getPosition().y < 332) cadre_select.move(sf::Vector2f(0,+132));
                            menu_son.play();
                        }
                        break;
                    }

                    case  sf::Keyboard::Return:{
                        if (cadre_select.getPosition().y < 190){
                        monclient.rejoindreUnePartie(fenetre);
                        Multi jeu_multi;
                        jeu_multi.afficher(fenetre);
                        }
                        else std::cout<<"La partie n'existe pas"<<std::endl;
                        break;
                    }

                    case sf::Keyboard::C:{
                        m_choix_reseau = m_creer_partie;
                        monclient.creerUnePartie();
                        break;
                    }

                    case sf::Keyboard::R:{
                        m_choix_reseau = m_retour;
                        return;
                        break;
                    }
                    default:
                        break;

                }
            }
        }
        mon_cadre.afficher_cadre(fenetre);
        //mon_cadre2.afficher_cadre(fenetre);
        //mon_cadre3.afficher_cadre(fenetre);
        fenetre.draw(cadre_select);
        fenetre.draw(Creer);
        fenetre.draw(Retour);
        fenetre.display();

        if (m_choix_reseau == m_retour) return;
        if (m_choix_reseau == m_quitter) return;
    }

}
Reseau::Choix_Reseau Reseau::m_choix_reseau = m_initialiser;