#include "LedControl.h"

// pins for CLK, CS, DIN
const int CLK = 6; 
const int CS = 7;  
const int DIN = 8;  

// instance of ledcontrol 
LedControl lc = LedControl(DIN, CLK, CS, 1); //DIN, CLK, CS, number of devices

//displayable bit patterns
byte heart[8] = {
  B00000000,
  B00100100,
  B01111110,
  B01111110,
  B00111100,
  B00011000,
  B00000000,
  B00000000
};

void setup() {
  // init MAX7219
  lc.shutdown(0, false);       // wake up matrix
  lc.setIntensity(0, 1);       // brightness setting (0 min, 15 max)
  lc.clearDisplay(0);          // clear
}

void loop() {
  for (int i = 0; i < 2; i++) {  // repeat pattern twice
    for (int frame = 0; frame < 4; frame++) {  // 
      for (int row = 0; row < 8; row++) {
        lc.setRow(0, row, heart[row]); // check in pattern if led needs to be turned on
      }
      delay(500); //delay until shifting
      shiftHeartLeft();
    }
  }
}

// shift pattern left
void shiftHeartLeft() {
  for (int i = 0; i < 8; i++) {
    heart[i] <<= 1;
    if (bitRead(heart[i], 7)) {
      bitWrite(heart[i], 0, 1);
    }
  }
}
