
/*
Projekt: Beerpong-Tisch
Part: 4
Autor: Lukas Jäschke
Date of Begin: 28.07.2020
*/
// Implementierung der LED-Bibliothek

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pix = Adafruit_NeoPixel(81, 6, NEO_GRB + NEO_KHZ800);

// Definition der Variablen

int r[25];

void setup() {

Serial.begin(9600);
pix.begin();

randomSeed(analogRead(15));
}

//////////////////////////////////////////////////////////////

void loop() {
  
// Alle LEDs auf eine Farbei bringen

for(int i = 0; i<81; i++){
  pix.setPixelColor(i, pix.Color(25, 25, 35));
}
pix.show();

// Zufällige Zahlen deklarieren


for(int i = 0; i < 25; i++){
  r[i] = random(0,41);
}

//Ignite
for(int j = 0; j < 25; j++){
  for(int i = 0; i < 41; i++){
    if(r[j]==i){
      pix.setPixelColor(i, pix.Color(150, 150, 210));
      pix.setPixelColor(80-i, pix.Color(150, 150, 210)); 
    } 
    pix.show();
  }
}   
delay(500);

//Reverse
for(int j = 0; j < 25; j++){
  for(int i = 0; i < 41; i++){
    if(r[j]==i){
      pix.setPixelColor(i, pix.Color(25, 25, 35));
      pix.setPixelColor(80-i, pix.Color(25, 25, 35)); 
    } 
    pix.show();
  }
}   

delay(300);
pix.clear();
}
