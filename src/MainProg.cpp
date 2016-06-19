#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "Joueur.hpp"
#include "Alien.hpp"
#include "Bouclier.hpp"
#include "Missile.hpp"
#include "Collision.hpp"

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

  float x = 36.00;
  float  y = 70.00, yPlus = 45.00;
  int boool = 1, depVaisseauX = 0, cpt1, depAlienX = 0, depAlienY = -50;
  int depHorizontal = 0, ok = 5, depMissileY = 525, depMissileX = 0;
  int missileOk = 2, depMissileAlienX, depMissileAlienY = 0, tireOk = 0;
  sf::Sprite tabAlien[5][11], tabAlienBis[5][11], tabBouclier[3][16];
  sf::Sprite spriteVaisseau, spriteMissileVaisseau, spriteMissileAlien;
  
  sf::Vector2f vecBou, vecAli, vecVai;
  
  int vieJoueur = joueur.getNbVie();
  sf::Sprite vie1, vie2, vie3;
  vie1 = joueur.ajouterVaisseau(spriteVaisseau, 440, 5);
  vie2 = joueur.ajouterVaisseau(spriteVaisseau, 490, 5);
  vie3 = joueur.ajouterVaisseau(spriteVaisseau, 540, 5);
  
  // Ligne en dessous de score
  sf::RectangleShape border;
  border.setSize(sf::Vector2f(600, 5));
  border.setPosition(0, 35);
  border.setFillColor(sf::Color(240,248,255));
  
  bool tabAlienSup[5][11];
  for(int j = 0; j < 5; j++)
    {
      for(int i = 0; i < 11; i++)
	{
	  tabAlienSup[j][i] = true;
	}
    }

  bool tabBouclierSup[3][16];
  
  for(int j = 0; j < 3; j++)
    {
      for(int i = 0; i < 16; i++)
	{
	  tabBouclierSup[j][i] = true;
	}
    }
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
  
  ali.alien.setSmooth(true);
  joueur.vaisseau.setSmooth(true);
  boucli.bouclier.setSmooth(true);

  int jeuFini = 0;
      
  while (app.isOpen())
    {
      if(vieJoueur == 0)
	return 0;
      for(int j = 0; j < 5; j++)
	{
	  for(int i = 0; i < 11; i++)
	    {
	      if(tabAlienSup[j][i] == false)
		jeuFini += 1;
	    }
	}

      if(jeuFini == 55)
	return 0;
      else
	jeuFini = 0;

      
      // random de 1 à 11 pour choisir aléatoirement quel alien dans la rangée horizontal va tirer
      int randomAlienTireX = rand()%11+1;
  
      // random de 1 à 5 pour choisir aléatoirement quel alien dans la rangée vertical va tirer
      int randomAlienTireY = rand()%5+1;
					  
      // random de 1 à 2, pour que ça tire de façon aléatoire
      int randomAlienMissile = rand()%2+1;
      
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

      // vies du vaisseau
      switch(vieJoueur)
	{
	case 3:
	  app.draw(vie1);app.draw(vie2);app.draw(vie3);break;
	case 2:
	  app.draw(vie1);app.draw(vie2);break;
	case 1:
	  app.draw(vie1);break;
	case 0:
	  std::cout << "!!!!! GAME OVER !!!!!" << std::endl;break;
	}
      
      if(randomAlienMissile == 1)
	{
	  if(tireOk == 2)
	    {
	      tireOk = 0;
	      depMissileAlienX = (x*(randomAlienTireX))+depAlienX-8;
	      depMissileAlienY = (y+yPlus*(randomAlienTireY))+depAlienY+45;
	    }
	}

      if(col.collisionVaisseau(spriteVaisseau, spriteMissileAlien))
	{
	  spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
	  std::cout << "IMPACT missile alien - vaisseau" << std::endl;
	  vieJoueur -= 1;
	  sleep(1);
	  tireOk = 2;
	}
      
      if(missileOk == 0)
	spriteMissileVaisseau = miss.ajouterMissileVaisseau(spriteMissileVaisseau, depMissileX + 21, depMissileY); 
      if(tireOk == 0)
	spriteMissileAlien = miss.ajouterMissileAlien(spriteMissileAlien, depMissileAlienX + 21, depMissileAlienY);
      
      // boucliers
      int dix = 450, vingt = 90, quatre = 0;
      for(int j = 0; j < 3; j++)
	{
	  for(int i = 0; i < 16; i++)
	    {
	      if(tabBouclierSup[j][i] == true)
		{
		  tabBouclier[j][i] = boucli.ajouterBouclier(tabBouclier[j][i], vingt + 160 * j, dix);
		  app.draw(tabBouclier[j][i]);
		}
	      vingt = vingt + 20; quatre = quatre + 1;
	      if(vingt == 170)
		vingt = 90;
	      if(quatre == 4)
		{
		  dix = dix + 10;
		  quatre = 0;
		}
	      if(col.collisionBouclier(tabBouclier[j][i], spriteMissileVaisseau))
		{
		  vecBou = boucli.getPosition(tabBouclier[j][i]);
		  if(vecBou.y + 10 == depMissileY)
		    {
		      spriteMissileVaisseau = miss.supprimerMissile(spriteMissileVaisseau);
		      std::cout << "IMPACT missile vaisseau - bouclier" <<std::endl;
		      tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
		      tabBouclierSup[j][i] = false;
		      missileOk = 2;
		    }
		}
	      if(col.collisionBouclier(tabBouclier[j][i], spriteMissileAlien))
		{
		  spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
		  std::cout << "IMPACT missile alien - bouclier" << std::endl;
		  tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
		  tabBouclierSup[j][i] = false;
		  tireOk = 2;
		}
	   
	    }
	  dix = 450;
	  vingt = 90;
	}
      
      // aliens
      for(int j = 0; j < 5; j++)
	{
	  for(int i = 0; i < 11; i++)
	    {
	      // Colision missile alien - alien
	      if(col.collisionAlien(tabAlien[j][i], spriteMissileAlien))
		{
		  vecAli = ali.getPosition(tabAlien[j][i]);
		  if(vecAli.y + 20 == depMissileAlienY)
		    {
		      spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
		      std::cout << "IMPACT missile alien - alien" <<std::endl;
		      tireOk = 2;
		    }
		}
	      
	      // Colision missile vaisseau - alien
	      if(col.collisionAlien(tabAlien[j][i], spriteMissileVaisseau))
		{
		  vecVai = ali.getPosition(tabAlien[j][i]);
		  if(vecVai.y + 20 == depMissileY)
		    {
		      tabAlienSup[j][i] = false;
		      spriteMissileVaisseau = miss.supprimerMissile(spriteMissileVaisseau);
		      std::cout << "IMPACT missile vaisseau - alien" <<std::endl;
		      tabAlien[j][i] = miss.supprimerMissile(tabAlien[j][i]);
		      tabAlienBis[j][i] = miss.supprimerMissile(tabAlienBis[j][i]);
		      missileOk = 2;
		    }
		}
	    }
	}
      
      if(boool > 50)
	{
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      if(tabAlienSup[0][cpt1] == true)
		// alien ligne 1 (en partant du bas)
		tabAlien[0][cpt1] = ali.ajouterAlien1_1(tabAlien[0][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*5)+depAlienY);app.draw(tabAlien[0][cpt1]);
	      
	      if(tabAlienSup[1][cpt1] == true)
		// alien ligne 2 (en partant du bas)
		tabAlien[1][cpt1] = ali.ajouterAlien1_1(tabAlien[1][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*4)+depAlienY);app.draw(tabAlien[1][cpt1]);
	     
	      if(tabAlienSup[2][cpt1] == true)
		// alien ligne 3 (en partant du bas)
		tabAlien[2][cpt1] = ali.ajouterAlien2_1(tabAlien[2][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*3)+depAlienY);app.draw(tabAlien[2][cpt1]);

	      if(tabAlienSup[3][cpt1] == true)
		// alien ligne 4 (en partant du bas)
		tabAlien[3][cpt1] = ali.ajouterAlien2_1(tabAlien[3][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*2)+depAlienY);app.draw(tabAlien[3][cpt1]);

	      if(tabAlienSup[4][cpt1] == true)
		// alien ligne 5 (en partant du bas)
		tabAlien[4][cpt1] = ali.ajouterAlien3_1(tabAlien[4][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*1)+depAlienY);app.draw(tabAlien[4][cpt1]);
	    }
	}else if(boool < 50)
	{	  
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      if(tabAlienSup[0][cpt1] == true)
		// alien 1 bis (en partant du bas)
		tabAlienBis[0][cpt1] = ali.ajouterAlien1_2(tabAlienBis[0][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*5)+depAlienY);app.draw(tabAlienBis[0][cpt1]);

	      if(tabAlienSup[1][cpt1] == true)
		// alien 2 bis (en partant du bas)
		tabAlienBis[1][cpt1] = ali.ajouterAlien1_2(tabAlienBis[1][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*4)+depAlienY);app.draw(tabAlienBis[1][cpt1]);

	      if(tabAlienSup[2][cpt1] == true)
		// alien 3 bis (en partant du bas)
		tabAlienBis[2][cpt1] = ali.ajouterAlien2_2(tabAlienBis[2][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*3)+depAlienY);app.draw(tabAlienBis[2][cpt1]);

	      if(tabAlienSup[3][cpt1] == true)
		// alien 4 bis (en partant du bas)
		tabAlienBis[3][cpt1] = ali.ajouterAlien2_2(tabAlienBis[3][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*2)+depAlienY);app.draw(tabAlienBis[3][cpt1]);

	      if(tabAlienSup[4][cpt1] == true)
		// alien 5 bis (en partant du bas)
		tabAlienBis[4][cpt1] = ali.ajouterAlien3_2(tabAlienBis[4][cpt1], (x*(cpt1+1))+depAlienX, (y+yPlus*1)+depAlienY);app.draw(tabAlienBis[4][cpt1]);
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
	  app.draw(spriteMissileVaisseau);
	}
      
      if(depMissileAlienY == 600)
	{
	  tireOk = 2;
	  depMissileAlienY = 600;
	}
      else
	{
	  depMissileAlienY += 1;
	  app.draw(spriteMissileAlien);
	}
      
      if (depHorizontal == 50)
	{
	  if(depAlienX > 130)
	    {
	      if(ok != 5)
		{
		  depAlienY += 10;
		  // si la vague descend trop
		  if(depAlienY == 140)
		    {
		      // le vaisseau perd 1 point de vie.
		      vieJoueur -= 1; 
		      depAlienY -= 40;
		    }
		}
	      ok = 1;
	    }
	  if(depAlienX == 0)
	    {
	      if(ok != 5)
		{
		  depAlienY += 10;
		  // si la vague descend trop
		  if(depAlienY == 140)
		    {
		      // le vaisseau perd 1 point de vie.
		      vieJoueur -= 1; 
		      depAlienY -= 40;
		    }
		}
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
}
