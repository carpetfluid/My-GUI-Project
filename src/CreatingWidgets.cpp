#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "CreatingWidgets.hpp"
#include "GUImain.hpp"

//Functions to create Widgets
std::shared_ptr<MainGui::GuiButton> createButton(
    const std::string& Label,
    sf::Color BackgroundColor,
    sf::Color TextColor
) {
    auto button = std::make_shared<MainGui::GuiButton>();
    button->GuiText = Label;
    button->backgroundColor = BackgroundColor;
    button->textColor = TextColor;
    return button;
}
