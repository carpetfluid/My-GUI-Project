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
```C++
MainGui MyGUI(window, {1,1}, {600, 800}, sf::Color::Black, "MyTestGUI", ComicSans, 100);
```

To Render the GUI in the window you need to call the
```C++
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

```C++
    MyGUI.addWidget(<myWidget>);
```

but for that you first need to create a Widget Template.

Its called a Template because it's not the widget itself, but rather instruction to the MainGui instance of what Widget to display.


Here's implementation for every Widget, and instructions how they work:

## Button
To create a button template you run the function
```C++
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
```C++
auto button = CreateButton("Click Me", sf::Color::White, "Guzik", sf::Color::Blue, 100, sf::Color::Red);
MyGUI.addWidget(button);
```

To add functionality to the button you need to give it a function.
To do that we use:
```C++
button->onClick = []() {
        //Your function
        //Example:
        std::cout<<"Clicked!!"<<std::endl;
    };
```
where button is your button template's name.
