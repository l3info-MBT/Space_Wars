//
// Created by tony on 21/06/16.
//

#ifndef DPSI_CADRE_H
#define DPSI_CADRE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <sstream>

class Cadre
{
public:
    std::string Nomreseaux1,Nomreseaux2,Nomreseaux3;
    std::string Datereseaux1,Datereseaux2,Datereseaux3;
    std::string Etat1,Etat2,Etat3;
    float nbplace1,nbplace2,nbplace3;

    sf::RectangleShape cadre;
    sf::Font font1,font2,font3,font4,font5,font6,font7,font8,font9,font10,font11,font12,font13,font14,font15,font16,font17,font18,font19;
    std::string Nomreseaux;
    sf::RectangleShape ajoutercadre1(sf::RectangleShape cadre, int posx,int posy);
    sf::RectangleShape ajoutercadre2(sf::RectangleShape cadre, int posx,int posy);
    sf::RectangleShape ajoutercadre3(sf::RectangleShape cadre, int posx,int posy);
    sf::RectangleShape ajoutercadre4(sf::RectangleShape cadre, int posx,int posy);

    sf::Text ajouterterme1(sf::Text textcadre,int posx,int posy,std::string terme);
    sf::Text ajouterterme2(sf::Text textcadre,int posx,int posy,std::string terme);
    sf::Text ajouterterme3(sf::Text textcadre,int posx,int posy,std::string terme);
    sf::Text ajouterterme4(sf::Text textcadre,int posx,int posy,std::string terme);
    sf::Text ajouterterme5(sf::Text textcadre,int posx,int posy,std::string terme);
    sf::Text afficherNom1(sf::Text textcadre,int posx,int posy,std::string Nomreseaux1);
    sf::Text afficherNom2(sf::Text textcadre,int posx,int posy,std::string Nomreseaux2);
    sf::Text afficherNom3(sf::Text textcadre,int posx,int posy,std::string Nomreseaux3);
    sf::Text afficherNomcp(sf::Text textcadre,int posx,int posy,std::string Nomreseauxcp);

    sf::Text nbrconnect1(sf::Text textcadre,int posx,int posy,int nbr1);
    sf::Text nbrconnect2(sf::Text textcadre,int posx,int posy,int nbr2);
    sf::Text nbrconnect3(sf::Text textcadre,int posx,int posy,int nbr3);

    sf::Text nbrconnectcp(sf::Text textcadre,int posx,int posy,int nbr);



    sf::CircleShape ajouter_circle(sf::CircleShape Circle,int nbr,int Cx,int Cy);
    sf::Text date1(sf::Text textcadre,int posx,int posy,std::string chainedate);
    sf::Text date2(sf::Text textcadre,int posx,int posy,std::string chainedate);
    sf::Text date3(sf::Text textcadre,int posx,int posy,std::string chainedate);
    sf::Text datecp(sf::Text textcadre,int posx,int posy,std::string chainedate);

    sf::Text etat(sf::Text textcadre,int posx,int posy,int nbr);

};

#endif //DPSI_CADRE_H
