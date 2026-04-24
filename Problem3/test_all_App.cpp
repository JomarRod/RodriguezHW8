/** File Name: test_all_App.cpp
*   Description:
**/

#include <iostream>
#include "AnalogIn.h"
#include "molloy_LED.h"
#include "GPIO.h"

using namespace std;
using namespace exploringBB;

int main() {
  //Turn on usr1 and usr3 leds
  LED usr1(1);
  LED usr3(3);

  usr1.turnOn();
  usr3.turnOn();

  //Flash usr2 leds
  LED usr2(2);
  usr2.flash("200");

  //REad temp sensor and print raw value
  AnalogIn AIN(0);
  int adcVal = AIN.readAdcSample();
  cout << "ADC Value: " << adcVal << endl;

  //Button Input and LED output
  GPIO Button(46);
  Button.setDirection(INPUT);
  GPIO_VALUE buttonState = Button.getValue();
  cout << "Button state: " << buttonState << endl;

  GPIO LED(60);
  LED.setDirection(OUTPUT);

  if(buttonState == HIGH) {
    LED.setValue(HIGH);
  }
  else {
    LED.setValue(LOW);
  }
  return 0;
}
