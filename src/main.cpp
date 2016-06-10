//
//Fichier Cpp - Projet Space Wars
//Etudiant: Deborguere Tony - Tekeli Baris - Touat Malik - Qi Zhiwen
//
//===================================================================
//
// Régle de nommage des fonctions:
//      - Majuscule à chaque mot sauf le premier (exemple: maSuperFonction()).
//      - Nom explicite commençant par un verbe.
// 
// Régle de nommage des variable:
//      - écrit en minusicle avec une  '_' pour séparer chaque mot (exemple: ma_super_variable).
//      - Nom explicite.
//
// Régle de nommage des Classe:
//      - Commençant par une Majuscule, mot séparé par un '_' (exemple: Ma_Classe).
//      - Nom explicite.
//
// Régle de nommage des fichiers sources:
//      - Nom en minisucule, mot séparer par un '_'.
//      - Nom explicite.
//
// Commentaire:
//      - Voir pour résoudre le fais que les appuies sur le clavier se fasse deux fois.
//      - Penser à séparer le code.
//
//===================================================================
//

/*=========================================================================================================================*/
/*                                              Inclusion                                                                  */
/*=========================================================================================================================*/

// Inclusion des librairies
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Inclusion des Dépendances
#include "icon.hpp"

/*=========================================================================================================================*/
/*                                              Code                                                                       */
/*=========================================================================================================================*/

int main()
{

//Création d'une fenêtre de taille 800,600 nomée space wars avec une barre de titre et une croix pour fermer
    unsigned int ma_width = sf::VideoMode::getDesktopMode().width;
    unsigned int ma_height = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window;
    if (ma_width > 800 && ma_height > 600)
    {
        std::cout<<"test2"<<std::endl;
        window.create(sf::VideoMode(800, 600), "Space Wars", sf::Style::Close | sf::Style::Titlebar);
    }
    else
    {
        std::cout<<"test"<<std::endl;
        window.create(sf::VideoMode(ma_width, ma_height), "Space Wars", sf::Style::Fullscreen );
    }
    window.setPosition(sf::Vector2i(100, 100));
    window.setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);
    window.setVerticalSyncEnabled (true);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(120);
    window.setMouseCursorVisible(false);      

//Création d'une variable - test affichage qui change
    int choix_menu = 0;
    int compteur_input =1;
    sf::Clock clock;

/*=========================================================================================================================*/
/*                                    Création d'une image de fond                                                         */
/*=========================================================================================================================*/

    sf::Texture fond_menu;
    if (!fond_menu.loadFromFile("fond_solo.png"))
    {
        //gestion de l'erreur
        return 1;
    }
    fond_menu.setSmooth(true);
    sf::Sprite menu_background;
    menu_background.setTexture(fond_menu);
    menu_background.setScale(sf::Vector2f(0.45f, 0.45f));
    menu_background.move(-100,0);

/*=========================================================================================================================*/
/*                                    Création d'un titre                                                                  */
/*=========================================================================================================================*/
    sf::Font police_titre;
    if (!police_titre.loadFromFile("fonts.TTF"))
    {
        //gestion de l'erreur
        return 1;
    }

    sf::Font police_reseaux;
    if (!police_reseaux.loadFromFile("fonts3.ttf"))
    {
        //gestion de l'erreur
        return 1;
    }

    sf::Text titre_jeu;
    titre_jeu.setFont(police_titre); 
    titre_jeu.setString("Space Wars");
    titre_jeu.setCharacterSize(50);
    titre_jeu.setColor(sf::Color::White);
    titre_jeu.setStyle(sf::Text::Underlined);
    titre_jeu.setPosition(sf::Vector2f(200, 10));

 
    sf::Text titre_reseaux;
    titre_reseaux.setFont(police_reseaux);
    titre_reseaux.setString(L"Space Wars -Partie Réseaux");
    titre_reseaux.setCharacterSize(50); 
    titre_reseaux.setColor(sf::Color::White);
    titre_reseaux.setStyle(sf::Text::Underlined);
    titre_reseaux.setPosition(sf::Vector2f(150, 10));
    

//Ajout d'un son au menu
    sf::Music musique_menu;
    if (!musique_menu.openFromFile("musique_menu.ogg"))
    {
        // gestion de l'erreur
        return -1;
    }
    musique_menu.play();
    musique_menu.setLoop(true);
    musique_menu.setVolume(100);

//Ajout des choix du menu 
    sf::Font police_menu;
    if (!police_menu.loadFromFile("fonts2.ttf"))
    {
        //gestion de l'erreur
        return 1;
    }
    sf::Text menu_solo;
    menu_solo.setFont(police_menu);
    menu_solo.setString("Jouer");
    menu_solo.setCharacterSize(25);
    menu_solo.setColor(sf::Color::White);
    menu_solo.setPosition(sf::Vector2f(50, 450));
    sf::Text menu_reseaux;
    menu_reseaux.setFont(police_menu);
    menu_reseaux.setString(L"Jouer en Réseaux");
    menu_reseaux.setCharacterSize(25);
    menu_reseaux.setColor(sf::Color::White);
    menu_reseaux.setPosition(sf::Vector2f(50, 500));

    sf::Text menu_solo2;
    menu_solo2.setFont(police_menu);
    menu_solo2.setString("Jouer contre l'ia");
    menu_solo2.setCharacterSize(25);
    menu_solo2.setColor(sf::Color::White);
    menu_solo2.setPosition(sf::Vector2f(50, 500));
    sf::Text menu_reseaux2;
    menu_reseaux2.setFont(police_menu);
    menu_reseaux2.setString(L"Tour par tour");
    menu_reseaux2.setCharacterSize(25);
    menu_reseaux2.setColor(sf::Color::White);
    menu_reseaux2.setPosition(sf::Vector2f(50, 450));

    sf::Text menu_solo3;
    menu_solo3.setFont(police_menu);
    menu_solo3.setString("Jeu Originale");
    menu_solo3.setCharacterSize(25);
    menu_solo3.setColor(sf::Color::White);
    menu_solo3.setPosition(sf::Vector2f(50, 450));
    sf::Text menu_reseaux3;
    menu_reseaux3.setFont(police_menu);
    menu_reseaux3.setString(L"Temps Réel");
    menu_reseaux3.setCharacterSize(25);
    menu_reseaux3.setColor(sf::Color::White);
    menu_reseaux3.setPosition(sf::Vector2f(50, 500));

    sf::Text menu_quitter;
    menu_quitter.setFont(police_menu);
    menu_quitter.setString("Quitter");
    menu_quitter.setCharacterSize(25); 
    menu_quitter.setColor(sf::Color::White);
    menu_quitter.setPosition(sf::Vector2f(50, 550));
    sf::Text menu_retour;
    menu_retour.setFont(police_menu);
    menu_retour.setString("Retour");
    menu_retour.setCharacterSize(25); 
    menu_retour.setColor(sf::Color::White);
    menu_retour.setPosition(sf::Vector2f(50, 550));

//Ajout d'un indicateur menu
    sf::CircleShape selecteur_menu(5);
    // met la couleur transparent dans le cercle
    selecteur_menu.setFillColor(sf::Color::Transparent);
    selecteur_menu.setOutlineThickness(2);
    selecteur_menu.setOutlineColor(sf::Color(255, 255, 255));
    selecteur_menu.setPosition(sf::Vector2f(30, 450));
    selecteur_menu.move(sf::Vector2f(0, 12));

//création d'un cadre semi transparent
    sf::RectangleShape alpha_rectangle_menu(sf::Vector2f(300, 200));
    alpha_rectangle_menu.setFillColor(sf::Color(0, 0, 0, 128));
    alpha_rectangle_menu.setOutlineThickness(2);
    alpha_rectangle_menu.setOutlineColor(sf::Color(255, 255, 255,150));
    alpha_rectangle_menu.setPosition(sf::Vector2f(10, 390));

//Création D'icon  
    sf::Texture icon_son_on_menu;
    if (!icon_son_on_menu.loadFromFile("son_icon_on.png"))
    {
        //gestion de l'erreur
        return 1;
    }
    icon_son_on_menu.setSmooth(true);
    sf::Sprite menu_icon_son;
    menu_icon_son.setTexture(icon_son_on_menu);
    menu_icon_son.setScale(sf::Vector2f(0.10f, 0.10f));
    menu_icon_son.setPosition(sf::Vector2f(90, 400));

//=====================================================//

    sf::Texture icon_son_off_menu;
    if (!icon_son_off_menu.loadFromFile("son_icon_off.png"))
    {
        //gestion de l'erreur
        return 1;
    }
    icon_son_off_menu.setSmooth(true);
    sf::Sprite menu_icon_son_off;
    menu_icon_son_off.setTexture(icon_son_off_menu);
    menu_icon_son_off.setScale(sf::Vector2f(0.10f, 0.10f));
    menu_icon_son_off.setPosition(sf::Vector2f(90, 400));

//=====================================================//

    sf::Texture icon_music_on_menu;
    if (!icon_music_on_menu.loadFromFile("music_on.png"))
    {
        //gestion de l'erreur
        return 1;
    }
    icon_music_on_menu.setSmooth(true);
    sf::Sprite menu_icon_music;
    menu_icon_music.setTexture(icon_music_on_menu);     
    menu_icon_music.setScale(sf::Vector2f(0.10f, 0.10f));
    menu_icon_music.setPosition(sf::Vector2f(120, 400));

//=====================================================//

        sf::Texture icon_music_off_menu;
    if (!icon_music_off_menu.loadFromFile("music_pause.png"))
    {
        //gestion de l'erreur
        return 1;
    }
    icon_music_off_menu.setSmooth(true);
    sf::Sprite menu_icon_music_off;
    menu_icon_music_off.setTexture(icon_music_off_menu);
    menu_icon_music_off.setScale(sf::Vector2f(0.10f, 0.10f));
    menu_icon_music_off.setPosition(sf::Vector2f(120, 400));



// Boucle de traitement
    while (window.isOpen())
    {

    sf::Time frameTime = clock.restart();
    float framerate = 1 / (frameTime.asMilliseconds() * 0.001);
    //std::cout <<"Temp en ms : " << frameTime.asMilliseconds() <<" Fps estimé :"<<framerate << std::endl;


        sf::Event event;
        //on gére les événements
        while (window.pollEvent(event))
        {
            //Création des variables pour la gestion des événements
            sf::Vector2f position_selecteur_menu = selecteur_menu.getPosition();
            sf::Vector2f position_dernier_menu = menu_quitter.getPosition();
            sf::Vector2f position_premier_menu = menu_solo.getPosition();
            float volume_musique = musique_menu.getVolume();
            int status_musique = musique_menu.getStatus();

            // si on clique sur la croix on ferme
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // la touche "flèche bas" est enfoncée : on bouge le selecteur
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (position_selecteur_menu.y <  position_dernier_menu.y)
                {
                    selecteur_menu.move(0, 50);
                }        
                else
                {
                    selecteur_menu.move(0, -100);
                }     
            }
            // la touche "flèche haut" est enfoncée : on bouge le selecteur
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if ( position_selecteur_menu.y == position_premier_menu.y+12)
                {
                    selecteur_menu.move(0, 100);
                }
                else
                {
                    selecteur_menu.move(0, -50);
                }    
            }
            // si on appuie sur la fléche droite on augement le volume
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            // si on appuie sur la fléche droite on augement le volume
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (volume_musique > 1)
                {
                    musique_menu.setVolume(volume_musique-1);
                }  
            }
            // si on appuie sur la fléche droite on augement le volume
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (volume_musique < 99)
                {
                    musique_menu.setVolume(volume_musique+1);
                }   
            }
            //si on appuie sur s on coupe la musique
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                compteur_input ++;
                if ((compteur_input % 2)==0)
                {
                    if (volume_musique !=0) 
                    {
                        musique_menu.setVolume(0.0);
                    }
                    if  (volume_musique == 0) 
                    {
                        musique_menu.setVolume(100.0);
                    }
                }
            }
            //si on appuie sur m on mute la musique
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                compteur_input ++;
                if ((compteur_input % 2)==0)
                {
                    if (status_musique == 2 )musique_menu.pause();
                    if (status_musique == 1 )musique_menu.play();
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                compteur_input ++;
                if ((compteur_input % 2)==0)
                {
                    sf::Mouse::setPosition(sf::Vector2i(30, 462), window);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                compteur_input ++;
                if ((compteur_input % 2)==0)
                {
                    if (position_selecteur_menu.y == 462) 
                    {
                        choix_menu = 1;
                    }
                    if (position_selecteur_menu.y == 512)
                    {
                        choix_menu = 2;
                    }
                    if (position_selecteur_menu.y == 562 && choix_menu ==0)
                    {
                        window.close();
                    }
                    if (position_selecteur_menu.y == 562 && choix_menu !=0)
                    {
                        choix_menu=0;
                    }
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if (localPosition.y==462) std::cout << "jambon" << std::endl;
            }

        }

        switch (choix_menu) 
        {
            case 1:
                window.clear();
                window.draw(menu_background);
                window.draw(alpha_rectangle_menu);
                window.draw(titre_jeu);
                if (musique_menu.getVolume() > 1) window.draw(menu_icon_son);
                if (musique_menu.getVolume() < 1) window.draw(menu_icon_son_off);
                if (musique_menu.getStatus() == 2) window.draw(menu_icon_music);
                if (musique_menu.getStatus() == 1) window.draw(menu_icon_music_off);
                window.draw(menu_solo3);
                window.draw(menu_solo2);
                window.draw(menu_retour);
                window.draw(selecteur_menu);
                window.display();
            break;

            case 2:
                window.clear();
                window.draw(menu_background);
                window.draw(alpha_rectangle_menu);
                window.draw(titre_jeu);
                if (musique_menu.getVolume() > 1) window.draw(menu_icon_son);
                if (musique_menu.getVolume() < 1) window.draw(menu_icon_son_off);
                if (musique_menu.getStatus() == 2) window.draw(menu_icon_music);
                if (musique_menu.getStatus() == 1) window.draw(menu_icon_music_off);
                window.draw(menu_reseaux2);
                window.draw(menu_reseaux3);
                window.draw(menu_retour);
                window.draw(selecteur_menu);
                window.display();
            break;

            default:
                window.clear();
                window.draw(menu_background);
                window.draw(alpha_rectangle_menu);
                window.draw(titre_jeu);
                if (musique_menu.getVolume() > 1) window.draw(menu_icon_son);
                if (musique_menu.getVolume() < 1) window.draw(menu_icon_son_off);
                if (musique_menu.getStatus() == 2) window.draw(menu_icon_music);
                if (musique_menu.getStatus() == 1) window.draw(menu_icon_music_off);
                window.draw(menu_solo);
                window.draw(menu_reseaux);
                window.draw(menu_quitter);
                window.draw(selecteur_menu);
                window.display();
            break;
        }
    }

    return 0;
}
