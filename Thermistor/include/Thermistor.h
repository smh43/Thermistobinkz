const double ZERO_CELSIUS=273.15; //little const of absolute zero for maths

class Thermistor
{
    private:
    double Rref, R0, Beta, T0 , Vcc; 
    unsigned samplingBitsNumber; 

    public: 
    /**
        * @brief Thermistor class
        * @param Rref is your Thermistor value in Ohm 
        * @param R0 R0 is the resistance fixed after your thermistor (in Ohm)
        * @param Beta Beta is a const value linked to your Thermistor value, by default it's 3950, change it if Rref is less than 10k Ohm, or greater than 100k Ohm
        * @param samplingBitsNumber 2**samplingBitsNumber is the range of values for temperature, by default it's 10 bits
        * @param VCC Vcc is the voltage of the source, by default 5V
        * @param T0 T0 is a const in Kelvin for reference, i advise you to don't change it
    **/

    Thermistor(double Rref, double R0, double Beta , unsigned samplingBitsNumber=10 , 
               double Vcc=5, double T0=298.15); 
    
    /** 
     * @param adc your analogic value mesured
     * @param unit A unit in Char type : 'K' for Kelvin, 'C' for Celsius, 'F' for fahrenheit
     * @return a double value of the temperature in the unit you choose, by default in Kelvin
     **/
    double getTemperature(double adc, char unit='K');   

};

