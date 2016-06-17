#include <iostream>
#include <vector>
#include <unistd.h>
#include <SFML/Graphics.hpp>

//#include "type.h"
#include "Joueur.hpp"
#include "Alien.hpp"
#include "Bouclier.hpp"


int main()
{  
  sf::RenderWindow app(sf::VideoMode(600, 600, 32), "Space Wars",sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);

  sf::Font font;
  sf::Text textVie, textScore;
  
  Joueur joueur;
  Alien ali;
  Bouclier boucli;
  
  // Ligne en dessous de score
  sf::RectangleShape border;
  border.setSize(sf::Vector2f(600, 5));
  border.setPosition(0, 35);
  border.setFillColor(sf::Color(240,248,255));
  
  //font1 pour afficher le mot Score
  if (!font.loadFromFile("images/fonts.ttf"))
    {
      std::cout<<"Erreur durant le chargement de ficher fonts.ttf"<<std::endl;
    }
  else
    {
      textScore.setFont(font);
      textScore.setString("Score: ");
      textScore.setCharacterSize(30);
      textScore.setPosition(10,0);
      textScore.setColor(sf::Color(0,0,255));
      textScore.setStyle(sf::Text::Bold);
      textVie.setFont(font);
      textVie.setString("Vie: ");
      textVie.setCharacterSize(30);
      textVie.setPosition(350,0);
      textVie.setColor(sf::Color(0,0,255));
      textVie.setStyle(sf::Text::Bold);
    }

  float x = 36.00;
  float  y = 70.00, yPlus = 45.00;
  int boool = 1, depVaisseauX = 0, cpt1;//, cpt2;
  int depBoucli = 80; // déplacement des boucliers
  int depAlienX = 0, depAlienY = -50, depHorizontal = 0, ok = 5;

  
  std::vector<sf::Sprite> vecteurAlien;
  sf::Sprite tabAlien[5][11];
  sf::Sprite tabAlienBis[5][11];
  //  int tabIndiceX[5][11], tabIndiceY[5][11];

  // boucliers
    
  // bouclier 1
  sf::Sprite spriteVaisseau, bou101, bou102, bou103, bou104, bou105,bou106, bou107,
    bou108, bou109, bou110, bou111, bou112, bou113, bou114,
    bou115,bou116, bou117, bou118, bou119, bou120,

    // bouclier 2
    bou201, bou202, bou203, bou204, bou205,bou206, bou207,
    bou208, bou209, bou210, bou211, bou212, bou213, bou214,
    bou215,bou216, bou217, bou218, bou219, bou220,

    // bouclier 3
    bou301, bou302, bou303, bou304, bou305,bou306, bou307,
    bou308, bou309, bou310, bou311, bou312, bou313, bou314,
    bou315,bou316, bou317, bou318, bou319, bou320;
        
  ali.alien.setSmooth(true);
  joueur.vaisseau.setSmooth(true);
  boucli.bouclier.setSmooth(true);

  while (app.isOpen())
    {
      sf::Event event;
      while (app.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    app.close();

	  // déplacer vaisseau à gauche
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	    if(depVaisseauX > 50)
	      depVaisseauX = depVaisseauX - 10;

	  // déplacer vaisseau à droite
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    if(depVaisseauX < 500)
	      depVaisseauX = depVaisseauX + 10;

	  // tirer avec le vaisseau
	  // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	  spriteVaisseau = joueur.ajouterVaisseau(spriteVaisseau, depVaisseauX, 535);
	  // gérer le missile.
	  //	  spriteMissile = Miss.ajouterMissile(spriteMissile, depVaisseauX, 525);
	}
      app.clear();

      /********************************************************/
      /*** Tous les boucliers sont à mettre dans un tableau ***/
      /********************************************************/
      
      // bouclier 1
      bou101 = boucli.ajouterBouclier(bou101, 10 + depBoucli, 450);
      bou102 = boucli.ajouterBouclier(bou102, 30 + depBoucli, 450);
      bou103 = boucli.ajouterBouclier(bou103, 50 + depBoucli, 450);
      bou104 = boucli.ajouterBouclier(bou104, 70 + depBoucli, 450);
      bou105 = boucli.ajouterBouclier(bou105, 10 + depBoucli, 460);
      bou106 = boucli.ajouterBouclier(bou106, 30 + depBoucli, 460);
      bou107 = boucli.ajouterBouclier(bou107, 50 + depBoucli, 460);
      bou108 = boucli.ajouterBouclier(bou108, 70 + depBoucli, 460);
      bou109 = boucli.ajouterBouclier(bou109, 10 + depBoucli, 470);
      bou110 = boucli.ajouterBouclier(bou110, 30 + depBoucli, 470);
      bou111 = boucli.ajouterBouclier(bou111, 50 + depBoucli, 470);
      bou112 = boucli.ajouterBouclier(bou112, 70 + depBoucli, 470);
      bou113 = boucli.ajouterBouclier(bou113, 10 + depBoucli, 480);
      bou114 = boucli.ajouterBouclier(bou114, 30 + depBoucli, 480);
      bou115 = boucli.ajouterBouclier(bou115, 50 + depBoucli, 480);
      bou116 = boucli.ajouterBouclier(bou116, 70 + depBoucli, 480);
      
      app.draw(bou101);app.draw(bou102);app.draw(bou103);
      app.draw(bou104);app.draw(bou105);app.draw(bou106);
      app.draw(bou107);app.draw(bou108);app.draw(bou109);
      app.draw(bou110);app.draw(bou111);app.draw(bou112);
      app.draw(bou113);app.draw(bou114);app.draw(bou115);
      app.draw(bou116);
      	  
      // bouclier 2
      bou201 = boucli.ajouterBouclier(bou201, 170 + depBoucli, 450);
      bou202 = boucli.ajouterBouclier(bou202, 190 + depBoucli, 450);
      bou203 = boucli.ajouterBouclier(bou203, 210 + depBoucli, 450);
      bou204 = boucli.ajouterBouclier(bou204, 230 + depBoucli, 450);
      bou205 = boucli.ajouterBouclier(bou205, 170 + depBoucli, 460);
      bou206 = boucli.ajouterBouclier(bou206, 190 + depBoucli, 460);
      bou207 = boucli.ajouterBouclier(bou207, 210 + depBoucli, 460);
      bou208 = boucli.ajouterBouclier(bou208, 230 + depBoucli, 460);
      bou209 = boucli.ajouterBouclier(bou209, 170 + depBoucli, 470);
      bou210 = boucli.ajouterBouclier(bou210, 190 + depBoucli, 470);
      bou211 = boucli.ajouterBouclier(bou211, 210 + depBoucli, 470);
      bou212 = boucli.ajouterBouclier(bou212, 230 + depBoucli, 470);
      bou213 = boucli.ajouterBouclier(bou213, 170 + depBoucli, 480);
      bou214 = boucli.ajouterBouclier(bou214, 190 + depBoucli, 480);
      bou215 = boucli.ajouterBouclier(bou215, 210 + depBoucli, 480);
      bou216 = boucli.ajouterBouclier(bou216, 230 + depBoucli, 480);

      app.draw(bou201);app.draw(bou202);app.draw(bou203);
      app.draw(bou204);app.draw(bou205);app.draw(bou206);
      app.draw(bou207);app.draw(bou208);app.draw(bou209);
      app.draw(bou210);app.draw(bou211);app.draw(bou212);
      app.draw(bou213);app.draw(bou214);app.draw(bou215);
      app.draw(bou216);

      // bouclier 3
      bou301 = boucli.ajouterBouclier(bou301, 330 + depBoucli, 450);
      bou302 = boucli.ajouterBouclier(bou302, 350 + depBoucli, 450);
      bou303 = boucli.ajouterBouclier(bou303, 370 + depBoucli, 450);
      bou304 = boucli.ajouterBouclier(bou304, 390 + depBoucli, 450);
      bou305 = boucli.ajouterBouclier(bou305, 330 + depBoucli, 460);
      bou306 = boucli.ajouterBouclier(bou306, 350 + depBoucli, 460);
      bou307 = boucli.ajouterBouclier(bou307, 370 + depBoucli, 460);
      bou308 = boucli.ajouterBouclier(bou308, 390 + depBoucli, 460);
      bou309 = boucli.ajouterBouclier(bou309, 330 + depBoucli, 470);
      bou310 = boucli.ajouterBouclier(bou310, 350 + depBoucli, 470);
      bou311 = boucli.ajouterBouclier(bou311, 370 + depBoucli, 470);
      bou312 = boucli.ajouterBouclier(bou312, 390 + depBoucli, 470);
      bou313 = boucli.ajouterBouclier(bou313, 330 + depBoucli, 480);
      bou314 = boucli.ajouterBouclier(bou314, 350 + depBoucli, 480);
      bou315 = boucli.ajouterBouclier(bou315, 370 + depBoucli, 480);
      bou316 = boucli.ajouterBouclier(bou316, 390 + depBoucli, 480);

      app.draw(bou301);app.draw(bou302);app.draw(bou303);
      app.draw(bou304);app.draw(bou305);app.draw(bou306);
      app.draw(bou307);app.draw(bou308);app.draw(bou309);
      app.draw(bou310);app.draw(bou311);app.draw(bou312);
      app.draw(bou313);app.draw(bou314);app.draw(bou315);
      app.draw(bou316);

      // faire une fonction qui retournera les indices du tableau (X et Y) 
      //int testX = 2, testY = 1;
      // aliens
      if(boool > 50)
	{
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      tabAlien[0][cpt1] = ali.ajouterAlien1_1(tabAlien[0][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*5)+depAlienY); // alien 1
	      app.draw(tabAlien[0][cpt1]);
	      //if(0 != testX && cpt1 != testY) // eliminer alien à compléter
		//if(testX != x*(cpt1+1) && testY != y+yPlus*5)
		/*tabIndiceX[0][cpt1] = x*(cpt1+1);	      tabIndiceY[0][cpt1] = y+yPlus*5;*/

		tabAlien[1][cpt1] = ali.ajouterAlien1_1(tabAlien[1][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*4)+depAlienY); // alien 2
	      app.draw(tabAlien[1][cpt1]);

	      tabAlien[2][cpt1] = ali.ajouterAlien2_1(tabAlien[2][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*3)+depAlienY); // alien 3
	      app.draw(tabAlien[2][cpt1]);

	      tabAlien[3][cpt1] = ali.ajouterAlien2_1(tabAlien[3][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*2)+depAlienY); // alien 4
	      app.draw(tabAlien[3][cpt1]);

	      tabAlien[4][cpt1] = ali.ajouterAlien3_1(tabAlien[4][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*1)+depAlienY); // alien 5
	      app.draw(tabAlien[4][cpt1]);
	    }
	}else if(boool < 50)
	{	  
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      tabAlienBis[0][cpt1] = ali.ajouterAlien1_2(tabAlienBis[0][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*5)+depAlienY); // alien 1 bis
	      app.draw(tabAlienBis[0][cpt1]);
	      
	      tabAlienBis[1][cpt1] = ali.ajouterAlien1_2(tabAlienBis[1][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*4)+depAlienY); // alien 2 bis
	      app.draw(tabAlienBis[1][cpt1]);

	      tabAlienBis[2][cpt1] = ali.ajouterAlien2_2(tabAlienBis[2][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*3)+depAlienY); // alien 3 bis
	      app.draw(tabAlienBis[2][cpt1]);
		
	      tabAlienBis[3][cpt1] = ali.ajouterAlien2_2(tabAlienBis[3][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*2)+depAlienY); // alien 4 bis
	      app.draw(tabAlienBis[3][cpt1]);

	      tabAlienBis[4][cpt1] = ali.ajouterAlien3_2(tabAlienBis[4][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*1)+depAlienY); // alien 5 bis
	      app.draw(tabAlienBis[4][cpt1]);
	    }
	}

      // test d'élimination de l'alien placé en 2 - 5.
      /*int testX = 2, testY = 5;
	for(cpt1 = 0; cpt1 < 5; cpt1++)
	{
	for(cpt2 = 0; cpt2 < 11; cpt2++)
	{
	if(tabIndiceX[cpt1][cpt2] == testX && tabIndiceY[cpt1][cpt2] == testY)
	{
	//effacer tabAlien[cpt1][cpt2]
	tabAlien[cpt1][cpt2] = ali.supprimerAlien(tabAlien[cpt1][cpt2]);
	app.draw(tabAlien[cpt1][cpt2]);
	//effacer tabAlienBis[cpt1][cpt2]:
	tabAlienBis[cpt1][cpt2] = ali.supprimerAlien(tabAlienBis[cpt1][cpt2]);
	app.draw(tabAlienBis[cpt1][cpt2]);
	}
	}
	}*/
      // fin test.
      if (boool == 100)
	boool = 0;
      else
	boool += 1;
      if (depHorizontal == 50)
	{
	  if(depAlienX > 130)
	    {
	      if(ok != 5)
		depAlienY += 10;
	      ok = 1;
	    }
	  if(depAlienX == 0)
	    {
	      if(ok != 5)
		depAlienY += 10;
	      ok = 0;
	    }

	  if(ok == 0)
	    depAlienX += 132/18;
	  if(ok == 1)
	    depAlienX -= 132/18;
	  
	  depHorizontal = 0;
	}
      else
	depHorizontal += 1;
      app.draw(textVie);app.draw(textScore);app.draw(border);app.draw(spriteVaisseau);
      app.display();
    }
}


