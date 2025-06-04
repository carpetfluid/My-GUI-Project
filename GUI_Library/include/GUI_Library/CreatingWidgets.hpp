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
//==========================================================
std::shared_ptr<MainGui::GuiCheckbox> CreateCheckbox(
    bool* LinkedVariable,
    std::string CheckboxLabel = "Checkbox",
    bool isChecked = false
);
//==========================================================
std::shared_ptr<MainGui::GuiRadio> CreateRadio(
    float* linkedVariable,
    float RadioValue = 0.0f,
    std::string RadioLabel = "",
    sf::Color custonLabelColor = sf::Color::White, // Custom color for the label
    sf::Color customRadioColor = sf::Color::White // Custom color for the radio and label
);
//==========================================================
std::shared_ptr<MainGui::GuiNumber> CreateNumber(
    int* Value = 0,
    std::string NumberLabel = "",
    int stepValue = 1
);
//==========================================================
std::shared_ptr<MainGui::GuiSlider> CreateSlider(
    float* linkedVariable,
    std::string SliderLabel = "Slider",
    float MinValue = -100.0f,
    float MaxValue = 100.0f,
    float StepValue = 1.0f,
    sf::Color SliderColor = sf::Color::White,
    sf::Color SliderBoxColor = sf::Color::White
);