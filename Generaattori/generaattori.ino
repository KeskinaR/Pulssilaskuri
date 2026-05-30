//TimerOne kirjaston tulee olla asennettu!!
//Asentamisohjeet lueteltu alla:
// 1. Avaa ArduinoIDE 
// 2. Mene kohtaan Library Manager (Vasen sivu, neljän palkin kuvake)
// 3. Hae TimerOne
// 4. paina "INSTALL" ylimmässä vaihtoehdossa (älä asenna TimerOne_V2 tai muita versioita)

#include <TimerOne.h>

//määritetyt lähetysportit
const int outPin1 = 9;
const int outPin2 = 10;

void setup() {
  //lähetetään porteista
  pinMode(outPin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  
  //konfiguroidaan pulssin suuruus
  Timer1.initialize(3300);
  Timer1.pwm(outPin1, 26);
  Timer1.pwm(outPin2, 13);
}

void loop() {

}
