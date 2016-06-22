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

    sf::Texture fond_menu;
    sf::Sprite menu_background;
    sf::Font font1,font2;
    sf::Text text1,text2,textcadre1,textcadre2,textcadre3,textcadre4,textcadre5,textcadre6,textcadre7,textcadre8,textcadre9,textcadre10,textcadre11,textcadre12,textcadre13,textcadre14,textcadre15,textcadre16,textcadre17,textcadre18,textcadre19,textcadre20,textcadre21,textcadre22;
    Cadre cad;
    sf::RectangleShape cadre1,cadre2,cadre3,cadre4;
    sf::CircleShape circle1,circle2,circle3;
    Client monclient;
    monclient.seConnecter();
    monclient.recupererListePartie();

//background
    if (!fond_menu.loadFromFile("ressource/fond_menu.png"))
    {
        std::cout<<"error de charge l'image background"<<std::endl;
        return;
    }
    else
    {
        fond_menu.setSmooth(true);
        menu_background.setTexture(fond_menu);
    }
    //font1 pour afficher "RESEAU DISPONIBLE" qui utilise text1
    if (!font1.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher fonts.ttf"<<std::endl;
        return;
    }
    else
    {
        text1.setFont(font1);
        text1.setString("RESEAUX DISPONIBLE");
        text1.setCharacterSize(20);
        text1.setPosition(60,10);
        text1.setColor(sf::Color(255,255,255));
        //text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
    //font1 pour afficher "retour" qui utilise text2
    if (!font2.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher fonts.ttf"<<std::endl;
        return;
    }
    else
    {
        text2.setFont(font2);
        text2.setString("RETOUR");
        text2.setCharacterSize(20);
        text2.setPosition(650,15);
        text2.setColor(sf::Color(255,255,255));
        //text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }

    //premier rectangele border en haut
    sf::RectangleShape borderhaut1;
    borderhaut1.setSize(sf::Vector2f(680, 5));//longeur largeur
    borderhaut1.setPosition(60,45);
    borderhaut1.setFillColor(sf::Color(255,255,255));

    //premier rectangele border à gauche
    sf::RectangleShape bordergauche1;
    bordergauche1.setSize(sf::Vector2f(5, 375));
    bordergauche1.setPosition(60, 45);
    bordergauche1.setFillColor(sf::Color(255,255,255));

    //premier rectangele border à droit
    sf::RectangleShape borderdroit1;
    borderdroit1.setSize(sf::Vector2f(5,375));
    borderdroit1.setPosition(735, 45);
    borderdroit1.setFillColor(sf::Color(255,255,255));

    //premier rectangele border en bas
    sf::RectangleShape borderbas1;
    borderbas1.setSize(sf::Vector2f(680, 5));
    borderbas1.setPosition(60,420);
    borderbas1.setFillColor(sf::Color(255,255,255));


    //deuxième rectangele border en haut
    sf::RectangleShape borderhaut2;
    borderhaut2.setSize(sf::Vector2f(680, 5));//longeur largeur
    borderhaut2.setPosition(60,445);
    borderhaut2.setFillColor(sf::Color(255,255,255));

    //deuxième rectangele border à gauche
    sf::RectangleShape bordergauche2;
    bordergauche2.setSize(sf::Vector2f(5,120));
    bordergauche2.setPosition(60, 445);
    bordergauche2.setFillColor(sf::Color(255,255,255));

    //deuxième rectangele border à droit
    sf::RectangleShape borderdroit2;
    borderdroit2.setSize(sf::Vector2f(5,120));
    borderdroit2.setPosition(735,445);
    borderdroit2.setFillColor(sf::Color(255,255,255));

    //deuxième rectangele border en bas
    sf::RectangleShape borderbas2;
    borderbas2.setSize(sf::Vector2f(680, 5));
    borderbas2.setPosition(60,565);
    borderbas2.setFillColor(sf::Color(255,255,255));


    //border selecteur en haut
    sf::RectangleShape border_selecteur_haut;
    border_selecteur_haut.setSize(sf::Vector2f(652, 2));//longeur largeur
    border_selecteur_haut.setPosition(74,62);
    border_selecteur_haut.setFillColor(sf::Color(255,255,255));

    //border selecteur à gauche
    sf::RectangleShape border_selecteur_gauche;
    border_selecteur_gauche.setSize(sf::Vector2f(2, 94));//longeur largeur
    border_selecteur_gauche.setPosition(73,63);
    border_selecteur_gauche.setFillColor(sf::Color(255,255,255));

    //border selecteur à droit
    sf::RectangleShape border_selecteur_droit ;
    border_selecteur_droit.setSize(sf::Vector2f(2, 94));//longeur largeur
    border_selecteur_droit.setPosition(725,63);
    border_selecteur_droit.setFillColor(sf::Color(255,255,255));

    //border selecteur en bas
    sf::RectangleShape border_selecteur_bas ;
    border_selecteur_bas.setSize(sf::Vector2f(652,2));//longeur largeur
    border_selecteur_bas.setPosition(74,155);
    border_selecteur_bas.setFillColor(sf::Color(255,255,255));


    while (fenetre.isOpen()) {
        sf::Event event;
        fenetre.clear();
        fenetre.draw(menu_background);
        fenetre.draw(text1);
        fenetre.draw(text2);

        fenetre.draw(borderhaut1);
        fenetre.draw(bordergauche1);
        fenetre.draw(borderdroit1);
        fenetre.draw(borderbas1);

        fenetre.draw(borderhaut2);
        fenetre.draw(bordergauche2);
        fenetre.draw(borderdroit2);
        fenetre.draw(borderbas2);


        fenetre.draw(border_selecteur_haut);
        fenetre.draw(border_selecteur_gauche);
        fenetre.draw(border_selecteur_droit);
        fenetre.draw(border_selecteur_bas);


        //gerer les 4 cadres
        int text1_x = 80;
        int text1_y = 70;           //position de "Nom du reseau" dans cadre1 
        int text2_x = 80;
        int text2_y = 70 + 120;       //position de "Nom du reseau" dans cadre2
        int text3_x = 80;
        int text3_y = 70 + 240;       //position de "Nom du reseau" dans cadre3

        int text4_x = 350;
        int text4_y = 110;         //position "Creer le:" dans cadre1
        int text5_x = 350;
        int text5_y = 230;         //position "Creer le:" dans cadre2
        int text6_x = 350;
        int text6_y = 350;         //position "Creer le:" dans cadre3

        int text7_x = 385;
        int text7_y = 90;          //position VIDE  dans cadre 1
        int text8_x = 385;
        int text8_y = 210;         //position VIDE  dans cadre 2
        int text9_x = 385;
        int text9_y = 330;         //position VIDE  dans cadre 3 

        int text10_x = 290;
        int text10_y = 70;        //variable de Nom du reseaux cadre1
        int text11_x = 290;
        int text11_y = 190;       //variable de Nom du reseaux cadre2
        int text12_x = 290;
        int text12_y = 190 + 120;   //variable de Nom du reseaux cadre3

        int text13_x = 120;
        int text13_y = 110;       //nbr connecteur dans cadre 1
        int text14_x = 120;
        int text14_y = 230;       //nbr connecteur dans cadre 2
        int text15_x = 120;
        int text15_y = 350;       //nbr connecteur dans cadre 3      

        int text16_x = 480;
        int text16_y = 110;       //position de date dans cadre 1
        int text17_x = 480;
        int text17_y = 230;       //position de date dans cadre 2
        int text18_x = 480;
        int text18_y = 350;       //position de date dans cadre 3

        int text19_x = 80;
        int text19_y = 450;       //position de "Nom du reseaux:" dans cadre4
        int text20_x = 80;
        int text20_y = 480;       //position "Creer le:" dans cadre4
        int text21_x = 80;
        int text21_y = 510;       //position "Etat:" dans cadre4
        int text22_x = 420;
        int text22_y = 510;       //position "Nombre de place:"  dans cadre4

        //gerer les terme affiche dans les cadres
        std::string terme1("Nom du reseaux:");
        std::string terme2("Creer le:");
        std::string terme3("VIDE");
        std::string terme4("Etat:");
        std::string terme5("Nombre de place:");

        //ajouter les cadres
        int x = 75;
        int y = 65;  //x,y sont les position des cadres
        cadre1 = cad.ajoutercadre1(cadre1, x, y);
        cadre2 = cad.ajoutercadre2(cadre2, x, y + 120);
        cadre3 = cad.ajoutercadre3(cadre3, x, y + 240);
        cadre4 = cad.ajoutercadre4(cadre4, 65, 450);

        //ajouter le terme "Nom de reseaux:" dans les cadres
        textcadre1 = cad.ajouterterme1(textcadre1, text1_x, text1_y, terme1);
        textcadre2 = cad.ajouterterme1(textcadre2, text2_x, text2_y, terme1);
        textcadre3 = cad.ajouterterme1(textcadre3, text3_x, text3_y, terme1);

        //ajouter terme "Cree le"
        textcadre4 = cad.ajouterterme2(textcadre4, text4_x, text4_y, terme2);
        textcadre5 = cad.ajouterterme2(textcadre5, text5_x, text5_y, terme2);
        textcadre6 = cad.ajouterterme2(textcadre6, text6_x, text6_y, terme2);

        //ajouter terme  "Vide"
        textcadre7 = cad.ajouterterme3(textcadre7, text7_x, text7_y, terme3);
        textcadre8 = cad.ajouterterme3(textcadre8, text8_x, text8_y, terme3);
        textcadre9 = cad.ajouterterme3(textcadre9, text9_x, text9_y, terme3);

        //ajouter les variables de Nom du reseaux    ep. Nom du reseaux:toto alors ajoute toto
        std::string nomvar1 = "Super Joueur";
        textcadre10 = cad.afficherNom1(textcadre10, text10_x, text10_y, nomvar1);
        std::string nomvar2 = "debrouille";
        textcadre11 = cad.afficherNom2(textcadre11, text11_x, text11_y, nomvar2);
        std::string nomvar3 = "debudant";
        textcadre12 = cad.afficherNom3(textcadre12, text12_x, text12_y, nomvar3);


        //afficher le nbr de connecteur
        int nbr1 = 1;
        int nbr2 = 1;
        int nbr3 = 2;
        textcadre13 = cad.nbrconnect1(textcadre13, text13_x, text13_y, nbr1);
        textcadre14 = cad.nbrconnect2(textcadre14, text14_x, text14_y, nbr2);
        textcadre15 = cad.nbrconnect3(textcadre15, text15_x, text15_y, nbr3);


        //ajouter le circle  si nbr<=2 green si nbr==2 red
        int cx1 = 100;
        int cy1 = 120;
        circle1 = cad.ajouter_circle(circle1, nbr1, cx1, cy1);     //dans 1ere cadre
        circle2 = cad.ajouter_circle(circle2, nbr2, cx1, cy1 + 120); //dans 2ime cadre
        circle3 = cad.ajouter_circle(circle3, nbr3, cx1, cy1 + 240); //dans 3ime cadre

        //afficher terme "Nom du reseaux:" dans cadre4 
        textcadre19 = cad.ajouterterme1(textcadre19, text19_x, text19_y, terme1);
        //afficher terme "Creer le:" dans cadre4 
        textcadre20 = cad.ajouterterme2(textcadre20, text20_x, text20_y, terme2);
        //afficher terme "Etat:" dans cadre4  
        textcadre21 = cad.ajouterterme4(textcadre21, text21_x, text21_y, terme4);
        //afficher terme "Nombre de place:" dans cadre4 
        textcadre22 = cad.ajouterterme5(textcadre22, text22_x, text22_y, terme5);

        //current date/time based on current system
        time_t now = time(0);
        tm *ltm = localtime(&now);

        //change type int au type string
        int day = ltm->tm_mday;        //jour
        std::stringstream ss1;
        std::string strday;
        ss1 << day;
        ss1 >> strday;
        int mois = 1 + ltm->tm_mon;     //mois
        std::stringstream ss2;
        std::string strmois;
        ss2 << mois;
        ss2 >> strmois;
        int an = 1900 + ltm->tm_year;   //année
        std::stringstream ss3;
        std::string stran;
        ss3 << an;
        ss3 >> stran;
        int heur = ltm->tm_hour;      //heur
        std::stringstream ss4;
        std::string strheur;
        ss4 << heur;
        ss4 >> strheur;
        int min = 1 + ltm->tm_min;    //minute
        std::stringstream ss5;
        std::string strmin;
        ss5 << min;
        ss5 >> strmin;


        std::string date1 = strday + '/' + strmois + '/' + stran + '-' + strheur + ':' + strmin;
        std::string date2 = strday + '/' + strmois + '/' + stran + '-' + strheur + ':' + strmin;
        std::string date3 = strday + '/' + strmois + '/' + stran + '-' + strheur + ':' + strmin;
        //ajouter les dates
        textcadre16 = cad.date1(textcadre16, text16_x, text16_y, date1);//date dans 1ieme cadre
        textcadre17 = cad.date2(textcadre17, text17_x, text17_y, date2);//date dans 2ieme cadre
        textcadre18 = cad.date3(textcadre18, text18_x, text18_y, date3);//date dans 3ieme cadre

        //tout abord afficher les 4 cadres 
        fenetre.draw(cadre1);
        fenetre.draw(cadre2);
        fenetre.draw(cadre3);
        fenetre.draw(cadre4);

        bool c1 = true;
        bool c2 = false;
        bool c3 = false;

        // si il existe les infos sur serveur dans 1ere cadre alors affiche
        if (c1 == true) {
            fenetre.draw(textcadre1);    //afficher "Nom du reseaux"
            fenetre.draw(textcadre4);    //afficher "Creer le" 
            fenetre.draw(textcadre10);   //afficher le variable de nom du reseaux 
            fenetre.draw(textcadre13);   //afficher le nbr de connecteur
            fenetre.draw(textcadre16);   //afficher la date de la creation
            fenetre.draw(circle1);       //afficher le circle 
        }

        if (c1 == false) {
            fenetre.draw(textcadre7);
        }

        if (c2 == true) {
            fenetre.draw(textcadre2);    //afficher "Nom du reseaux"
            fenetre.draw(textcadre5);    //afficher "Creer le" 
            fenetre.draw(textcadre11);   //afficher le variable de nom du reseaux 
            fenetre.draw(textcadre14);   //afficher le nbr de connecteur
            fenetre.draw(textcadre17);   //afficher la date de la creation
            fenetre.draw(circle2);       //afficher le circle 
        }
        if (c2 == false) {
            fenetre.draw(textcadre8);
        }

        if (c3 == true) {
            fenetre.draw(textcadre3);    //afficher "Nom du reseaux"
            fenetre.draw(textcadre6);    //afficher "Creer le" 
            fenetre.draw(textcadre12);   //afficher le variable de nom du reseaux 
            fenetre.draw(textcadre15);   //afficher le nbr de connecteur
            fenetre.draw(textcadre18);   //afficher la date de la creation
            fenetre.draw(circle3);       //afficher le circle 
        }
        if (c3 == false) {
            fenetre.draw(textcadre9);
        }


        while (fenetre.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                fenetre.close();

            //obtenir position du border de selecteur
            sf::Vector2f pos_selecteur_haut = border_selecteur_haut.getPosition();
            //pour copier les valeurs 
            sf::Text textcadrecp1, textcadrecp2, textcadrecp3, textcadrecp4;

            int text23_x = 290;
            int text23_y = 450;    //variable de "Nom du reseaux:" dans cadre4   
            int text24_x = 200;
            int text24_y = 480;    //variable de "Creer le:" dans cadre4  
            int text25_x = 150;
            int text25_y = 510;     //variable de "Etat:" dans cadre4 
            int text26_x = 650;
            int text26_y = 510;     //variable de "Nombre de place:" dans cadre4   
            if (pos_selecteur_haut.y == 62 && c1 == true) {
                textcadrecp1 = cad.afficherNomcp(textcadrecp1, text23_x, text23_y, nomvar1);
                textcadrecp2 = cad.datecp(textcadrecp2, text24_x, text24_y, date1);
                textcadrecp3 = cad.etat(textcadrecp3, text25_x, text25_y, nbr1);
                textcadrecp4 = cad.nbrconnectcp(textcadrecp4, text26_x, text26_y, nbr1);

                fenetre.draw(textcadrecp1);
                fenetre.draw(textcadrecp2);
                fenetre.draw(textcadrecp3);
                fenetre.draw(textcadrecp4);

                fenetre.draw(textcadre19);
                fenetre.draw(textcadre20);
                fenetre.draw(textcadre21);
                fenetre.draw(textcadre22);

            }

            if (pos_selecteur_haut.y == 182 && c2 == true) {
                textcadrecp1 = cad.afficherNomcp(textcadrecp1, text23_x, text23_y, nomvar2);
                textcadrecp2 = cad.datecp(textcadrecp2, text24_x, text24_y, date2);
                textcadrecp3 = cad.etat(textcadrecp3, text25_x, text25_y, nbr1);
                textcadrecp4 = cad.nbrconnectcp(textcadrecp4, text26_x, text26_y, nbr2);

                fenetre.draw(textcadrecp1);
                fenetre.draw(textcadrecp2);
                fenetre.draw(textcadrecp3);
                fenetre.draw(textcadrecp4);

                fenetre.draw(textcadre19);
                fenetre.draw(textcadre20);
                fenetre.draw(textcadre21);
                fenetre.draw(textcadre22);
            }

            if (pos_selecteur_haut.y == 302 && c3 == true) {
                textcadrecp1 = cad.afficherNomcp(textcadrecp1, text23_x, text23_y, nomvar3);
                textcadrecp2 = cad.datecp(textcadrecp2, text24_x, text24_y, date3);
                textcadrecp3 = cad.etat(textcadrecp3, text25_x, text25_y, nbr3);
                textcadrecp4 = cad.nbrconnectcp(textcadrecp4, text26_x, text26_y, nbr3);

                fenetre.draw(textcadrecp1);
                fenetre.draw(textcadrecp2);
                fenetre.draw(textcadrecp3);
                fenetre.draw(textcadrecp4);

                fenetre.draw(textcadre19);
                fenetre.draw(textcadre20);
                fenetre.draw(textcadre21);
                fenetre.draw(textcadre22);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                //change position du border de selecteur par key up ou down
                if (pos_selecteur_haut.y != 62 + 240)  //62 est position de border_selecteur_haut
                {
                    border_selecteur_haut.move(0, 120);
                    border_selecteur_gauche.move(0, 120);
                    border_selecteur_droit.move(0, 120);
                    border_selecteur_bas.move(0, 120);
                }
                else {
                    border_selecteur_haut.move(0, -240);
                    border_selecteur_gauche.move(0, -240);
                    border_selecteur_droit.move(0, -240);
                    border_selecteur_bas.move(0, -240);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (pos_selecteur_haut.y != 62) {
                    border_selecteur_haut.move(0, -120);
                    border_selecteur_gauche.move(0, -120);
                    border_selecteur_droit.move(0, -120);
                    border_selecteur_bas.move(0, -120);
                }
                else {
                    border_selecteur_haut.move(0, +240);
                    border_selecteur_gauche.move(0, +240);
                    border_selecteur_droit.move(0, +240);
                    border_selecteur_bas.move(0, +240);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                m_choix_reseau = m_retour;
            }

            fenetre.display();

            if (m_choix_reseau == m_creer_partie) {
                monclient.creerUnePartie(fenetre);
            }
            if (m_choix_reseau == m_rejoindre) {
                monclient.rejoindreUnePartie(fenetre);
            }
            if (m_choix_reseau == m_joue){
            }
            if(m_choix_reseau == m_fin){
                m_choix_reseau = m_initialiser;
            }
            if(m_choix_reseau == m_retour){
                return;
            }
            if (m_choix_reseau==m_quitter){
                return;
            }

        }
    }
}
Reseau::Choix_Reseau Reseau::m_choix_reseau = m_initialiser;

