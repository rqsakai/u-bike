#define AutoBreak_h
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
class AutoBreak
{
    public:
        AutoBreak(int breakLeds, char yPin);
        void execute();
    protected:
        void calibrate();
};

/*
 Conecte o Pino 5V do Acelerometro no pino 5V do Arduino
 Conecte o Pino GND do Acelerometro no pino GND do Arduino
 Conecte o Pino SL do Acelerometro no pino 3V3 do Arduino
 Conecte o Pino X do Acelerometro no pino Ax do Arduino
 Conecte o Pino Y do Acelerometro no pino Ay do Arduino
 Conecte o Pino Z do Acelerometro no pino Az do Arduino
 Conecte o Pino GS Desconectado para sensibilidade de 1.5g a 800 mV/g, caso queira sensibilidade de 6g a 206 mV/g conecte ao 5V.
 */
