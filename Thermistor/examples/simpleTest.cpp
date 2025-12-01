#include <Arduino.h>
#include <Thermistor.h>

#define A1 15 //change this pin at your will, just put an analog pin

Thermistor ter(10000, 12000, 3950); //you can add parameters to the constructor to change bits 

void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print( ter.getTemperature(analogRead(A1), 'C') ); //getTemperature() takes the adc mesure and the unit in char type 
  Serial.println(" C°"); //pretty print unit
  delay(5000);
}
