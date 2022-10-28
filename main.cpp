#include "mbed.h"

// A class for flip()-ing a DigitalOut
class Flipper {
public:
    Flipper(PinName pin) : _pin(pin)
    {
        _pin = 0;
    }
    void flip()
    {
        _pin = !_pin;
    }
private:
    DigitalOut _pin;
};

DigitalOut led1(LED1);
DigitalOut led3(LED3);
Flipper f(LED2);
Ticker t;
Ticker flipper;

void flip()
{
    led3 = !led3;
}



int main()
{
    // the address of the object, member function, and interval
    t.attach(callback(&f, &Flipper::flip), 2.0);
    led3 = 1;
    flipper.attach(&flip, 2.0); // the address of the function to be attached (flip) and the interval (2 seconds)

    // spin in a main loop. flipper will interrupt it to call flip
    while (1) {
        led1 = !led1;
        ThisThread::sleep_for(200);
    }
}


