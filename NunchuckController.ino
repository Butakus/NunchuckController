#include "Nunchuck.h"

Nunchuck wii;

void setup(){
	Serial.begin(9600);
	wii.init();
	delay(100);
}

void loop(){
	// Takes around 20-22ms each loop
	wii.update();
	Serial.print(wii.accelX);
	Serial.print(';');
	Serial.print(wii.accelY);
	Serial.print(';');
	Serial.print(wii.accelZ);
	Serial.print(';');
	Serial.print(wii.joyX);
	Serial.print(';');
	Serial.print(wii.joyY);
	Serial.print(';');
	Serial.print(wii.botonZ);
	Serial.print(';');
	Serial.print(wii.botonC);
	Serial.print(';');
	Serial.print('\n');
}
