#include "../include/GUI_Library/CreatingWidgets.hpp"

//Usefull Variables


std::shared_ptr<MainGui::GuiButton> CreateButton(
    std::string ButtonText,
    sf::Color ButtonTextColor,
    std::string ButtonLabel,
    sf::Color ButtonColor,
    float ButtonWidth,
    sf::Color ButtonHoverColor
    
) {
    auto button = std::make_shared<MainGui::GuiButton>();
	button->ButtonText = ButtonText;
    button->ButtonTextColor = ButtonTextColor;
    button->ButtonLabel = ButtonLabel;
    button->ButtonColor = ButtonColor;
    button->ButtonHoverColor = ButtonHoverColor;
    button->ActualWidth = ButtonWidth;
	return button;
}
//===========================================================
std::shared_ptr<MainGui::GuiCheckbox> CreateCheckbox(
    bool* LinkedVariable,
    std::string CheckboxLabel,
    bool isChecked
){
    auto checkbox = std::make_shared<MainGui::GuiCheckbox>();
    checkbox->linkedVariable = LinkedVariable;
    checkbox->CheckboxLabel = CheckboxLabel;
    checkbox->isChecked = isChecked;
    return checkbox;
}
//===========================================================
std::shared_ptr<MainGui::GuiRadio> CreateRadio(
    float* linkedVariable,
    float RadioValue,
    std::string RadioLabel,
    sf::Color custonLabelColor, // Custom color for the label
    sf::Color customRadioColor // Custom color for the radio and label
) {
        auto radio = std::make_shared<MainGui::GuiRadio>();
    radio->linkedVariable = linkedVariable;
    radio->RadioValue = RadioValue;
    radio->RadioLabel = RadioLabel;
    radio->custonLabelColor = custonLabelColor;
    radio->customRadioColor = customRadioColor;
	return radio;
}
//===========================================================
std::shared_ptr<MainGui::GuiNumber> CreateNumber(
    int* Value,
    std::string NumberLabel,
    int stepValue
) {
    auto number = std::make_shared<MainGui::GuiNumber>();
    number->Value = Value;
    number->NumberLabel = NumberLabel;
    number->stepValue = stepValue;
    return number;
}
//==========================================================
std::shared_ptr<MainGui::GuiSlider> CreateSlider(
    float* linkedVariable,
    std::string SliderLabel,
    float MinValue,
    float MaxValue,
    float StepValue,
    sf::Color SliderColor,
    sf::Color SliderBoxColor
) {
    auto slider = std::make_shared<MainGui::GuiSlider>();
    slider->LinkedVariable = linkedVariable;
    slider->SliderLabel = SliderLabel;
    slider->MinValue = MinValue;
    slider->MaxValue = MaxValue;
	slider->StepValue = StepValue;
    slider->SliderColor = SliderColor;
    slider->SliderBoxColor = SliderBoxColor;
    return slider;
}