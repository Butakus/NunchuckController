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

/* Functions:
*	init()		//Initialize the wire library and start the communication.
*	update()	//Read from the nunchuck and update the variables.
*
*  Public variables:
*	accelX		//X axis accelerometer value
*	accelY		//Y axis accelerometer value
*	accelZ		//Z axis accelerometer value
*	joyX		//X axis joystick value
*	joyY		//Y axis joystick value
*	botonZ		//Z button value: 1=pushed, 0=released
*	botonC		//C button value: 1=pushed, 0=released
*/


#include "Wire.h"
#include "Nunchuck.h"

#define NUNCHUCK_ADDRESS 0x52

Nunchuck::Nunchuck(){}
Nunchuck::~Nunchuck(){}

char Nunchuck::_decodeByte(char x){
	return ((x ^ 0x17) + 0x17);
}

void Nunchuck::init(){
	Wire.begin();

	Wire.beginTransmission(NUNCHUCK_ADDRESS);
	Wire.write((byte)0x40);
	Wire.write((byte)0x00);
	Wire.endTransmission();
}

void Nunchuck::update(){

	Wire.beginTransmission(NUNCHUCK_ADDRESS);
	Wire.write((byte)0x00);
	Wire.endTransmission();

	delay(5);

	Wire.requestFrom(NUNCHUCK_ADDRESS, 6);
	while (!Wire.available());
	for (int i = 0; i < 6; ++i){
		_buffer[i] = _decodeByte(Wire.read());
	}
	
	joyX = _buffer[0];
	joyY = _buffer[1];
	accelX = _buffer[2];
	accelY = _buffer[3];
	accelZ = _buffer[4];
	
	if ((_buffer[5] >> 0) & 1){
		botonZ = 0;
	}
	else{
		botonZ = 1;
	}
	
	if ((_buffer[5] >> 1) & 1){
		botonC = 0;
	}
	else{
		botonC = 1;
	}
	
	// Improve the accel's precision:
	if ((_buffer[5] >> 2) & 1){
		accelX += 2;
	}
	if ((_buffer[5] >> 3) & 1){
		accelX += 1;
	}
	if ((_buffer[5] >> 4) & 1){
		accelY += 2;
	}
	if ((_buffer[5] >> 5) & 1){
		accelY += 1;
	}
	if ((_buffer[5] >> 6) & 1){
		accelZ += 2;
	}
	if ((_buffer[5] >> 7) & 1){
		accelZ += 1;
	}
}
