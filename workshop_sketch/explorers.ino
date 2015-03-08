// sketch for wearables workshop. Uses a switch-case to put in different algorithms
// and variables for each changeable thing to make it easier to teach.
// also uses commenting and uncommenting to make it accessible for slow typists/make sure everything's correct.

// Origianl by Charlotte Godley
// tweaked by Carl Monk to aid clarity (for me anyway)
 
#include <Adafruit_NeoPixel.h>
 
#define PIN 1
#define PIXELS 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELS, PIN);

// colour pallet
// below are some example colours, only one can be active at one time
// color[] is an array which allows us to define one or more colours for funky effects

uint32_t color[1]={0x4D2177}; // Scout purple!

// Other examples
//uint32_t color[1]={0xFFFF00}; // yellow!
//uint32_t color[1]={0xFF0000}; //red
//uint32_t color[1]={0xFF4F01}; //orange
//uint32_t color[1]={0x00FF00}; // green
//uint32_t color[6]={0x1D6FEE,0xD5442F,0xFFB706,0x1D6FEE,0x009350,0xD5442F}; // multi coloured!

// brightness
// 30 is plenty, if you don't believe me crank it up to 50 but only with sunglasses
uint8_t bright=30;

// delay
// the amount of time in milliseconds between colour changes
// 1 second = 1000 milliseconds
// default is 60, try 100 for a longer flash, 10 if you're not photosesitive!
uint8_t timeToDelay=60;

// pattern
// there are 3 predefined patterns, change the number from 1-3 to see the difference
uint8_t pattern=1;


uint8_t neg=-1;
uint8_t i=0;
uint8_t col=0;

void setup() {
  pixels.begin();
  pixels.setBrightness(bright); // 1/3 brightness
  uint8_t i=0;
    for(i=0;i<PIXELS;i++)
  {
    pixels.setPixelColor(i,color[0]);
  }
  pixels.show();
}
 
void loop() {
  switch(pattern)
  {
    case 1:
      if(col<sizeof(color)/sizeof(color[0]))
       {
         col++;
       }
     if(col==sizeof(color)/sizeof(color[0]))
       {
         col=0;
       }
      for(i=0;i<PIXELS;i++)
      {
      pixels.setPixelColor(i,color[col]);
      }
      pixels.show();
      delay(timeToDelay);
  
      for(i=0;i<PIXELS;i++)
      {
        pixels.setPixelColor(i,0x000000);
      }
      pixels.show();
      delay(timeToDelay);
      break;
      //col++;
   case 2:
     if(col<sizeof(color)/sizeof(color[0]))
       {
         col++;
       }
     if(col==sizeof(color)/sizeof(color[0]))
       {
         col=0;
       }
     pixels.setPixelColor(i,color[col]);
     pixels.show();
     delay(timeToDelay);
     pixels.setPixelColor(i,0x000000);
     delay(timeToDelay);
     i++;
     if(i>PIXELS-1)
     {
       i=0;
     }
     break;
   case 3:
     if(bright>30)
      {
      neg=-1;
      if(col>=sizeof(color)/sizeof(color[0]))
        {
        col=0;
        }
      if(col<sizeof(color)/sizeof(color[0])-1)
       {
       col++;
       }
      }
      if(bright<5)
      {
      neg=1;
      }
     
     bright+=neg;
     pixels.setBrightness(bright);
     pixels.setPixelColor(i,color[col]);
     pixels.show();
     delay(timeToDelay);
     if(i<PIXELS-1)
     {
       i++;
     }
     else
     {
       i=0;
     }
     break;
     
  }
}
