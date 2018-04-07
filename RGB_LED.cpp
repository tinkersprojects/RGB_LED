/**********************************************************************************************
 * Arduino LED RGB Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "RGB_LED.h"



/******************* SETUP *******************/

RGB_LED::RGB_LED(byte pinR,byte pinG,byte pinB)
{
    R_Pin = pinR;
    G_Pin = pinG;
    B_Pin = pinB;
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
}



/******************* SET *******************/

void RGB_LED::fadeTo(byte Rvalue,byte Gvalue,byte Bvalue,unsigned long speedValue)
{
    Speed = speedValue;

    R_Last_value = R_Current_value;
    G_Last_value = G_Current_value;
    B_Last_value = B_Current_value;

    R_Future_value = Rvalue;
    G_Future_value = Gvalue;
    B_Future_value = Bvalue;

    function=Solid;
    starting_time = millis();
}

void RGB_LED::set(byte Rvalue,byte Gvalue,byte Bvalue)
{
    R_Last_value = Rvalue;
    G_Last_value = Gvalue;
    B_Last_value = Bvalue;

    R_Current_value = Rvalue;
    G_Current_value = Gvalue;
    B_Current_value = Bvalue;

    R_Future_value = Rvalue;
    G_Future_value = Gvalue;
    B_Future_value = Bvalue;

    function=Solid;

    writeOutput();
}

void RGB_LED::setColour(byte colour)
{
    switch (colour) {
        case Black:
            RGB_LED::set(0,0,0);
            break;
        case White:
            RGB_LED::set(255,255,255);
            break;
        case Red:
            RGB_LED::set(255,0,0);
            break;
        case Green:
            RGB_LED::set(0,255,0);
            break;
        case Blue:
            RGB_LED::set(0,0,255);
            break;
        case Yellow:
            RGB_LED::set(255,255,0);
            break;
        case Purple:
            RGB_LED::set(80,0,80);
            break;
        case Aqua:
            RGB_LED::set(0,255,255);
            break;
      }
}

void RGB_LED::fadeToColour(byte colour,unsigned long speedValue)
{
    switch (colour) {
        case Black:
            RGB_LED::fadeTo(0,0,0,speedValue);
            break;
        case White:
            RGB_LED::fadeTo(255,255,255,speedValue);
            break;
        case Red:
            RGB_LED::fadeTo(255,0,0,speedValue);
            break;
        case Green:
            RGB_LED::fadeTo(0,255,0,speedValue);
            break;
        case Blue:
            RGB_LED::fadeTo(0,0,255,speedValue);
            break;
        case Yellow:
            RGB_LED::fadeTo(255,255,0,speedValue);
            break;
        case Purple:
            RGB_LED::fadeTo(80,0,80,speedValue);
            break;
        case Aqua:
            RGB_LED::fadeTo(0,255,255,speedValue);
            break;
      }
}

void RGB_LED::setSpeed(unsigned long speedValue)
{
    starting_time = millis();
    Speed = speedValue;
    R_Last_value = R_Current_value;
    G_Last_value = G_Current_value;
    B_Last_value = B_Current_value;
}

void RGB_LED::setFunction(byte functionValue)
{
    function=functionValue;
}

void RGB_LED::setRandom()
{
    function=Random;
}

void RGB_LED::setPercentFade(float PercentFade)
{
    if(PercentFade>1)PercentFade=1;
    if(PercentFade<0)PercentFade=0;

    double diff = double(PercentFade)*double(Speed);
    starting_time = millis()-diff;
}

void RGB_LED::setFunctionCount(int FunctionCount)
{
    count = FunctionCount;
}


/******************* GET *******************/

unsigned long RGB_LED::getSpeed()
{
    return Speed;
}

float RGB_LED::getPercentFade()
{
    unsigned long diff = millis()-starting_time;
    float PercentFade = double(diff)/double(Speed);
    if(PercentFade>1)PercentFade=1;
    return PercentFade;
}

byte RGB_LED::getFunction()
{
   return function;
}

int RGB_LED::getFunctionCount()
{
   return count;
}

byte RGB_LED::getCurrentRValue()
{
   return R_Current_value;
}

byte RGB_LED::getCurrentGValue()
{
   return G_Current_value;
}

byte RGB_LED::getCurrentBValue()
{
   return R_Current_value;
}
        
/******************* CHECKING *******************/

boolean RGB_LED::hasFinished()
{
    return ((R_Future_value == R_Current_value) && (G_Future_value == G_Current_value) && (B_Future_value == B_Current_value));
}



/******************* COMMANDS *******************/

void RGB_LED::run()
{
    if(function != Solid && RGB_LED::hasFinished()) RGB_LED::FunctionsFinished();
    
    unsigned long diff = millis()-starting_time;
    float PercentFade = double(diff)/double(Speed);
    if(PercentFade>1)PercentFade=1;
    R_Current_value = R_Last_value+((R_Future_value - R_Last_value)*PercentFade);
    G_Current_value = G_Last_value+((G_Future_value - G_Last_value)*PercentFade);
    B_Current_value = B_Last_value+((B_Future_value - B_Last_value)*PercentFade);
    
    writeOutput();
}

void RGB_LED::stop()
{
    function=Solid;
    R_Last_value = R_Current_value;
    G_Last_value = G_Current_value;
    B_Last_value = B_Current_value;
    R_Future_value = B_Current_value;
    G_Future_value = B_Current_value;
    B_Future_value = B_Current_value;
}

void RGB_LED::delay(unsigned long delayValue)
{
    unsigned long currentLocalTime = millis();
    while(currentLocalTime+delayValue>millis())
    {
        RGB_LED::run();
    }
}



/******************* FUNCTIONS *******************/

void RGB_LED::writeOutput()
{
    analogWrite(R_Pin,R_Current_value);
    analogWrite(G_Pin,G_Current_value);
    analogWrite(B_Pin,B_Current_value);
}

void RGB_LED::FunctionsFinished()
{
    randomSeed(millis());
    int currentfuction = function;
    
    switch (function) {
        case Fade:
            RGB_LED::FadeFunction();
            break;
        case FadeRandom:
            RGB_LED::FadeRandomFunction();
            break;
        case Step1:
            RGB_LED::StepRGBWFunction();
            break;
        case Step2:
            RGB_LED::StepAllFunction();
            break;
        case StepRandom:
            RGB_LED::StepRandomFunction();
            break;
      }
      
    function=currentfuction;
}






/******************* COLOUR FUNCTIONS *******************/

void RGB_LED::FadeFunction()
{
    switch (count%4) {
        case 0:
            RGB_LED::fadeToColour(White,Speed);
            break;
        case 1:
            RGB_LED::fadeToColour(Red,Speed);
            break;
        case 2:
            RGB_LED::fadeToColour(Green,Speed);
            break;
        case 3:
            RGB_LED::fadeToColour(Blue,Speed);
            break;
        default: 
            RGB_LED::fadeToColour(White,Speed);
            break;
      }

    count++;
}

void RGB_LED::FadeRandomFunction()
{
    RGB_LED::fadeTo(random(255),random(255),random(255),random(100,5000));
}



void RGB_LED::StepRGBWFunction()
{
    if(starting_time + Speed <millis())
    {
        starting_time = millis();
        switch (count%4) {
            case 0:
                RGB_LED::setColour(White);
                break;
            case 1:
                RGB_LED::setColour(Red);
                break;
            case 2:
                RGB_LED::setColour(Green);
                break;
            case 3:
                RGB_LED::setColour(Blue);
                break;
            default: 
                RGB_LED::setColour(White);
                break;
        }
        count++;
    }
}



void RGB_LED::StepAllFunction()
{
    if(starting_time + Speed <millis())
    {
        starting_time = millis();
        switch (count%7) {
            case 0:
                RGB_LED::setColour(White);
                break;
            case 1:
                RGB_LED::setColour(Red);
                break;
            case 2:
                RGB_LED::setColour(Green);
                break;
            case 3:
                RGB_LED::setColour(Blue);
                break;
            case 4:
                RGB_LED::setColour(Yellow);
                break;
            case 5:
                RGB_LED::setColour(Purple);
                break;
            case 6:
                RGB_LED::setColour(Aqua);
                break;
            default: 
                RGB_LED::setColour(White);
                break;
        }
        count++;
    }
}



void RGB_LED::StepRandomFunction()
{
    if(starting_time + Speed <millis())
    {
        starting_time = millis();
        Speed = random(100,5000);
        RGB_LED::set(random(255),random(255),random(255));
    }
}

