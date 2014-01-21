#include "Arduino.h"
#include "RGBLed.h"


//Class to control a ** COMMON ANODE ** RBG. Notice the inversion of RGB numbers in WriteRGB.

RGBLed::RGBLed(byte redPin, byte greenPin, byte bluePin) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
  WriteRGB(0, 0, 0);
}

//Public
void RGBLed::Red() {
  WriteRGB(255, 0, 0);
}

void RGBLed::Yellow() {
  WriteRGB(255, 100, 0);
}

void RGBLed::Green() {
  WriteRGB(0, 175, 0);
}

void RGBLed::Brown() {
  WriteRGB(150, 20, 0);
}

void RGBLed::Blue() {
  WriteRGB(0, 0, 200);
}

void RGBLed::Pink() {
  WriteRGB(255, 0, 175);
}

void RGBLed::Black() {
  WriteRGB(0, 0, 0);
}

void RGBLed::Clear() {
  WriteRGB(0, 0, 0);
}

void RGBLed::CycleSpectrum() {
  byte rgbColour[3];
 
  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  
 
  // Choose the colours to increment and decrement.
  for (byte decColour = 0; decColour < 3; decColour++) {
    int incColour = decColour == 2 ? 0 : decColour + 1;
 
    // cross-fade the two colours.
    for(byte i = 0; i < 255; i++) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      WriteRGB(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }

  }
}

void RGBLed::WriteRGB(byte red, byte green, byte blue) {
 //Invert as PWMs are ground
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  
  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
}
