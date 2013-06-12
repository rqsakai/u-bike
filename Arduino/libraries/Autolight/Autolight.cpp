#include "Autolight.h"

int _photocell_pin;
int _headlight_pin;
int _taillight_pin;
int _sensorValue;

Autolight::Autolight(int photocell, int headlight, int taillight)
{
    pinMode(photocell, INPUT);
    pinMode(headlight, OUTPUT);
    pinMode(taillight, OUTPUT);
    _photocell_pin = photocell;
    _headlight_pin = headlight;
    _taillight_pin = taillight;
    _sensorValue = 0;
}

void Autolight::execute()
{
    _sensorValue = analogRead(_photocell_pin);
    if (_sensorValue < 250)
    {
        digitalWrite(_headlight_pin,HIGH);
        digitalWrite(_taillight_pin,HIGH);
    }
    else
    {
        digitalWrite(_headlight_pin,LOW);
        digitalWrite(_taillight_pin,LOW);
    }
}