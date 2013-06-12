#include <AutoBreak.h>
#include <Horn.h>
#include <Setas.h>
#include <Autolight.h>

Autolight autolight(0,13,12);
Horn horn(1,7);
Setas setas(2,3,10,9,280, A1);
AutoBreak autobreak(11,A2);

void setup() {
  Serial.begin(9600);
}

void loop() {
   //autolight.execute();
   //setas.execute();
   //horn.execute();
   autobreak.execute();
}
