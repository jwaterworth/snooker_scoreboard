#ifndef RGBLed_h
#define RGBLed_h

#include "Arduino.h"

class RGBLed {
  public:
    RGBLed(byte redPin, byte greenPin, byte bluePin);
    void Red();
    void Yellow();
    void Green();
    void Brown();
    void Blue();
    void Pink();
    void Black();
	void Clear();
	void CycleSpectrum();
	void WriteRGB(byte red, byte green, byte blue);
	
  private:     
    byte _redPin;
    byte _greenPin;
    byte _bluePin;

};

#endif
