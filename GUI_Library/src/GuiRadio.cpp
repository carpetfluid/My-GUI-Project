#include "../include/GUI_Library/GUImain.hpp"


//GuiRadio

void MainGui::GuiRadio::Render() {
		if (!window) return;
		//Making a Label for Radio
		ActualWidth = size.y / 2; // Width of the checkbox shape
		LabelWidth = size.x - ActualWidth;
		sf::Text RenderLabelText(FontPath);
		RenderLabelText.setString(RadioLabel);
		RenderLabelText.setFillColor(custonLabelColor);
		RenderLabelText.setCharacterSize(size.y / 2);
		//Centering the position of label text
		sf::Rect LabelTextBounds = RenderLabelText.getLocalBounds();
		sf::Vector2 LabelPosition = { position.x, position.y + size.y / 4 };
		RenderLabelText.setPosition(LabelPosition);
		//Making Checkbox shape
		sf::CircleShape RadioShape(size.y / 4);
		//RadioShape.setOrigin({ size.y / 4, size.y / 4 }); // Set origin to center of the circle
		RadioShape.setPosition({ position.x + LabelWidth - (ActualWidth/2), position.y + size.y / 4 });
		RadioShape.setOutlineThickness(4.0f);
		if (isChecked) {
			RadioShape.setFillColor(customRadioColor);
			RadioShape.setOutlineColor(sf::Color::White);
		}
		else {
			RadioShape.setFillColor(sf::Color::White);
			RadioShape.setOutlineColor(customRadioColor);
		}
		window->draw(RenderLabelText);
		window->draw(RadioShape);
}
void MainGui::GuiRadio::HandleClick() {
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

	// Calculate center of the circular radio button
	float centerX = position.x + LabelWidth - (ActualWidth/2) + ActualWidth / 2;
	float centerY = position.y + size.y / 2;
	float radius = ActualWidth / 2;

	// Calculate distance from mouse to center of the circle
	float dx = mousePos.x - centerX;
	float dy = mousePos.y - centerY;
	bool isInside = (dx * dx + dy * dy) <= (radius * radius);

	if (RadioValue != *linkedVariable) 
		isChecked = false;
	if(isChecked == false && isPressed && isInside && !wasPressed) {
		isChecked = true;
		*linkedVariable = RadioValue;
		wasPressed = true;
	}
	else if (isPressed && isInside && !wasPressed) {
		isChecked = false;
		*linkedVariable = -1; // Reset the linked variable if unchecked
		wasPressed = true;
	}
	else if (!isPressed) {
		wasPressed = false; // reset po puszczeniu myszy
	}
}