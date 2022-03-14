# Arduino-Music-Player-Jukebox
A simple arduino music player with 11 songs.

# Tutorial
Parts and Video Demo Here - https://socialrumbles.com/post/230

Libraries:
- https://github.com/MHeironimus/ArduinoJoystickLibrary (joystick.h)
- https://github.com/YuriiSalimov/AxisJoystick (axisjoystick.h)
- https://www.arduino.cc/en/reference/wire (wire.h)
- https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (liquidcrystal_I2C.h)

Connections:
**Joystick:**
- GND to GND
- 5V to 5V
- VRX to A0
- VRY to A1
- SW to 53


**LCD I2C:**
- GND to GND
- 5V to 5V
- SDA to SDA (20)
- SCL to SCL (21)


**Buzzer:**
- GND to GND
- 5V to 11
