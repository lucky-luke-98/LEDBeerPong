#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pix = Adafruit_NeoPixel(22, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
pix.begin();
pix.setPixelColor(21, pix.Color(0,0,0));
pix.show();
}

void loop() {
  // put your main code here, to run repeatedly:
}
