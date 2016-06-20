#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <unistd.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Joueur.hpp"
#include "Alien.hpp"
#include "Bouclier.hpp"
#include "Missile.hpp"
#include "Collision.hpp"

int main()
{  
  sf::RenderWindow app(sf::VideoMode(600, 600, 32), "Space Wars",sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);

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
  borderTop.setFillColor(sf::Color(240,248,255));
  
  sf::RectangleShape borderBottom;
  borderBottom.setSize(sf::Vector2f(600, 30));
  borderBottom.setPosition(0, 570);
  borderBottom.setFillColor(sf::Color(240,248,255));

  bool tabAlienSup[5][11], tabBouclierSup[3][16], explose = false;  
  //Tableau des aliens éliminés, false si éliminé.
  for(int j = 0; j < 5; j++)
    {
      for(int i = 0; i < 11; i++)
	{
	  tabAlienSup[j][i] = true;
	}
    }
  
  //Tableau des boucliers détruits, false si détruit.
  for(int j = 0; j < 3; j++)
    {
      for(int i = 0; i < 16; i++)
	{
	  tabBouclierSup[j][i] = true;
	}
    }

  sf::SoundBuffer bufferExplosionVaisseau, bufferTire, bufferExplosionAlien;
  if (!bufferExplosionVaisseau.loadFromFile("sons/vaisseauExplosion.wav"))
    {
      std::cout << "Erreur durant le chargement de vaisseauExplosion.wav" << std::endl;
    }
  else
    {
      soundExplosionVaisseau.setBuffer(bufferExplosionVaisseau);
    }
  
  if (!bufferExplosionAlien.loadFromFile("sons/alienExplosion.wav"))
    {
      std::cout << "Erreur durant le chargement de alienExplosion.wav" << std::endl;
    }
  else
    {
      soundExplosionAlien.setBuffer(bufferExplosionAlien);
    }
  
  if (!bufferTire.loadFromFile("sons/tire.wav"))
    {
      std::cout << "Erreur durant le chargement de tire.wav" << std::endl;
    }
  else
    {
      soundTire.setBuffer(bufferTire);
    }
  
  ali.alien.setSmooth(true);
  joueur.vaisseau.setSmooth(true);
  boucli.bouclier.setSmooth(true);
  
  int jeuFini = 0;
  
  while (app.isOpen())
    {
      
      if (!font.loadFromFile("images/fonts.ttf"))
	{
	  std::cout << "Erreur durant le chargement de ficher fonts.ttf" << std::endl;
	}
      else
	{
	  textScore.setFont(font);
	  textScore.setString("Score: ");
	  textScore.setCharacterSize(30);
	  textScore.setPosition(10,0);
	  sfScore.setColor(sf::Color(255, 255, 255));
	  textScore.setStyle(sf::Text::Bold);

	  std::string  scoreString;
	  std::ostringstream os;
	  os << score;
	  scoreString = os.str();
      
	  sfScore.setFont(font);
	  sfScore.setString(scoreString);
	  sfScore.setCharacterSize(25);
	  sfScore.setPosition(180,5);
	  sfScore.setColor(sf::Color(255, 255, 255));
	  sfScore.setStyle(sf::Text::Bold);
      
	  textVie.setFont(font);
	  textVie.setString("Vie: ");
	  textVie.setCharacterSize(30);
	  textVie.setPosition(350,0);
	  sfScore.setColor(sf::Color(255, 255, 255));
	  textVie.setStyle(sf::Text::Bold);
	}
      //Si le joueur atteint 0 point de vie:
      if(viesJoueur == 0)
	{
	  std::cout << "!!!!! GAME OVER !!!!!" << std::endl;
	  return 0;
	}
      

      //On parcours le tableau des aliens éliminés.
      for(int j = 0; j < 5; j++)
	{
	  for(int i = 0; i < 11; i++)
	    {
	      //Si l'alien en [j][i] est éliminé:
	      if(tabAlienSup[j][i] == false)
		//On incrémente jeuFini.
		jeuFini += 1;
	    }
	}

      //On sait qu'il y a 5 * 11 aliens, soit 55.
      //Si jeuFini = 55:
      if(jeuFini == 55)
	{
	//Retourner au menu %menu
	  std::cout << "!!!!!! Victoire !!!!!!" << std::endl;;
	  return 0;
	}
      else
	//Sinon, on reinitialise jeuFini pour la prochaine vérification.
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
	  //Si l'utilisateur clique sur la croix pour fermer la fenetre du jeu:
	  if (event.type == sf::Event::Closed)
	    app.close();
	  
	  // déplacer vaisseau à gauche
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	    //Pour ne pas se déplacer hors de la fenetre.
	    if(depVaisseauX > 50)
	      depVaisseauX = depVaisseauX - 10;
	  
	  // déplacer vaisseau à droite
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    //Pour ne pas se déplacer hors de la fenetre.
	    if(depVaisseauX < 500)
	      depVaisseauX = depVaisseauX + 10;
	  
	  // tirer avec le vaisseau
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	    {
	      if(missileVaisseauOk == 2)
		{
		  soundTire.play();
		  missileVaisseauOk = 0;
		  depMissileY = 525;
		  depMissileX = depVaisseauX;
		}
	    }
	}
      
      app.clear();

      //spriteVaisseauExplose = joueur.vaisseauExplose(spriteVaisseauExplose, depVaisseauX, 535);
      spriteVaisseau = joueur.ajouterVaisseau(spriteVaisseau, depVaisseauX, 535);
      //app.draw(spriteVaisseau);
      
      //Si randomAlienMissile tombe sur 1, on peut tirer.
      if(randomAlienMissile == 1)
	{
	  if(missileAlienOk == 2)
	    {
	      missileAlienOk = 0;
	      depMissileAlienX = (x*(randomAlienTireX))+depAlienX-8;
	      depMissileAlienY = (y+yPlus*(randomAlienTireY))+depAlienY+45;
	    }
	}
      
      if(col.collisionVaisseau(spriteVaisseau, spriteMissileAlien))
	{
	  spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
	  viesJoueur -= 1;
	  explose = true;
	  //std::cout << " collision vaisseau missile alien" << std::endl;
	  //	  app.draw(spriteVaisseau);
	  //sleep(1);
	  missileAlienOk = 2;
	}
      
      if(missileVaisseauOk == 0)
	spriteMissileVaisseau = miss.ajouterMissileVaisseau(spriteMissileVaisseau, depMissileX + 21, depMissileY); 
      if(missileAlienOk == 0)
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
		      tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
		      tabBouclierSup[j][i] = false;
		      missileVaisseauOk = 2;
		    }
		}
	      if(col.collisionBouclier(tabBouclier[j][i], spriteMissileAlien))
		{
		  spriteMissileAlien = miss.supprimerMissile(spriteMissileAlien);
		  tabBouclier[j][i] = miss.supprimerMissile(tabBouclier[j][i]);
		  tabBouclierSup[j][i] = false;
		  missileAlienOk = 2;
		}
	   
	    }
	  dix = 450;
	  vingt = 90;
	}
      
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
		      missileAlienOk = 2;
		    }
		}
	      
	      // Colision missile vaisseau - alien
	      if(col.collisionAlien(tabAlien[j][i], spriteMissileVaisseau))
		{
		  vecVai = ali.getPosition(tabAlien[j][i]);
		  if(vecVai.y + 20 == depMissileY)
		    {
		      soundExplosionAlien.play();
		      tabAlienSup[j][i] = false;
		      spriteMissileVaisseau = miss.supprimerMissile(spriteMissileVaisseau);
		      tabAlien[j][i] = miss.supprimerMissile(tabAlien[j][i]);
		      tabAlienBis[j][i] = miss.supprimerMissile(tabAlienBis[j][i]);
		      missileVaisseauOk = 2;
		      score += 10;
		    }
		}
	    }
	}

      // aliens      
      if(boool > 50)
	{
	  for(cpt1 = 0; cpt1 < 11; cpt1++)
	    {
	      //On vérifie s'ils sont éliminés.
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
	  missileVaisseauOk = 2;
	  depMissileY = 40;
	}
      else
	{
	  depMissileY -=5;
	  app.draw(spriteMissileVaisseau);
	}
      
      if(depMissileAlienY == 575)
	{
	  //nazerkkm
	  missileAlienOk = 2;
	  depMissileAlienY = 600;
	}
      else
	{
	  depMissileAlienY += 5;
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
		      viesJoueur -= 1;
		      explose = true;
		      //		      app.draw(spriteVaisseau);
		      //sleep(1);
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
		      viesJoueur -= 1;
		      explose = true;
		      //		      app.draw(spriteVaisseau);
		      //sleep(1);
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
      
      if (explose == true)
	{
	  spriteVaisseauExplose = joueur.vaisseauExplose(spriteVaisseauExplose, depVaisseauX, 535);  
	  app.draw(spriteVaisseauExplose);
	  soundExplosionVaisseau.play();
	  app.display();
	}
      else
	{
	  app.draw(spriteVaisseau);
	}

      if(explose == true)
	sleep(1);
     
      // vies du vaisseau
      switch(viesJoueur)
	{ 
	case 3://Si 3 vies:
	  app.draw(vie1);app.draw(vie2);app.draw(vie3);break;
	case 2://Si 2 vies:
	  app.draw(vie1);app.draw(vie2);break;
	case 1://Si 1 vie:
	  app.draw(vie1);break;
	default:
	  break;
	}
      
      app.draw(textVie);
      app.draw(textScore);
      app.draw(borderTop);
      app.draw(borderBottom);
      app.draw(sfScore);
      
      explose = false;
      app.display();
    }
}
