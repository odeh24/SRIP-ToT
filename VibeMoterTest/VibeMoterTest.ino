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
  for(int i=0; i <= 255; i++){
    Serial.println(i);
    analogWrite(vibePin1, i);
    analogWrite(vibePin2, i);
    analogWrite(vibePin3, i);
    analogWrite(vibePin4, i);
    analogWrite(vibePin5, i);
    delay(50);
  }
  for(int i=255; i >= 0; i= i- 1){
    Serial.println(i);
    analogWrite(vibePin1, i);
    analogWrite(vibePin2, i);
    analogWrite(vibePin3, i);
    analogWrite(vibePin4, i);
    analogWrite(vibePin5, i);
    delay(50);
  }
  
}

