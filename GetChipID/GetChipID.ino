/* The true ESP32 chip ID is essentially its MAC address.
This sketch provides an alternate chip ID that matches 
the output of the ESP.getChipId() function on ESP8266 
(i.e. a 32-bit integer matching the last 3 bytes of 
the MAC address. This is less unique than the 
MAC address chip ID, but is helpful when you need 
an identifier that can be no more than a 32-bit integer 
(like for switch...case).

created 2020-06-07 by cweinhofer
with help from Cicicok */
//	
//uint32_t chipId = 0;
//int x =0;
//void setup() {
//	Serial.begin(115200);
//}
//
//void loop() {
//	for(int i=0; i<17; i=i+8) {
//	  chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//	}
//
//	Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
//	Serial.printf("This chip has %d cores\n", ESP.getChipCores());
//  Serial.print("Chip ID: "); Serial.println(chipId);
//    Serial.print(x);
//  x++;
//	delay(3000);
//
//}









/*
  modified on Sep 8, 2020
  Modified by MohammedDamirchi from Arduino Examples
  Home
*/
//const int AudioPin = 34;
//
//// the setup routine runs once when you press reset:
//void setup() {
//  // initialize serial communication at 9600 bits per second:
//  Serial.begin(115200);
//}
//
//// the loop routine runs over and over again forever:
//void loop() {
//  // read the input on analog pin 0:
//  int sensorValue = analogRead(AudioPin);
//  // print out the value you read:
//  Serial.println(sensorValue);
//  delay(100);
//  }










#include <Adafruit_NeoPixel.h>
 
#define PIN 19 //not 12,35,
 #define LED_COUNT 100
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
const int num_pixels = pixels.numPixels();
void setup() 
{
   Serial.begin(115200);
   pixels.begin(); // This initializes the NeoPixel library.
randomSeed(analogRead(0));
}


void loop() 
{

  colorSweep(pixels.Color(random(255),   random(255),   random(255)), 10);
   
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 4095;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(35);
      if (sample < 4095)  // toss out spurious readings
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
   double volts = (peakToPeak * 3.3) / 4095;  // convert to volts

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
  pixels.setPixelColor(num_pixels-1,0,0,0);
    pixels.show();
                  
}
