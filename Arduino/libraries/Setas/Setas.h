#define Setas_h
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
class Setas
{
    public:
        Setas(int buttonLeft, int buttonRight, int ledLeft, int ledRight, long interval, char xPin);
        void execute();
    private:
        int _button_left_pin;
        int _button_right_pin;
        int _led_left_pin;
        int _led_right_pin;
        int last;
        long interval;
        long previousMillis;
        int ledState;
        char _x_pin;
        float blinkLed;
};
