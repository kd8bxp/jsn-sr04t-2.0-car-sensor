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

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <TimedAction.h>

#define ECHOPIN 2// Pin to receive echo pulse
#define TRIGPIN 3// Pin to send trigger pulse
#define BUZZER 6 // Pin of the buzzer
#define LDR A0 //Photo Resistor pin
#define PIXEL 8 //Pin for Neopixel strip
#define PIXELCOUNT 16 //how many neopixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELCOUNT, PIXEL, NEO_GRB + NEO_KHZ800);
int distance, count, sum, near, bright;
void ping(){
  int avg = 100;
  //count = count + 1;
  for (int i=0;i<=avg;i++){
   // count = count + 1;
  digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
  delayMicroseconds(6); //6
  digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW); // Send pin low again
  digitalWrite(ECHOPIN, LOW);
  int duration = pulseIn(ECHOPIN,HIGH,38000); // Read in times pulse
  duration = duration/148;
  if (duration < 100 || duration > 0) {sum = sum + duration; }
  }
  distance = sum / avg; //count; //avg
  Serial.print(distance);
  Serial.println("   in");
  sum = 0;
  //if (count >= avg) {count = 0;}                    
  //delay(150);// Wait 50mS before next ranging
}


TimedAction timedAction = TimedAction(100,ping);



void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LDR, INPUT);
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  //digitalWrite(ECHOPIN, HIGH);
  
}

void loop(){
  //ping();
   timedAction.check();
  bright = analogRead(LDR);
  strip.setBrightness(map(bright,1024,0,0,50));
  if (distance >= 60 || distance <= 0) {
    timedAction.check();
    colorWipe(strip.Color(0,0,0), 15);} //LEDs off
  if (distance <= 59 && distance >= 40) {
    timedAction.check();
    colorWipe(strip.Color(255,128,0),5); //yellow 
    near = map(distance,40,59,200,500);
    //colorWipe(strip.Color(0,0,0),15);
    buzzer();} 
  if (distance <=39  && distance > 0) {
    timedAction.check();
    colorWipe(strip.Color(255,0,0),5); //red
    near = map(distance,0,39,50,100);
    buzzer();
    } 
  //delay(150);
  timedAction.check();
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


