    #include <FastLED.h>
    #define LED_PIN     7
    #define NUM_LEDS    10
    CRGB leds[NUM_LEDS];
    void setup() {
      FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    }
    void loop() {
      for (int i = 0; i <= 9; i++) {
        leds[i] = CRGB ( 0, 0, 205);
        FastLED.show();
        delay(10);
      }
      for (int i = 9; i >= 0; i--) {
        leds[i] = CRGB ( 255, 0, 0);
        FastLED.show();
        delay(40);
      }
    }
