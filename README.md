# My-GUI-Project
Just a very simple GUI project that will allow me to test my other projects more easly. It will be used as a library when i finish it.

How to build:
1. Install CMake.
2. Run:
cmake -B build
cmake --build build
In the Terminal while in the Root folder.
3. The project should be ready to open in VS.

How to use:
The project is build using SFML library.
To use the main features you first need to create your GUI window.
Use:
  MainGui ExampleName(sfmlWindow, {position.x, position.y}, {size.x, size.y}, BackgroundColor(sfml), "Label GUIName", WidgetSpacing(int))
  
That will create your window which you can add widgets too.
The size.x will automatically change if the Label is too long, and the size.y will strech when adding Widgets if they are out of bounds.

To Add a Widget first you need to create a Widget Template for the MainGui to copy.

To do that you need to:

auto WidgetName = Create"___"(Values to customize and add functionality);

Where "____" is the name of the Widget you want to add.
The current list of Widgets:
  Button
  Checkbox
  Radio

The functionality of each Widget:
  Button:
  A button can recive an "onClick" function that will be called upon clicking the button.
  To pass it the function you need to write:
  ButtonName->onCllick =[parameters](){
    //Your function
  };

  Checkbox:
  A Checkbox can be linked to any bool variable via pointers and is able to toggle it between true or false when Checked.
  The same value can be linked to multiple Checkboxes which will trigger all of them upon checking one.

  Radio:
  Radio button can be linked to any float variable via pointers and is able to pass it its RadioValue when checked.
  Multiple radio buttons can be linked to the same variable - which couses them to automatically uncheck if any other linked radio button is checked.

After creating a template you can then add it to your GUI by using a command:
  ExampleName.addWidget(yourWidget);
Which will accept any of your widget templates and add them to your GUI.

You can have multiple GUI's in the same Window and you can also pass the same Templates many times in the same and different GUI's.

THERE WILL BE MORE UPDATES
