#include "../include/GUI_Library/GUImain.hpp"
//Useful Variables

//GuiButton

void MainGui::GuiButton::Render() {
	if (!window) return;
	//Variables
	LabelWidth = size.x - ActualWidth;
	sf::Vector2 LabelPosition = {position.x, position.y + size.y/4};
	sf::Vector2f ButtonPosition{ position.x + LabelWidth, position.y };
	//Making a Label for the button
	
	sf::Text RenderLabelText(FontPath);
	RenderLabelText.setString(ButtonLabel);
	RenderLabelText.setFillColor(sf::Color::White);
	RenderLabelText.setCharacterSize(size.y/2);
	//Centering the position of label text
	sf::Rect LabelTextBounds = RenderLabelText.getLocalBounds();
	
	RenderLabelText.setPosition(LabelPosition);

	//Making a button shape
	sf::RectangleShape Button;
	Button.setSize({ActualWidth,size.y});
	Button.setPosition(ButtonPosition);
	if(isHovered) {
		Button.setFillColor(ButtonHoverColor);
	} else {
		Button.setFillColor(ButtonColor);
	}
	//Making a Button Text
	sf::Text RenderButtonText(FontPath);
	RenderButtonText.setString(ButtonText);
	
	RenderButtonText.setFillColor(ButtonTextColor);
	RenderButtonText.setCharacterSize(size.y / 4);
	sf::Rect ButtonTextBounds = RenderButtonText.getLocalBounds();

	sf::Vector2f ButtonTextPosition = { position.x + (LabelWidth + ActualWidth / 2) - (ButtonTextBounds.size.x / 2),position.y + (size.y / 2) - ButtonTextBounds.size.y };

	RenderButtonText.setPosition(ButtonTextPosition);

	window->draw(RenderLabelText);
	window->draw(Button);
	window->draw(RenderButtonText);

}

void MainGui::GuiButton::HandleClick() {
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

	float ActualButtonX = position.x + LabelWidth;
	bool isInside = mousePos.x >= ActualButtonX && mousePos.x <= ActualButtonX + ActualWidth &&
		mousePos.y >= position.y && mousePos.y <= position.y + size.y;
	if (isInside) {
		isHovered = true;
	}
	else if (!isInside) {
		isHovered = false;
	}
	if (isPressed && isInside && !wasPressed) {
		wasPressed = true;
		if (onClick) onClick(); // tylko raz na kliknięcie
	}
	else if (!isPressed) {
		wasPressed = false; // reset po puszczeniu myszy
	}

}
