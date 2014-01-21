
#ifndef RGB_Tlc5940_h
#define RGB_Tlc5940_h
#include "Arduino.h"
#include <Tlc5940.h>

struct RGB {
	byte r;
	byte g;
	byte b;
};

//Library Tlc5940.h must also be included in the client code for this library to work. (#include <Tlc5940.h>)

class RGB_Tlc5940 {
  public:
    RGB_Tlc5940(int numLeds, struct RGB ledPins[]);
	void Red(byte index);
    void Yellow(byte index);
    void Green(byte index);
    void Brown(byte index);
    void Blue(byte index);
    void Pink(byte index);
    void Black(byte index);
	void Clear(byte index);
	void CycleSpectrum();
	void WriteRGB(byte index, byte red, byte green, byte blue);
	void WriteRGB(byte index, byte red, byte green, byte blue, boolean sync);//Gives ability to batch commit
	void Commit();
  private:
	//Member Variables
	byte _numLeds;
	//Pointer to an array of ledPins. Each instance defines the red, blue and green pin for that RGB LED
    struct RGB* _ledPins;
	Tlc5940 _tlc;
		
	//Methods
	boolean ValidateIndex(byte index);
};

#endif