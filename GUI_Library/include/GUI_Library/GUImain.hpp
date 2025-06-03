#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>



//MainGui CLass
class MainGui {
public:
    class Widget {
    public:
        sf::RenderWindow* window = nullptr;
        sf::Vector2f position;
		sf::Vector2f size;
        float ActualWidth;
        float LabelWidth;

        sf::Font FontPath;


        
        

        Widget() = default;
        virtual ~Widget() = default;

		virtual std::shared_ptr<Widget> clone() const = 0; //Method used to copy widgets - to be implemented by derived classes

        virtual void Render() {
            std::cout << "Rendering base Widget\n";
        }
        virtual void HandleClick() {
            std::cout << "Handling click in base Widget\n";
        }
    };

    class GuiButton : public Widget {
    public:
        bool wasPressed = false;
        //Values for the button (Customization)
        std::string ButtonText;
        sf::Color ButtonTextColor;
        std::string ButtonLabel;
        sf::Color ButtonColor;
        sf::Color ButtonHoverColor;

        
		bool isHovered = false; // To track hover state
        
        //Function to call when button is clicked
        std::function<void()> onClick = [this]() {
            std::cout << ButtonText << " Was pressed" << std::endl;
            };

        //Functionality
        void HandleClick() override;
		void Render() override;

        //Cloning method
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiButton>(*this);
        }
        
    };

    class GuiCheckbox : public Widget {
    public:
        bool isChecked = false;
		bool wasPressed = false;
        bool* linkedVariable = nullptr; // Reference to a variable to link checkbox state

        //Values for the Checkbox (Customization)
        std::string CheckboxLabel;
        
        //Functionality
		void HandleClick() override;
        void Render() override;

        //Cloning method
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiCheckbox>(*this);
        }

    };
    
    class GuiRadio : public Widget {
    public:
        bool isChecked = false;
        bool wasPressed = false;
        float* linkedVariable = nullptr; // Reference to a variable to link Radio state
        float RadioValue = 0.0f;

        //Values for the Radio (Customization)
        std::string RadioLabel;
		sf::Color custonLabelColor = sf::Color::White; // Custom color for the label
		sf::Color customRadioColor = sf::Color::White; // Custom color for the radio and label

        //Functionality
        void HandleClick() override;
        void Render() override;

        //Cloning method
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiRadio>(*this);
        }
    };

    class GuiNumber : public Widget {
    public:
        //Visuals
        std::string NumberLabel;

        //ForTypingNumber
        int* Value = 0;
        int stepValue = 1;
        std::string DisplayNumber = "30000000";

        bool isDownHover = false;
        bool isUpHover = false;

        bool wasPressed = false;

        bool isNumSelected = false;

        //Functionality
        void HandleClick() override;
        void Render() override;

        //Cloning method
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiNumber>(*this);
        }

    };
    class GuiSlider : public Widget {
    public:
        //Visuals
        std::string SliderLabel;
        sf::Color SliderColor = sf::Color::White;
        sf::Color SliderBoxColor = sf::Color::White;

        bool isHovered = false;
        
        //ForSlider
        float GrabPositionX;
        std::string displayNumber = "0";
        float* LinkedVariable;

        float MaxValue = 100;
        float MinValue = -100;

        bool isGrabbing = false;

        float StepValue = 1.0f;

        bool wasPressed = false;

        //Functionality
        void HandleClick() override;
        void Render() override;

        float mapValue(float value, float inMin, float inMax, float outMin, float outMax) {
            return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
        }


        //Cloning method
        std::shared_ptr<Widget> clone() const override {
            return std::make_shared<GuiSlider>(*this);
        }
    };


    //MainGui variables and Methods
    sf::RenderWindow& window;
    sf::View view;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color backgroundColor;
    std::string GuiLabel;
    float widgetHeight;

    std::vector<std::shared_ptr<Widget>> Widgets;
    sf::Font Font;

    MainGui(sf::RenderWindow& window,
        sf::Vector2f position,
        sf::Vector2f size,
        sf::Color backgroundColor,
        std::string GuiLabel,
        sf::Font Font,
        float widgetHeight = 50);

    // Change to take const reference and clone internally
    void addWidget(const std::shared_ptr<Widget>& widget);
    void Render();
    void adjustViewToWindow();
  
};