Firmware for DMX controller based on a tlc5940
==============================================

Requirements
------------

TLC5940 libary http://playground.arduino.cc/learning/TLC5940
DMXSerial libary http://playground.arduino.cc/Learning/DMXSerial

Pinout
-----

TLC5940 pinout is the same as given in the library

PD5 is the DMX indicator led. (pin 5 on atmega168 and atmega328 based ardunio boards)

portC [0-3] are address pins to select DMX location in 16 channel steps.
with the atmega168 and atmega328 based arduino boards these are A[0-3].