#include "../GUImain.hpp"
//Useful Variables
sf::Font WidgetFontButton("C:/Users/jack9/OneDrive/Pulpit/PROGRAMOWANIE/C++/Grafika/GUI PROJECT/MyTryAtGuiRework/assets/arial.ttf");


//GuiButton

void MainGui::GuiButton::Render() {
	if (!window) return;
	
	//Making a Label for the button
	LabelWidth = size.x - ActualWidth;
	sf::Text RenderLabelText(WidgetFontButton);
	RenderLabelText.setString(ButtonLabel);
	RenderLabelText.setFillColor(sf::Color::White);
	RenderLabelText.setCharacterSize(size.y/2);
	RenderLabelText.setPosition(position);
	//Making a button shape
	sf::RectangleShape Button;
	Button.setSize({ActualWidth,size.y});
	Button.setPosition({position.x+LabelWidth, position.y});
	if(isHovered) {
		Button.setFillColor(ButtonHoverColor);
	} else {
		Button.setFillColor(ButtonColor);
	}
	//Making a Button Text
	sf::Text RenderButtonText(WidgetFontButton);
	RenderButtonText.setString(ButtonText);
	
	RenderButtonText.setFillColor(ButtonTextColor);
	RenderButtonText.setCharacterSize(size.y / 2);
	RenderButtonText.setPosition({(size.x-ActualWidth/2)+position.x,position.y});
	sf::Rect ButtonTextBounds = RenderButtonText.getLocalBounds();
	RenderButtonText.setOrigin({ ButtonTextBounds.position.x+ButtonTextBounds.size.x/2.0f, 0.f});
	//RenderButtonText.setPosition({ ButtonTextBounds.position.x + ButtonTextBounds.size.x / 2.0f,position.y });

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
		if (onClick) onClick(); // tylko raz na klikniêcie
	}
	else if (!isPressed) {
		wasPressed = false; // reset po puszczeniu myszy
	}
}

