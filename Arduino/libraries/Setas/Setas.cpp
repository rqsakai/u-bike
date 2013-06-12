#include "Setas.h"

int leftValidate = 0;
int rightValidate = 0;

Setas::Setas(int buttonLeft, int buttonRight, int ledLeft, int ledRight, long interval, char xPin)
{
    pinMode(buttonLeft, INPUT);
    pinMode(buttonRight, INPUT);
    pinMode(ledLeft, OUTPUT);
    pinMode(ledRight, OUTPUT);
    _button_left_pin = buttonLeft;
    _button_right_pin = buttonRight;
    _led_left_pin = ledLeft;
    _led_right_pin = ledRight;
    _x_pin = xPin;
    digitalWrite(_led_right_pin,LOW);
    digitalWrite(_led_left_pin,LOW);
    interval = interval;
    previousMillis = 0;
    ledState = LOW;
    blinkLed = -1;
}


void Setas::execute()
{
    if(digitalRead(_button_left_pin) && leftValidate == 0){
        leftValidate = 1;
        if(blinkLed == _led_left_pin){
            blinkLed = -1;
        }else{
            blinkLed = _led_left_pin;
        }
    }else if(!digitalRead(_button_left_pin)){
        leftValidate = 0;
    }
    if(digitalRead(_button_right_pin) && rightValidate == 0){
        if(blinkLed == _led_right_pin){
            blinkLed = -1;
        }else{
            blinkLed = _led_right_pin;
        }
    }else if(!digitalRead(_button_right_pin)){
        rightValidate = 0;
    }
    unsigned long currentMillis = millis();
    if(currentMillis > (previousMillis + interval)) {
        previousMillis = currentMillis;
        if (ledState == LOW){
            ledState = HIGH;
        }else{
            ledState = LOW;
        }
    }
    if(blinkLed > 0){
        digitalWrite(blinkLed, ledState);
        if(_led_right_pin == blinkLed){
            digitalWrite(_led_left_pin, LOW);
        }else{
            digitalWrite(_led_right_pin, LOW);
        }
    }else{
        digitalWrite(_led_right_pin, LOW);
        digitalWrite(_led_left_pin, LOW);
    }
    
    float reading = 0;
    for(int i = 0; i < 20; i++){
        reading += analogRead(_x_pin);
    }
    reading /= 20;
    
    int inTurn = 0;
    
    if(reading < 270 && blinkLed == _led_right_pin){
        inTurn = 1;
    }
    if(reading > 300){
        if(inTurn){
            blinkLed = -1;
            inTurn = 0;
        }
    }
    if(reading > 370 && blinkLed == _led_left_pin){
        inTurn = 1;
    }
}