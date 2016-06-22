
#include "Cadre.h"

Cadre::Cadre(){
    cpt_cadre++;
    nbcadre = cpt_cadre;
    type="OUVERT";
    nom_reseaux ="EXEMPLE";
    etat_partie ="Partie de test";
    nbplace=1;
}
Cadre::~Cadre(){
    cpt_cadre--;
}

Cadre::Cadre(std::string ptype){
    type=ptype;
    cpt_cadre++;
    nbcadre = cpt_cadre;
    type="FERMER";
    nom_reseaux="Partie Indisponnible";
    etat_partie="Ce slot est Ferme";
    nbplace=0;
}
Cadre::Cadre (std::string ptype,std::string pnom_reseaux,std::string petat_partie){
    cpt_cadre++;
    nbcadre = cpt_cadre;
    type=ptype;
    nom_reseaux=pnom_reseaux;
    etat_partie=petat_partie;
    nbplace=1;
}

void Cadre::setType(std::string p_type){
    type = p_type;
}
void Cadre::setNomReseau(std::string p_nom){
    nom_reseaux = p_nom;
}
void Cadre::setEtatPartie(std::string p_etat){
    etat_partie = p_etat;
}
void Cadre::setNbPlace(int p_nbjoueur){
    nbplace = p_nbjoueur;
}
void Cadre::afficher_cadre(sf::RenderWindow& fenetre){
    sf::Font font;
    if(!font.loadFromFile("ressource/fonts.ttf"))
    {
        std::cout<<"Erreur durant le chargement de ficher ressource/fonts.ttf"<<std::endl;
        return;
    }

    sf::RectangleShape cadre;
    cadre.setSize(sf::Vector2f(598,394/3.f));
    cadre.setOutlineThickness(2);
    cadre.setOutlineColor(sf::Color(0,0,0,255));
    cadre.setFillColor(sf::Color(0,0,0,0));
    cadre.setPosition(101,101+((394/3.f)*nbcadre));

    sf::Text NomReseau;
    NomReseau.setFont(font);
    NomReseau.setString(nom_reseaux);
    NomReseau.setCharacterSize(30);
    NomReseau.setPosition(180,120+(120*nbcadre));
    NomReseau.setColor(sf::Color(255,255,255));
    NomReseau.setStyle(sf::Text::Bold);

    sf::Text EtatPartie;
    EtatPartie.setFont(font);
    EtatPartie.setString(etat_partie);
    EtatPartie.setCharacterSize(20);
    EtatPartie.setPosition(105,180+(120*nbcadre));
    EtatPartie.setColor(sf::Color(255,255,255));

    sf::CircleShape status;
    status.setRadius(10);
    if (getNbPlace() == 1) status.setFillColor(sf::Color(0,255,0));
    if (getNbPlace() != 1) status.setFillColor(sf::Color(255,0,0));
    status.setPosition(550,185+(120*nbcadre));

    std::string msg;
    sf::Text NbJoueur;
    NbJoueur.setFont(font);
    if (type=="FERMER") msg = "0/2";
    else  msg = "1/2";
    NbJoueur.setString(msg);
    NbJoueur.setCharacterSize(20);
    NbJoueur.setPosition(580,180+(120*nbcadre));
    NbJoueur.setColor(sf::Color(255,255,255));
    fenetre.draw(cadre);
    fenetre.draw(NomReseau);
    fenetre.draw(EtatPartie);
    fenetre.draw(NbJoueur);
    fenetre.draw(status);
}

int Cadre::cpt_cadre=-1;