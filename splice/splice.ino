#include <Adafruit_NeoPixel.h>
 
#define PIN 35
 #define LED_COUNT 10
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() 
{
   Serial.begin(115200);
   pixels.begin(); // This initializes the NeoPixel library.
randomSeed(analogRead(0));
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(34);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

   Serial.println(volts);
   if(volts>3){
   colorSweep(pixels.Color(random(255),   random(255),   random(255)), 10);}
   
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
