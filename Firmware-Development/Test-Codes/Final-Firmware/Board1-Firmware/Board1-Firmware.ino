// NeoPixel simple sketch (c) 2013 Shae Erisson, adapted to tinyNeoPixel library by Spence Konde 2019.
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <tinyNeoPixel_Static.h>


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN             3
#define PIN2            12
#define CPIN            15
#define ledpwr1         4
#define ledpwr2         5
#define piezoPin        1
#define piezoPin1       2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      161

// Since this is for the static version of the library, we need to supply the pixel array
// This saves space by eliminating use of malloc() and free(), and makes the RAM used for
// the frame buffer show up when the sketch is compiled.

byte pixels[NUMPIXELS * 3];
byte pixels1[1 * 3];

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.

tinyNeoPixel leds = tinyNeoPixel(NUMPIXELS, PIN, NEO_GRB, pixels);
//tinyNeoPixel c_led = tinyNeoPixel(1, CPIN, NEO_GRB, pixels1);
//tinyNeoPixel leds = tinyNeoPixel(NUMPIXELS, PIN2, NEO_GRB, pixels);

unsigned long previousMillis = 0;
const long interval = 40000;
bool flag = false;

void setup() {
  
  pinMode(ledpwr1, OUTPUT);
  pinMode(ledpwr2, OUTPUT);
  
  delay (100);
  digitalWrite(ledpwr1, HIGH);
  digitalWrite(ledpwr2, HIGH);
  
  pinMode(PIN, OUTPUT);

  leds.setBrightness(50);
//  pinMode(CPIN, OUTPUT);



  //with tinyNeoPixel_Static, you need to set pinMode yourself. This means you can eliminate pinMode()
  //and replace with direct port writes to save a couple hundred bytes in sketch size (note that this
  //savings is only present when you eliminate *all* references to pinMode).
  //leds.begin() not needed on tinyNeoPixel



  

  
}

void loop() {



while (millis() - previousMillis < 5000) {
  for(int x = 0; x < 256; x+=2){
    leds.setPixelColor(0, leds.Color(x, 0, 0)); // Yellow Fade-in
    leds.show();
    delay(5);
  }

  
  for(int x = 255; x > 0; x-=2){
    leds.setPixelColor(0, leds.Color(x, 0, 0)); // Yellow Fade-in
    leds.show();
    delay(5);
  }
}

if (!flag) {
  leds.setPixelColor(0, leds.Color(255, 0, 0)); // Yellow Fade-in
  leds.show();
  delay(5);

  for( int ring1=0; ring1<256; ring1+=2 ) {
      int r = ring1;  // Redness starts at zero and goes up to full
      int b = 0;  // Blue starts at full and goes down to zero
      int g = ring1;              // No green needed to go from blue to red
      
      for(int x = 1; x < 13; x++){
          leds.setPixelColor(x, leds.Color(r, g, b)); // Yellow Fade-in
      }
      leds.show();
      delay(5);
  }

  flag = true;
}
if (millis() - previousMillis < interval) {


//  for( int ring1=0; ring1<256; ring1++ ) {
//      int r = ring1;  // Redness starts at zero and goes up to full
//      int b = 0;  // Blue starts at full and goes down to zero
//      int g = ring1;              // No green needed to go from blue to red
      
/*

*/
//
//
//      
//      for(int x = 0; x < 12; x++){
//          leds.setPixelColor(x, leds.Color(r, g, b)); // Yellow Fade-in
//      }
//      
//      leds.show();
//      delay(10);
//  }

  for( int ring2=0; ring2<256; ring2+=2 ) {
      int r = ring2;  // Redness starts at zero and goes up to full
      int b = 0;  // Blue starts at full and goes down to zero
      int g = ring2;              // No green needed to go from blue to red

      for(int x = 1; x < 13; x++){
          leds.setPixelColor(x, leds.Color(255-r, 255-g, b)); 
      }
      
      leds.show();
      delay(1);

      for(int x = 13; x < 35; x++){
          leds.setPixelColor(x, leds.Color(r, g/1.54, b)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int ring3=0; ring3<256; ring3+=2 ) {
      int r = ring3;  // Redness starts at zero and goes up to full
      int b = 0;  // Blue starts at full and goes down to zero
      int g = ring3;              // No green needed to go from blue to red

      for(int x = 13; x < 35; x++){
          leds.setPixelColor(x, leds.Color(255-r, 165-(g/1.54), b)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
      
      for(int x = 35; x < 67; x++){
          leds.setPixelColor(x, leds.Color(r, 0, b)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int ring4=0; ring4<256; ring4+=2 ) {
      for(int x = 35; x < 67; x++){
          leds.setPixelColor(x, leds.Color(255-ring4, 0, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);

      for(int x = 67; x < 109; x++){
          leds.setPixelColor(x, leds.Color(0, ring4, ring4)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int ring5=0; ring5<256; ring5+=2 ) {
      for(int x = 67; x < 109; x++){
          leds.setPixelColor(x, leds.Color(0, 255-ring5, 255-ring5)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);

      for(int x = 109; x < 161; x++){
          leds.setPixelColor(x, leds.Color(ring5, 0, ring5)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int fin=0; fin<256; fin+=2 ) {
      for(int x = 109; x < 161; x++){
          leds.setPixelColor(x, leds.Color(255-fin, 0, 255-fin)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);

      for(int x = 67; x < 109; x++){
          leds.setPixelColor(x, leds.Color(0, fin, fin)); // Yellow Fade-in
      }

      leds.show();
      delay(1);
  }

  for( int ring6=0; ring6<256; ring6+=2 ) {
      for(int x = 67; x < 109; x++){
          leds.setPixelColor(x, leds.Color(0, 255-ring6, 255-ring6)); // Yellow Fade-in
      }

      leds.show();
      delay(1);

      for(int x = 35; x < 67; x++){
          leds.setPixelColor(x, leds.Color(ring6, 0, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int ring7=0; ring7<256; ring7+=2 ) {
      for(int x = 35; x < 67; x++){
          leds.setPixelColor(x, leds.Color(255-ring7, 0, 0)); // Yellow Fade-in
      }

      leds.show();
      delay(1);

      for(int x = 13; x < 35; x++){
          leds.setPixelColor(x, leds.Color(ring7, ring7/1.54, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

  for( int ring8=0; ring8<256; ring8+=2 ) {
      for(int x = 13; x < 35; x++){
          leds.setPixelColor(x, leds.Color(255-ring8, 165-(ring8/1.54), 0)); // Yellow Fade-in
      }

      leds.show();
      delay(1);

      for(int x = 1; x < 13; x++){
          leds.setPixelColor(x, leds.Color(ring8, ring8, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(1);
  }

}

else {
      
      tone(piezoPin, 1000, 500);
      
      for(int x = 1; x < 161; x++){
          leds.setPixelColor(x, leds.Color(255, 0, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(500);

//      for(int x = 0; x < 12; x++){
//          leds.setPixelColor(x, leds.Color(0, 0, 0)); // Yellow Fade-in
//      }
//      
//      leds.show();
//      delay(10);
//
//      for(int x = 12; x < 34; x++){
//          leds.setPixelColor(x, leds.Color(255, 0, 0)); // Yellow Fade-in
//      }
//      
//      leds.show();
//      delay(100);
//
//      for(int x = 12; x < 34; x++){
//          leds.setPixelColor(x, leds.Color(0, 0, 0)); // Yellow Fade-in
//      }
//      
//      leds.show();
//      delay(10);
//
//      for(int x = 34; x < 67; x++){
//          leds.setPixelColor(x, leds.Color(255, 0, 0)); // Yellow Fade-in
//      }
//      
//      leds.show();
//      delay(100);

      for(int x = 1; x < 161; x++){
          leds.setPixelColor(x, leds.Color(0, 0, 0)); // Yellow Fade-in
      }
      
      leds.show();
      delay(500);
}
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one. 

//  for (int i = 0; i < NUMPIXELS; i++) {
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//
//    
//    leds.setPixelColor(i, leds.Color(127, 127, 0)); // Moderately bright green color.
//    
//    leds.show(); // This sends the updated pixel color to the hardware.
//
//    //delay(delayval); // Delay for a period of time (in milliseconds).
//  }
//
//  delay(delayval); //delay for a period of time
//  
//  //with tinyNeoPixel_Static, since we have the pixel array, we can also directly manipulate it - this sacrifices the correction for the pixel order, and the clarity of setColor to save a tiny amount of flash and time.
//  for (int i = 0; i < (NUMPIXELS  * 3 ); i++) {
////    pixels[i] = 150; //set byte i of array (this is channel (i%3) of led (i/3) (respectively, i%4 and i/4 for RGBW leds)
////    leds.show(); //show
//    
//    pixels[i] = 0; //turn off the above pixel
////    result is that each pixel will cycle through each of the primary colors (green, red, blue for most LEDs) in turn, and only one LED will be on at a time.
//  }
}
