/*
 *  Type Fichier:   Header
 *  Nom Fichier :   Client.h
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#ifndef DPSI_CLIENT_H
#define DPSI_CLIENT_H
#pragma once

#include <iostream>
#include <list>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Multi.h"

class Client {

    public:
    struct Info
    {
        std::string type_msg;
        std::string nom_partie;
        std::string adr_hote;
        int scores;
        int nb_vie;
        bool pleine;
        std::list<Info> maliste;
    };

    friend sf::Packet& operator << (sf::Packet& packet, const Client::Info& info)
    {
        return packet << info.type_msg << info.nom_partie << info.adr_hote << info.scores << info.nb_vie;
    }

    friend sf::Packet& operator >> (sf::Packet& packet, Client::Info& info)
    {
        return packet >> info.type_msg >> info.nom_partie >> info.adr_hote >> info.scores >> info.nb_vie;
    }

    private:
    sf::UdpSocket socket;
    unsigned short int port;
    unsigned short int rport;
    const sf::IpAddress ip = sf::IpAddress::getLocalAddress();
     sf::IpAddress ip_serveur;
    Info mesinfo;

    public:
    Client();
    ~Client();
    unsigned short int getPort () const {return port;};
    unsigned short int setPort (unsigned short int p_port);
    const std::string getIp() const { return ip.toString();};
    void recupererListePartie() ;
    void seConnecter();
    void creerUnePartie(sf::RenderWindow& fenetre);
    void rejoindreUnePartie(sf::RenderWindow& fenetre);
};


#endif //DPSI_CLIENT_H
