#include "Arduino.h"
#include "RGB_Tlc5940.h"

//Constructor
RGB_Tlc5940::RGB_Tlc5940(int numLeds, struct RGB ledPins[]) {
	Serial.println("Constructor Start");
	_numLeds = numLeds;
	_ledPins = ledPins;
	
	Tlc.init();
	
	for(int i=0; i<_numLeds; ++i) {
		Clear(i);
	}
	
	Serial.println("Constructor End");
}

//Public
void RGB_Tlc5940::Red(byte index) {
  WriteRGB(index, 255, 0, 0);
}

void RGB_Tlc5940::Yellow(byte index) {
  WriteRGB(index, 255, 100, 0);
}

void RGB_Tlc5940::Green(byte index) {
  WriteRGB(index, 0, 175, 0);
}

void RGB_Tlc5940::Brown(byte index) {
  WriteRGB(index, 150, 20, 0);
}

void RGB_Tlc5940::Blue(byte index) {
  WriteRGB(index, 0, 0, 200);
}

void RGB_Tlc5940::Pink(byte index) {
  WriteRGB(index, 255, 0, 175);
}

void RGB_Tlc5940::Black(byte index) {
  WriteRGB(index, 0, 0, 0);
}

void RGB_Tlc5940::Clear(byte index) {
  WriteRGB(index, 0, 0, 0);
}

void RGB_Tlc5940::CycleSpectrum() {
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
      
	  for(byte j=0; j<_numLeds; j++) {
		WriteRGB(j, rgbColour[0], rgbColour[1], rgbColour[2], false);		
	  }
      Commit();
      delay(15);
    }

  }
}

void RGB_Tlc5940::WriteRGB(byte index, byte red, byte green, byte blue) {	 
	//If index is invalid, abort write
	if(!ValidateIndex(index))
		return;
		
	Serial.println("Validation Complete!");
	
	Serial.println("Mapping values...");
	int absRed = map(red, 0, 255, 0, 4095);
	int absGreen = map(green, 0, 255, 0, 4095);
	int absBlue = map(blue, 0, 255, 0, 4095);
	
    Serial.print("Red: ");
	Serial.print(red);
	Serial.print(" to ");
	Serial.print(absRed);
	Serial.print(" ");
	
	Serial.print("Green: ");
	Serial.print(green);
	Serial.print(" to ");
	Serial.print(absGreen);
	Serial.print(" ");
	
	Serial.print("Blue: ");
	Serial.print(blue);
	Serial.print(" to ");
	Serial.println(absBlue);
	
	Serial.print("Writing to pins...");
	Serial.print("Red : ");
	Serial.print(_ledPins[index].r);
	Serial.print(" ");
	Serial.print("Green : ");
	Serial.print(_ledPins[index].g);
	Serial.print(" ");
	Serial.print("Blue : ");
	Serial.println(_ledPins[index].b);
	
	Tlc.set(_ledPins[index].r, absRed);
	Tlc.set(_ledPins[index].g, absGreen);
	Tlc.set(_ledPins[index].b, absBlue);
	Commit();
  
  return;
}

void RGB_Tlc5940::WriteRGB(byte index, byte red, byte green, byte blue, boolean sync) {	 
	//If index is invalid, abort write
	if(!ValidateIndex(index))
		return;

	//Serial.println("Validation Complete!");
	
	//Serial.println("Mapping values...");
	int absRed = map(red, 0, 255, 0, 4095);
	int absGreen = map(green, 0, 255, 0, 4095);
	int absBlue = map(blue, 0, 255, 0, 4095);
    
	//Serial.println("Setting values...");
	Tlc.set(_ledPins[index].r, absRed);
	Tlc.set(_ledPins[index].g, absGreen);
	Tlc.set(_ledPins[index].b, absBlue);
	
  if(sync) {
	Commit();
  }
  
  return;
}

void RGB_Tlc5940::Commit() {
	//Serial.println("Committing");
	Tlc.update();
	//Serial.println("Committed");
}

//Private
boolean RGB_Tlc5940::ValidateIndex(byte index) {
	//Serial.print("Validating index: ");
	//Serial.println(index);
	return _numLeds >= index;
}