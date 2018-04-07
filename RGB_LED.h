
#ifndef RGB_LED_h
#define RGB_LED_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif

//colours
#define Black 0
#define White 1
#define Red 2
#define Green 3
#define Blue 4
#define Yellow 5
#define Purple 6
#define Aqua 7

//functions
#define Random -1
#define Solid 0
#define Fade 1
#define FadeRandom 3
#define Step1 4
#define Step2 5
#define StepRandom 6


class RGB_LED
{
    public:
        // SETUP 
        RGB_LED(byte pinR,byte pinG,byte pinB);
        
        // SET 
        void set(byte Rvalue,byte Gvalue,byte Bvalue);
        void setSpeed(unsigned long speedValue);
        void setPercentFade(float FadeValue);
        void fadeTo(byte Rvalue,byte Gvalue,byte Bvalue,unsigned long speedValue);
        void setFunction(byte functionValue);
        void setRandom();
        void setColour(byte colour);
        void fadeToColour(byte colour,unsigned long speedValue);
        void setFunctionCount(int FunctionCount);
        
        //GET
        unsigned long getSpeed();
        float getPercentFade();
        byte getFunction();
        byte getCurrentRValue();
        byte getCurrentGValue();
        byte getCurrentBValue();
        int getFunctionCount();

        // CHECKING 
        boolean hasFinished();
        
        // COMMANDS 
        void run();
        void stop();
        void delay(unsigned long delayValue);
        
    private:
        byte R_Pin;
        byte G_Pin;
        byte B_Pin;
        byte R_Last_value;
        byte G_Last_value;
        byte B_Last_value;
        byte R_Current_value;
        byte G_Current_value;
        byte B_Current_value;
        byte R_Future_value;
        byte G_Future_value;
        byte B_Future_value;

        unsigned long Speed = 2000;
        unsigned long starting_time;
        int function=0;
        int count;

        void writeOutput();
        void FunctionsFinished();
        void FadeFunction();
        void FadeRandomFunction();
        void StepRGBWFunction();
        void StepAllFunction();
        void StepRandomFunction();
};

#endif 
