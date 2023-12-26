

#include <Adafruit_NeoPixel.h>
 
#define LED_Pin1 19 //use 33,32,27,26,25,19,18,14
#define LED_Pin2 18 //use 33,32,27,26,25,19,18,14
#define LED_Pin3 32 //use 33,32,27,26,25,19,18,14
#define LED_Pin4 33 //use 33,32,27,26,25,19,18,14
#define LED_Pin5 25 //use 33,32,27,26,25,19,18,14
#define LED_Pin6 26 //use 33,32,27,26,25,19,18,14
#define LED_Pin7 27 //use 33,32,27,26,25,19,18,14
#define Audio_Pin 35 // use 34 or 35
#define Pot_Pin 34 // use 34 or 35
#define LED_COUNT 50
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(LED_COUNT, LED_Pin1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(LED_COUNT, LED_Pin2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(LED_COUNT, LED_Pin3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(LED_COUNT, LED_Pin4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5 = Adafruit_NeoPixel(LED_COUNT, LED_Pin5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels6 = Adafruit_NeoPixel(LED_COUNT, LED_Pin6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels7 = Adafruit_NeoPixel(LED_COUNT, LED_Pin7, NEO_GRB + NEO_KHZ800);
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
const int num_pixels = pixels1.numPixels();
unsigned int pot;
//void setup() 
//{
//   Serial.begin(115200);
//   pixels1.begin(); // This initializes the NeoPixel library.
//   pixels2.begin();
//   pixels3.begin();
//   pixels4.begin();
//   pixels5.begin();
//   pixels6.begin();
//   pixels7.begin();
//randomSeed(analogRead(0));
//}

//
//void loop() 
//{
//  Serial.println("pot");
//   pot = analogRead(Audio_Pin);
//   Serial.println(pot);
//   double pot = (pot * 3.3) / 4095;  // convert to volts
//
//   Serial.println(pot);
//   Serial.println("end pot");
//   colorSweep(pixels1.Color(random(255),   random(255),   random(255)), 100);
//
//   
//   unsigned long startMillis= millis();  // Start of sample window
//   unsigned int peakToPeak = 0;   // peak-to-peak level
//
//   unsigned int signalMax = 0;
//   unsigned int signalMin = 4095;
//
//   // collect data for 50 mS
//   while (millis() - startMillis < sampleWindow)
//   {
//      sample = analogRead(Audio_Pin);
//      if (sample < 4095)  // toss out spurious readings
//      {
//         if (sample > signalMax)
//         {
//            signalMax = sample;  // save just the max levels
//         }
//         else if (sample < signalMin)
//         {
//            signalMin = sample;  // save just the min levels
//         }
//      }
//   }
//   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
//   double volts = (peakToPeak * 3.3) / 4095;  // convert to volts
//
//   Serial.println(volts);
//   if(volts>2){
//   colorSweep(pixels1.Color(random(255),   random(255),   random(255)), 10);}
//   
//}




void colorSweep(uint32_t color, int wait) {
  for(int i=0; i<pixels1.numPixels(); i++) { // For each pixel in strip...
   // pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)

   pixels1.setPixelColor(i, random(255),random(255),random(255));
   pixels2.setPixelColor(i, random(255),random(255),random(255));
   pixels3.setPixelColor(i, random(255),random(255),random(255));
   pixels4.setPixelColor(i, random(255),random(255),random(255));
   pixels5.setPixelColor(i, random(255),random(255),random(255));
   pixels6.setPixelColor(i, random(255),random(255),random(255));
   pixels7.setPixelColor(i, random(255),random(255),random(255));
   if (i ==0){}
   else{
   pixels1.setPixelColor(i-1,0,0,0);
   pixels2.setPixelColor(i-1,0,0,0);
   pixels3.setPixelColor(i-1,0,0,0);
   pixels4.setPixelColor(i-1,0,0,0);
   pixels5.setPixelColor(i-1,0,0,0);
   pixels6.setPixelColor(i-1,0,0,0);
   pixels7.setPixelColor(i-1,0,0,0);}
   pixels1.show();                         //  Update strip to match
   pixels2.show();
   pixels3.show();
   pixels4.show();
   pixels5.show();
   pixels6.show();
   pixels7.show();
    delay(wait);                           //  Pause for a moment
  } 
  pixels1.setPixelColor(num_pixels-1,0,0,0);
  pixels1.show();
  pixels2.setPixelColor(num_pixels-1,0,0,0);
  pixels2.show();
  pixels3.setPixelColor(num_pixels-1,0,0,0);
  pixels3.show();
  pixels4.setPixelColor(num_pixels-1,0,0,0);
  pixels4.show();
  pixels5.setPixelColor(num_pixels-1,0,0,0);
  pixels5.show();
  pixels6.setPixelColor(num_pixels-1,0,0,0);
  pixels6.show();
  pixels7.setPixelColor(num_pixels-1,0,0,0);
  pixels7.show();
  
                  
}

//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//




//
//
//
//#include "FFT.h" // include the library
//#include "FFT_signal.h"
//
//
//void setup() {
//  Serial.begin(115200); // use the serial port
//  char print_buf[300];
//  fft_config_t *real_fft_plan = fft_init(FFT_N, FFT_REAL, FFT_FORWARD, fft_input, fft_output);
//
//  for (int k = 0 ; k < FFT_N ; k++)
//    real_fft_plan->input[k] = (float)fft_signal[k];
//
//  long int t1 = micros();
//  // Execute transformation
//  fft_execute(real_fft_plan);
//  
//  // Print the output
//  for (int k = 1 ; k < real_fft_plan->size / 2 ; k++)
//  {
//    /*The real part of a magnitude at a frequency is followed by the corresponding imaginary part in the output*/
//    float mag = sqrt(pow(real_fft_plan->output[2*k],2) + pow(real_fft_plan->output[2*k+1],2))/1;
//    float freq = k*1.0/TOTAL_TIME;
////    sprintf(print_buf,"%f Hz : %f", freq, mag);
////    Serial.println(print_buf);
//    if(mag > max_magnitude)
//    {
//        max_magnitude = mag;
//        fundamental_freq = freq;
//    }
//  }
//  long int t2 = micros();
//  
//  Serial.println();
//  /*Multiply the magnitude of the DC component with (1/FFT_N) to obtain the DC component*/
//  sprintf(print_buf,"DC component : %f g\n", (real_fft_plan->output[0])/10000/FFT_N);  // DC is at [0]
//  Serial.println(print_buf);
//
//  /*Multiply the magnitude at all other frequencies with (2/FFT_N) to obtain the amplitude at that frequency*/
//  sprintf(print_buf,"Fundamental Freq : %f Hz\t Mag: %f g\n", fundamental_freq, (max_magnitude/10000)*2/FFT_N);
//  Serial.println(print_buf);
//
//  Serial.print("Time taken: ");Serial.print((t2-t1)*1.0/1000);Serial.println(" milliseconds!");
//  
//  // Clean up at the end to free the memory allocated
//  fft_destroy(real_fft_plan);
//  
//}
//
//void loop() {
//  
//}















//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//#define FFT_N 2048 // Must be a power of 2
//#define TOTAL_TIME 9.391904 //The time in which data was captured. This is equal to FFT_N/sampling_freq
//float fft_input[FFT_N];
//float fft_output[FFT_N];
//float max_magnitude = 0;
//float fundamental_freq = 0;
///* Dummy data (Output of an accelerometer)
//* Frequency: 5 Hz
//* Amplitude: 0.25g
//*/
//double fft_signal[FFT_N] = {
//11100,10600,11200,11700,12200,12900,12900,.....,11000
//};
//
//
//
//#include "FFT.h"
//#include "FFT_signal.h"
//
//
//
//fft_config_t *real_fft_plan = fft_init(FFT_N, FFT_REAL, FFT_FORWARD, fft_input, fft_output);
//
//
//for (int k = 0 ; k < FFT_N ; k++)
//  real_fft_plan->input[k] = (float) fft_signal[k];
//
//fft_execute(real_fft_plan);
//
//
//for (int k = 1 ; k < real_fft_plan->size / 2 ; k++)
//{
//  /*The real part of a magnitude at a frequency is 
//    followed by the corresponding imaginary part in the output*/
//float mag = sqrt(pow(real_fft_plan->output[2*k],2) + pow(real_fft_plan->output[2*k+1],2));
//  
//float freq = k*1.0/TOTAL_TIME;
//if(mag > max_magnitude)
//  {
//    max_magnitude = mag;
//    fundamental_freq = freq;
//  }
//}
//
//
//
///*Multiply the magnitude at all other frequencies with (2/FFT_N) to obtain the amplitude at that frequency*/
//sprintf(print_buf,"Fundamental Freq: %f Hz\t Mag: %f g\n", 
//fundamental_freq, (max_magnitude/10000)*2/FFT_N);
//Serial.println(print_buf);
//
//
///*Multiply the magnitude of the DC component with (1/FFT_N) to obtain the DC component*/
//sprintf(print_buf,"DC component: %f g\n",(real_fft_plan->output[0])/10000/FFT_N); // DC is at [0]
//Serial.println(print_buf);
//
//
//// Clean up at the end to free the memory allocated
//fft_destroy(real_fft_plan);
//
//
//
//
//
//
//
//
//



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void codeForTask1( void * parameter ) {
   for (;;) {
      Serial.print("Code is running on Core: ");Serial.println( xPortGetCoreID());
      colorSweep(pixels1.Color(random(255),   random(255),   random(255)), 10);
      delay(100);
   }
}


void codeForTask2( void * parameter ) {
   for (;;) {
      Serial.print("                                                            Code is running on Core: ");Serial.println( xPortGetCoreID());
      colorSweep(pixels1.Color(random(255),   random(255),   random(255)), 10);
      delay(150);
   }
}





TaskHandle_t Task1, Task2;




void setup() {
   Serial.begin(115200);

      Serial.begin(115200);
   pixels1.begin(); // This initializes the NeoPixel library.
   pixels2.begin();
   pixels3.begin();
   pixels4.begin();
   pixels5.begin();
   pixels6.begin();
   pixels7.begin();
randomSeed(analogRead(0));
   /*Syntax for assigning task to a core:
   xTaskCreatePinnedToCore(
                    coreTask,   // Function to implement the task
                    "coreTask", // Name of the task 
                    10000,      // Stack size in words 
                    NULL,       // Task input parameter 
                    0,          // Priority of the task 
                    NULL,       // Task handle. 
                    taskCore);  // Core where the task should run 
   */
   xTaskCreatePinnedToCore(    codeForTask1,    "FibonacciTask",    5000,      NULL,    2,    &Task1,    0);
   //delay(500);  // needed to start-up task1
   xTaskCreatePinnedToCore(    codeForTask2,    "SumTask",    5000,    NULL,    2,    &Task2,    1);
}







void loop() {
  
  
  }





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//  
//uint32_t chipId = 0;
//int x =0;
//void setup() {
//  Serial.begin(115200);
//}
//
//void loop() {
//  for(int i=0; i<17; i=i+8) {
//    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
//  }
//
//  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
//  Serial.printf("This chip has %d cores\n", ESP.getChipCores());
//  Serial.print("Chip ID: "); Serial.println(chipId);
//    Serial.print(x);
//  x++;
//  delay(3000);
//
//}
