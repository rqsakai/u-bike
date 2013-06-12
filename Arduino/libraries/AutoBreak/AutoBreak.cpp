#include "AutoBreak.h"

char _y_pin;
int _break_leds;
float mY = 0;
float lastValue = 0;

AutoBreak::AutoBreak(int breakLeds,char yPin)
{
    pinMode(breakLeds, OUTPUT);
    _y_pin = yPin;
    _break_leds = breakLeds;
}


void AutoBreak::execute()
{
    float reading = 0;
    for(int i = 0; i < 30; i++){
        reading += analogRead(_y_pin)-mY;
    }
    reading /= 30;
    
    if(reading < 300){
        digitalWrite(_break_leds, HIGH);
    }
    if(reading > 400){
        digitalWrite(_break_leds, LOW);
    }
}




















