#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>

class MainGui {
public:
    class Widget {
    public:
        sf::RenderWindow* window = nullptr;
        sf::Vector2f position;
        bool hasPosition = false;
        sf::Vector2f size;

        Widget() = default;
        virtual ~Widget() = default;


        // Pure virtual clone method - every subclass must implement it
        virtual std::shared_ptr<Widget> clone() const = 0;

        virtual void Render() {
            std::cout << "Rendering base Widget\n";
        }
    };

    class GuiButton : public Widget {
    public:
        std::string GuiText;
        sf::Color backgroundColor;
        sf::Color textColor;
        bool wasPreviouslyPressed = false;


        std::function<void()> onClick;

        void HandleClick();

        void Render() override;

        // Implement clone by copying this object
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiButton>(*this);
        }
    };

    class Lever : public Widget {
        bool& changingValue;
        bool LeverState = false;

        std::string Label = "";

    };

    class GuiSlider : Widget {};

    class GuiNumber : Widget {};

    class GuiText : Widget {};

    class GuiCheckbox : Widget {};

    class GuiRadio : Widget {};
    // MainGui members ...
    sf::RenderWindow& window;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color backgroundColor;
    float widgetHeight;

    std::vector<std::shared_ptr<Widget>> Widgets;

    MainGui(sf::RenderWindow& window,
        sf::Vector2f position,
        sf::Vector2f size,
        sf::Color backgroundColor,
        float widgetHeight);

    // Change to take const reference and clone internally
    void addWidget(const std::shared_ptr<Widget>& widget);
    void Render();
};
