#include <Thermistor.h>
#include <math.h>

//constructor
Thermistor::Thermistor(double Rref, double R0, double Beta, unsigned samplingBitsNumber,double vcc, double t0) : Rref(Rref),R0(R0),Beta(Beta),samplingBitsNumber(samplingBitsNumber),Vcc(vcc),T0(t0) {}

double Thermistor::getTemperature(double adc, char unit){ //by default unit is in Kelvin
	double b3 = this->R0 * ( (pow(2, this->samplingBitsNumber)-1)/adc -1 ); //first part of the equation
	double f1 = 1/this->T0 + (1/this->Beta * log(b3/Rref));  //second part

	f1 = 1/f1; //multiplicative inverse

	if(unit == 'C') //f1 is in kelvin, so we will convert if needed
		f1 -= ZERO_CELSIUS; 
	else if(unit == 'F')
		f1 = (9*(f1-ZERO_CELSIUS)/5) + 32;

	return f1;
}
