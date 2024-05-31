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

This is the code that is directly uploaded to the Arduino via the Arduino IDE.



## MoonDawgArduino



This is the the code that will be run on the robot.
Make sure to follow the README in the "Libraries" folder to properly run and compile the file in the Arduino IDE
