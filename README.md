# My-GUI-Project
Very simple Library for creating and using basic GUI's using SFML studio. Meant to be used while testing programs or simulations.
The project needs an SFML library to work. In the library there is a README file that contains the CMakeLists code that will help implement the library with SFML integrated

The library was made by me, as a side project to get started with SFML graphics.
It has some basic features like crating a menu and giving it a size and position, creating Widget Templates and adding them to the menu, and giving the Widgets functionality.

## Features

- Creating useful interfaces for testing other projects
- Adding multiple interfaces on one scene and using them seperately
- Creating Widget templates that can be added to any interface
- Adding functionality to the Widgets


## Acknowledgements

 - [SFML 3.0.0 Documentation](https://www.sfml-dev.org/documentation/3.0.0/)





## Run Locally

Clone the Library

```bash
  git clone https://github.com/carpetfluid/My-GUI-Project.git
```
Creatre a project Folder and clone [Project Template](https://github.com/SFML/cmake-sfml-project)

```bash 
 git clone https://github.com/SFML/cmake-sfml-project.git
 ```
go to the CMakeLists.txt and change its content to the README.txt found in Library folder.
Remember to change the path to the path of the downloaded Library.

In the root folder create a "build" folder and enter it.
Use right-click to open CMD and type

```bash
cmake ..
cmake --build .
```

To use a library you need to add two includes

```bash
#include <GUI_Library/GUImain.hpp>
#include <GUI_Library/CreatingWidgets.hpp>
```

and now you're free to use the library in your project.


## Creating GUI
To create your GUI you will create a MainGui instance.
MainGui takes parameters
```C++
MainGui MyGUI(<SFML Window>, <position {x, y}>, <size {x, y}>, <SFML Color>, <Label {string}>, <SFML Font>, <Height{int}>)
```
Where:

<SFML Window> stands for Window or RenderWindow object from SFML.

<position {x,y}> stands for SFML Vector2f or {x, y}, that stores x and y position.

<size {x, y}> stands for SFML Vector2f or {x, y}, that stores x and y size.

<SFML Color> stands for SFML Color that will be displayed as a background of the GUI.

<Label{string}> Is a string value that will be used as GUI Label at the top.

<SFML font> Stands for SFML font that will be used in the GUI.

<Height{int}> Is a universal Height for every Widget


So Example Implementation would look something like that:
```cpp
MainGui MyGUI(window, {1,1}, {600, 800}, sf::Color::Black, "MyTestGUI", ComicSans, 100);
```

To Render the GUI in the window you need to call the
```cpp
MyGUI.Render();
```
function each frame.
## Widgets

The list of Widgets consists of:
- Button
- Checkbox
- Radio
- Number
- Slider

Too add a Widget to your GUI you need to run the addWidget() Function.

```cpp
    MyGUI.addWidget(<myWidget>);
```

but for that you first need to create a Widget Template.

Its called a Template because it's not the widget itself, but rather instruction to the MainGui instance of what Widget to display.


Here's implementation for every Widget, and instructions how they work:

## Button
To create a button template run a function
```cpp
CreateButton(<ButtonText>, <ButtonTextColor>, <ButtonLabel>, <ButtonColor>, <ButtonWidth>, <ButtonHoverColor>);
```
(All Colors are implemented using SFML Color)

<ButtoText> is a string value displayed on the button.

<ButtonTextColor> is the color of the text on the button.

<ButtonLabel> is a string value displayed next to the button.

<ButtonColor> is a color of a button itself

<ButtonWidth> is the width of this specific Button.

<ButtonHoverColor> is the color of the button when the pointer is over it.

So the example usage would be:
```cpp
auto button = CreateButton("Click Me", sf::Color::White, "Guzik", sf::Color::Blue, 100, sf::Color::Red);
MyGUI.addWidget(button);
```

To add functionality to the button you need to give it a function.
To do that we use:
```cpp
button->onClick = []() {
        //Your function
        //Example:
        std::cout<<"Clicked!!"<<std::endl;
    };
```
where "button" is your button template's name.

## Checkbox
To create a checkbox template run a function:
```cpp
CreateCheckbox(<PointerToVariable>,<Label>, <IsChecked{bool}>);
```
<PointerToVariable> is a pointer to a bool Variable that will toggle with the checkbox.

<Label> is a string Value displayed next to the checkbox.

<IsChecked> is the initial value of the checkbox.

So the example usage would be:

```cpp
auto checkbox = CreateCheckbox(&isVisible, "Visibility", false);
MyGUI.addWidget(checkbox);
```
Now when the checkbox is checked the Linked variable will be set to true, and if its unchecked, the variable will be set to false.
## Radio
To create a Radio button template run a function:
```cpp
CreateRadio(<PointerToVariable>, <RadioValue>, <Label>);
```

<PointerToVariable> is a pointer to a float variable that will be changed when radio is checked.

<RadioValue> is a float value that the pointed variable will be set to when radio is checked.

<Label> is a string value displayed next to the Radio button.

So the example usage would be:
```cpp
auto radio = CreateRadio(&width, 1980, "Width of the screen");
```

Many Radio buttons can be linked to the same variable. That will allow to switch the value of the linked variable between the value's of radio's.
## Number
To create a Number Widget run a function:
```cpp
CreateNumber(<PointerToVariable>, <Label>, <Step>);
```

<PointerToVariable> is a pointer to a int variable that will be effected by the Widget.

<Label> is a string value displayed next to the number widget.

<Step> is an int value of how much the value changes each click.

So the example usage would be:
```cpp
auto number = CreateNumber(&Value, "Number of something", 1); 

MyGUI.addWidget(number);
```
To change the value of the linked variable you press the arrow buttons next to the number.

## Slider
To create a Slider Widget run a function:

```cpp
CreateSlider(<PointerToVariable>, <Label>, <MinValue>, <MaxValue>, <Step>);
```

<PointerToVariable> is a pointer to a float variable that will be effected by the Slider

<Label> is a string value displayed above the slider.

<MinValue> is the lowest value that the slider can be set to.

<MaxValue> is the biggest value that the slider can be set to.

<Step> is a float value of how much the linked variable changes by when button's are pressed.

So the example usage would be:

```cpp
auto slider = CreateSlider(&brightness, "Brightness", 0, 100, 1);
MyGUI.addWidget(slider);
```

You can now change the value of linked variable by dragging the slider or pressing the buttons for more accurate control.
