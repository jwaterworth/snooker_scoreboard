
#define SWITCH A0
#define BUTTONDELAY 300
#define DEBOUNCEDELAY 50

int buttonPressed = 0;
int prevButtonPressed = 0;
long buttonLastChecked = 0; //Limit the button getting checked every cycle

//Button delay
boolean pauseButtons = false;

//Debouncing Variables
int reading = 0;
boolean checkReading = true;
long lastDebounceTime = 0;

void setup() 
{
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH); //enable internal pullup
  Serial.begin(9600); 
}

void loop() 
{
  Serial.println(analogRead(SWITCH));
  /*if(buttonPressed = CheckButtons(SWITCH)) {
      Serial.println(buttonPressed); 
  }*/
}

int CheckButtons(int pinNum) {
  int returnVal = 0;
  
  if(!pauseButtons)
    returnVal = DebounceCheckButton();
  
  //if we detect a button press, ensure no more button presses can happen for BUTTONDELAY ms
  
  if(millis() - buttonLastChecked > BUTTONDELAY) {
    
    pauseButtons = false;
    
    buttonLastChecked = millis(); //reset value
  }    
  
  if(returnVal)
    pauseButtons = true;
  
  return returnVal;
}

int DebounceCheckButton() {
    int returnVal = 0;
    
    //Get reading once
    if(checkReading) {
      //Serial.println("Checking Reading");
      reading = GetButton(analogRead(SWITCH));
      //Serial.print("Reading = ");
      //Serial.println(reading);
      lastDebounceTime = millis();  
      checkReading = false;
    }     
    
    //Wait for debounce delay
    if((millis() - lastDebounceTime) > DEBOUNCEDELAY) {
      //Serial.println("Debounce Delay Reached");
      //if reading now == reading then, return number, otherwise 0;
      int state = GetButton(analogRead(SWITCH));
      //Serial.print("State after delay = ");
      //Serial.println(state);
      if(reading == state) {
       //Return value
       returnVal = state;
      }
      //Setup for next time 
       reading = 0;
       checkReading = true;
       lastDebounceTime = millis();
    }
    
    return returnVal;
}

int GetButton(int val) {
  if(val < 800 && val > 600) {
    //Serial.println(val);
    return 1;
  }      
  else if(val < 600 && val > 400) {
    //Serial.println(val);
    return 2;
  }      
  else if(val < 300 && val > 100) {
    //Serial.println(val);
    return 3;
  }      
  else if(val < 100 && val > 0) {
    //Serial.println(val);
    return 4;
  }
  else
    return 0;
}

