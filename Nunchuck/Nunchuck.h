/* Library to control Wii's Nunchuck with Arduino 
*  Get the data from the 3-axis accel, the 2-axis joystick and the 2 buttons.
*
*  Note: Works only on version 1.0 and above of Arduino IDE. (only arduino.h)
*
*  Author:	Francisco Miguel Moreno. @Butakus
*  Email:	butakus@gmail.com
*  Version:	0.1
*  Date:	3/8/2013
*/

#ifndef Nunchuck_h
#define Nunchuck_h

#include <Arduino.h>

class Nunchuck{

public:
	int8_t accelX;
	int8_t accelY;
	int8_t accelZ;
	int8_t joyX;
	int8_t joyY;
	int8_t botonZ;
	int8_t botonC;

	Nunchuck();
	~Nunchuck();

	void init();
	void update();

private:
	char _decodeByte(char);
	int _buffer[6];
};

#endif
