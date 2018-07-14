/*
Copyright (c) 2018 LeRoy Miller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define TXPIN 3 // ECHO Pin 
#define RXPIN 2 // TRIG Pin 
#define BUZZER 6 // Pin of the buzzer
#define LDR A0 //Photo Resistor pin
#define PIXEL 8 //Pin for Neopixel strip
#define PIXELCOUNT 16 //how many neopixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELCOUNT, PIXEL, NEO_GRB + NEO_KHZ800);
int distance, count, sum, near, bright;

SoftwareSerial mySerial(RXPIN, TXPIN); //RX, TX

void ping(){
   int avg = 0;
for (int i=0;i<10;i++) {
  int temp = readSerial();
  if (temp >= 220 || temp <= 0) { i = i -1;}
   else { avg = avg + temp; }
}
distance = avg/10;
Serial.print(distance);Serial.println(" in. ");
}


void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(LDR, INPUT);
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop(){
  ping();
  bright = analogRead(LDR);
  strip.setBrightness(map(bright,1024,0,0,50));
  if (distance >= 60 || distance <= 0) {
      colorWipe(strip.Color(0,0,0), 15);} //LEDs off
  if (distance <= 59 && distance >= 40) {
      colorWipe(strip.Color(255,128,0),5); //yellow 
      near = map(distance,40,59,200,500);
      buzzer();} 
  if (distance <=39  && distance > 0) {
      colorWipe(strip.Color(255,0,0),5); //red
      near = map(distance,0,39,50,100);
      buzzer();
    } 
  }
  


void buzzer() {
  tone(6,7000,50);
delay(50);
tone(6,5000,50);
delay(50);
tone(6,7000,50);
delay(near);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

int readSerial() {
  byte serialData[5];
  int discalc;
while (mySerial.available()) {
  byte b = mySerial.read();
  }
  mySerial.setTimeout(95);
  if( mySerial.readBytes(serialData,4) > 0) {
    discalc = ((serialData[1] * 256) + serialData[2]);
    //Serial.print(int(distance* (1/25.4))); Serial.println(" in.");
    discalc = (discalc * (1/25.4)); //distance is returned from sensor in mm - this will convert to inches.
  }
  return discalc;
  }
