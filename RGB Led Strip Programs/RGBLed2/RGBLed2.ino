    #include <FastLED.h>
    #define LED_PIN     7
    #define NUM_LEDS    10
    CRGB leds[NUM_LEDS];
    void setup() {
      FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
      
    }
    void loop() {
      
      leds[0] = CRGB(184, 134, 11);
      FastLED.show();
      delay(500);  
      leds[1] = CRGB(184, 134, 11);
      FastLED.show();
      delay(500);
      leds[2] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[3] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[4] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[5] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[6] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[7] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[8] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
      leds[9] = CRGB(255, 200, 20);
      FastLED.show();
      delay(500);
    }
