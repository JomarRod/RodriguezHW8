/** File Name: test_analog.cpp
*   Description
**/

#include "AnalogIn.h"
#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
  AnalogIn Test(0);
  cout << "ADC Number: " << Test.getNumber() << endl;
  cout << "ADC Value: " << Test.readAdcSample() << endl;

  //Get temperature if it is a temp sensor adc input
  float cur_voltage = Test.readAdcSample() * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
  float diff_degreesC = (cur_voltage-0.75f)/0.01f;
  float temp = 25.0f + diff_degreesC;

  float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
  cout << "Example Temperature is " << temp << "°C (" << fahr << "°F)" << endl;
  return 0;
}

