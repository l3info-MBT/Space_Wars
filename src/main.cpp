//Inclusion des Librairies
#include <iostream>
#include <SFML/Graphics.hpp>

//Inclusion des Dépendances
#include "menu.hpp"


//Code
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "Space Wars", sf::Style::Close | sf::Style::Titlebar);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
