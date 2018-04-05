#  RGB_LED Library


##  Fuctions
###  SETUP
#### RGB_LED(byte pinR,byte pinG,byte pinB);   
###  SET 
#### void set(byte Rvalue,byte Gvalue,byte Bvalue);
#### void setSpeed(unsigned long speedValue);
#### void setPercentFade(float FadeValue);
#### void fadeTo(byte Rvalue,byte Gvalue,byte Bvalue,unsigned #### long speedValue);
#### void setFunction(byte functionValue);
#### void setRandom();
#### void setColour(byte colour);
#### void fadeToColour(byte colour,unsigned long speedValue);
###  GET
#### unsigned long getSpeed();
#### float getPercentFade();
#### byte getFunction();
#### byte getCurrentRValue();
#### byte getCurrentGValue();
#### byte getCurrentRValue();
#### int getFunctionCount();
###  CHECKING 
#### boolean hasFinished();
###  COMMANDS 
#### void run();
#### void stop();

##  Colours
####  Black
####  White
####  Red
####  Green
####  Blue
####  Yellow
####  Purple
####  Aqua

##  Colour Functions
####  Random
####  Solid
####  Fade
####  FadeRandom
####  Step1
####  Step2
####  StepRandom

##  Example
###  Example 1: Fade

```c++
#include <RGB_LED.h>

RGB_LED LED(9,10,11);

#### void setup() 
{
  LED.setFunction(Fade);
}

#### void loop() 
{
   LED.run();
}
```

###  Example 2: Set Speed

```c++
#include <RGB_LED.h>

####  upButtonPin 4
####  downButtonPin 5

unsigned int speed = 1000;

RGB_LED LED(9,10,11);

#### void setup() 
{
  pinMode(upButtonPin,INPUT);
  pinMode(downButtonPin,INPUT);
  LED.setFunction(Fade);
}

#### void loop() 
{
   LED.run();

   if(digitalRead(downButtonPin)==HIGH && speed<100)
   {
      speed--;
      LED.setSpeed(speed);
      delay(10);
   }
   if(digitalRead(upButtonPin)==HIGH && speed>20000)
   {
      speed++;
      LED.setSpeed(speed);
      delay(10);
   }
}
```

#  To Do list
- 
