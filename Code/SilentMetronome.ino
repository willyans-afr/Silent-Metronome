// C++ code
//
#include <LiquidCrystal.h>

const float segundos = 60;
float bpm = 0;
float esperaMilisegundos = 0;
float hitPerSec = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Arduino digital ports used.

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  
  lcd.begin(16, 2); //Seting 16 coluns and 2 lines of LCD
  pinMode(6,OUTPUT);
  analogWrite(6,50); //pin 6 gives constrast 50 replacing potetiometer.
}

void loop()
{
  //Potetiometer config to bpm
  bpm = map(analogRead(A0), 0, 1023, 60, 200);
  //Config time to led stay high and down, simulating metronome
  esperaMilisegundos = 1000/(bpm/segundos);
  hitPerSec = bpm/segundos;
  
  //LCD Config  
  lcd.setCursor(0,0);
  lcd.print("BPM: "+(String)bpm);
  lcd.setCursor(0,1);
  lcd.print("NOTE TIME: "+(String)hitPerSec);
  
  //Leds config  
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  delay(esperaMilisegundos); // Wait for 1000 * batidas millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(8, HIGH);
  delay(esperaMilisegundos); // Wait for 1000 * batidas millisecond(s)
}
