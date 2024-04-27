// helper_funcs.cpp

#include "helper_funcs.h"
#include <Adafruit_NeoPixel-1.12.0/Adafruit_NeoPixel.h>


/**
 * @brief Initialize the Serial and the NeoPixel inside the setup.
 * 
 * @param pix The instance of the Adafruit Neopixel
 * @param n_pixel The number of pixels in the led-strip
*/
void initializeSerialAndPixel(
    Adafruit_NeoPixel &pix, 
    int n_pixel
){

    Serial.begin(9600);
    pix.begin();

    for(int i=0; i<n_pixel; i++){
        pix.setPixelColor(i, pix.Color(0, 0, 0));
    }
    pix.show();
}

/**
 * @brief Computation of brightness for photresistors \\
 * @brief 1a. Compute current brightness \\
 * @brief 1b. Cumulate brightness for multiple loops (n_measurements) \\
 * @brief 2. Divide cumulative brightness by number of n_measurements
 * 
 * @param n_measurements The number of measurements to perform.
 * @param color The color to take for the initialization (upload color).
 * @param delay The time interval to wait between every measurement (in ms).
 * 
 * @return The integer array of the average brightness for each photoresistor
 * @return after initialization.
*/
int* initializePhotoresistors(
    int n_measurements, 
    Adafruit_NeoPixel &pix, 
    int delay_time
){  
    int* avg_brightness = new int[10];
    int sum[10] = {};

    for(int measurment=0; measurment<n_measurements; measurment++){
        for(int resistor=0; resistor<10; resistor++){
            sum[resistor] += analogRead(resistor);  // this might be wrong here...

            Serial.print(sum[resistor]);
            Serial.print("   ");
        }

        Serial.println("");

        // show specific color theme (loading) changing after each iteration
        for(int i=0; i<4; i++){
            pix.setPixelColor(4*measurment+i, pix.Color(47, 79, 79));
            pix.setPixelColor(80-i-4*measurment, pix.Color(47, 79, 79));
        }

        delay(delay_time);
        pix.show();
    }

    // computation of average
    for(int resistor=0; resistor<10; resistor++){
        
        avg_brightness[resistor] = sum[resistor] / n_measurements;

        Serial.print(resistor+1);
        Serial.print(". Photoresistor:  ");
        Serial.println(avg_brightness[resistor]);
    }

    pix.clear();
    pix.show();

    return avg_brightness;

}