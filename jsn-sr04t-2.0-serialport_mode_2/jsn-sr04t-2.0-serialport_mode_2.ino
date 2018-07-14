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

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop() {
  int avg = 0;
for (int i=0;i<10;i++) {
  int temp = readSerial();
  if (temp >= 220 || temp <= 0) { i = i -1;}
   else { avg = avg + temp; }
}
 int distance = avg/10;
 Serial.print(distance);Serial.println(" in.");
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

