# Idea for a blind spot detector, or a how close is the car behind you

The JSN-SR04T-2.0 Sensor was provided by ICStation.com  
Get the sensor here:  
http://www.icstation.com/ultrasonic-module-sr04t-distance-measuring-transducer-sensor-module-p-5046.html  
Use this code to get %15 off:  
Code: LeRics  
Discount Amount: 15% off  
Max Use: 1 (one for per user)  
Amount Limit: 300   


## Installation

Other things used in this project, WS2812 Neopixel Ring (16 pixels)  
Active pizzo buzzer, and a photo resistor breakout board (a photo resistor setup as a voltage devider would work as well.)  
A micro-controller, Arduino UNO is what I used, any should work.  
Required Libraries:  
SoftwareSerial  should be in the library manager of the Arduino IDE.  
(only needed if you use serial mode2 of the sensor).  
Adafruit Neopixel - should be in the library manager  
TimedAction - I'm not sure where I got this library from.  

## Videos  
Introduction to the project: https://youtu.be/3zgp5uto6YM  
Road Tests: https://youtu.be/2OTSzJj-5g8  


## Things To Do


## Usage

Mode 1 - uses the echo/trig pins like a standard ultrasonic, I found this mode  
to be unstable at best, thou adding some averaging did seem to help.  
Use the jsn-sr04t-car_sensor sketch.  

Mode 2 - uses software serial, seems to be a little more stable, but still needed to have averaging applied.  
The hookup for the sensor/other componets is the same, if you wish to use mode 2  
you need a 47k resistor soldered to jumper R27.  
https://www.roboter-bausatz.de/media/pdf/83/0f/93/JSN-SR04T_outputmode.pdf  

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2018 LeRoy Miller

## License

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
