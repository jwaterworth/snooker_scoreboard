#include "Arduino.h"
#include "AnalogSwitch.h"


/*Class to custom built to provide an interface to 7 tactile push button switches sharing
a common source voltage and ground using a single analog pin to read resistances. */

AnalogSwitch::AnalogSwitch(byte pinNum) {
	_switchPin = pinNum;
	
	
	//_buttonPressed = 0;
	//prevbuttonPressed = 0;
	_buttonLastChecked = 0; //Limit the button getting checked every cycle

	
	//Button delay
	_pauseButtons = false;

	//Debouncing Variables
	_reading = 0;
	_checkReading = true;
	_lastDebounceTime = 0;
	
	 pinMode(pinNum, INPUT);
	digitalWrite(pinNum, HIGH); //enable internal pullup
	
}

//Public
byte AnalogSwitch::CheckButtons() {
	int returnVal = 0;
  
	if(!_pauseButtons)
		returnVal = DebounceCheckButton();

	//if we detect a button press, ensure no more button presses can happen for BUTTONDELAY ms  
	if(millis() - _buttonLastChecked > BUTTONDELAY) {    
		_pauseButtons = false;    
		_buttonLastChecked = millis(); //reset value
	}    
  
	if(returnVal)
		_pauseButtons = true;
  
  return returnVal;
}

//Private 
byte AnalogSwitch::DebounceCheckButton() {
	int returnVal = 0;

	//Get _reading once
	if(_checkReading) {
		//Serial.println("Checking _reading");
		_reading = GetButton(analogRead(_switchPin));
		//Serial.print("_reading = ");
		//Serial.println(_reading);
		_lastDebounceTime = millis();  
		_checkReading = false;
	}     

	//Wait for debounce delay
	if((millis() - _lastDebounceTime) > DEBOUNCEDELAY) {
		//Serial.println("Debounce Delay Reached");
		//if _reading now == _reading then, return number, otherwise 0;
		int state = GetButton(analogRead(_switchPin));
		//Serial.print("State after delay = ");
		//Serial.println(state);
		if(_reading == state) {
			//Return value
			returnVal = state;
		}
		//Setup for next time 
		_reading = 0;
		_checkReading = true;
		_lastDebounceTime = millis();
	}

	return returnVal;
}

int AnalogSwitch::GetButton(int val) {
	byte buttonNum = 0;
	Serial.print(val);
	Serial.print(" ");
	if(BUTTON1 - BUTTON_ERR < val && val < BUTTON1 + BUTTON_ERR) {
		buttonNum = 1;
	} else if(BUTTON2 - BUTTON_ERR < val && val < BUTTON2 + BUTTON_ERR) {
		buttonNum = 2;
	} else if(BUTTON3 - BUTTON_ERR < val && val < BUTTON3 + BUTTON_ERR) {
		buttonNum = 3;
	} else if(BUTTON4 - BUTTON_ERR < val && val < BUTTON4 + BUTTON_ERR) {
		buttonNum = 4;
	} else if(BUTTON5 - BUTTON_ERR < val && val < BUTTON5 + BUTTON_ERR) {
		buttonNum = 5;
	} else if(BUTTON6 - BUTTON_ERR < val && val < BUTTON6 + BUTTON_ERR) {
		buttonNum = 6;
	} else if(BUTTON7 - BUTTON_ERR < val && val < BUTTON7 + BUTTON_ERR) {
		buttonNum = 7;
	}
	
	Serial.println(buttonNum);
	return buttonNum;
}

