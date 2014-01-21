#include <Tlc5940.h>
#include <RGB_Tlc5940.h>

//Set up pins
RGB ledPins[] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};

//Set up library object to control pins
RGB_Tlc5940* rgbLeds;

void setup() {
  Serial.begin(9600);
  rgbLeds = new RGB_Tlc5940(5, ledPins);
  //rgbLeds.Red(0);
  //rgbLeds.Blue(1);
  //rgbLeds.Red(2);
  //rgbLeds.Green(3);
  //rgbLeds.Red(4);
 
  
  //rgbLeds.CycleSpectrum();
}

void loop() {
  rgbLeds->CycleSpectrum();
}
