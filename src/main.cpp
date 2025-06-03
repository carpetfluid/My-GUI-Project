#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>

#include "GUIstuff/GUImain.hpp"
#include "GUIstuff/CreatingWidgets.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode()), "GUI TEST SCREEN");
    
    window.setFramerateLimit(144);

    MainGui GUItest(window, { 1,1 }, { 600,10 }, sf::Color(0,0,255,180), "TestGuiLabel", 100);
  

    auto button1 = CreateButton("Button1", sf::Color::White, "Label Test", sf::Color(10,10,10), 200);
    auto button2 = CreateButton("Button2", sf::Color::Red, "Label2", sf::Color(10, 10, 10), 200);

	bool TestZmienna = false;
    auto Checkbox1 = CreateCheckbox(&TestZmienna, "CheckboxTest");

    float radioValue = -1.0f;
    auto radio1 = CreateRadio(&radioValue, 1,"RadioValue: 1", sf::Color::White, sf::Color::Magenta);
    auto radio2 = CreateRadio(&radioValue, 2, "RadioValue: 2", sf::Color::White, sf::Color::Magenta);
    auto radio3 = CreateRadio(&radioValue, 3, "RadioValue: 3", sf::Color::White, sf::Color::Magenta);
   
	GUItest.addWidget(button1);
    GUItest.addWidget(button2);
	GUItest.addWidget(Checkbox1);
	GUItest.addWidget(radio1);
	GUItest.addWidget(radio2);
	GUItest.addWidget(radio3);


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
        GUItest.Render();
		std::cout << "RadioValue: " << radioValue << std::endl;
        
        window.display();
    }
}
