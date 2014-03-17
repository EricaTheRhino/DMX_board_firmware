
#include "Tlc5940.h"
#include <DMXSerial.h>
#include <avr/io.h>

void setup()
{
  /* Call Tlc.init() to setup the tlc.
     You can optionally pass an initial PWM value (0 - 4095) for all channels.*/
  Tlc.init();
  
  DMXSerial.init(DMXReceiver);
  
  // set some default values
  for (int channel = 0; channel < NUM_TLCS * 16; channel += 1) {
    DMXSerial.write(channel+1, 0);
  }
  
  pinMode(5, OUTPUT);
  DDRC &= 0x0F; // set jupers as input
  
}

void loop()
{
  int offset = 16 * (PINC & 0x0F); // calculate dmx offset
  
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  Tlc.clear();
  if (lastPacket < 5000) {
    // read recent DMX values and set pwm levels 
    analogWrite(5,   250);
    for (int channel = 0; channel < NUM_TLCS * 16; channel += 1) {
      Tlc.set(channel, DMXSerial.read(channel+1+offset)*4);
    }
    Tlc.update();
  } else {
    analogWrite(5,   0);
    for (int channel = 0; channel < NUM_TLCS * 16; channel += 1) {
      Tlc.set(channel, 125);
    }
    Tlc.update();
  } // if
}

