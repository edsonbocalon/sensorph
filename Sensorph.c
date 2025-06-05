//Medidor de pH
//Medidor de ph utilizando o Sensor de pH 4502c, placa Arduino e o Display LCD 16x2.

//Carrega a biblioteca LiquidCrystal 
//Carrega a biblioteca Wire
#include <Wire.h>
#include <LiquidCrystal.h>

// Pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// Pino do sensor de pH
const int pHSensorPin = A0;

// Variáveis de calibração
float offset = 0.0;      // Offset para calibrar o pH
float slope = 3.5;       // Fator de escala padrão (ajustável)

void setup() {
  lcd.begin(16, 2);
  lcd.print("Medidor de pH");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(pHSensorPin);
  float voltage = rawValue * (5.0 / 1023.0);

  // Conversão da tensão em pH com possibilidade de ajuste
  float pHValue = slope * voltage + offset;

  // Exibe no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tensao: ");
  lcd.print(voltage, 2); // Mostra tensão com 2 casas decimais

  lcd.setCursor(0, 1);
  lcd.print("pH: ");
  lcd.print(pHValue, 2); // Mostra pH com 2 casas decimais

  delay(1000);
}
