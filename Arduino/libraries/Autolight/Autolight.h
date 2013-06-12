#define Autolight_h
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
class Autolight
{
    public:
        Autolight(int photocell, int headlight, int taillight);
        void execute();    
};
