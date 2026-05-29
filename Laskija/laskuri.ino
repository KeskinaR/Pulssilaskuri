//LiquidCrystal_I2C Kirjaston tulee olla asennettu! Ohjeet alla:
// 1. Avaa Arduino IDE
// 2. Mene kohtaan Library Manager (Vasen sivu, neljän palkin kuvake)
// 3. Hae LiquidCrystal_I2C
// 4. paina "INSTALL" ylimmässä vaihtoehdossa (Martin Kubovcik versio on oikea)


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//nollataan kanavat a ja b
volatile unsigned long pulsesA = 0;
volatile unsigned long pulsesB = 0;

void setup() {
  //I2C setup säätö
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600); //taajuus 9600
  delay(1000); //1sec tauko

  //odotetaan kanavilla 1 ja 2
  lcd.setCursor(0, 0);
  lcd.print("CNL 1 STBY");
  lcd.setCursor(0, 1);
  lcd.print("CNL 2 STBY");

  delay(3000); //3sec tauko

  //nollataan näyttö ja historia
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cleared!");

  delay(3000); //ehkä korjaa miksi "Cleared!" ei näy

  //Portit, joista luetaan
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  //seurataan laskuriportteja 2 ja 3
  attachInterrupt(digitalPinToInterrupt(2), CnlAmountA, RISING);
  attachInterrupt(digitalPinToInterrupt(3), CnlAmountB, RISING);
}

void loop() {
  //nollataan näyttö ja historia
  lcd.clear();

  //printataan lukemat näytölle
  lcd.setCursor(0, 0);
  lcd.print("CNL1: ");
  lcd.print(pulsesA);
  
  lcd.setCursor(0, 1);
  lcd.print("CNL2: ");
  lcd.print(pulsesB);

  delay(1000); //1sec tauko lukemien välille
}

//lasketaan kanavan a pulssit
void CnlAmountA() {
  pulsesA++;
}

//lasketaan kanavan b pulssit
void CnlAmountB() {
  pulsesB++;
}
