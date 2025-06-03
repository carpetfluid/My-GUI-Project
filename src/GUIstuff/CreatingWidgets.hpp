#pragma once

#include "GUImain.hpp"

std::shared_ptr<MainGui::GuiButton> CreateButton(
    std::string ButtonText = "Button",
    sf::Color ButtonTextColor = sf::Color::White,
    std::string ButtonLabel = "",
    sf::Color ButtonColor = sf::Color(194, 194, 194, 255),
    float ButtonWidth = 100.0f,
    sf::Color ButtonHoverColor = sf::Color(40, 44, 75)
);

std::shared_ptr<MainGui::GuiCheckbox> CreateCheckbox(
    bool* LinkedVariable,
    std::string CheckboxLabel = "Checkbox",
    bool isChecked = false
);

std::shared_ptr<MainGui::GuiRadio> CreateRadio(
    float* linkedVariable,
    float RadioValue = 0.0f,
    std::string RadioLabel = "",
    sf::Color custonLabelColor = sf::Color::White, // Custom color for the label
    sf::Color customRadioColor = sf::Color::White // Custom color for the radio and label
);