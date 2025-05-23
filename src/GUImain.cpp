#include <iostream>
#include <SFML/Graphics.hpp>

#include "GUImain.hpp"


//Main GUI CLASS
MainGui::MainGui(
    sf::RenderWindow& window,
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color backgroundColor,
    float widgetHeight
    //std::vector<std::unique_ptr<Widget>>&& widgets
    )
    : window(window),
    position(position),
    size(size),
    backgroundColor(backgroundColor),
    widgetHeight(widgetHeight)
{
    //addWidgets(std::move(widgets));
}

/*void MainGui::addWidgets(std::vector<std::unique_ptr<Widget>>&& givenWidgets) {
    float yOffset = 0;

    for (auto& widget : givenWidgets) {
        widget->window = &window;

        if(!widget->hasPosition) {
			widget->position = sf::Vector2f(position.x, position.y + yOffset);
			widget->hasPosition = true;
        }
		widget->size = sf::Vector2f(size.x, widgetHeight);
        yOffset += widgetHeight;
		this->Widgets.push_back(std::move(widget));
    }
}*/

void MainGui::addWidget(const std::shared_ptr<Widget>& widget) {
    auto widgetCopy = widget->clone(); // clone the widget

    widgetCopy->window = &window;
    widgetCopy->position = sf::Vector2f(position.x, position.y + Widgets.size() * widgetHeight);
    widgetCopy->size = sf::Vector2f(size.x, widgetHeight);

    Widgets.push_back(std::move(widgetCopy));
}
void MainGui::Render() {
    for (auto& widget : Widgets) {
        widget->Render();
    }
}

//BUTTON CLASS
void MainGui::GuiButton::Render() {
    if (!window) return;
	HandleClick(); // Check for click events
    sf::RectangleShape Button;
    sf::Font font("C:/Users/jack9/OneDrive/Pulpit/PROGRAMOWANIE/C++/Grafika/GUI PROJECT/MyTryAtGui/assets/arial.ttf");

    sf::Text text(font);
    text.setString(GuiText);
    text.setCharacterSize(size.y / 2);
    text.setFillColor(textColor);
    text.setPosition({ position.x, position.y + size.y / (size.y / 2) });
    Button.setPosition(position);
    Button.setFillColor(backgroundColor);
    Button.setSize(size);
    window->draw(Button);
    window->draw(text);
}

void MainGui::GuiButton::HandleClick() {
    bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    bool isInside = mousePos.x >= position.x && mousePos.x <= position.x + size.x &&
        mousePos.y >= position.y && mousePos.y <= position.y + size.y;

    if (isPressed && isInside && !wasPreviouslyPressed) {
        wasPreviouslyPressed = true;
        if (onClick) onClick(); // tylko raz na klikniêcie
    }
    else if (!isPressed) {
        wasPreviouslyPressed = false; // reset po puszczeniu myszy
    }
}



