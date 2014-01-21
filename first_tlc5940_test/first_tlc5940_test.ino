#include <Tlc5940.h>

boolean on = false;

void setup()
{
  /* Call Tlc.init() to setup the tlc.
     You can optionally pass an initial PWM value (0 - 4095) for all channels.*/
  Tlc.init();
  
  Tlc.set(1, 0); //Blue
  Tlc.set(2, 0); //Green
  Tlc.set(3, 0); //Red
  
  delay(1000);
  Tlc.update();
  Tlc.set(4, 2000); //Blue
  Tlc.set(5, 0); //Green
  Tlc.set(6, 0); //Red
  
  delay(1000);
  Tlc.update();
  
  Tlc.set(7, 0); //Blue
  Tlc.set(8, 0); //Green
  Tlc.set(9, 2000); //Red
  delay(1000);
  Tlc.update();
  
  Tlc.set(10, 0); //Blue
  Tlc.set(11, 2000); //Green
  Tlc.set(12, 0); //Red
  delay(1000);
  Tlc.update();
  
  Tlc.set(13, 0); //Blue
  Tlc.set(14, 0); //Green
  Tlc.set(15, 2000); //Red
  delay(1000);
  Tlc.update();
}

void loop() 
{

}

void rotate() {
  for(int i = 1; i < 16; i+=3) {
     Tlc.set(i, 2000); //Blue
     Tlc.set(i+1, 0); //Green
     Tlc.set(i+2, 0); //Red
  } 
  Tlc.update();
  delay(500);
  
  for(int i = 1; i < 16; i+=3) {
     Tlc.set(i, 0); //Blue
     Tlc.set(i+1, 0); //Green
     Tlc.set(i+2, 2000); //Red
  } 
  Tlc.update();
  delay(500);
  
  for(int i = 1; i < 16; i+=3) {
     Tlc.set(i, 0); //Blue
     Tlc.set(i+1, 2000); //Green
     Tlc.set(i+2, 0); //Red
  } 
  Tlc.update();
  delay(500);
  
  for(int i = 1; i < 16; i+=3) {
     Tlc.set(i, 2000); //Blue
     Tlc.set(i+1, 0); //Green
     Tlc.set(i+2, 2000); //Red
  } 
  Tlc.update();
  delay(500);
  
  for(int i = 1; i < 16; i+=3) {
     Tlc.set(i, 0); //Blue
     Tlc.set(i+1, 1000); //Green
     Tlc.set(i+2, 2000); //Red
  } 
  Tlc.update();
  delay(500);
  
}


