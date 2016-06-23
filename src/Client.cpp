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
    unsigned short int pport = getPort() + 1;
    while(!socket.bind(port))
    {
        if (!socket.bind(pport))
        {
            pport = pport + 1;
        }
    }
    ip_serveur = "192.168.22.133";
    mesinfo.nom_partie="Partie de";
    mesinfo.adr_hote=sf::IpAddress::getLocalAddress().toString();
    mesinfo.nb_vie=3;
    mesinfo.scores=0;
    mesinfo.pleine=false;
    mesinfo.type_msg="";
    mesinfo.maliste.begin();
    std::cout<<"Création d'un client..."<<std::endl;
}
Client::~Client(){

}

unsigned short int Client::setPort (unsigned short int p_port){
    port = p_port;
    if(port == p_port){ return 0;}
    else { return 1;}
}

void Client::attendre(sf::RenderWindow& fenetre){

    sf::Packet packet_connexion;
    Info att_partie;
    do
    {
        std::cout<<"Attente d'un adversaire"<<std::endl;
        socket.receive(packet_connexion,ip_serveur,port);
        packet_connexion >> att_partie;
        att_partie.pleine = true;
    }while (!att_partie.pleine);
    Multi monjeu;
    monjeu.afficher(fenetre);
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
    if (reception.type_msg == "OK") std::cout<<"\tConnexion prise en compte"<<std::endl;
}

Cadre Client::creerUnePartie(sf::RenderWindow& fenetre){
    sf::Packet packet_connexion;
    mesinfo.type_msg="CREER";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Envoie d'une requête de création"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    if (reception.type_msg == "REPONSE"){
         std::cout<<"\tCréation rde partie prise en compte"<<std::endl;
        std::cout<<reception.type_msg<<std::endl;
        std::cout<<reception.nom_partie<<std::endl;
        std::cout<<reception.adr_hote<<std::endl;
        Cadre mon_cadre("OUVERT",reception.nom_partie,reception.adr_hote);
        attendre(fenetre);
        return mon_cadre;
    }
    else {
        std::cout<<"\tUne Erreur est survenue"<<std::endl;
        std::cout<<reception.type_msg<<std::endl;
        std::cout<<reception.nom_partie<<std::endl;
        std::cout<<reception.adr_hote<<std::endl;
        Cadre mon_cadre("Ferme",reception.nom_partie,reception.adr_hote);
        attendre(fenetre);
        return mon_cadre;
    }
}
void Client::rejoindreUnePartie(Cadre mon_cadre, sf::RenderWindow& fenetre){
    sf::Packet packet_connexion;
    mesinfo.type_msg="REJOINDRE";
    mesinfo.nom_partie = mon_cadre.getNomReseau();
    mesinfo.adr_hote=mon_cadre.getEtatPartie();
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Demande d'une partie"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    std::cout<<reception.type_msg<<std::endl;
    if (reception.type_msg == "OK")
    {
        std::cout<<"Une partie a été trouvée"<<std::endl;
        Multi partie;
        partie.afficher(fenetre);
    }
    else{
        std::cout<<"Aucune partie n'est disponnible."<<std::endl;
    }

}
Cadre Client::recupererListePartie(sf::RenderWindow& fenetre) {
    sf::Packet packet_connexion;
    mesinfo.type_msg="LISTE";
    packet_connexion << mesinfo;
    socket.send(packet_connexion,ip_serveur,port);
    std::cout<<"Demande de la liste"<<std::endl;
    socket.receive(packet_connexion,ip_serveur,port);
    Info reception;
    packet_connexion >> reception;
    std::cout<<reception.type_msg<<std::endl;
    if (reception.type_msg=="NON"){
        return creerUnePartie(fenetre);
    }
    else if (reception.type_msg == "OK"){
        std::cout<<"\tRécupération de la liste des parties"<<std::endl;
        Cadre mon_cadre("OUVERT",reception.nom_partie,reception.adr_hote);
        return mon_cadre;
    }
    else return Cadre();
}
