/*
 *  Type Fichier:   Cpp
 *  Nom Fichier :   Client.cpp
 *  Projet      :   DPSI
 *  Etudiant    :   Deborguere Tony
 *                  Tekeli Baris
 *                  Touat Malik
 *                  Zhiwen Qi
 */

#include "Client.h"

Client::Client(){
    setPort(55002);
    socket.bind(port);
    sf::Packet packet;
    if (ip_serveur == NULL){
        socket.receive(packet,ip_serveur,rport);
    }
    mesinfo.nom_partie="Partie de";
    mesinfo.adr_hote=sf::IpAddress::getLocalAddress().toString();
    mesinfo.nb_vie=3;
    mesinfo.scores=0;
    mesinfo.pleine=false;
    mesinfo.type_msg="";
}
Client::~Client(){

}

unsigned short int Client::setPort (unsigned short int p_port){
    port = p_port;
    if(port == p_port){ return 0;}
    else { return 1;}
}

void Client::seConnecter(){
    sf::Packet packet_connexion;
    mesinfo.type_msg="CONNEXION";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Demande de connexion au serveur"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    if (reception.type_msg == "OK") std::cout<<"Connexion prise en compte"<<std::endl;
}

void Client::creerUnePartie(sf::RenderWindow &fenetre){
    sf::Packet packet_connexion;
    mesinfo.type_msg="CREER";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Envoie d'une requête de création"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    do {
        if (reception.type_msg == "OK") std::cout<<"Création de partie prise en compte"<<std::endl;
        socket.receive(packet_connexion,ip_serveur,port);
        packet_connexion >> reception;
        std::cout<<"Attente d'un autre adversaire"<<std::endl;
    }while(reception.type_msg !="TROUVE");
    Multi partie;
    partie.afficher(fenetre);
}
void Client::rejoindreUnePartie(sf::RenderWindow &fenetre){
    sf::Packet packet_connexion;
    mesinfo.type_msg="REJOINDRE";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Demande d'une partie"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    if (reception.type_msg == "OK")
    {
        std::cout<<"Une partie a été trouvée"<<std::endl;
        Multi partie;
        partie.afficher(fenetre);
    }
    else{
        std::cout<<"Aucune partie n'est disponnible création d'une partie"<<std::endl;
        creerUnePartie(fenetre);
    }

}
void Client::recupererListePartie() {
    sf::Packet packet_connexion;
    mesinfo.type_msg="LISTE";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Demande de la liste"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    if (reception.type_msg == "OK"){
        std::cout<<"Récupération de la liste des parties"<<std::endl;
        mesinfo.maliste = reception.maliste;
        if (mesinfo.maliste.size())std::cout<<"la liste n'est pas vide"<<std::endl;
    }
}