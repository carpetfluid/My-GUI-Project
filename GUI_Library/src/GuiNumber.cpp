#include "../include/GUI_Library/GUImain.hpp"
//Useful Variables

//GuiNumber

void MainGui::GuiNumber::Render() {
	if (!window) return;
	//Variables
	float ButtonSize = (size.y / 5) * 2;

	ActualWidth = (size.y /5) *8;
	LabelWidth = size.x - ActualWidth;

	sf::Vector2 LabelPosition = { position.x, position.y + size.y / 4 };
	sf::Vector2 ContainerPosition = { position.x + LabelWidth - (ActualWidth / 10),position.y + size.y / 10 };

	sf::Vector2 addNumPos = { position.x + LabelWidth - (ActualWidth / 10) + ActualWidth - ButtonSize, position.y + size.y / 10 };
	sf::Vector2 subNumPos = { position.x + LabelWidth - (ActualWidth / 10) + ActualWidth - ButtonSize, position.y + (size.y / 10) + (size.y / 5) * 2 };

	//Number Display
	sf::Text numberDisplay(FontPath);
	numberDisplay.setString(DisplayNumber);
	numberDisplay.setCharacterSize(ButtonSize);
	numberDisplay.setFillColor(sf::Color::White);
	
	sf::Rect numberDisplayBounds = numberDisplay.getLocalBounds();
	if (numberDisplayBounds.size.x > ActualWidth - ButtonSize) {
		if (isNumSelected) {
			ActualWidth = numberDisplayBounds.size.x * 1.5;
			LabelWidth = size.x - ActualWidth;
		}
		else {
			numberDisplay.setString("click");
			numberDisplayBounds = numberDisplay.getLocalBounds();
		}
	}

	//Making a Label for the Number
	
	sf::Text RenderLabelText(FontPath);
	RenderLabelText.setString(NumberLabel);
	RenderLabelText.setFillColor(sf::Color::White);
	RenderLabelText.setCharacterSize(size.y / 2);
	//Centering the position of label text
	sf::Rect LabelTextBounds = RenderLabelText.getLocalBounds();
	RenderLabelText.setPosition(LabelPosition);

	//Making a NumberShape
	sf::RectangleShape NumberContainer({ ActualWidth,(size.y/5)*4 });
	NumberContainer.setFillColor(sf::Color::Black);
	NumberContainer.setOutlineThickness(1.0f);
	NumberContainer.setOutlineColor(sf::Color::White);

	NumberContainer.setPosition(ContainerPosition);

	//Making the buttons
	
	//First Button
	sf::RectangleShape addNumButton({ ButtonSize, ButtonSize });

	addNumButton.setFillColor(sf::Color::Black);
	addNumButton.setOutlineThickness(1.0f);
	addNumButton.setOutlineColor(sf::Color::White);
	
	addNumButton.setPosition(addNumPos);

	sf::CircleShape upArrow(ButtonSize / 2, 3);
	upArrow.setFillColor(sf::Color::White);

	upArrow.setPosition(addNumPos);


	//Second Button
	sf::RectangleShape subNumButton({ ButtonSize, ButtonSize });

	subNumButton.setFillColor(sf::Color::Black);
	subNumButton.setOutlineThickness(1.0f);
	subNumButton.setOutlineColor(sf::Color::White);

	subNumButton.setPosition(subNumPos);

	sf::CircleShape downArrow(ButtonSize / 2, 3);
	downArrow.setFillColor(sf::Color::White);
	downArrow.setRotation(sf::degrees(180));

	downArrow.setPosition(subNumPos+sf::Vector2(ButtonSize,ButtonSize)); //To fix arrow rotation

	//Drawing the number
	
	numberDisplay.setPosition({ContainerPosition.x+((ActualWidth-ButtonSize)/2)-(numberDisplayBounds.size.x/2), ContainerPosition.y + ButtonSize - numberDisplayBounds.size.y});


	window->draw(RenderLabelText);
	window->draw(NumberContainer);
	window->draw(numberDisplay);
	window->draw(addNumButton);
	window->draw(upArrow);
	window->draw(subNumButton);
	window->draw(downArrow);


}

void MainGui::GuiNumber::HandleClick() {
	DisplayNumber = std::to_string(*Value);

	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

	sf::Vector2 ContainerPos = { position.x + LabelWidth - (ActualWidth / 10),position.y + size.y / 10 };
	
	float buttonSize = (size.y / 5)*2;
	//ContainerCords
	float ActualNumberX = ContainerPos.x;
	float ActualNumberY = ContainerPos.y;
	//Show more Logic
	bool isInsideContainer = mousePos.x >= ActualNumberX && mousePos.x <= (ActualNumberX + ActualWidth)&&
		mousePos.y >= ActualNumberY && mousePos.y <= position.y + ActualNumberY+(size.y / 5) * 4;

	if (isInsideContainer && isPressed && isNumSelected == false) {
		isNumSelected = true;
	}
	else if (!isInsideContainer && isPressed) {
		isNumSelected = false;
	}
	//Changing Number logic
	float UpPosX = position.x + LabelWidth - (ActualWidth / 10) + ActualWidth - buttonSize;
	float UpPosY = position.y + size.y / 10;

	float DownPosX = UpPosX;
	float DownPosY = position.y + size.y / 10 + buttonSize;

	bool isInsideUp = mousePos.x >= UpPosX && mousePos.x <= UpPosX + buttonSize &&
		mousePos.y >= UpPosY && mousePos.y <= UpPosY + buttonSize;

	bool isInsideDown = mousePos.x >= DownPosX && mousePos.x <= DownPosX + buttonSize &&
		mousePos.y >= DownPosY && mousePos.y <= DownPosY + buttonSize;
	if(isInsideUp && isPressed&& !wasPressed){
		(*Value)+=stepValue;
		wasPressed = true;
	}
	if (isInsideDown && isPressed && !wasPressed) {
		(*Value) -= stepValue;
		wasPressed = true;
	}


	if (!isPressed) {
		wasPressed = false;
	}
}

