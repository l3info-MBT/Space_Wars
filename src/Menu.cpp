/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Menu.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#include "Menu.h"
#include "interpolate.h"

Menu::Menu()
{
    m_choix_menu = m_non_initialiser;
}

Menu::~Menu()
{

}

void Menu::afficher(sf::RenderWindow& fenetre)
{
    if(!m_choix_menu == m_non_initialiser) return;
    m_choix_menu = m_indecis;

    //Création des Ressources Menu
    sf::Font police_menu;
    if(!police_menu.loadFromFile("ressource/fonts.ttf"))
    {
        std::cerr<<"Impossible de charger la police d'écriture."<<std::endl;
    }

    sf::Texture fond_menu;
    if(!fond_menu.loadFromFile("ressource/fond.png"))
    {
        std::cerr<<"Impossible de charger l'image de fond."<<std::endl;
    }
    fond_menu.setSmooth(true);

    sf::Sprite fond;
    fond.setTexture(fond_menu);
    fond.setPosition(0,0);

    sf::Text titre ("SPACE WARS",police_menu,50);
    titre.setOrigin(titre.getGlobalBounds().width/2.f, titre.getGlobalBounds().height/2.f);
    titre.setPosition(800/2.f, 600/6.f);
    titre.setColor(sf::Color(255,255,255,255));
    titre.setStyle(sf::Text::Underlined);

    sf::Text subtitle("...Ceci n'est pas un clone de Space Invaders!", police_menu, 24);
    subtitle.setOrigin(subtitle.getGlobalBounds().width/2.f, subtitle.getGlobalBounds().height/2.f);
    subtitle.setPosition(titre.getPosition().x, titre.getPosition().y + (titre.getGlobalBounds().height * 2.f));
    subtitle.setColor(sf::Color(0,255,255,255));

    sf::Text solo("Jeu Solo", police_menu, 35);
    solo.setOrigin(0.f, solo.getGlobalBounds().height/2.f);
    solo.setPosition(40, fenetre.getSize().y/2.f);

    sf::Text reseau("Multijoueur", police_menu, 35);
    reseau.setOrigin(0.f, reseau.getGlobalBounds().height/2.f);
    reseau.setPosition(40, solo.getPosition().y + (solo.getGlobalBounds().height * 2.0f));

    sf::Text quitter("Quitter", police_menu, 35);
    quitter.setOrigin(0.f, quitter.getGlobalBounds().height/2.f);
    quitter.setPosition(40, reseau.getPosition().y + (reseau.getGlobalBounds().height * 2.0f));


    //mask for fade in/out
    sf::RectangleShape masque;
    masque.setSize(sf::Vector2f(fenetre.getSize().x,fenetre.getSize().y));
    masque.setPosition(0,0);
    masque.setFillColor(sf::Color(0,0,0,255));

    sf::SoundBuffer menu_son_selection;
    if(!menu_son_selection.loadFromFile("ressource/son_selection.ogg"))
    {
        std::cerr<<"Impossible de charger la son de selection du menu! "<<std::endl;
    }
    sf::Sound menu_son;
    menu_son.setBuffer(menu_son_selection);
    menu_son.setVolume(50);

    sf::Music menu_musique;
    if(!menu_musique.openFromFile("ressource/musique.ogg"))
    {
        std::cout<<"Musique d'ambiance introuvable"<<std::endl;
    }
    menu_musique.setVolume(50);
    menu_musique.setLoop(true);
    menu_musique.play();

    //housekeeping variables for keeping track of the selection
    std::size_t selection = 0;
    std::size_t boundcount = 0;
    std::size_t hovercount = 0;

    bool running = true;
    sf::Event e;

    //time stuff...
    sf::Clock tickClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    sf::Time fadeInFrames = sf::Time::Zero;
    sf::Time moveText = sf::Time::Zero;
    sf::Time colorChanger = sf::Time::Zero;
    int couleurSwitch = 1;

    while(running)
    {
        while(fenetre.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                m_choix_menu = m_quitter;
                return;
            }

            if(e.type == sf::Event::KeyPressed)
            {
                switch(e.key.code)
                {
                    case sf::Keyboard::Escape:
                    {
                        m_choix_menu = m_quitter;
                        return;
                        break;
                    }

                    case sf::Keyboard::Return:
                    {
                        return;
                        break;
                    }
                    case sf::Keyboard::M:
                    {
                        if (menu_musique.getStatus()== sf::SoundStream::Playing) menu_musique.pause();
                        if (menu_musique.getStatus()== sf::SoundStream::Paused) menu_musique.play();
                        return;
                        break;
                    }
                    case sf::Keyboard::Up:
                    {
                        if(selection <= 0)
                        {
                            boundcount++;
                            selection = 0;
                            std::cout<<"bound count : "<<boundcount<<std::endl;
                        }
                        else
                        {
                            selection--;
                            boundcount = 0;
                            std::cout<<"bound count : "<<boundcount<<std::endl;
                        }

                        if(boundcount == 0)
                            menu_son.play();
                    }
                        break;

                    case sf::Keyboard::Down:
                    {
                        if(selection >= 2)
                        {
                            boundcount++;
                            selection = 2;
                            std::cout<<"bound count : "<<boundcount<<std::endl;
                        }
                        else
                        {
                            boundcount = 0;
                            selection++;
                            std::cout<<"bound count : "<<boundcount<<std::endl;
                        }

                        if(boundcount == 0)
                            menu_son.play();
                    }
                        break;

                    default:
                        break;
                }
            }

            sf::Vector2i mousepos = sf::Mouse::getPosition(fenetre);
            if(mousepos.x >= solo.getPosition().x
               && mousepos.y >= solo.getPosition().y
               && mousepos.x <= solo.getPosition().x + solo.getGlobalBounds().width
               && mousepos.y <= solo.getPosition().y + solo.getGlobalBounds().height)
            {
                //on définite la selection et on tiens compte du hover
                selection = 0;
                hovercount++;

                // Gestion de son pour la souris
                if(hovercount == 1)//parce qu'il y a plusieurs évenements et que l'on veut que le premier
                {
                    menu_son.play();
                }
                else
                {
                    if(menu_son.getStatus() != sf::Sound::Playing)
                        menu_son.stop(); // on tue le son pour éviter la répètitions
                }

                if(e.type == sf::Event::MouseButtonPressed)
                {
                    return;
                }

            }

            else if(mousepos.x >= reseau.getPosition().x
                    && mousepos.y >= reseau.getPosition().y
                    && mousepos.x <= reseau.getPosition().x + reseau.getGlobalBounds().width
                    && mousepos.y <= reseau.getPosition().y + reseau.getGlobalBounds().height)
            {

                selection = 1;
                hovercount++;


                if(hovercount == 1)
                {
                    menu_son.play();
                }
                else
                {
                    if(menu_son.getStatus() != sf::Sound::Playing)
                        menu_son.stop();
                }

                if(e.type == sf::Event::MouseButtonPressed)
                {
                    return;
                }
            }

            else if(mousepos.x >= quitter.getPosition().x
                    && mousepos.y >= quitter.getPosition().y
                    && mousepos.x <= quitter.getPosition().x + quitter.getGlobalBounds().width
                    && mousepos.y <= quitter.getPosition().y + quitter.getGlobalBounds().height)
            {

                selection = 2;
                hovercount++;

                if(hovercount == 1)
                {
                    menu_son.play();
                }
                else
                {

                    if(menu_son.getStatus() != sf::Sound::Playing)
                        menu_son.stop();
                }

                if(e.type == sf::Event::MouseButtonPressed)
                {
                    return;
                }
            }
            else
                hovercount = 0;
        }

        timeSinceLastUpdate += tickClock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            fadeInFrames += TimePerFrame;

            if(fadeInFrames.asSeconds() < 1.f)
                masque.setFillColor(sf::Color(0,0,0,255-(unsigned int)interpolate::sineEaseIn(fadeInFrames.asSeconds(),0.f,255.f,1.f)));

            if(fadeInFrames.asSeconds() > 1.f)
            {
                moveText += TimePerFrame;

                if(colorChanger.asSeconds() > 3.f)
                {
                    colorChanger = sf::Time::Zero;
                    couleurSwitch *= -1;
                }

                else
                    colorChanger += TimePerFrame;

                float r = interpolate::sineEaseIn(colorChanger.asSeconds(),0.f,255.f,2.f);
                float b = interpolate::sineEaseIn(colorChanger.asSeconds(),0.f,255.f,2.f);

                //visual indicators of selection made
                //as well as setting the choice enum accordingly
                //to trigger the proper state
                if(moveText.asSeconds() < 1.f)
                {
                    solo.move((800*.01f)*interpolate::backEaseInOut(moveText.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    reseau.move((800*.01f)*interpolate::backEaseInOut(moveText.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    quitter.move((800*.01f)*interpolate::backEaseInOut(moveText.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }

                switch(selection)
                {
                    case 0:
                    {
                        m_choix_menu = m_menu_solo;
                        solo.setColor(sf::Color(55,55,255,255));
                        reseau.setColor(sf::Color(255,255,255,255));
                        quitter.setColor(sf::Color(255,255,255,255));
                    }
                        break;

                    case 1:
                    {
                        m_choix_menu =  m_menu_reseau;
                        solo.setColor(sf::Color(255,255,255,255));
                        reseau.setColor(sf::Color(55,55,255,255));
                        quitter.setColor(sf::Color(255,255,255,255));
                    }
                        break;

                    case 2:
                    {
                        m_choix_menu = m_quitter;
                        solo.setColor(sf::Color(255,255,255,255));
                        reseau.setColor(sf::Color(255,255,255,255));
                        quitter.setColor(sf::Color(55,55,255,255));
                    }
                        break;

                    default:
                        break;
                }


                if(couleurSwitch == 1 && r < 255)
                    titre.setColor(sf::Color(255, 255, 255-b, 255));
                if(couleurSwitch == -1 && r < 255)
                    titre.setColor(sf::Color(255, 255, b, 255));
            }
        }

        fenetre.clear();
        fenetre.draw(fond);
        fenetre.draw(titre);
        fenetre.draw(subtitle);
        fenetre.draw(solo);
        fenetre.draw(reseau);
        fenetre.draw(quitter);
        fenetre.draw(masque);
        fenetre.display();
    }
    return;
}

 Menu::Choix_Menu Menu::m_choix_menu= m_non_initialiser;


