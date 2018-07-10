#include <Servo.h>
Servo servo1; //Creates control for servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
/***************************************************************************
Build a voltage divider circuit combining a flex sensor with a 4.7k resistor.
- The resistor goes from A0 to GND.
- The flex sensor connects A0 to 3.3V
As the flex sensor is being bent, the resistance increases and the reading 
by A0 should decrease.
****************************************************************************/
#define FLEX_PIN1 0 //Pin connected glex sensor
#define FLEX_PIN2 1 
#define FLEX_PIN3 2 
#define FLEX_PIN4 3 
#define FLEX_PIN5 4 

void setup() {
  servo1.attach(3); //attaches pin 3 to the servo control 
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(8);
  servo5.attach(9);
}

void loop() {
  int flex1 = analogRead(FLEX_PIN1); //read output value 
  int flex2 = analogRead(FLEX_PIN2); //from flex sensors
  int flex3 = analogRead(FLEX_PIN3);
  int flex4 = analogRead(FLEX_PIN4);
  int flex5 = analogRead(FLEX_PIN5);

  int value1 = map(flex1, 80, 360, 0, 255); //maps to PWM scale
  int value2 = map(flex2, 120, 600, 0, 255);
  int value3 = map(flex3, 120, 600, 0, 255);
  int value4 = map(flex4, 120, 600, 0, 255);
  int value5 = map(flex5, 120, 600, 0, 255);
    
  servo1.write(value1); //turn w value given by flex sensor
  servo2.write(value2);
  servo3.write(value3);
  servo4.write(value4);
  servo5.write(value5);
}
