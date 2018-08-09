/***************************************************************************
Build a voltage divider circuit combining a flex sensor with a 4.7k resistor.
- The resistor goes from A0 to GND.
- The flex sensor connects A0 to 3.3V
As the flex sensor is being bent, the resistance increases and the reading 
by A0 should decrease.
Any other flex sensors added would need to be powered, connected to a resistor,
and grounded the same way. The output pins are the only thing that differs.
****************************************************************************/
#define FLEX_PIN1 0 //Pin connected to respective 
#define FLEX_PIN2 1 //flex sensor
#define FLEX_PIN3 2
#define FLEX_PIN4 3 
#define FLEX_PIN5 4 

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int flex1 = analogRead(FLEX_PIN1); //read output value
  int flex2 = analogRead(FLEX_PIN2);
  int flex3 = analogRead(FLEX_PIN3);
  int flex4 = analogRead(FLEX_PIN4);
  int flex5 = analogRead(FLEX_PIN5);

  int value1 = map(flex1, 80, 360, 0, 255); //maps value to PWM scale
  int value2 = map(flex2, 120, 600, 0, 255); //0 is 0% duty cycle 
  int value3 = map(flex3, 120, 600, 0, 255); //255 is 100% duty cycle
  int value4 = map(flex4, 120, 600, 0, 255);
  int value5 = map(flex5, 120, 600, 0, 255);
  
  Serial.println(String(flex1) + String (" ") + String(value1)); //print output value of around 530 to start
  Serial.println(String(flex2) + String (" ") + String(value2)); //values decease as voltage decrease when 
  Serial.println(String(flex3) + String (" ") + String(value3)); //the sensor is bent
  Serial.println(String(flex4) + String (" ") + String(value4)); //lowest values around 150
  Serial.println(String(flex5) + String (" ") + String(value5)); //lowest values around 150
  
  //Original value which starts around 275 for short and 500 for long
  Serial.println();

  delay(150);
}

