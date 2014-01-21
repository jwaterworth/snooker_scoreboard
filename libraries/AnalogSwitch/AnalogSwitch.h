#ifndef AnalogSwitch_h
#define AnalogSwitch_h

#include "Arduino.h"

#define BUTTON1 882
#define BUTTON2 744
#define BUTTON3 608
#define BUTTON4 469
#define BUTTON5 326
#define BUTTON6 176
#define BUTTON7 14

//There is a gap of roughly 140 between each amount
//so an an error of 50 (140/2 - 20) has been chosen to allow
//a reasonable amount of room for error
#define BUTTON_ERR 70

//Button delay is the amount of time we should wait 
//before allowing the button to be registered as
//pressed again.
#define BUTTONDELAY 300

//Debounce delay is the interval at which a pressed button is checked
//to ensure an actual 'clean' press has taken place. False presses such
//as bouncing which may occur at a rate higher than DEBOUNCEDELAY ms will be ignored
#define DEBOUNCEDELAY 50

class AnalogSwitch {
  public:
    AnalogSwitch(byte pinNum);
    
	byte CheckButtons();
	
  private:    
	//byte _buttonPressed;
	//byte _prevButtonPressed;
	byte _switchPin;
	
	int _reading;
	
	long _buttonLastChecked;
	long _lastDebounceTime;
	
	boolean _pauseButtons;	
	boolean _checkReading;
	
	
	byte DebounceCheckButton();
    int GetButton(int val);
};

#endif
