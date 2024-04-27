#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pix = Adafruit_NeoPixel(23, 6, NEO_GRB + NEO_KHZ800);

void setup() {

pix.begin();

}

void loop() {

/*
for(int i=0; i<150; i++)
{
  pix.setPixelColor(i, pix.Color(rand() % 250,rand() % 250,rand() % 250));
  pix.setPixelColor(i+1, pix.Color(rand() % 250,rand() % 250,rand() % 250));
  pix.setPixelColor(i+2, pix.Color(rand() % 250,rand() % 250,rand() % 250));
  pix.setPixelColor(i+3, pix.Color(rand() % 250,rand() % 250,rand() % 250));
  pix.setPixelColor(i+4, pix.Color(rand() % 250,rand() % 250,rand() % 250));
  pix.show();
  delay(50);
  pix.setPixelColor(i, pix.Color(0,0,0));
  pix.setPixelColor(i+1, pix.Color(0,0,0));
  pix.setPixelColor(i+2, pix.Color(0,0,0));
  pix.setPixelColor(i+3, pix.Color(0,0,0));
  pix.setPixelColor(i+4, pix.Color(0,0,0));
}
*/
for(int i=0; i<23; i++)
{
  pix.setPixelColor(i, pix.Color(rand() % 30,rand() % 30,rand() % 30));
  pix.show();
  delay(50);
  pix.clear();
}

}
