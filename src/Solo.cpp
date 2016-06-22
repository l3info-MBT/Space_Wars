/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Solo.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */
#include "Solo.h"

Solo::Solo() {

}

Solo::~Solo() {

}

void Solo::pause(sf::RenderWindow& fenetre){
    while (m_solo == m_pause){

        sf::Font police_menu;
        if(!police_menu.loadFromFile("../ressource/fonts.ttf"))
        {
            std::cerr<<"Impossible de charger la police d'écriture."<<std::endl;
        }
        sf::Text pause("PAUSE",police_menu,50);
        pause.setOrigin(pause.getGlobalBounds().width/2.f, pause.getGlobalBounds().height/2.f);
        pause.setPosition(800/2.f, 600/2.f);
        pause.setColor(sf::Color(255,255,255,255));
        pause.setStyle(sf::Text::Underlined);

        sf::RectangleShape grisaille;
        grisaille.setSize(sf::Vector2f(fenetre.getSize().x,fenetre.getSize().y));
        grisaille.setPosition(0,0);
        grisaille.setFillColor(sf::Color(25,25,25,70));

        sf::RectangleShape cadre_pause;
        cadre_pause.setSize(sf::Vector2f(pause.getGlobalBounds().width+50,pause.getGlobalBounds().height+50));
        cadre_pause.setOrigin(pause.getGlobalBounds().width/2.f, pause.getGlobalBounds().height/2.f);
        cadre_pause.setPosition(800/2.f,600/2.f);
        cadre_pause.setFillColor(sf::Color(25,25,25,70));

        sf::Event e;
        while(fenetre.pollEvent(e))
        {
            if(e.type == sf::Event::KeyPressed)
            {
                if(e.key.code==sf::Keyboard::P)
                {
                    m_solo=m_joue;
                }
            }
        }

        fenetre.draw(grisaille);
        fenetre.draw(cadre_pause);
        fenetre.draw(pause);
    }
}

void Solo::afficher(sf::RenderWindow& fenetre) {
    sf::Event e;
    while (fenetre.pollEvent(e)) {
        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::P) {
                m_solo = m_pause;
                this->pause(fenetre);
            }
            if(e.type == sf::Keyboard::Escape)
            {
                m_solo = m_quitter;
                return;
            }
        }
        sf::Font font;
        sf::Text textVie, textScore, sfScore;
        Joueur joueur;
        Alien ali;
        Bouclier boucli;
        Missile miss;
        Collision col;

        float x = 36.00, y = 70.00, yPlus = 45.00;

        int boool = 1, depVaisseauX = 0, cpt1, depAlienX = 0, depAlienY = -50,
                depHorizontal = 0, ok = 5, depMissileY = 525, depMissileX = 0,
                missileVaisseauOk = 2, depMissileAlienX, depMissileAlienY = 0,
                missileAlienOk = 0, viesJoueur = joueur.getNbVie(), score = 000;

        sf::Sprite tabAlien[5][11], tabAlienBis[5][11], tabBouclier[3][16],
                spriteVaisseau, spriteVaisseauExplose, spriteMissileVaisseau,
                spriteMissileAlien, vie1, vie2, vie3;

        sf::Vector2f vecBou, vecAli, vecVai;

        sf::Sound soundExplosionVaisseau, soundTire, soundExplosionAlien;

        //On ajoute 1 vaisseau pour chaque vie.
        vie1 = joueur.ajouterVaisseau(spriteVaisseau, 440, 5);
        vie2 = joueur.ajouterVaisseau(spriteVaisseau, 490, 5);
        vie3 = joueur.ajouterVaisseau(spriteVaisseau, 540, 5);

        // Ligne en dessous de score
        sf::RectangleShape borderTop;
        borderTop.setSize(sf::Vector2f(600, 5));
        borderTop.setPosition(0, 35);
        borderTop.setFillColor(sf::Color(240, 248, 255));

        sf::RectangleShape borderBottom;
        borderBottom.setSize(sf::Vector2f(600, 30));
        borderBottom.setPosition(0, 570);
        borderBottom.setFillColor(sf::Color(240, 248, 255));

        bool tabAlienSup[5][11], tabBouclierSup[3][16], explose = false;
        //Tableau des aliens éliminés, false si éliminé.
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < 11; i++) {
                tabAlienSup[j][i] = true;
            }
        }

        //Tableau des boucliers détruits, false si détruit.
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 16; i++) {
                tabBouclierSup[j][i] = true;
            }
        }

        sf::SoundBuffer bufferExplosionVaisseau, bufferTire, bufferExplosionAlien;
        if (!bufferExplosionVaisseau.loadFromFile("ressource/vaisseauExplosion.wav")) {
            std::cout << "Erreur durant le chargement de vaisseauExplosion.wav" << std::endl;
        }
        else {
            soundExplosionVaisseau.setBuffer(bufferExplosionVaisseau);
        }

        if (!bufferExplosionAlien.loadFromFile("ressource/alienExplosion.wav")) {
            std::cout << "Erreur durant le chargement de alienExplosion.wav" << std::endl;
        }
        else {
            soundExplosionAlien.setBuffer(bufferExplosionAlien);
        }

        if (!bufferTire.loadFromFile("ressource/tire.wav")) {
            std::cout << "Erreur durant le chargement de tire.wav" << std::endl;
        }
        else {
            soundTire.setBuffer(bufferTire);
        }

        ali.alien.setSmooth(true);
        joueur.vaisseau.setSmooth(true);
        boucli.bouclier.setSmooth(true);

        int jeuFini = 0;

        while (fenetre.isOpen()) {

            if (!font.loadFromFile("ressource/fonts.ttf")) {
                std::cout << "Erreur durant le chargement de ficher fonts.ttf" << std::endl;
            }
            else {
                textScore.setFont(font);
                textScore.setString("Score: ");
                textScore.setCharacterSize(30);
                textScore.setPosition(10, 0);
                sfScore.setColor(sf::Color(255, 255, 255));
                textScore.setStyle(sf::Text::Bold);

                std::string scoreString;
                std::ostringstream os;
                os << score;
                scoreString = os.str();

                sfScore.setFont(font);
                sfScore.setString(scoreString);
                sfScore.setCharacterSize(25);
                sfScore.setPosition(180, 5);
                sfScore.setColor(sf::Color(255, 255, 255));
                sfScore.setStyle(sf::Text::Bold);

                textVie.setFont(font);
                textVie.setString("Vie: ");
                textVie.setCharacterSize(30);
                textVie.setPosition(350, 0);
                sfScore.setColor(sf::Color(255, 255, 255));
                textVie.setStyle(sf::Text::Bold);
            }
            //Si le joueur atteint 0 point de vie:
            if (viesJoueur == 0) {
                std::cout << "!!!!! GAME OVER !!!!!" << std::endl;
                m_solo = m_fin;
                return;
            }


            //On parcours le tableau des aliens éliminés.
            for (int j = 0; j < 5; j++) {
                for (int i = 0; i < 11; i++) {
                    //Si l'alien en [j][i] est éliminé:
                    if (!tabAlienSup[j][i])
                        //On incrémente jeuFini.
                        jeuFini += 1;
                }
            }

            //On sait qu'il y a 5 * 11 aliens, soit 55.
            //Si jeuFini = 55:
            if (jeuFini == 55) {
                //Retourner au menu %menu
                std::cout << "!!!!!! Victoire !!!!!!" << std::endl;;
                m_solo = m_fin;
                return;
            }
            else
                //Sinon, on reinitialise jeuFini pour la prochaine vérification.
                jeuFini = 0;


            // random de 1 à 11 pour choisir aléatoirement quel alien dans la rangée horizontal va tirer
            int randomAlienTireX = rand() % 11 + 1;

            // random de 1 à 5 pour choisir aléatoirement quel alien dans la rangée vertical va tirer
            int randomAlienTireY = rand() % 5 + 1;

            // random de 1 à 2, pour que ça tire de façon aléatoire
            int randomAlienMissile = rand() % 2 + 1;

            sf::Event event;

            while (fenetre.pollEvent(event)) {
                //Si l'utilisateur clique sur la croix pour fermer la fenetre du jeu:
                if (event.type == sf::Event::Closed)
                    fenetre.close();

                // déplacer vaisseau à gauche
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //Pour ne pas se déplacer hors de la fenetre.
                if (depVaisseauX > 50)
                    depVaisseauX = depVaisseauX - 10;

                // déplacer vaisseau à droite
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //Pour ne pas se déplacer hors de la fenetre.
                if (depVaisseauX < 500)
                    depVaisseauX = depVaisseauX + 10;

                // tirer avec le vaisseau
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    if (missileVaisseauOk == 2) {
                        soundTire.play();
                        missileVaisseauOk = 0;
                        depMissileY = 525;
                        depMissileX = depVaisseauX;
                    }
                }
            }

            fenetre.clear();

            //spriteVaisseauExplose = joueur.vaisseauExplose(spriteVaisseauExplose, depVaisseauX, 535);
            spriteVaisseau = joueur.ajouterVaisseau(spriteVaisseau, depVaisseauX, 535);
            //app.draw(spriteVaisseau);

            //Si randomAlienMissile tombe sur 1, on peut tirer.
            if (randomAlienMissile == 1) {
                if (missileAlienOk == 2) {
                    missileAlienOk = 0;
                    depMissileAlienX = (x * (randomAlienTireX)) + depAlienX - 8;
                    depMissileAlienY = (y + yPlus * (randomAlienTireY)) + depAlienY + 45;
                }
            }

            if (col.collisionVaisseau(spriteVaisseau, spriteMissileAlien)) {
                spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
                viesJoueur -= 1;
                explose = true;
                //std::cout << " collision vaisseau missile alien" << std::endl;
                //	  app.draw(spriteVaisseau);
                //sleep(1);
                missileAlienOk = 2;
            }

            if (missileVaisseauOk == 0)
                spriteMissileVaisseau = miss.ajouterMissileVaisseau(spriteMissileVaisseau, depMissileX + 21,
                                                                    depMissileY);
            if (missileAlienOk == 0)
                spriteMissileAlien = miss.ajouterMissileAlien(spriteMissileAlien, depMissileAlienX + 21,
                                                              depMissileAlienY);

            // boucliers
            int dix = 450, vingt = 90, quatre = 0;
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 16; i++) {
                    if (tabBouclierSup[j][i]) {
                        tabBouclier[j][i] = boucli.ajouterBouclier(tabBouclier[j][i], vingt + 160 * j, dix);
                        fenetre.draw(tabBouclier[j][i]);
                    }
                    vingt = vingt + 20;
                    quatre = quatre + 1;
                    if (vingt == 170)
                        vingt = 90;
                    if (quatre == 4) {
                        dix = dix + 10;
                        quatre = 0;
                    }
                    if (col.collisionBouclier(tabBouclier[j][i], spriteMissileVaisseau)) {
                        vecBou = boucli.getPosition(tabBouclier[j][i]);
                        if (vecBou.y + 10 == depMissileY) {
                            spriteMissileVaisseau = miss.supprimerMissile(spriteMissileVaisseau);
                            tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
                            tabBouclierSup[j][i] = false;
                            missileVaisseauOk = 2;
                        }
                    }
                    if (col.collisionBouclier(tabBouclier[j][i], spriteMissileAlien)) {
                        spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
                        tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
                        tabBouclierSup[j][i] = false;
                        missileAlienOk = 2;
                    }

                }
                dix = 450;
                vingt = 90;
            }

            for (int j = 0; j < 5; j++) {
                for (int i = 0; i < 11; i++) {
                    // Colision missile alien - alien
                    if (col.collisionAlien(tabAlien[j][i], spriteMissileAlien)) {
                        vecAli = ali.getPosition(tabAlien[j][i]);
                        if (vecAli.y + 20 == depMissileAlienY) {
                            spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
                            missileAlienOk = 2;
                        }
                    }

                    // Colision missile vaisseau - alien
                    if (col.collisionAlien(tabAlien[j][i], spriteMissileVaisseau)) {
                        vecVai = ali.getPosition(tabAlien[j][i]);
                        if (vecVai.y + 20 == depMissileY) {
                            soundExplosionAlien.play();
                            tabAlienSup[j][i] = false;
                            spriteMissileVaisseau = miss.supprimerMissile(spriteMissileVaisseau);
                            tabAlien[j][i] = miss.supprimerMissile(tabAlien[j][i]);
                            tabAlienBis[j][i] = miss.supprimerMissile(tabAlienBis[j][i]);
                            missileVaisseauOk = 2;
                            if (j==0 || j==1) score += 10;
                            if (j==2 || j==3) score += 20;
                            if (j==4 ) score += 50;
                        }
                    }
                }
            }

            // aliens
            if (boool > 50) {
                for (cpt1 = 0; cpt1 < 11; cpt1++) {
                    //On vérifie s'ils sont éliminés.
                    if (tabAlienSup[0][cpt1])
                        // alien ligne 1 (en partant du bas)
                        tabAlien[0][cpt1] = ali.ajouterAlien1_1(tabAlien[0][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                (y + yPlus * 5) + depAlienY);
                    fenetre.draw(tabAlien[0][cpt1]);

                    if (tabAlienSup[1][cpt1])
                        // alien ligne 2 (en partant du bas)
                        tabAlien[1][cpt1] = ali.ajouterAlien1_1(tabAlien[1][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                (y + yPlus * 4) + depAlienY);
                    fenetre.draw(tabAlien[1][cpt1]);

                    if (tabAlienSup[2][cpt1])
                        // alien ligne 3 (en partant du bas)
                        tabAlien[2][cpt1] = ali.ajouterAlien2_1(tabAlien[2][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                (y + yPlus * 3) + depAlienY);
                    fenetre.draw(tabAlien[2][cpt1]);

                    if (tabAlienSup[3][cpt1])
                        // alien ligne 4 (en partant du bas)
                        tabAlien[3][cpt1] = ali.ajouterAlien2_1(tabAlien[3][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                (y + yPlus * 2) + depAlienY);
                    fenetre.draw(tabAlien[3][cpt1]);

                    if (tabAlienSup[4][cpt1])
                        // alien ligne 5 (en partant du bas)
                        tabAlien[4][cpt1] = ali.ajouterAlien3_1(tabAlien[4][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                (y + yPlus * 1) + depAlienY);
                    fenetre.draw(tabAlien[4][cpt1]);
                }
            } else if (boool < 50) {
                for (cpt1 = 0; cpt1 < 11; cpt1++) {
                    if (tabAlienSup[0][cpt1])
                        // alien 1 bis (en partant du bas)
                        tabAlienBis[0][cpt1] = ali.ajouterAlien1_2(tabAlienBis[0][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                   (y + yPlus * 5) + depAlienY);
                    fenetre.draw(tabAlienBis[0][cpt1]);

                    if (tabAlienSup[1][cpt1])
                        // alien 2 bis (en partant du bas)
                        tabAlienBis[1][cpt1] = ali.ajouterAlien1_2(tabAlienBis[1][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                   (y + yPlus * 4) + depAlienY);
                    fenetre.draw(tabAlienBis[1][cpt1]);

                    if (tabAlienSup[2][cpt1])
                        // alien 3 bis (en partant du bas)
                        tabAlienBis[2][cpt1] = ali.ajouterAlien2_2(tabAlienBis[2][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                   (y + yPlus * 3) + depAlienY);
                    fenetre.draw(tabAlienBis[2][cpt1]);

                    if (tabAlienSup[3][cpt1])
                        // alien 4 bis (en partant du bas)
                        tabAlienBis[3][cpt1] = ali.ajouterAlien2_2(tabAlienBis[3][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                   (y + yPlus * 2) + depAlienY);
                    fenetre.draw(tabAlienBis[3][cpt1]);

                    if (tabAlienSup[4][cpt1])
                        // alien 5 bis (en partant du bas)
                        tabAlienBis[4][cpt1] = ali.ajouterAlien3_2(tabAlienBis[4][cpt1], (x * (cpt1 + 1)) + depAlienX,
                                                                   (y + yPlus * 1) + depAlienY);
                    fenetre.draw(tabAlienBis[4][cpt1]);
                }
            }

            // fin test.
            if (boool == 100)
                boool = 0;
            else
                boool += 1;

            if (depMissileY == 40) {
                missileVaisseauOk = 2;
                depMissileY = 40;
            }
            else {
                depMissileY -= 5;
                fenetre.draw(spriteMissileVaisseau);
            }

            if (depMissileAlienY == 575) {
                //nazerkkm
                missileAlienOk = 2;
                depMissileAlienY = 600;
            }
            else {
                depMissileAlienY += 5;
                fenetre.draw(spriteMissileAlien);
            }

            if (depHorizontal == 50) {
                if (depAlienX > 130) {
                    if (ok != 5) {
                        depAlienY += 10;
                        // si la vague descend trop
                        if (depAlienY == 140) {
                            // le vaisseau perd 1 point de vie.
                            viesJoueur -= 1;
                            explose = true;
                            //		      app.draw(spriteVaisseau);
                            //sleep(1);
                            depAlienY -= 40;
                        }
                    }
                    ok = 1;
                }
                if (depAlienX == 0) {
                    if (ok != 5) {
                        depAlienY += 10;
                        // si la vague descend trop
                        if (depAlienY == 140) {
                            // le vaisseau perd 1 point de vie.
                            viesJoueur -= 1;
                            explose = true;
                            //		      app.draw(spriteVaisseau);
                            //sleep(1);
                            depAlienY -= 40;
                        }
                    }
                    ok = 0;
                }

                if (ok == 0)
                    depAlienX += 132 / 18;
                if (ok == 1)
                    depAlienX -= 132 / 18;

                depHorizontal = 0;
            }
            else
                depHorizontal += 1;

            if (explose) {
                spriteVaisseauExplose = joueur.vaisseauExplose(spriteVaisseauExplose, depVaisseauX, 535);
                fenetre.draw(spriteVaisseauExplose);
                soundExplosionVaisseau.play();
                fenetre.display();
            }
            else {
                fenetre.draw(spriteVaisseau);
            }

            if (explose)
                sleep(1);

            // vies du vaisseau
            switch (viesJoueur) {
                case 3://Si 3 vies:
                    fenetre.draw(vie1);
                    fenetre.draw(vie2);
                    fenetre.draw(vie3);
                    break;
                case 2://Si 2 vies:
                    fenetre.draw(vie1);
                    fenetre.draw(vie2);
                    break;
                case 1://Si 1 vie:
                    fenetre.draw(vie1);
                    break;
                default:
                    break;
            }

            fenetre.draw(textVie);
            fenetre.draw(textScore);
            fenetre.draw(borderTop);
            fenetre.draw(borderBottom);
            fenetre.draw(sfScore);

            explose = false;
            fenetre.display();

        }
    }
}
Solo::Etat_Solo Solo::m_solo = m_joue;

