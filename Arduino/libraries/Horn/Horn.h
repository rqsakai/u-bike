#define Setas_h
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
class Horn
{
    public:
        Horn(int button, int speakerPin);
        void execute();
    private:
        int _button;
        int _speaker_pin;
};
