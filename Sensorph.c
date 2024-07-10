//Medidor de pH
//Medidor de ph utilizando o Sensor de pH 4502c, placa Arduino e o Display LCD 16x2.

//Carrega a biblioteca LiquidCrystal 
//Carrega a biblioteca Wire
#include <Wire.h>
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

const int pHSensorPin = A0; // Pino analógico onde o sensor de pH está conectado

void setup() {
  lcd.begin(16, 2); // Inicia o LCD
  lcd.print("Medidor de pH"); // Mensagem inicial no LCD
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(pHSensorPin); // Lê o valor analógico do sensor de pH
  float voltage = sensorValue * (5.0 / 1023.0); // Converte o valor para tensão
  float pHValue = 3.5 * voltage; // Fórmula para converter a tensão em pH (ajuste conforme necessário)

  lcd.setCursor(3, 0); // Define o cursor na primeira linha
  lcd.print("pH: ");
  lcd.print(pHValue); // Exibe o valor de pH no LCD
  delay(1000); // Espera 1 segundo antes de atualizar
}
