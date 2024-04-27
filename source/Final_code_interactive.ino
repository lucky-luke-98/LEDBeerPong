
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

int hellig[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int summe[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int anzahl = 0;
int start[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int reihenfolge[] = {0, 1, 3, 4, 6, 7, 9, 10, 12, 13};

int writ[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int active[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void setup() {

Serial.begin(9600);
pix.begin();

for(int i = 0; i<81; i++)
{
  pix.setPixelColor(i, pix.Color(0, 0, 0));
}
pix.show();

// Ermittlung und Aufsummierung

for(int i=0; i<10; i++)
{
  for(int j=0; j<10; j++)
  {
    summe[j]+=analogRead(j);
    Serial.print(analogRead(j));
    Serial.print("    ");
  }
  Serial.println("");
  anzahl++;
  pix.setPixelColor(4*i, pix.Color(47, 79, 79));
  pix.setPixelColor(4*i+1, pix.Color(47, 79, 79));
  pix.setPixelColor(4*i+2, pix.Color(47, 79, 79));
  pix.setPixelColor(4*i+3, pix.Color(47, 79, 79));
  pix.setPixelColor(80-4*i, pix.Color(47, 79, 79));
  pix.setPixelColor(79-4*i, pix.Color(47, 79, 79));
  pix.setPixelColor(78-4*i, pix.Color(47, 79, 79));
  pix.setPixelColor(77-4*i, pix.Color(47, 79, 79));
  delay(300);
  pix.show();
}

// Berechnung der Durchschnittswerte

for(int i=0; i<10; i++)
{
  start[i] = summe[i]/anzahl;
  Serial.print(i+1);
  Serial.print(". Photoresistor:  ");
  Serial.println(start[i]);
}

pix.clear();
pix.show();

}

void loop() {

int activenumb = 0;  

for(int i=0; i<10; i++)
{
  hellig[i] = analogRead(reihenfolge[i]);  
}

for(int i=0; i<10; i++)
{
  if(hellig[i] < start[i]*0.8)
  {
    active[i] = 1;
  }
}

    Serial.print(hellig[0]);
    Serial.print("   ");
    Serial.print(hellig[1]);
    Serial.print("   ");
    Serial.print(hellig[2]);
    Serial.print("   ");
    Serial.print(hellig[3]);
    Serial.print("   ");
    Serial.print(hellig[4]);
    Serial.print("   ");
    Serial.print(hellig[5]);
    Serial.print("   ");
    Serial.print(hellig[6]);
    Serial.print("   ");
    Serial.print(hellig[7]);
    Serial.print("   ");
    Serial.print(hellig[8]);
    Serial.print("   ");
    Serial.println(hellig[9]);

for(int i=0; i<10; i++)
{
  if(active[i] == 1)
  {
    activenumb++;
  }
}

for(int i=1; i<11; i++)
{
  if(activenumb<=i)
  {
    for(int j=0; j<4*activenumb; j++)
    {
      pix.setPixelColor(j, pix.Color(60, 60, 40+4*j));
      pix.setPixelColor(80-j, pix.Color(60, 60, 40+4*j));
    }
    pix.show();
  }
  if(activenumb==6)
  {
    pix.setPixelColor(40, pix.Color(25, 12, 0));
  }
  if(activenumb==10)
  {
    delay(100);
    pix.clear();
    for(int i = 0; i<41; i++)
    {
      pix.setPixelColor(i, pix.Color(rand() % 100, rand() % 100, rand() % 100));
      pix.setPixelColor(80-i, pix.Color(rand() % 100, rand() % 100, rand() % 100));
      pix.show();
      delay(50);
    }
    delay(300);
  }
}

delay(200);

for(int i=0; i<10; i++)
{
  active[i] = 0;
}

pix.clear();

}
