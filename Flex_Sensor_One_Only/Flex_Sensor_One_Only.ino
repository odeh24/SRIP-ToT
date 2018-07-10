/******************************************************************************
  Flex_Sensor_Example.ino
  Example sketch for SparkFun's flex sensors
  (https://www.sparkfun.com/products/10264)
  Jim Lindblom @ SparkFun Electronics
  April 28, 2016

  Create a voltage divider circuit combining a flex sensor with a 47k resistor.
  - The resistor should connect from A0 to GND.
  - The flex sensor should connect from A0 to 3.3V
  As the resistance of the flex sensor increases (meaning it's being bent), the
  voltage at A0 should decrease.

  Development environment specifics:
  Arduino 1.6.7
******************************************************************************/
const int FLEX_PIN = 0; // Pin connected to voltage divider output

// Measure the voltage at 3.3V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 3.3; // Measured voltage of Ardunio 3.3V line
const float R_DIV = 38000.0; // Measured resistance of 47k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 30000.0; // resistance when straight
const float BEND_RESISTANCE = 70000.0; // resistance at 90 deg

void setup()
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
}

void loop()
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * (3.3 * (1024/5)); //input 0-5 V maps to 0 to 1023, 49 mV/unit
  float flexR = R_DIV * ((VCC / flexV) -1) ;
  Serial.println(String(flexV));
  Serial.println(String(flexADC));

  //Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
}
