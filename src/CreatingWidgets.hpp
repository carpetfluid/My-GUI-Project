#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GUImain.hpp"

//Deklaracja Funkcji Dodawania Widgets

std::shared_ptr<MainGui::GuiButton> createButton(
    const std::string& Label,
    sf::Color BackgroundColor,
    sf::Color TextColor
);