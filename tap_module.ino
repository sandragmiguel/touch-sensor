#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int  buttonPin = 8;
const int ledPinVermelho = 9;
const int ledPinVerde = 10;

// variaveis
int buttonPushCounter = 0;   
int buttonState = 0;
int lastButtonState = 0;

// inicializando o botao, led e o serial
void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  pinMode(ledPinVermelho, OUTPUT);
  pinMode(ledPinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  lcd.setCursor(0,0);
  lcd.print("APROXIME-SE");
  digitalWrite(ledPinVerde, HIGH);
      
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("Numero de vezes que o botão foi pressionado:  ");
      Serial.println(buttonPushCounter);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("B. ACIONADO ON");
      lcd.setCursor(0,1);
      lcd.print("ACIONADO: ");
      lcd.print(buttonPushCounter);
      digitalWrite(ledPinVermelho, HIGH);
      digitalWrite(ledPinVerde, LOW);
      delay(2000);
    } 
    else {
      Serial.println("off");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("B. ACIONADO OFF"); 
      digitalWrite(ledPinVermelho, LOW);
      digitalWrite(ledPinVerde, HIGH);
    }
  }
  lastButtonState = buttonState;
}
