// the number of the LED pin
const int ledPin = 33;  // 16 corresponds to GPIO16
const int ledPin2 = 32;

// setting PWM properties
const int freq = 500;
const int ledChannel = 0;
const int ledChannel2 = 1;
const int resolution = 8;
int rotation = 0;
int mins = 10800; // 45 mins is around 10800
float progress = 0;

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <WiFi.h>
#include "time.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

#define TFT_BLACK 0x0000 // black

 
void setup(){
// setting up lcd
  tft.init();
  tft.setRotation(1);
  
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
    ledcSetup(ledChannel2, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
    ledcAttachPin(ledPin2, ledChannel2);
  rotation=0;
    Serial.begin(115200);
}
 
void loop(){
  //lcd.setCursor(0,0);
  //lcd.print("Starting rotations ");
//  tft.fillScreen(TFT_BLACK);
//  tft.setCursor(0, 0, 2);
//  tft.setTextColor(TFT_WHITE,TFT_BLACK);  
//  tft.setTextSize(3);
//
//
//  tft.println("Long Test");
//  tft.println("On");
//
//  ledcWrite(ledChannel,255);
//  delay(mins*1000);
//  

  tft.println("Starting");
  tft.println("rotations");

  
  while(rotation<=(mins/40-1)){
  
  // increase the LED brightness
  int dutyCycle2 = 255;
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){  
    dutyCycle2--; 
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
        ledcWrite(ledChannel2, dutyCycle2);
    Serial.println(dutyCycle);
    delay(20);
  }

  // decrease the LED brightness
  int dutyCycle = 0;
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    dutyCycle2++;
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);  
        ledcWrite(ledChannel2, dutyCycle2);
    Serial.println(dutyCycle); 
    delay(20);
  }
rotation++;
Serial.println("Current Rotation");
Serial.println(rotation);

    //lcd.setCursor(0,0);
   progress = rotation / (mins/40.00);
    //lcd.print("scan start    ");
    //lcd.print(progress);

    tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  
  tft.setTextSize(3);
  tft.println("Scan");
  tft.println("Progress");
    tft.print(progress);
    tft.print("%");
    
}
rotation=0;
    ledcWrite(ledChannel, 0);  
        ledcWrite(ledChannel2, 0);
 while(rotation<=(mins/40-1)){
  //delay(mins*250);


     progress = rotation / (mins/40.00);
    tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  
  tft.setTextSize(3);
  tft.println("Light");
  tft.println("Off");
    tft.print(progress);
    tft.print("%");
    Serial.println(rotation);
rotation++;
    delay(40*255);

}
 rotation=0;
}
