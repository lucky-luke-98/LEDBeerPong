// helper_funcs.h

#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

#include <Adafruit_NeoPixel.h>

void initializeSerialAndPixel(
    Adafruit_NeoPixel &pix, 
    int n_pixel
);

int* initializePhotoresistors(
    int n_measurements, 
    Adafruit_NeoPixel &pix, 
    int delay_time
);

#endif