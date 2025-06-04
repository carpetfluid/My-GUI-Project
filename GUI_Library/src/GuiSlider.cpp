#include "../include/GUI_Library/GUImain.hpp"
#include <sstream>
#include <iomanip>
//Useful Variables

//GuiSlider

void MainGui::GuiSlider::Render() {
	float ButtonSize = size.y / 2;
	ActualWidth = size.x-ButtonSize;
	LabelWidth = ActualWidth;
	float SliderWidth = ActualWidth * 0.8f;
	sf::Vector2f SliderPosition = { position.x + (ActualWidth / 2) - SliderWidth / 2, position.y + size.y / 2 };

	GrabPositionX = mapValue(*LinkedVariable, MinValue, MaxValue, SliderPosition.x, SliderPosition.x + SliderWidth);
	//Changing the background
	sf::RectangleShape SliderMainContainer({ size.x, size.y });
	SliderMainContainer.setPosition({ position.x,position.y });
	SliderMainContainer.setFillColor(sf::Color::Black);
	SliderMainContainer.setOutlineColor(sf::Color::White);
	SliderMainContainer.setOutlineThickness(1.0f);

	//The Slider Itself
	sf::RectangleShape Slider({ SliderWidth, 2.0f });
	Slider.setPosition(SliderPosition);
	Slider.setFillColor(sf::Color::White);

	//SliderGrab
	sf::Vector2f GrabSize = { size.y / 12, size.y / 6 };
	sf::RectangleShape Grab(GrabSize);
	Grab.setPosition({ GrabPositionX, position.y + (size.y / 2) - size.y/12 });
	if (!isHovered) {
		Grab.setFillColor(sf::Color::Black);
		Grab.setOutlineColor(sf::Color::White);
		Grab.setOutlineThickness(2.0f);
	}
	else if (isHovered) {
		Grab.setFillColor(sf::Color::White);
	}

	//Label
	sf::Text SliderLabelRend(FontPath);
	SliderLabelRend.setCharacterSize(size.y / 3);
	SliderLabelRend.setFillColor(sf::Color::White);
	SliderLabelRend.setString(SliderLabel);
	sf::Rect LabelBounds = SliderLabelRend.getLocalBounds();
	sf::Vector2f LabelPosition = { position.x + ActualWidth / 2 - LabelBounds.size.x / 2,position.y };
	SliderLabelRend.setPosition(LabelPosition);

	//NumberDisplay
	sf::Text numberDisplay(FontPath);
	numberDisplay.setString(displayNumber);
	numberDisplay.setCharacterSize(size.y/3);
	numberDisplay.setFillColor(sf::Color::White);
	sf::Rect NumberBounds = numberDisplay.getLocalBounds();
	sf::Vector2f NumberPos = { position.x + ActualWidth / 2 - NumberBounds.size.x / 2, (position.y + (size.y/5)*3) + 2.0f };
	numberDisplay.setPosition(NumberPos);

	//NumberArrows

	//First Button
	sf::RectangleShape addNumButton({ ButtonSize, ButtonSize });

	addNumButton.setFillColor(sf::Color::Black);
	addNumButton.setOutlineThickness(1.0f);
	addNumButton.setOutlineColor(sf::Color::White);
	sf::Vector2 addNumPos = { position.x + ActualWidth, position.y};
	addNumButton.setPosition(addNumPos);

	sf::CircleShape upArrow(ButtonSize / 2, 3);
	upArrow.setFillColor(sf::Color::White);

	upArrow.setPosition(addNumPos);


	//Second Button
	sf::RectangleShape subNumButton({ ButtonSize, ButtonSize });

	subNumButton.setFillColor(sf::Color::Black);
	subNumButton.setOutlineThickness(1.0f);
	subNumButton.setOutlineColor(sf::Color::White);
	sf::Vector2 subNumPos = { position.x + ActualWidth, position.y + size.y/2};
	subNumButton.setPosition(subNumPos);

	sf::CircleShape downArrow(ButtonSize / 2, 3);
	downArrow.setFillColor(sf::Color::White);
	downArrow.setRotation(sf::degrees(180));

	downArrow.setPosition(subNumPos + sf::Vector2(ButtonSize, ButtonSize)); //To fix arrow rotation

	window->draw(SliderMainContainer);
	window->draw(SliderLabelRend);
	window->draw(Slider);
	window->draw(numberDisplay);
	window->draw(Grab);
	window->draw(addNumButton);
	window->draw(subNumButton);
	window->draw(upArrow);
	window->draw(downArrow);
}

void MainGui::GuiSlider::HandleClick() {
	float ButtonSize = size.y / 2;
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << *LinkedVariable;
	displayNumber = stream.str();

	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(pixelPos);

	float SliderWidth = ActualWidth * 0.8f;
	sf::Vector2f SliderPosition = { position.x + (ActualWidth / 2) - SliderWidth / 2, position.y + size.y / 2 };

	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

	bool isMouseIn = mousePos.x >= SliderPosition.x && mousePos.x <= SliderPosition.x+SliderWidth &&
		mousePos.y >= position.y + (size.y / 2) - 10 && mousePos.y <= position.y + (size.y / 2) + 10
		&& isPressed;

	bool isHover = mousePos.x >= GrabPositionX && mousePos.x <= GrabPositionX+size.y/12 &&
		mousePos.y >= position.y + (size.y / 2) - size.y/12 && mousePos.y <= position.y + (size.y / 2) + size.y/12;
	if (isHover||isGrabbing) {
		isHovered = true;
	}
	else if (!isHover) isHovered = false;


	if (isMouseIn && isPressed) {
		isGrabbing = true;
	}
	if (!isPressed) {
		isGrabbing = false;
		wasPressed = false;
	}

	if (isGrabbing) {
		float value = mapValue(
			mousePos.x,
			SliderPosition.x,                 // Left edge of slider
			SliderPosition.x + SliderWidth,  // Right edge of slider
			MinValue,
			MaxValue
		);
		*LinkedVariable = std::clamp(value, MinValue, MaxValue);

	}

	//TheButtons Logic
	//Changing Number logic
	float UpPosX = position.x + ActualWidth;
	float UpPosY = position.y;

	float DownPosX = UpPosX;
	float DownPosY = position.y + ButtonSize;

	bool isInsideUp = mousePos.x >= UpPosX && mousePos.x <= UpPosX + ButtonSize &&
		mousePos.y >= UpPosY && mousePos.y <= UpPosY + ButtonSize;

	bool isInsideDown = mousePos.x >= DownPosX && mousePos.x <= DownPosX + ButtonSize &&
		mousePos.y >= DownPosY && mousePos.y <= DownPosY + ButtonSize;

	if (isInsideUp && isPressed && !wasPressed && *LinkedVariable<MaxValue) {
		*LinkedVariable += StepValue;
		wasPressed = true;
		if(*LinkedVariable > MaxValue) {
			*LinkedVariable = MaxValue; // Clamp to MaxValue
		}
	}
	if( isInsideDown && isPressed && !wasPressed &&*LinkedVariable>MinValue) {
		*LinkedVariable -= StepValue;
		wasPressed = true;
		if(*LinkedVariable < MinValue) {
			*LinkedVariable = MinValue; // Clamp to MinValue
		}
	}

}

