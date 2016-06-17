#include <iostream>
#include <vector>
//#include <Rect.hpp>
#include <unistd.h>
#include <SFML/Graphics.hpp>

//#include "type.h"
#include "Joueur.hpp"
#include "Alien.hpp"
#include "Bouclier.hpp"
#include "Missile.hpp"
#include "Collision.hpp"
/*
sf::Vector2f getPosition(sf::Sprite sp)
{
  return sp.getPosition();
}
*/
int main()
{  
  sf::RenderWindow app(sf::VideoMode(600, 600, 32), "Space Wars",sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);

  sf::Font font;
  sf::Text textVie, textScore;
  
  Joueur joueur;
  Alien ali;
  Bouclier boucli;
  Missile miss;
  Collision col;
  
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
  int depAlienX = 0, depAlienY = -50, depHorizontal = 0, ok = 5;
  int depMissileY = 525, depMissileX = 0, missileOk = 2;
  int testX = 2, testY = 5;
      
  sf::Sprite tabAlien[5][11];
  sf::Sprite tabAlienBis[5][11];
  sf::Sprite tabBouclier[3][16];
  sf::Vector2f vecBou;
  //bool tabBouclierSup[3][16];
  int tabIndiceX[5][11], tabIndiceY[5][11];
  
  /*  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 16; j++)
	{
	  tabBouclierSup[i][j] = true;
	}
    }
  */
  
  // boucliers
  // bouclier 1
  sf::Sprite spriteVaisseau, spriteMissile;


        
  ali.alien.setSmooth(true);
  joueur.vaisseau.setSmooth(true);
  boucli.bouclier.setSmooth(true);

  sf::Sprite sprite;
  app.draw(sprite);
    


    
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
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	    {
	      if(missileOk == 2)
		{
		  missileOk = 0;
		  depMissileY = 525;
		  depMissileX = depVaisseauX;
		}
	    }
	  
	  // Sprite du vaisseau
	}
      spriteVaisseau = joueur.ajouterVaisseau(spriteVaisseau, depVaisseauX, 535);
      app.clear();

      if(missileOk == 0)
	{
	  spriteMissile = miss.ajouterMissile(spriteMissile, depMissileX + 21, depMissileY);
	}
      
      // boucliers
      int dix = 450, vingt = 90, quatre = 0;
      for(int j = 0; j < 3; j++)
	{
	  for(int i = 0; i < 16; i++)
	    {
	      /*if(tabBouclierSup[i][j] == true)
		{*/
		  tabBouclier[j][i] = boucli.ajouterBouclier(tabBouclier[j][i], vingt + 160 * j, dix);
		  app.draw(tabBouclier[j][i]);
		  //	}
	      vingt = vingt + 20; quatre = quatre + 1;
	      if(vingt == 170)
		vingt = 90;
	      if(quatre == 4)
		{
		  dix = dix + 10;
		  quatre = 0;
		}
	      if(col.collisionBouclier(tabBouclier[j][i], spriteMissile))
		{
		  vecBou = boucli.getPosition(tabBouclier[j][i]);
		  std::cout << "IMPACT" << std::endl;

		  // missile
		  // si missile.y == bouclier.y-10)
		  if(vecBou.y+10 == depMissileY)
		    {
		      spriteMissile = miss.supprimerMissile(spriteMissile);
		      missileOk = 2;
		    }
		  
		  // bouclier
		  /*if(tabBouclierSup[i][j] == true)
		  {
		    tabBouclierSup[i][j] = false;
		    tabBouclier[j][i] = boucli.supprimerBouclier(tabBouclier[j][i]);
		    }*/
		}
	    }
	  dix = 450;
	  vingt = 90;
	}
      // faire une fonction qui retournera les indices du tableau (X et Y) 
      // aliens
      if(boool > 50)
	{
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      tabAlien[0][cpt1] = ali.ajouterAlien1_1(tabAlien[0][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*5)+depAlienY); // alien 1
	      app.draw(tabAlien[0][cpt1]);
	      if(0 != testX && cpt1 != testY) // eliminer alien à compléter
		if(testX != x*(cpt1+1) && testY != y+yPlus*5)
		  {
		    tabIndiceX[0][cpt1] = x*(cpt1+1);
		    tabIndiceY[0][cpt1] = y+yPlus*5;
		  }

	      // alien 2
	      tabAlien[1][cpt1] = ali.ajouterAlien1_1(tabAlien[1][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*4)+depAlienY);
	      app.draw(tabAlien[1][cpt1]);

	      //col.collisionAlien(sdsdfsdf)
	      
	      // alien 3
	      tabAlien[2][cpt1] = ali.ajouterAlien2_1(tabAlien[2][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*3)+depAlienY); 
	      app.draw(tabAlien[2][cpt1]);

	       // alien 4
	      tabAlien[3][cpt1] = ali.ajouterAlien2_1(tabAlien[3][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*2)+depAlienY);
	      app.draw(tabAlien[3][cpt1]);

	      // alien 5
	      tabAlien[4][cpt1] = ali.ajouterAlien3_1(tabAlien[4][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*1)+depAlienY);
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

      for(cpt1 = 0; cpt1 < 5; cpt1++)
	{
	  for(int cpt2 = 0; cpt2 < 11; cpt2++)
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
	}
      // fin test.
      if (boool == 100)
	boool = 0;
      else
	boool += 1;

      if(depMissileY == 40)
	{
	  missileOk = 2;
	  depMissileY = 40;
	}
      else
	{
	  depMissileY -= 5;
	  app.draw(spriteMissile);
	}
      
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
      
      app.draw(textVie);
      app.draw(textScore);
      app.draw(border);
      app.draw(spriteVaisseau);
      app.display();
    }
  //  if(spriteMissile
}
//HITBOwwwwwwwwX


