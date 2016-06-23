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
        int scoresj1;
        int scoresj2;
        int nb_vie;
        bool pleine;
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
    Info partie;
    sf::Packet packet;
    int nbclient =0;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    bool is_partie =false;

    std::cout<<"Ouverture des Logs ..."<<std::endl;
    std::ofstream fichier("log.txt", std::ios::out | std::ios::ate);

    if(fichier)
    {
        std::cout<<"\tOuverture Réussi!\n"<<std::endl;
        std::cout<<ip<<std::endl;

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
        std::cout<<"Nombre de partie :"<<is_partie<< std::endl;
        while (serv)
        {
            Info reponse;
            socket.receive(packet,sender,port);
            packet >> mesinfo;

            if(mesinfo.type_msg == "CONNEXION" )
            {
                sf::Packet rpacket;
                nbclient++;    
                std::cout<<"Ajout d'un client :"<< sender.toString()<< std::endl;
                reponse.type_msg = "OK";
                rpacket << reponse;
                socket.send(rpacket,sender,port);
                std::cout<<reponse.type_msg<<std::endl;
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }

            if(mesinfo.type_msg == "CREER" )
            {  sf::Packet rpacket;
                std::cout<<"Le client "<< sender.toString()<<" demande de créer une partie"<< std::endl;
                reponse.type_msg = "REPONSE";
                std::string ip = sender.toString();
                reponse.nom_partie= "Partie de " + ip;
                reponse.pleine = false;
                reponse.adr_hote = ip  ;
                partie.nom_partie= "Partie de " + ip;
                partie.pleine = false;
                partie.adr_hote = ip   ;
                rpacket << reponse;
                is_partie = true;   
                socket.send(rpacket,sender,port);
                std::cout<<reponse.type_msg<<std::endl;
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }


            if(mesinfo.type_msg == "REJOINDRE" )
            {
                std::cout<<"Le client "<<sender.toString()<<" recherche une partie"<<std::endl;
                if (is_partie)
				{
                    sf::Packet rpacket;
                    reponse.type_msg ="OK";
                    reponse.nom_partie= partie.nom_partie;
					reponse.pleine = true;
					reponse.adr_hote = partie.adr_hote;
                    rpacket << reponse;
                    socket.send(rpacket,sender,port);
                    socket.send(rpacket,partie.adr_hote,port);
                }
                else
                {
                    sf::Packet rpacket;
                    reponse.type_msg = "NON";
                    socket.send(rpacket,sender,port);
                    std::cout<<"La partie n'existe pas"<<std::endl;
                }
            }

            if(mesinfo.type_msg == "LISTE" )
            {  
                std::cout<<"Le client "<<sender.toString()<<" demande la lite des parties"<<std::endl;
                if (is_partie) {
                    sf::Packet rpacket;
                    std::cout<<"Il existe actuellement : "<<is_partie<<" sur le serveur"<<std::endl;
                    reponse.type_msg = "OK";
                    reponse.nom_partie = partie.nom_partie;
                    reponse.pleine = partie.pleine;
                    reponse.adr_hote = partie.adr_hote;
                    rpacket << reponse;
                    socket.send(rpacket,sender,port);
                }
                else {
                    sf::Packet rpacket;
                    std::cout<<"Il existe actuellement : "<<is_partie<<" sur le serveur"<<std::endl;
                    reponse.type_msg ="NON";
                    std::cout<<reponse.type_msg<<std::endl;
                    rpacket << reponse;
                    socket.send(rpacket,sender,port);
                }
                std::cout<<"\t Envoie d'une réponse à "<<sender.toString()<<std::endl;
            }

            if(mesinfo.type_msg == "SCORES" )
            {
                if(mesinfo.adr_hote == partie.adr_hote) partie.scoresj1=mesinfo.scorej1;
                else partie.scoresj2=mesinfo.scorej2;
                sf::Packet rpacket;
                std::cout<<"envoie du score à  "<<is_partie<<std::endl;
                reponse.type_msg ="OK";
                reponse.scoresj1=partie.scoresj1;
                reponse.scoresj2=partie.scoresj2;
                rpacket << reponse;
                socket.send(rpacket,sender,port);
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
