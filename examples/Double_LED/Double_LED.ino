#include <RGB_LED.h>

RGB_LED LED1(9,10,11);
RGB_LED LED2(3,4,5);

void setup() 
{
  LED1.setFunction(Fade);
  LED2.setFunction(Step);
}

void loop() 
{
   LED1.run();
   LED2.run();
}