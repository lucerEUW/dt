#include "LedControl.h"

//def analog pins
#define VRX_PIN  A1 
#define VRY_PIN  A0 

// jjoyS values
int xValue = 0; 
int yValue = 0; 
const int switchPin = 2;

// matrix Dpins
const int CLK = 3;  
const int CS = 4;   
const int DIN = 5;  

// instance of ledC for matrix
LedControl lc = LedControl(DIN, CLK, CS, 1); // DIN, CLK, CS, number of devices

// initial start values 0-7
int ledX = 3; 
int ledY = 3; 

void setup() {
  // setup joystick
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);

  // init matrix
  lc.shutdown(0, false);       
  lc.setIntensity(0, 1);     
  lc.clearDisplay(0);         
  
  // turn on init. pos led
  lc.setLed(0, ledX, ledY, true);
}

void loop() {
  // read analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // convert joyValues to -1/1
  int xMovement = map(xValue, 0, 1000, -1, 1); //only 100 to account for specific stick drift
  int yMovement = map(yValue, 0, 1023, -1, 1);

  // updated ledPos with joystick input (subtracting or adding to Pos values)
  ledX = constrain(ledX + xMovement, 0, 7); // constrain x in 0-7 range
  ledY = constrain(ledY + yMovement, 0, 7); // constrain y in 0-7 range

  // clear matrix
  lc.clearDisplay(0);

  // tur on led in new pos
  lc.setLed(0, ledX, ledY, true);

  delay(100); // delay for movespeed

  // serial mon output to troubleshoot 
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(200);
}