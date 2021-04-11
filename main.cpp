// Example: MirroringSample
// NodeMCU 1.0 (ESP12E Module), Wemos D1
// In this example, we're going to set up six NEOPIXEL strips on six different pins,
// and show the same thing on all six of them.

#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 24
#define BRIGHTNESS  64

CRGB leds[NUM_LEDS_PER_STRIP];


void setup() {
  
  FastLED.addLeds<NEOPIXEL, D3>(leds, NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, D4>(leds, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, D5>(leds, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, D6>(leds, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, D7>(leds, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, D8>(leds, NUM_LEDS_PER_STRIP);

  FastLED.setBrightness(BRIGHTNESS);
}


void fadeall() { for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) { leds[i].nscale8(250); } }

void loop() { 
  static uint8_t hue = 0;
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    
    FastLED.show(); 
    
    //leds[i] = CRGB::Black;
    fadeall();
    
    delay(50);
  }
}
  
