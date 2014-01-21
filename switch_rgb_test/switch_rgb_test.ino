#include <RGBLed.h>
#include <AnalogSwitch.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

#define SWITCHES A0

AnalogSwitch switches(SWITCHES);
RGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);

byte buttonPressed;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //if(buttonPressed = switches.CheckButtons()) {
   //BallPotted(buttonPressed);
  //}
  led.Blue();
  led.Clear();
}

void BallPotted(byte value) {
 switch(value) {
  case 1: 
    led.Red();
    break;
  case 2:
    led.Yellow();
    break;
  case 3:
    led.Green();
    break;
  case 4:
    led.Brown();
    break;
  case 5:
    led.Blue();
    break;
  case 6:
    led.Pink();
    break;
  case 7:
    led.Black();
    break;
  default:
    led.WriteRGB(255,255,255); 
 } 
  
}
