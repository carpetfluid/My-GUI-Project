#include "../include/GUI_Library/GUImain.hpp"

//Useful Variables

//GuiCheckbox

void MainGui::GuiCheckbox::Render() {
	if (!window) return;
	//Variables
	ActualWidth = size.y / 2; // Width of the checkbox shape
	LabelWidth = size.x - ActualWidth;

	sf::Vector2 LabelPosition = { position.x, position.y + size.y / 4 };
	sf::Vector2f CheckboxPosition = { position.x + LabelWidth - (ActualWidth / 2), position.y + size.y / 4 };
	
	//Label for the checkbox
	sf::Text RenderLabelText(FontPath);
	RenderLabelText.setString(CheckboxLabel);
	RenderLabelText.setFillColor(sf::Color::White);
	RenderLabelText.setCharacterSize(size.y *0.4f);

	//Centering the position of label text
	sf::Rect LabelTextBounds = RenderLabelText.getLocalBounds();
	
	RenderLabelText.setPosition(LabelPosition);

	//Making Checkbox shape
	sf::RectangleShape CheckboxShape({ActualWidth, ActualWidth});
	CheckboxShape.setPosition(CheckboxPosition);
	CheckboxShape.setOutlineColor(sf::Color::White);
	CheckboxShape.setOutlineThickness(2.0f);
	if(isChecked){
		CheckboxShape.setFillColor(sf::Color::Green);
	} else {
		CheckboxShape.setFillColor(sf::Color::Black);
		
	}
	window->draw(RenderLabelText);
	window->draw(CheckboxShape);
	

}
void MainGui::GuiCheckbox::HandleClick() {
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

	float ActualCheckboxX = position.x + LabelWidth - (ActualWidth / 2);
	float ActualCheckboxY = position.y + size.y / 4;

	bool isInside = mousePos.x >= ActualCheckboxX && mousePos.x <= ActualCheckboxX + ActualWidth &&
		mousePos.y >= ActualCheckboxY && mousePos.y <= ActualCheckboxY + size.y/2;
	
	if (isPressed && isInside && !wasPressed) {
		wasPressed = true;
		isChecked = !isChecked;// tylko raz na kliknięcie
		*linkedVariable = isChecked; // aktualizacja zmiennej powiązanej
	}
	else if (!isPressed) {
		wasPressed = false; // reset po puszczeniu myszy
	}
	if(*linkedVariable != isChecked) {
		isChecked = *linkedVariable; // synchronizacja stanu checkboxa z powiązaną zmienną
	}
}