#define snsrPin1 0
#define snsrPin2 1
#define snsrPin3 2
#define snsrPin4 3
#define snsrPin5 4

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.print("Pressure Sensor 1:"); Serial.print(analogRead(snsrPin1));
  Serial.print("   Pressure Sensor 2:"); Serial.print(analogRead(snsrPin2));
  Serial.print("   Pressure Sensor 3:"); Serial.print(analogRead(snsrPin3));
  Serial.print("   Pressure Sensor 4:"); Serial.print(analogRead(snsrPin4));
  Serial.print("   Pressure Sensor 5:"); Serial.println(analogRead(snsrPin5));


}
