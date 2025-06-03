#include "../GUImain.hpp"

//Useful Variables
sf::Font WidgetFontCheckbox("C:/Users/jack9/OneDrive/Pulpit/PROGRAMOWANIE/C++/Grafika/GUI PROJECT/MyTryAtGuiRework/assets/arial.ttf");

//GuiCheckbox

void MainGui::GuiCheckbox::Render() {
	if (!window) return;

	//Label for the checkbox
	ActualWidth = size.y / 2; // Width of the checkbox shape
	LabelWidth = size.x - ActualWidth;
	sf::Text RenderLabelText(WidgetFontCheckbox);
	RenderLabelText.setString(CheckboxLabel);
	RenderLabelText.setFillColor(sf::Color::White);
	RenderLabelText.setCharacterSize(size.y / 2);
	RenderLabelText.setPosition(position);
	//Making Checkbox shape
	sf::RectangleShape CheckboxShape({size.y / 2, size.y / 2});
	CheckboxShape.setPosition({position.x + LabelWidth-(ActualWidth*3)/2, position.y + size.y / 4});
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

	float ActualCheckboxX = position.x + LabelWidth - (ActualWidth * 3) / 2;
	float ActualCheckboxY = position.y + size.y / 4;
	bool isInside = mousePos.x >= ActualCheckboxX && mousePos.x <= ActualCheckboxX + ActualWidth &&
		mousePos.y >= ActualCheckboxY && mousePos.y <= ActualCheckboxY + size.y/2;
	
	if (isPressed && isInside && !wasPressed) {
		wasPressed = true;
		isChecked = !isChecked;// tylko raz na klikniêcie
		*linkedVariable = isChecked; // aktualizacja zmiennej powi¹zanej
	}
	else if (!isPressed) {
		wasPressed = false; // reset po puszczeniu myszy
	}
	if(*linkedVariable != isChecked) {
		isChecked = *linkedVariable; // synchronizacja stanu checkboxa z powi¹zan¹ zmienn¹
	}
}