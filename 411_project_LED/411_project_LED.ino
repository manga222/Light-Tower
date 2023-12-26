#include <Adafruit_NeoPixel.h>
 
#define PIN 8
 #define LED_COUNT 120
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
pixels.begin(); // This initializes the NeoPixel library.
randomSeed(analogRead(0));
Serial.begin(9600);
}
 
void loop()
{
colorSweep(pixels.Color(random(255),   random(255),   random(255)), 10); // Red
//

}
void colorSweep(uint32_t color, int wait) {
  for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
   // pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)

   pixels.setPixelColor(i, random(255),random(255),random(255));
   if (i ==0){}
   else{
   pixels.setPixelColor(i-1,0,0,0);}
    pixels.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
