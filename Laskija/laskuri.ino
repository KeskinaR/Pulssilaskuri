//nollataan tulokset kanavilla a ja b
volatile unsigned long pulsesA = 0;
volatile unsigned long pulsesB = 0;

void setup() {
  Serial.begin(9600); //taajuus 9600
  delay(1000); //1000ms = 1sec (tauko)

  //odotetaan inputtia kanavilla a ja b
  Serial.println("CNL 1 waiting");
  Serial.println("CNL 2 waiting");
  // ==================================

  delay(3000); //3000ms = 3sec (tauko)
  Serial.println("Cleared"); //nollataan näyttö juuri ennen laskemisen alkua

  //määritetyt input portit (Kolvattu)
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  //luetaan porteista 2 ja 3 (nouseva määrä)
  attachInterrupt(digitalPinToInterrupt(2), CnlAmountA, RISING);
  attachInterrupt(digitalPinToInterrupt(3), CnlAmountB, RISING);
}

//lasketaan kanavan a pulssit
void CnlAmountA() {
  pulsesA++;
}

//lasketaan kanavan b pulssit
void CnlAmountB() {
  pulsesB++;
}

void loop() {
  //printataan tulokset näytölle molemmista kanavista
  Serial.print("CNL 1: ");
  Serial.print(pulsesA);
  Serial.print("CNL 2: ");
  Serial.print(pulsesB);
  delay(2000); //2000ms = 2sec (tauko) 
}
