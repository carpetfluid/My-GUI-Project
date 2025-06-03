#include "GUImain.hpp"
//Useful Variables
sf::Color ContainerColor = sf::Color(89, 96, 166, 255); //Color for the Widget container


float GuiLabelHeight = 50.0f; //Height of the GUI label box

sf::Font GuiLabelFont("C:/Users/jack9/OneDrive/Pulpit/PROGRAMOWANIE/C++/Grafika/GUI PROJECT/MyTryAtGuiRework/assets/arial.ttf");


//MainGui functions

MainGui::MainGui(
    sf::RenderWindow& window,
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color backgroundColor,
    std::string GuiLabel,
    float widgetHeight

)
    : window(window),
    position({position.x,position.y+ GuiLabelHeight }),
    size(size),
    backgroundColor(backgroundColor),
	GuiLabel(GuiLabel),
    widgetHeight(widgetHeight) {
    view = window.getView();
};
//Adding a widget to the GUI
void MainGui::addWidget(const std::shared_ptr<Widget>& widget) {
    auto widgetCopy = widget->clone(); // clone the widget

    widgetCopy->window = &window;
    widgetCopy->position = sf::Vector2f(position.x, position.y + Widgets.size() * widgetHeight);
    widgetCopy->size = sf::Vector2f(size.x, widgetHeight);
    
    Widgets.push_back(std::move(widgetCopy));
	if (Widgets.size() * widgetHeight > size.y) size.y = Widgets.size() * widgetHeight; // Adjust the size of the GUI if needed
}

void MainGui::Render() {
    adjustViewToWindow();
   

    sf::Vector2u winSize = window.getSize();
	sf::Vector2f LabelPosition = { size.x/2 + position.x, position.y - GuiLabelHeight };
    sf::RectangleShape LabelBox({ size.x, GuiLabelHeight });
    LabelBox.setFillColor(sf::Color::Transparent);
	LabelBox.setPosition({position.x,position.y- GuiLabelHeight });
	LabelBox.setOutlineColor(sf::Color::White);
	LabelBox.setOutlineThickness(1.0f);

	sf::Text labelText(GuiLabelFont);
    
	labelText.setString(GuiLabel);
	labelText.setCharacterSize(GuiLabelHeight*0.8);
	labelText.setFillColor(sf::Color::White);
    labelText.setPosition(LabelPosition);
    sf::Rect LabelTextBounds = labelText.getLocalBounds();
    labelText.setOrigin({ LabelTextBounds.position.x + LabelTextBounds.size.x / 2, 0.0f });
    if (LabelTextBounds.size.x > size.x) {
        size.x = LabelTextBounds.size.x;
        for (auto& widget : Widgets) {
            widget->size.x = size.x;
        }
    }

	window.draw(LabelBox);
	window.draw(labelText);
	// Draw the background rectangle
	sf::RectangleShape background(size);
	background.setPosition(position);
    background.setFillColor(backgroundColor);
    background.setOutlineColor(backgroundColor);
    background.setOutlineThickness(1.0f);
    window.draw(background);
    //Add the Label For the GUI
	
	
    // Draw the widgets
    for (const auto& widget : Widgets) {
		//Container for the widget (Every widgets container is the same but the widget itself is different)
        sf::RectangleShape WidgetContainer({size.x, widgetHeight});
		WidgetContainer.setPosition(widget->position);
		WidgetContainer.setFillColor(ContainerColor);
        window.draw(WidgetContainer);
        widget->Render();
	}
	background.setPosition(position);
    for (auto& widget : Widgets) {
        widget->Render();
        widget->HandleClick();
    }
}
void MainGui::adjustViewToWindow() {
    // Get the current size of the window
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / view.getSize().x;
    float scaleY = static_cast<float>(windowSize.y) / view.getSize().y;

    window.setView(view);
}
