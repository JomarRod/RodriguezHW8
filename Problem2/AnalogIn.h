/** File Name: AnalogIn.h
*   Description
**/
#ifndef ANALOGIN_H
#define ANALOGIN_H

using namespace std;

class AnalogIn{
  private:
  unsigned int number;
  public:
  AnalogIn();
  AnalogIn(unsigned int n);
  virtual unsigned int getNumber() {return number; } // inline function implementation.
  virtual void setNumber(unsigned int n);
  virtual int readAdcSample();
  virtual ~AnalogIn();
};

#endif
