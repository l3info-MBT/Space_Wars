
#include "Cadre.h"


sf::RectangleShape Cadre::ajoutercadre1(sf::RectangleShape cadre1,int posx,int posy)
{
    cadre1.setSize(sf::Vector2f(650, 90));
    cadre1.setPosition(posx,posy);
    cadre1.setFillColor(sf::Color(0,0,0));
    return cadre;
}

sf::RectangleShape Cadre::ajoutercadre2(sf::RectangleShape cadre2,int posx,int posy)
{
    cadre2.setSize(sf::Vector2f(650, 90));
    cadre2.setPosition(posx,posy);
    cadre2.setFillColor(sf::Color(0,0,0));
    return cadre;
}

sf::RectangleShape Cadre::ajoutercadre3(sf::RectangleShape cadre3,int posx,int posy)
{
    cadre3.setSize(sf::Vector2f(650, 90));
    cadre3.setPosition(posx,posy);
    cadre3.setFillColor(sf::Color(0,0,0));
    return cadre;
}

sf::RectangleShape Cadre::ajoutercadre4(sf::RectangleShape cadre4,int posx,int posy)
{
    cadre4.setSize(sf::Vector2f(670,110));
    cadre4.setPosition(posx,posy);
    cadre4.setFillColor(sf::Color(0,0,0));
    return cadre;
}

sf::Text Cadre::ajouterterme1(sf::Text textcadre,int posx,int posy,std::string terme)
{
    if(!font1.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font1);
        textcadre.setString(terme);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        textcadre.setStyle(sf::Text::Bold);
        return  textcadre;
    }
}


sf::Text Cadre::ajouterterme2(sf::Text textcadre,int posx,int posy,std::string terme)
{
    if(!font2.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font2);
        textcadre.setString(terme);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        textcadre.setStyle(sf::Text::Bold);
        return  textcadre;
    }
}

sf::Text Cadre::ajouterterme3(sf::Text textcadre,int posx,int posy,std::string terme)
{
    if(!font3.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font3);
        textcadre.setString(terme);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        textcadre.setStyle(sf::Text::Bold);
        return  textcadre;
    }
}

sf::Text Cadre::ajouterterme4(sf::Text textcadre,int posx,int posy,std::string terme)
{
    if(!font4.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font4);
        textcadre.setString(terme);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        textcadre.setStyle(sf::Text::Bold);
        return  textcadre;
    }
}

sf::Text Cadre::ajouterterme5(sf::Text textcadre,int posx,int posy,std::string terme)
{
    if(!font5.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font5);
        textcadre.setString(terme);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        textcadre.setStyle(sf::Text::Bold);
        return  textcadre;
    }
}


sf::Text Cadre::afficherNom1(sf::Text textcadre,int posx,int posy,std::string Nomreseaux1)
{

    if(!font6.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font6);
        textcadre.setString(Nomreseaux1);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::afficherNom2(sf::Text textcadre,int posx,int posy,std::string Nomreseaux2)
{

    if(!font10.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font10);
        textcadre.setString(Nomreseaux2);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::afficherNom3(sf::Text textcadre,int posx,int posy,std::string Nomreseaux3)
{

    if(!font11.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font11);
        textcadre.setString(Nomreseaux3);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::afficherNomcp(sf::Text textcadre,int posx,int posy,std::string Nomreseaux)
{

    if(!font16.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font16);
        textcadre.setString(Nomreseaux);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}


sf::Text Cadre::nbrconnect1(sf::Text textcadre,int posx,int posy,int nbr1)
{
    std::stringstream ss;
    std::string stringnbr;
    ss<<nbr1;
    ss>>stringnbr;
    std::string NBR=stringnbr+"/2";
    if(!font7.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font7);
        textcadre.setString(NBR);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}
sf::Text Cadre::nbrconnect2(sf::Text textcadre,int posx,int posy,int nbr2)
{
    std::stringstream ss;
    std::string stringnbr;
    ss<<nbr2;
    ss>>stringnbr;
    std::string NBR=stringnbr+"/2";
    if(!font12.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font12);
        textcadre.setString(NBR);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::nbrconnect3(sf::Text textcadre,int posx,int posy,int nbr3)
{
    std::stringstream ss;
    std::string stringnbr;
    ss<<nbr3;
    ss>>stringnbr;
    std::string NBR=stringnbr+"/2";
    if(!font13.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font13);
        textcadre.setString(NBR);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::nbrconnectcp(sf::Text textcadre,int posx,int posy,int nbr)
{
    std::stringstream ss;
    std::string stringnbr;
    ss<<nbr;
    ss>>stringnbr;
    std::string NBR=stringnbr+"/2";
    if(!font19.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font19);
        textcadre.setString(NBR);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}


sf::CircleShape Cadre::ajouter_circle(sf::CircleShape Circle,int nbr,int Cx,int Cy)
{

    Circle.setRadius(8.f);
    if (nbr<2)
    {
        Circle.setFillColor(sf::Color::Green);
        Circle.setPosition(Cx,Cy);
        return Circle;
    }
    else
    {
        Circle.setFillColor(sf::Color::Red);
        Circle.setPosition(Cx,Cy);
        return Circle;
    }
}



sf::Text Cadre::date1(sf::Text textcadre,int posx,int posy,std::string chainedate)
{

    if(!font9.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font9);
        textcadre.setString(chainedate);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}


sf::Text Cadre::date2(sf::Text textcadre,int posx,int posy,std::string chainedate)
{

    if(!font14.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font14);
        textcadre.setString(chainedate);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::date3(sf::Text textcadre,int posx,int posy,std::string chainedate)
{

    if(!font15.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font15);
        textcadre.setString(chainedate);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}

sf::Text Cadre::datecp(sf::Text textcadre,int posx,int posy,std::string chainedate)
{

    if(!font17.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font17);
        textcadre.setString(chainedate);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}


sf::Text Cadre::etat(sf::Text textcadre,int posx,int posy,int nbr)
{

    std::string resultat;
    if(nbr<2)
    {
        resultat="Disponible";
    }
    if(nbr==2)
    {
        resultat="Indisponible";
    }

    if(!font18.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ../ressource/fonts.ttf"<<std::endl;
        return textcadre;
    }
    else
    {
        textcadre.setFont(font18);
        textcadre.setString(resultat);
        textcadre.setCharacterSize(30);
        textcadre.setPosition(posx,posy);
        textcadre.setColor(sf::Color(255,255,255));
        return  textcadre;
    }
}


