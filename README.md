# Thermistobinkz
## Smahbinkz
### 1 december 2025


Little Arduino/ESP32 lib to mesure temperature with thermistor.
Thermistor is a Class with one method to get the temperature from an analogic mesure. You can choose an unit of temperature between Farhenheit, Celsius and Kelvin.

The class need at least ** 3 ** parameters : Your thermistor resistance value, your fixed resistance and the const Beta value.

You need to make this scheme to make the program work: 
![Schema](https://imagesend.fr/uploads/20251201/81f03fc60bc0df23effdc506fe97d91e9d053585.png)

Rt is your thermistor, R0 your fixed resistance, ADC is the analogic value mesured on your analogic pin
You need to plug your analogic pin between Rt and R0. The voltage needs to be provide by Vcc.

Here is the array needed to choose the Beta value:
![Array](https://imagesend.fr/uploads/20251201/81f03fc60bc0df23effdc506fe97d91e9d053585.png](https://imagesend.fr/uploads/20251201/f19d508b2db7cf09b42cb788019b38075f30306c.png)

And for exemple, here is a small program to show you how you can test the library easily:

```
#include <Arduino.h>
#include <Thermistor.h>

#define A1 15

Thermistor t(10000, 12000, 3950);

void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print( t.getTemperature(analogRead(A1), 'C') ); Serial.println(" C°");
  delay(5000);
}
```
