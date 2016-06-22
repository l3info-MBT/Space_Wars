//
// Created by tony on 21/06/16.
//

#ifndef DPSI_CADRE_H
#define DPSI_CADRE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

class Cadre {
    private:
        static int cpt_cadre;
        int nbcadre;
        std::string type;
        std::string nom_reseaux;
        std::string etat_partie;
        int nbplace;

    public:

        Cadre();
        ~Cadre();

        Cadre (std::string ptype);
        Cadre (std::string ptype,std::string nom_reseaux,std::string etat_partie);

        std::string getType() const { return type; };
        std::string getNomReseau() const { return nom_reseaux; };
        std::string getEtatPartie() const { return etat_partie; };
        int getNbPlace() const { return nbplace; };

        void setType(std::string p_type);
        void setNomReseau(std::string p_nom);
        void setEtatPartie(std::string p_etat);
        void setNbPlace(int p_nbjoueur);

        void afficher_cadre(sf::RenderWindow& fenetre);
};

#endif //DPSI_CADRE_H
