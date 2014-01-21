#include <RGBLed.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11


RGBLed led(RED_PIN, GREEN_PIN, BLUE_PIN);

void setup() {
  
}


void loop() {  
  led.Red();
  delay(1000);
  led.Yellow();
  delay(1000);
  led.Green();
  delay(1000);
  led.Brown();
  delay(1000);
  led.Blue();
  delay(1000);
  led.Pink();
  delay(1000);
  led.Black();
  delay(1000);
  
}
