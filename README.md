# RGB_LED Library
 

## Functions
### SETUP
#### RGB_LED(byte pinR,byte pinG,byte pinB)
This is the setup for the class, this is where the pins are declared for the RGB LED.
### SET 
#### void set(byte Rvalue,byte Gvalue,byte Bvalue)
This function sets a RGB colour. It will stop a fade to be the set color. *Rvalue*, *Gvalue* and *Bvalue* are used to set the RGB colour. These RGB Byte variables are the values between 0 and 255. 0 is the LED completely off, 255 is the LED Completely on and all values between is a PWM percent.
#### void setSpeed(unsigned long speedValue)
This Functions sets the speed of fades and the speed of colour functions. The speedValue is in milliseconds and is used from the start to the finish of the fade.
#### void setPercentFade(float FadeValue)
This function set the where the fade is. The *FadeValue* is a between 0 and 1. If the *FadeValue* is set to be 0.5 at 1000 speed the fade would continue from 50%. 
#### void fadeTo(byte Rvalue,byte Gvalue,byte Bvalue,unsigned long speedValue)
This function is used to fade from the current set colour to a RGB colour at a speed. *Rvalue*, *Gvalue* and *Bvalue* are used to set the RGB colour and *speedValue* is used to set the fade speed. These *Rvalue*, *Gvalue* and *Bvalue* Byte variables are the values between 0 and 255. 0 is the LED completely off, 255 is the LED Completely on and all values between is a PWM percent. The *speedValue* is in milliseconds and is used from the start to the finish of the fade.
#### void setFunction(byte functionValue)

#### void setRandom()

#### void setColour(byte colour)

#### void fadeToColour(byte colour,unsigned long speedValue)

### GET
#### unsigned long getSpeed()

#### float getPercentFade()

#### byte getFunction()

#### byte getCurrentRValue()

#### byte getCurrentGValue()

#### byte getCurrentRValue()

#### int getFunctionCount()

### CHECKING 
#### boolean hasFinished()

### COMMANDS 
#### void run()

#### void stop()

#### void delay(unsigned long delayValue)

## Colours
- Black
- White
- Red
- Green
- Blue
- Yellow
- Purple
- Aqua

## Colour Functions
- **Random:** this randomly fades betweens random colours at random speeds.
- **Solid:** this stays at a set colour.
- **Fade:** this fades betweens Red, Green and blue colours at a set speed.
- **FadeRandom:** this fades betweens random colours at a set speeds.
- **Step1:** this steps betweens Red, Green and blue colours at a set speed.
- **Step2:** this steps betweens all colours at a set speed.
- **StepRandom:** this steps betweens random colours at a set speeds.

## Example
### Example 1: Fade

```c++
#include <RGB_LED.h>

RGB_LED LED(9,10,11);

void setup() 
{
  LED.setFunction(Fade);
}

void loop() 
{
   LED.run();
}
```

### Example 2: Two LEDs

```c++
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
```

### Example 3: Set Speed

```c++
#include <RGB_LED.h>

#define upButtonPin 4
#define downButtonPin 5

unsigned int speed = 1000;

RGB_LED LED(9,10,11);

void setup() 
{
  pinMode(upButtonPin,INPUT);
  pinMode(downButtonPin,INPUT);
  LED.setFunction(Fade);
}

void loop() 
{
   LED.run();

   if(digitalRead(downButtonPin)==HIGH && speed<100)
   {
      speed--;
      LED.setSpeed(speed);
      LED.delay(10);
   }
   if(digitalRead(upButtonPin)==HIGH && speed>20000)
   {
      speed++;
      LED.setSpeed(speed);
      LED.delay(10);
   }
}
```

## To Do list
- 
