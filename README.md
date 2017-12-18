# lazerjingle
The project undertaken for this semester was the construction of a laser tripwire which is unique in its own way. The project is completely based on the Input Processing Storage Output (IPSO) model. The core of this project is Arduino UNO which based on ATmega328P. It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz quartz crystal, a USB connection, a power jack, an ICSP header and a reset button. It contains everything needed to support the microcontroller and the project. The project efficiently makes use of LEDs, sensors, storage media, speaker and resistors. The basic structure of this project is that, a laser is pointed directly to the photoresistor mounted on the arduino and if an object intersect its path the tripwire gets triggered; it shoots a rubber band to scare off the target and plays “jingle bells” tune using the piezo speaker; to make the set-up look more fancy and creative there is also an RGB LED mounted on the arduino board. The LED lights up in various beautiful Christmas colors which is synchronized with the notes played by the piezo speaker.
	The photo-resistor detects the obstacle using a threshold value which is very important to trigger the tripwire. The sketch used in this project also logs the number of times the tripwire was triggered.
Few changes have been made to the project since the project proposal was submitted. This includes addition of a hand-made rubber band shooter using servo motor instead of using a 3D printed mini-catapult due to time constraints.

### Build and Design

The project design is simple and straight forward. The laser tripwire was made with an RGB LED, a photoresistor, laser, breadboard, Arduino UNO, piezo speaker, servo motor, four 560 Ohm resistors, one 220 Ohm resistor, popsicle stick, rubber band and few jumper wires.

![alt text](https://i.imgur.com/d0MNIxp.jpg "design")


### Working Principle

The laser trip wire is really easy to use. Just point a laser onto the photo-resistor mounted on the Arduino UNO and point the servo motor rubber band shooter towards the target. As soon as the target gets in the way of the photo-resistor and the laser; the system gets triggered and it plays jingle bells and shoots the rubber band onto the target and also the LED starts to blink in various colors synchronized with the notes. This project can be used as a Christmas prank or a self security system. The sketch implemented in the Arduino also logs the number of times the alarm was triggered.
The photo-resistor is connected to pin A0, piezo speaker to pin 2, Red to pin 7, Green to pin 6, Blue to pin 5 and the servo motors is connected to pin 9. The working principle of the system is very simple, if the photo-resistor reads value less than the threshold value it triggers the alarm and the notes start to play through the piezo speaker and LED lights blink in various RGB colors synchronized with the notes. The Arduino sketch for this project is highly optimized so that it uses less memory and less microcontroller power. The obstacle detection is really quick.

### Setbacks and Failures

The biggest setback for this project was finding a KY-008 laser and a strong buzzer. Due to time constraints and lack of part availability KY-008 couldn’t be implemented into the project. A toy laser was used to test the setup. Different types of laser modules have various intensities and the threshold value can be set, by just modifying the code. Another setback was 3D printing a mini-catapult which was originally considered for this project. The 3D printing team of the University was reached but they didn’t have the required material for the mini-catapult. A custom made rubber band shooter was made with a popsicle stick powered by the servo motor instead.

### Conclusion

The project undertaken was very interesting and fun to build. There were a lot of challenges; fortunately all of the challenges were completed on time. This kind of project would be a great introduction to students who are new to Arduino development. This project completely based on the IPSO model.
The CS207 class really helps students to gain a basic knowledge of programmable electronic devices. Thanks to the professor for spreading knowledge and helping students out with their projects. There is still room for improvement in the project. Anyone can just create a fork on GitHub(https://github.com/verrit/arduino) and make changes or improvements so that it can be merged and made better. A proper readme file is provided in the GitHub page which shows more about this project as it also includes more pictures and videos of it in action.

### Final Design



### Credits

[1] http://blog.giacomocerquone.com/jingle-bell-with-an-arduino-and-a-buzzer/

[2] http://www.instructables.com/id/Arduino-Tutorial-Laser-Security-System/

[3] https://www.thingiverse.com/thing:1763518
