
/*
Projekt: LEDBeerPong
Author: Lukas Jäschke
Date of Begin: 28.07.2020
*/

// imports

#include <Adafruit_NeoPixel.h>
#include "helper_funcs.h"

#define LED_COUNT 81
#define LED_PIN 6

// specifying (LED_COUNT, LED_PIN, TYPE_FLAGS (here: grb bitstream, 800 KHz bitstream))

Adafruit_NeoPixel pix = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// definition of variables

int hellig[10] = {};
int reihenfolge[] = {0, 1, 3, 4, 6, 7, 9, 10, 12, 13};  // pins for the photoresistors
static float threshold = 0.8;
int writ[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int active[10] = {};


void setup() {

// setup

initializeSerialAndPixel(pix, LED_COUNT);
static int* avg_brightness = initializePhotoresistors(10, pix, 300);

}

void loop() {

// continous loop of the Arduino

// number of active cups on the table
int activenumb = 0;  

// reading in the current brightness

for(int i=0; i<10; i++)
{
  hellig[i] = analogRead(reihenfolge[i]);  
}

/* 
checking whether the current brightness is lower than threshold % of the init_value.
in this case active means that there is no cup on the position
*/

for(int i=0; i<10; i++)
{
  if(hellig[i] < start[i]*threshold)
  {
    active[i] = 1;
  }
}

// print out current brightness of the photosensors

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

// get number of total cups on the table

for(int i=0; i<10; i++)
{
  if(active[i] == 1)
  {
    activenumb++;
  }
}

// iterate over all activenumb values

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
