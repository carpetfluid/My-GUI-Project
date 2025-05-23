#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>

#include "GUImain.hpp" 
#include "CreatingWidgets.hpp"

int main()
{

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    std::string test = "Nie klikniête";

    
    MainGui myGui(window, { 0,0 }, { 100,200 }, sf::Color::White, 50);

    auto button1 = createButton("Button1", sf::Color::Red, sf::Color::White);
    auto button2 = createButton("Button2", sf::Color::Green, sf::Color::White);
    button1->onClick =[&test]() {
        test = "Klikniety";
        };

    myGui.addWidget(button1);
    myGui.addWidget(button2);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        std::cout << test << std::endl;

        myGui.Render();

        window.display();
    }
}
