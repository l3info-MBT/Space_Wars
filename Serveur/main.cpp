#include <iostream>
#include <fstream>
#include <list>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
    //on définit une structure
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

std::string genererLog()
{
    std::string msg = "";
    //Traitement de la génération de logs
    //Pas implémenter par manque de temps
    return msg;
}

    //surcharge des operateurs
    sf::Packet& operator <<(sf::Packet& packet, const Info& info){
        return packet << info.type_msg << info.nom_partie << info.adr_hote << info.scores << info.nb_vie;
    }

    sf::Packet& operator >>(sf::Packet& packet, Info& info){
        return packet >> info.type_msg >> info.nom_partie >> info.adr_hote >> info.scores >> info.nb_vie;
    }

int main()
{

    Info mesinfo;
    sf::Packet packet;
    sf::Packet rpacket;
    int nbclient =0;
    std::list<Info> maliste;
    std::list<Info> it;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    std::cout<<ip<<std::endl;
    it = maliste.begin();
    std::cout<<"Ouverture des Logs ..."<<std::endl;
    std::ofstream fichier("log.txt", std::ios::out | std::ios::ate);

    if(fichier)
    {
        std::cout<<"\tOuverture Réussi!\n"<<std::endl;

        std::cout<<"Création d'un socket udp liè au port 55002 ..."<<std::endl;
        sf::UdpSocket socket;
        socket.bind(55002);
        std::cout<<"Serveur en fonctionnement"<<std::endl;

        //Création des variables de traitements
        char buffer[1024];
        std::size_t received = 0;
        sf::IpAddress sender;
        unsigned short port;
        bool serv = true;

        while (serv)
        {
            Info reponse;
            socket.receive(packet,sender,port);
            packet >> mesinfo;

            if(mesinfo.type_msg == "CONNEXION" )
            {
                nbclient++;    
                std::cout<<"Ajout d'un client :"<< sender.toString()<< std::endl;
                reponse.type_msg = "OK";
                rpacket << reponse;
                socket.send(rpacket,sender,port);
                std::cout<<reponse.type_msg<<std::endl;
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }

            if(mesinfo.type_msg == "CREER" )
            {  
                std::cout<<"Le client :"<< sender.toString()<<" demande de créer une partie"<< std::endl;
                reponse.type_msg = "OK";
                std::string ip = sender.toString()
                reponse.nom_partie= "Partie de " + ip;
                reponse.pleine = false;
                maliste.push_back(mesinfo.maliste);
                rpacket << reponse;
                socket.send(rpacket,sender,port);
                std::cout<<reponse.type_msg<<std::endl;
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }

            if(mesinfo.type_msg == "REJOINDRE" )
            {   
                std::cout<<"Le client "<<sender.toString()<<" recherche une partie"<<std::endl;
            }

            if(mesinfo.type_msg == "LISTE" )
            {  
                std::cout<<"Le client "<<sender.toString()<<" demande la lite des parties"<<std::endl;
                reponse.type_msg = "OK";
                reponse.maliste = maliste;
                rpacket << reponse;
                socket.send(rpacket,sender,port);
                std::cout<<reponse.type_msg<<std::endl;
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }

            fichier << genererLog();
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Erreur lors de l'ouverture des logs !" << std::endl;
        return 2;
    }
    std::cout<<"Fin du test"<<std::endl;
    return 0;
}

/*
*/