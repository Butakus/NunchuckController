#include <Wire.h>
#include <Nunchuck.h>

Nunchuck wii;

void setup(){
  wii.init();
  Serial.begin(115200);
  delay(100);
}

void loop(){
  wii.update();
  
  Serial.print("X: ");
  Serial.println(wii.accelX);
  
  Serial.print("Y: ");
  Serial.println(wii.accelY);

  Serial.print("Z: ");
  Serial.println(wii.accelZ);

  Serial.print("c: ");
  Serial.println(wii.botonC);

  Serial.print("Z: ");
  Serial.println(wii.botonZ);

  Serial.print("joyX: ");
  Serial.println(wii.joyX);

  Serial.print("joyY: ");  
  Serial.println(wii.joyY);

  Serial.println();
  Serial.print("--------------------------------------------------------------------------------");
  Serial.println();
  
  
  
  delay(1000);
}
