/* 
 *  just the start
 * 
 * 
 */

#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    300
#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define songStart = 6000;
#define theChaseStart 15417 + songStart;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(192); } }

void loop()
{
  uint8_t randNum = random(300);
  CHSV randColor( random(255), 255, 255 );
  leds[randNum] = randColor;
  fadeall();
  FastLED.show();
  delay(50);
  
}
