#include <Joystick.h>
#include <AxisJoystick.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "pitches.h"

#define MELODY_LENGTH(melody) sizeof(melody)/sizeof(melody[0])/ 2
#define SW_PIN 53
#define VRX_PIN A0
#define VRY_PIN A1

Joystick* joystic;
LiquidCrystal_I2C lcd(0x27, 20, 4);

int buzzer = 11;
int happybirthday[] = {C4, 4, C4, 8, D4, -4, C4, -4, F4, -4, E4, -2, C4, 4, C4, 8, D4, -4, C4, -4, G4, -4, F4, -2, C4, 4, C4, 8, C5, -4, A4, -4, F4, -4, E4, -4, D4, -4, AS4, 4, AS4, 8, A4, -4, F4, -4, G4, -4, F4, -2,};
int harrypotter[] = {D4, 4, G4, -4, AS4, 8, A4, 4, G4, 2, D5, 4, C5, -2, A4, -2, G4, -4, AS4, 8, A4, 4, F4, 2, GS4, 4, D4, -1, D4, 4, G4, -4, AS4, 8, A4, 4, G4, 2, D5, 4, F5, 2, E5, 4, DS5, 2, B4, 4, DS5, -4, D5, 8, CS5, 4, CS4, 2, B4, 4, G4, -1, AS4, 4, D5, 2, AS4, 4, D5, 2, AS4, 4, DS5, 2, D5, 4, CS5, 2, A4, 4, AS4, -4, D5, 8, CS5, 4, CS4, 2, D4, 4, D5, -1, REST, 4, AS4, 4, D5, 2, AS4, 4, D5, 2, AS4, 4, F5, 2, E5, 4, DS5, 2, B4, 4, DS5, -4, D5, 8, CS5, 4, CS4, 2, AS4, 4, G4, -1,};
int vampirekiller[] = {E5, 16, E5, 8, D5, 16, REST, 16, CS5, -4, E4, 8, FS4, 16, G4, 16, A4, 16, B4, -8, E4, -8, B4, 8, A4, 16, D5, -4, E5, 16, E5, 8, D5, 16, REST, 16, CS5, -4, E4, 8, FS4, 16, G4, 16, A4, 16, B4, -8, E4, -8, B4, 8, A4, 16, D4, -4, REST, 8, E5, 8, REST, 16, B5, 16, REST, 8, AS5, 16, B5, 16, AS5, 16, G5, 16, REST, 4, B5, 8, B5, 16, AS5, 16, REST, 16, AS5, 16, A5, 16, REST, 16, B5, 16, G5, 16, B5, 16, AS5, 16, REST, 16, B5, 16, A5, 16, G5, 16, REST, 8, E5, 8, REST, 16, B5, 16, REST, 8, AS5, 16, B5, 16, AS5, 16, G5, 16, REST, 4, B5, 8, B5, 16, AS5, 16, REST, 16, AS5, 16, A5, 16, REST, 16, B5, 16, G5, 16, B5, 16, AS5, 16, REST, 16, B5, 16, A5, 16, G5, 16, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, E4, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, REST, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, E4, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, CS5, -8, DS5, 8, E5, 16, E5, 16, E4, 16, E4, -2, C4, 8, C4, 8, E4, 16, G4, -8, D4, 8, D4, 8, FS4, 16, A4, -8, E5, 16, E5, 16, E4, 16, E4, -2, C4, 8, C4, 8, E4, 16, G4, -8, D4, 8, D4, 8, B3, 16, D4, -8, E5, 16, E5, 8, D5, 16, REST, 16, CS5, -4, E4, 8, FS4, 16, G4, 16, A4, 16, B4, -8, E4, -8, B4, 8, A4, 16, D5, -4, E5, 16, E5, 8, D5, 16, REST, 16, CS5, -4, E4, 8, FS4, 16, G4, 16, A4, 16, B4, -8, E4, -8, B4, 8, A4, 16, D4, -4, REST, 8, E5, 8, REST, 16, B5, 16, REST, 8, AS5, 16, B5, 16, AS5, 16, G5, 16, REST, 4, B5, 8, B5, 16, AS5, 16, REST, 16, AS5, 16, A5, 16, REST, 16, B5, 16, G5, 16, B5, 16, AS5, 16, REST, 16, B5, 16, A5, 16, G5, 16, REST, 8, E5, 8, REST, 16, B5, 16, REST, 8, AS5, 16, B5, 16, AS5, 16, G5, 16, REST, 4, B5, 8, B5, 16, AS5, 16, REST, 16, AS5, 16, A5, 16, REST, 16, B5, 16, G5, 16, B5, 16, AS5, 16, REST, 16, B5, 16, A5, 16, G5, 16, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, E4, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, REST, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, G4, -8, E4, 8, DS4, -8, FS4, -8, C5, 8, B4, -8, CS5, -8, DS5, 8, E5, 16, E5, 16, E4, 16, E4, -2, C4, 8, C4, 8, E4, 16, G4, -8, D4, 8, D4, 8, FS4, 16, A4, -8, E5, 16, E5, 16, E4, 16, E4, -2, C4, 8, C4, 8, E4, 16, G4, -8, D4, 8, D4, 8, B3, 16, D4, -8,};
int merrychristmas[] = {C5, 4, F5, 4, F5, 8, G5, 8, F5, 8, E5, 8, D5, 4, D5, 4, D5, 4, G5, 4, G5, 8, A5, 8, G5, 8, F5, 8, E5, 4, C5, 4, C5, 4, A5, 4, A5, 8, AS5, 8, A5, 8, G5, 8, F5, 4, D5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 8, G5, 8, F5, 8, E5, 8, D5, 4, D5, 4, D5, 4, G5, 4, G5, 8, A5, 8, G5, 8, F5, 8, E5, 4, C5, 4, C5, 4, A5, 4, A5, 8, AS5, 8, A5, 8, G5, 8, F5, 4, D5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 4, F5, 4, E5, 2, E5, 4, F5, 4, E5, 4, D5, 4, C5, 2, A5, 4, AS5, 4, A5, 4, G5, 4, C6, 4, C5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 8, G5, 8, F5, 8, E5, 8, D5, 4, D5, 4, D5, 4, G5, 4, G5, 8, A5, 8, G5, 8, F5, 8, E5, 4, C5, 4, C5, 4, A5, 4, A5, 8, AS5, 8, A5, 8, G5, 8, F5, 4, D5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 4, F5, 4, E5, 2, E5, 4, F5, 4, E5, 4, D5, 4, C5, 2, A5, 4, AS5, 4, A5, 4, G5, 4, C6, 4, C5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 8, G5, 8, F5, 8, E5, 8, D5, 4, D5, 4, D5, 4, G5, 4, G5, 8, A5, 8, G5, 8, F5, 8, E5, 4, C5, 4, C5, 4, A5, 4, A5, 8, AS5, 8, A5, 8, G5, 8, F5, 4, D5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, C5, 4, F5, 4, F5, 8, G5, 8, F5, 8, E5, 8, D5, 4, D5, 4, D5, 4, G5, 4, G5, 8, A5, 8, G5, 8, F5, 8, E5, 4, C5, 4, C5, 4, A5, 4, A5, 8, AS5, 8, A5, 8, G5, 8, F5, 4, D5, 4, C5, 8, C5, 8, D5, 4, G5, 4, E5, 4, F5, 2, REST, 4};
int starwars[] = {AS4, 8, AS4, 8, AS4, 8, F5, 2, C6, 2, AS5, 8, A5, 8, G5, 8, F6, 2, C6, 4, AS5, 8, A5, 8, G5, 8, F6, 2, C6, 4, AS5, 8, A5, 8, AS5, 8, G5, 2, C5, 8, C5, 8, C5, 8, F5, 2, C6, 2, AS5, 8, A5, 8, G5, 8, F6, 2, C6, 4, AS5, 8, A5, 8, G5, 8, F6, 2, C6, 4, AS5, 8, A5, 8, AS5, 8, G5, 2, C5, -8, C5, 16, D5, -4, D5, 8, AS5, 8, A5, 8, G5, 8, F5, 8, F5, 8, G5, 8, A5, 8, G5, 4, D5, 8, E5, 4, C5, -8, C5, 16, D5, -4, D5, 8, AS5, 8, A5, 8, G5, 8, F5, 8, C6, -8, G5, 16, G5, 2, REST, 8, C5, 8, D5, -4, D5, 8, AS5, 8, A5, 8, G5, 8, F5, 8, F5, 8, G5, 8, A5, 8, G5, 4, D5, 8, E5, 4, C6, -8, C6, 16, F6, 4, DS6, 8, CS6, 4, C6, 8, AS5, 4, GS5, 8, G5, 4, F5, 8, C6, 1};
int mariogame[] = {E5, 8, E5, 8, REST, 8, E5, 8, REST, 8, C5, 8, E5, 8, G5, 4, REST, 4, G4, 8, REST, 4, C5, -4, G4, 8, REST, 4, E4, -4, A4, 4, B4, 4, AS4, 8, A4, 4, G4, -8, E5, -8, G5, -8, A5, 4, F5, 8, G5, 8, REST, 8, E5, 4, C5, 8, D5, 8, B4, -4, C5, -4, G4, 8, REST, 4, E4, -4, A4, 4, B4, 4, AS4, 8, A4, 4, G4, -8, E5, -8, G5, -8, A5, 4, F5, 8, G5, 8, REST, 8, E5, 4, C5, 8, D5, 8, B4, -4, REST, 4, G5, 8, FS5, 8, F5, 8, DS5, 4, E5, 8, REST, 8, GS4, 8, A4, 8, C4, 8, REST, 8, A4, 8, C5, 8, D5, 8, REST, 4, DS5, 4, REST, 8, D5, -4, C5, 2, REST, 2, REST, 4, G5, 8, FS5, 8, F5, 8, DS5, 4, E5, 8, REST, 8, GS4, 8, A4, 8, C4, 8, REST, 8, A4, 8, C5, 8, D5, 8, REST, 4, DS5, 4, REST, 8, D5, -4, C5, 2, REST, 2, C5, 8, C5, 4, C5, 8, REST, 8, C5, 8, D5, 4, E5, 8, C5, 4, A4, 8, G4, 2, C5, 8, C5, 4, C5, 8, REST, 8, C5, 8, D5, 8, E5, 8, REST, 1, C5, 8, C5, 4, C5, 8, REST, 8, C5, 8, D5, 4, E5, 8, C5, 4, A4, 8, G4, 2, E5, 8, E5, 8, REST, 8, E5, 8, REST, 8, C5, 8, E5, 4, G5, 4, REST, 4, G4, 4, REST, 4, C5, -4, G4, 8, REST, 4, E4, -4, A4, 4, B4, 4, AS4, 8, A4, 4, G4, -8, E5, -8, G5, -8, A5, 4, F5, 8, G5, 8, REST, 8, E5, 4, C5, 8, D5, 8, B4, -4, C5, -4, G4, 8, REST, 4, E4, -4, A4, 4, B4, 4, AS4, 8, A4, 4, G4, -8, E5, -8, G5, -8, A5, 4, F5, 8, G5, 8, REST, 8, E5, 4, C5, 8, D5, 8, B4, -4, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, D5, -8, A5, -8, A5, -8, A5, -8, G5, -8, F5, -8, E5, 8, C5, 4, A4, 8, G4, 2, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, B4, 8, F5, 4, F5, 8, F5, -8, E5, -8, D5, -8, C5, 8, E4, 4, E4, 8, C4, 2, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, D5, -8, A5, -8, A5, -8, A5, -8, G5, -8, F5, -8, E5, 8, C5, 4, A4, 8, G4, 2, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, B4, 8, F5, 4, F5, 8, F5, -8, E5, -8, D5, -8, C5, 8, E4, 4, E4, 8, C4, 2, C5, 8, C5, 4, C5, 8, REST, 8, C5, 8, D5, 8, E5, 8, REST, 1, C5, 8, C5, 4, C5, 8, REST, 8, C5, 8, D5, 4, E5, 8, C5, 4, A4, 8, G4, 2, E5, 8, E5, 8, REST, 8, E5, 8, REST, 8, C5, 8, E5, 4, G5, 4, REST, 4, G4, 4, REST, 4, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, D5, -8, A5, -8, A5, -8, A5, -8, G5, -8, F5, -8, E5, 8, C5, 4, A4, 8, G4, 2, E5, 8, C5, 4, G4, 8, REST, 4, GS4, 4, A4, 8, F5, 4, F5, 8, A4, 2, B4, 8, F5, 4, F5, 8, F5, -8, E5, -8, D5, -8, C5, 8, E4, 4, E4, 8, C4, 2, C5, -4, G4, -4, E4, 4, A4, -8, B4, -8, A4, -8, GS4, -8, AS4, -8, GS4, -8, G4, 8, D4, 8, E4, -2,};
int tetrisgame[] = {E5, 4, B4, 8, C5, 8, D5, 4, C5, 8, B4, 8, A4, 4, A4, 8, C5, 8, E5, 4, D5, 8, C5, 8, B4, -4, C5, 8, D5, 4, E5, 4, C5, 4, A4, 4, A4, 8, A4, 4, B4, 8, C5, 8, D5, -4, F5, 8, A5, 4, G5, 8, F5, 8, E5, -4, C5, 8, E5, 4, D5, 8, C5, 8, B4, 4, B4, 8, C5, 8, D5, 4, E5, 4, C5, 4, A4, 4, A4, 4, REST, 4, E5, 4, B4, 8, C5, 8, D5, 4, C5, 8, B4, 8, A4, 4, A4, 8, C5, 8, E5, 4, D5, 8, C5, 8, B4, -4, C5, 8, D5, 4, E5, 4, C5, 4, A4, 4, A4, 8, A4, 4, B4, 8, C5, 8, D5, -4, F5, 8, A5, 4, G5, 8, F5, 8, E5, -4, C5, 8, E5, 4, D5, 8, C5, 8, B4, 4, B4, 8, C5, 8, D5, 4, E5, 4, C5, 4, A4, 4, A4, 4, REST, 4, E5, 2, C5, 2, D5, 2, B4, 2, C5, 2, A4, 2, GS4, 2, B4, 4, REST, 8, E5, 2, C5, 2, D5, 2, B4, 2, C5, 4, E5, 4, A5, 2, GS5, 2,};
int miigame[] = {FS4, 8, REST, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, FS4, 8, D4, 8, D4, 8, D4, 8, REST, 8, REST, 4, REST, 8, CS4, 8, D4, 8, FS4, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, F4, 8, E5, -4, DS5, 8, D5, 8, REST, 8, REST, 4, GS4, 8, REST, 8, CS5, 8, FS4, 8, REST, 8, CS5, 8, REST, 8, GS4, 8, REST, 8, CS5, 8, G4, 8, FS4, 8, REST, 8, E4, 8, REST, 8, E4, 8, E4, 8, E4, 8, REST, 8, REST, 4, E4, 8, E4, 8, E4, 8, REST, 8, REST, 4, DS4, 8, D4, 8, CS4, 8, REST, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, FS4, 8, D4, 8, D4, 8, D4, 8, REST, 8, E5, 8, E5, 8, E5, 8, REST, 8, REST, 8, FS4, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, F4, 8, E5, 2, D5, 8, REST, 8, REST, 4, B4, 8, G4, 8, D4, 8, CS4, 4, B4, 8, G4, 8, CS4, 8, A4, 8, FS4, 8, C4, 8, B3, 4, F4, 8, D4, 8, B3, 8, E4, 8, E4, 8, E4, 8, REST, 4, REST, 4, AS4, 4, CS5, 8, D5, 8, FS5, 8, A5, 8, REST, 8, REST, 4, REST, 2, A3, 4, AS3, 4, A3, -4, A3, 8, A3, 2, REST, 4, A3, 8, AS3, 8, A3, 8, F4, 4, C4, 8, A3, -4, A3, 8, A3, 2, REST, 2, B3, 4, C4, 4, CS4, -4, C4, 8, CS4, 2, REST, 4, CS4, 8, C4, 8, CS4, 8, GS4, 4, DS4, 8, CS4, -4, DS4, 8, B3, 1, E4, 4, E4, 4, E4, 4, REST, 8, FS4, 8, REST, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, FS4, 8, D4, 8, D4, 8, D4, 8, REST, 8, REST, 4, REST, 8, CS4, 8, D4, 8, FS4, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, F4, 8, E5, -4, DS5, 8, D5, 8, REST, 8, REST, 4, GS4, 8, REST, 8, CS5, 8, FS4, 8, REST, 8, CS5, 8, REST, 8, GS4, 8, REST, 8, CS5, 8, G4, 8, FS4, 8, REST, 8, E4, 8, REST, 8, E4, 8, E4, 8, E4, 8, REST, 8, REST, 4, E4, 8, E4, 8, E4, 8, REST, 8, REST, 4, DS4, 8, D4, 8, CS4, 8, REST, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, FS4, 8, D4, 8, D4, 8, D4, 8, REST, 8, E5, 8, E5, 8, E5, 8, REST, 8, REST, 8, FS4, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, F4, 8, E5, 2, D5, 8, REST, 8, REST, 4, B4, 8, G4, 8, D4, 8, CS4, 4, B4, 8, G4, 8, CS4, 8, A4, 8, FS4, 8, C4, 8, B3, 4, F4, 8, D4, 8, B3, 8, E4, 8, E4, 8, E4, 8, REST, 4, REST, 4, AS4, 4, CS5, 8, D5, 8, FS5, 8, A5, 8, REST, 8, REST, 4, REST, 2, A3, 4, AS3, 4, A3, -4, A3, 8, A3, 2, REST, 4, A3, 8, AS3, 8, A3, 8, F4, 4, C4, 8, A3, -4, A3, 8, A3, 2, REST, 2, B3, 4, C4, 4, CS4, -4, C4, 8, CS4, 2, REST, 4, CS4, 8, C4, 8, CS4, 8, GS4, 4, DS4, 8, CS4, -4, DS4, 8, B3, 1, E4, 4, E4, 4, E4, 4, REST, 8, FS4, 8, REST, 8, A4, 8, CS5, 8, REST, 8, A4, 8, REST, 8, FS4, 8};
int pacmangame[] = {B4, 16, B5, 16, FS5, 16, DS5, 16, B5, 32, FS5, -16, DS5, 8, C5, 16, C6, 16, G6, 16, E6, 16, C6, 32, G6, -16, E6, 8, B4, 16, B5, 16, FS5, 16, DS5, 16, B5, 32, FS5, -16, DS5, 8, DS5, 32, E5, 32, F5, 32, F5, 32, FS5, 32, G5, 32, G5, 32, GS5, 32, A5, 16, B5, 8};
int rickroll[] = {D5, -4, E5, -4, A4, 4, E5, -4, FS5, -4, A5, 16, G5, 16, FS5, 8, D5, -4, E5, -4, A4, 2, A4, 16, A4, 16, B4, 16, D5, 8, D5, 16, D5, -4, E5, -4, A4, 4, E5, -4, FS5, -4, A5, 16, G5, 16, FS5, 8, D5, -4, E5, -4, A4, 2, A4, 16, A4, 16, B4, 16, D5, 8, D5, 16, REST, 4, B4, 8, CS5, 8, D5, 8, D5, 8, E5, 8, CS5, -8, B4, 16, A4, 2, REST, 4, REST, 8, B4, 8, B4, 8, CS5, 8, D5, 8, B4, 4, A4, 8, A5, 8, REST, 8, A5, 8, E5, -4, REST, 4, B4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, D5, 8, E5, 8, REST, 8, REST, 8, CS5, 8, B4, 8, A4, -4, REST, 4, REST, 8, B4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, A4, 4, E5, 8, E5, 8, E5, 8, FS5, 8, E5, 4, REST, 4, D5, 2, E5, 8, FS5, 8, D5, 8, E5, 8, E5, 8, E5, 8, FS5, 8, E5, 4, A4, 4, REST, 2, B4, 8, CS5, 8, D5, 8, B4, 8, REST, 8, E5, 8, FS5, 8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, E5, -8, E5, -8, D5, -8, CS5, 16, B4, -8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 8, A4, 8, A4, 8, E5, 4, D5, 2, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, A5, 4, CS5, 8, D5, -8, CS5, 16, B4, 8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 4, A4, 8, E5, 4, D5, 2, REST, 4, REST, 8, B4, 8, D5, 8, B4, 8, D5, 8, E5, 4, REST, 8, REST, 8, CS5, 8, B4, 8, A4, -4, REST, 4, REST, 8, B4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, A4, 4, REST, 8, A5, 8, A5, 8, E5, 8, FS5, 8, E5, 8, D5, 8, REST, 8, A4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, REST, 8, CS5, 8, B4, 8, A4, -4, REST, 4, B4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, A4, 4, REST, 8, REST, 8, E5, 8, E5, 8, FS5, 4, E5, -4, D5, 2, D5, 8, E5, 8, FS5, 8, E5, 4, E5, 8, E5, 8, FS5, 8, E5, 8, A4, 8, A4, 4, REST, -4, A4, 8, B4, 8, CS5, 8, D5, 8, B4, 8, REST, 8, E5, 8, FS5, 8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, E5, -8, E5, -8, D5, -8, CS5, 16, B4, 8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 4, A4, 8, E5, 4, D5, 2, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, A5, 4, CS5, 8, D5, -8, CS5, 16, B4, 8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 4, A4, 8, E5, 4, D5, 2, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, A5, 4, CS5, 8, D5, -8, CS5, 16, B4, 8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 4, A4, 8, E5, 4, D5, 2, A4, 16, B4, 16, D5, 16, B4, 16, FS5, -8, FS5, -8, E5, -4, A4, 16, B4, 16, D5, 16, B4, 16, A5, 4, CS5, 8, D5, -8, CS5, 16, B4, 8, A4, 16, B4, 16, D5, 16, B4, 16, D5, 4, E5, 8, CS5, -8, B4, 16, A4, 4, A4, 8, E5, 4, D5, 2, REST, 4};
int nokiaring[] = {E5, 8, D5, 8, FS4, 4, GS4, 4, CS5, 8, B4, 8, D4, 4, E4, 4, B4, 8, A4, 8, CS4, 4, E4, 4, A4, 2};

int selection = 0;
bool playingmusic = false;

typedef struct {
  uint8_t menu;
  char* strname;
  char* category;
  char* filename;
  int* tempo;
} music;

const music items[] {
  {0, " Vampire Killer ", "Game", "vampirekiller", 130},
  {1, " Mii Main Theme ", "Game", "miigame", 114},
  {2, "Main Mario Theme", "Game", "mariogame", 200},
  {3, "  Tetris Theme  ", "Game", "tetrisgame", 144},
  {4, " Pacman Losing ", "Game", "pacmangame", 105},
  {5, " Happy Birthday ", "Classic", "happybirthday", 140},
  {6, " Merry Christmas", "Classic", "merrychristmas", 140},
  {7, "  Harry Potter  ", "Movie", "harrypotter", 144},
  {8, "    Star Wars   ", "Movie", "starwars", 108},
  {9, "   Rick Roll   ", "Meme", "rickroll", 114},
  {10, " Nokia Ringtone", "Meme", "nokiaring", 180}
};

byte customChar[] = {B00100, B00110, B00101, B00100, B11100, B10100, B11100, B00000};

void playMelody(int melody[], int notes , int tempo, int beats) {
  int wholenote = (60000 * beats) / tempo;
  int divider = 0, noteDuration = 0;
  while (playingmusic) {
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      if (moveTitle(joystic->singleRead()) == "PRESS") {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(items[selection].strname);
        lcd.setCursor(0, 1);
        lcd.write(0);
        lcd.setCursor(2, 1);
        lcd.print(String(items[selection].category) + " - Play");
        playingmusic = false;
        break;
      }
      divider = melody[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5;
      }
      tone(buzzer, melody[thisNote], noteDuration * 0.9);
      delay(noteDuration);
      noTone(buzzer);
    }
  }
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, customChar);
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.setCursor(0, 0);
  lcd.print(" Vampire Killer ");
  lcd.setCursor(2, 1);
  lcd.print("Game - Play");
  joystic = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
}

void loop() {
  if (moveTitle(joystic->singleRead()) == "PRESS") {
    if (playingmusic == true) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(items[selection].strname);
      lcd.setCursor(0, 1);
      lcd.write(0);
      lcd.setCursor(2, 1);
      lcd.print(String(items[selection].category) + " - Play");
      playingmusic = false;
    } else {
      playingmusic = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(items[selection].strname);
      lcd.setCursor(0, 1);
      lcd.write(0);
      if (items[selection].category == "Classic") {
        lcd.setCursor(1, 1);
      } else {
        lcd.setCursor(2, 1);
      }
      lcd.print(String(items[selection].category) + " - Pause");
      if (String(items[selection].filename) == "vampirekiller") {
        playMelody(vampirekiller, MELODY_LENGTH(vampirekiller), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "happybirthday") {
        playMelody(happybirthday, MELODY_LENGTH(happybirthday), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "harrypotter") {
        playMelody(harrypotter, MELODY_LENGTH(harrypotter), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "merrychristmas") {
        playMelody(merrychristmas, MELODY_LENGTH(merrychristmas), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "rickroll") {
        playMelody(rickroll, MELODY_LENGTH(rickroll), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "starwars") {
        playMelody(starwars, MELODY_LENGTH(starwars), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "mariogame") {
        playMelody(mariogame, MELODY_LENGTH(mariogame), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "tetrisgame") {
        playMelody(tetrisgame, MELODY_LENGTH(tetrisgame), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "miigame") {
        playMelody(miigame, MELODY_LENGTH(miigame), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "pacmangame") {
        playMelody(pacmangame, MELODY_LENGTH(pacmangame), items[selection].tempo, 4);
      }
      if (String(items[selection].filename) == "nokiaring") {
        playMelody(nokiaring, MELODY_LENGTH(nokiaring), items[selection].tempo, 4);
      }
    }
  }
  if (playingmusic) {} else {
    if (joystic->isUp() == 1) {
      selection = selection - 1;
      if (selection < 0) {
        selection = 10;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(items[selection].strname);
      lcd.setCursor(0, 1);
      lcd.write(0);
      lcd.setCursor(2, 1);
      lcd.print(String(items[selection].category) + " - Play");
    }
    if (joystic->isDown() == 1) {
      selection = selection + 1;
      if (selection > 10) {
        selection = 0;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(items[selection].strname);
      lcd.setCursor(0, 1);
      lcd.write(0);
      lcd.setCursor(2, 1);
      lcd.print(String(items[selection].category) + " - Play");
    }
    delay(300);
  }
}

String moveTitle(const Joystick::Move move) {
  switch (move) {
    case Joystick::Move::NOT:
      return "NOT";
    case Joystick::Move::PRESS:
      return "PRESS";
    case Joystick::Move::UP:
      return "UP";
    case Joystick::Move::DOWN:
      return "DOWN";
    case Joystick::Move::RIGHT:
      return "RIGHT";
    case Joystick::Move::LEFT:
      return "LEFT";
    default:
      return "???";
  }
}
