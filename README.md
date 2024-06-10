# NASA Lunabotics

This is a competition that is hosted every year by NASA and other sponsors. The current obejctive of the competition is to build a bot that is able to traverse a simulated lunar enviroment (baring low gravity), at the end of this traversal it will need to then collect the lunar simulant *[BP-1](https://ares.jsc.nasa.gov/projects/simulants/bp-1.html)*, *[LHS-1](https://spaceresourcetech.com/products/lhs-1-lunar-highlands-simulant)*, etc. once collected this material is then transported to a deposition/berm building area. The rules, guidelines, and documentation can be found [here](https://www.nasa.gov/learning-resources/lunabotics-challenge/).

## embedded-berm-bot

For all things Arduino and Arduino-esque on the SIU Lunabotics bot. 
Due to the nature of how our bot is constructed we have seperated the logic in two distinct places. 
<details>
  <summary>Raspberry Pi/Master</summary>
  
  This will control the Arduino and tells it what to do along with communicating to the user. There is a more detailed description of how it works [here](https://github.com/SIU-Robotics/moondawg-ros). All that needs to be known for the Arduino side is that it will send data over Serial which is then parsed into usable bits for us to send to `commandProccessing` that will call specific functions and give it the data needed.
  
</details>

### Arduino/Slave

#### Overview
  
This is what processes the commands sent from the Raspberry Pi/Master and once processed they trigger certain commands that control the bot. There is no feedback currently implemented so it is all manually controlled by a user. 

#### File Summary

The file is structed into two different types of files. First, the main file (.ino) which is what calls all the libraries, functions, and is uploaded on the Arduino. Second, the libraries this is called in the main file and houses functions, definitions, and classes.

##### MoonDawgArduino.ino

This is the code that is directly uploaded to the Arduino via the Arduino IDE. This has all of the function calls, the serial communication logic, and initialization of the classes.

#### PinDefinitions.h

This is where we use `constexpr uint8_t` instead of `#define` to set what the pins will be. I found on a forum [here](https://stackoverflow.com/questions/42388077/when-should-i-prefer-constexpr-variables-over-macros/42388687#42388687).

#### Movement.h/Movement.cpp

These hold all of the classes and functions that allows the bot to move and function. We've found that you must have a default (or empty) constructor when making classes for an Arduino, after which you must have a function to "setup" the classes pin usages for it's functions. 

#### Camera.h/Camera.cpp

These hold all of the classes and functions to be able to move the camera arm. We've found that you must have a default (or empty) constructor when making classes for an Arduino, after which you must have a function to "setup" the classes pin usages for it's functions. As well 360&deg; servos can create a lot of noise (or some other black magic) that causes other nearby servos to become uncontrollable (have seizures). We fixed this by replacing the servo with a 180&deg; servo. In the future can look into stepper motors or something more reliable and easier to control.

### Adding Custom Libraries to Arduino IDE

To be able to use the libraries we make, you must import them into the IDE this is mandatory to ensure that the main file will correctly work. To do so follow these steps:

Download Library -> Zip the folder -> Open Arduino IDE -> Sketch -> Include Library -> Add .zip Libary -> Choose the .zip
