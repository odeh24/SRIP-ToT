#define snsrPin1 0
#define snsrPin2 1
#define snsrPin3 2
#define snsrPin4 3
#define snsrPin5 4

#define vibePin1 3
#define vibePin2 4
#define vibePin3 5
#define vibePin4 8
#define vibePin5 9



void setup() {
  pinMode(vibePin1, OUTPUT);
  pinMode(vibePin2, OUTPUT);
  pinMode(vibePin3, OUTPUT);
  pinMode(vibePin4, OUTPUT);
  pinMode(vibePin5, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  Serial.print("Pressure Sensor 1:"); Serial.print(analogRead(snsrPin1));
  Serial.print("   Pressure Sensor 2:"); Serial.println(analogRead(snsrPin2));
  //Serial.print("   Pressure Sensor 3:"); Serial.print(analogRead(snsrPin3));
  //Serial.print("   Pressure Sensor 4:"); Serial.print(analogRead(snsrPin4));
  //Serial.print("   Pressure Sensor 5:"); Serial.println(analogRead(snsrPin5));
  analogWrite(vibePin1, map(analogRead(snsrPin1), 0, 1023, 0, 255));
  analogWrite(vibePin2, map(analogRead(snsrPin2), 0, 1023, 0, 255));
  //analogWrite(vibePin3, analogRead(snsrPin3));
  //analogWrite(vibePin4, analogRead(snsrPin4));
  //analogWrite(vibePin5, analogRead(snsrPin5));
  delay(50);
} 
