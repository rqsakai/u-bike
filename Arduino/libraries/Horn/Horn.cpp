#include "Horn.h"

Horn::Horn(int button, int speakerPin)
{
    pinMode(button, INPUT);
    pinMode(speakerPin, OUTPUT);
    _speaker_pin = speakerPin;
    _button = button;
}


void Horn::execute()
{
    if(digitalRead(_button)){
        tone(_button, 262);
    }
}