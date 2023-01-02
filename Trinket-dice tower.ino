#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define BUTTON_PIN 2
#define PIN 1
#define NUMPIXELS 64
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t RED = pixels.Color(255, 0, 0);
uint32_t BLACK = pixels.Color(0, 0, 0);
boolean oldState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pixels.begin();
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  rainbow(0);
  reset();
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 2*40000; firstPixelHue += 255) {
    for(int i=0; i<pixels.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 800 / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    };    
    pixels.show();
  };
};

void reset(){
  pixels.fill(BLACK, 0, 64);
  pixels.show();
};

void loop() {
  boolean newState = digitalRead(BUTTON_PIN);
  if((newState == LOW) && (oldState == HIGH)) {
    delay(100);
    newState = digitalRead(BUTTON_PIN);
    if(newState == LOW) {
      diceRoll(pixels.Color(255, 0, 0), 0);
    }
  }
  oldState = newState;
};

void diceRoll(uint32_t color, int wait){

  pixels.fill(RED, 0, 8);
  pixels.fill(RED, 8, 1);
  pixels.fill(RED, 15, 1);
  pixels.fill(RED, 16, 1);
  pixels.fill(RED, 23, 1);
  pixels.fill(RED, 24, 1);
  pixels.fill(RED, 31, 1); 
  pixels.fill(RED, 32, 1);
  pixels.fill(RED, 39, 1); 
  pixels.fill(RED, 40, 1);
  pixels.fill(RED, 47, 1); 
  pixels.fill(RED, 48, 1);
  pixels.fill(RED, 55, 1); 
  pixels.fill(RED, 56, 8);

pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 9, 6);
  pixels.fill(RED, 17, 1);
  pixels.fill(RED, 22, 1);
  pixels.fill(RED, 25, 1);
	pixels.fill(RED, 30, 1);
  pixels.fill(RED, 33, 1);
  pixels.fill(RED, 38, 1); 
  pixels.fill(RED, 41, 1);
  pixels.fill(RED, 46, 1); 
  pixels.fill(RED, 49, 6);

pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 18, 4);
  pixels.fill(RED, 26, 1);
  pixels.fill(RED, 29, 1);
  pixels.fill(RED, 34, 1);
  pixels.fill(RED, 37, 1);
  pixels.fill(RED, 42, 4);

pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 27, 2);
  pixels.fill(RED, 35, 2);

pixels.show();
  delay(75);
    pixels.clear();

  pixels.fill(RED, 18, 4);
  pixels.fill(RED, 26, 1);
  pixels.fill(RED, 29, 1);
  pixels.fill(RED, 34, 1);
  pixels.fill(RED, 37, 1);
  pixels.fill(RED, 42, 4);

  pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 9, 6);
  pixels.fill(RED, 17, 1);
  pixels.fill(RED, 22, 1);
  pixels.fill(RED, 25, 1);
	pixels.fill(RED, 30, 1);
  pixels.fill(RED, 33, 1);
  pixels.fill(RED, 38, 1); 
  pixels.fill(RED, 41, 1);
  pixels.fill(RED, 46, 1); 
  pixels.fill(RED, 49, 6);

  pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 0, 8);
  pixels.fill(RED, 8, 1);
  pixels.fill(RED, 15, 1);
  pixels.fill(RED, 16, 1);
  pixels.fill(RED, 23, 1);
  pixels.fill(RED, 24, 1);
  pixels.fill(RED, 31, 1); 
  pixels.fill(RED, 32, 1);
  pixels.fill(RED, 39, 1); 
  pixels.fill(RED, 40, 1);
  pixels.fill(RED, 47, 1); 
  pixels.fill(RED, 48, 1);
  pixels.fill(RED, 55, 1); 
  pixels.fill(RED, 56, 8);

  pixels.show();
  delay(100);
    pixels.clear();

  pixels.fill(RED, 0, 64);

  pixels.show();
  delay(50);
    pixels.clear();

  pixels.fill(0, 0);

  pixels.show();
  delay(50);
    pixels.clear();

  pixels.fill(RED, 0, 64);

  pixels.show();
  delay(50);
    pixels.clear();
  pixels.fill(0, 0);

  pixels.show();
    pixels.clear();
};