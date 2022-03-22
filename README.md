# Arduino-Music-Player-Jukebox
A simple arduino music player with 11 songs.

# Credits
All music lyrics credit go to [robsoncouto](https://github.com/robsoncouto) and his [arduino-songs repository](https://github.com/robsoncouto/arduino-songs). Check it out if you want to add any new songs- they're great!

# Demo
Check out a demo here: https://socialrumbles.com/post/230

# Tutorial
Parts and Video Demo Here - https://socialrumbles.com/post/230

_📙 Libraries:_
- https://github.com/YuriiSalimov/AxisJoystick#installation (axisjoystick.h & joystick.h)
- https://www.arduino.cc/en/reference/wire (wire.h)
- https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (liquidcrystal_I2C.h)

_🔗 Connections/Schematics:_

**Joystick:**
- GND to GND
- 5V to 5V
- VRX to A0
- VRY to A1
- SW to 7


**LCD I2C:**
- GND to GND
- 5V to 5V
- SDA to SDA (20)
- SCL to SCL (21)


**Buzzer:**
- GND to GND
- 5V to 11

# Can I use this with an Arduino Uno?
You would have to change the SDA & SCL Pins, and you would have to remove some songs in order to fit the memory limitations of the Arduino Uno. So yes, but you'll only be able to play about 2~3 songs. I haven't tested it with an Arduino Uno though.
