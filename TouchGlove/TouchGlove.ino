#include <Radio.h>

#define vibePin1 3
#define vibePin2 4
#define vibePin3 5
#define vibePin4 8
#define vibePin5 9

#define FLEX_PIN1 0 // Pin connected to each flex sensor
#define FLEX_PIN2 1 
#define FLEX_PIN3 2 
#define FLEX_PIN4 3 
#define FLEX_PIN5 4 

Radio radio(11);

struct Packet {
  int snsrVal1 = 0; 
  int snsrVal2 = 0;
  int snsrVal3 = 0;
  int snsrVal4 = 0;
  int snsrVal5 = 0;
  int checkSum = 0;
} pkt;

struct Packet2 {
  int value1 = 0;
  int value2 = 0;
  int value3 = 0;
  int value4 = 0;
  int value5 = 0;
} pkt2;


void setup() {
  pinMode(vibePin1, OUTPUT);
  pinMode(vibePin2, OUTPUT);
  pinMode(vibePin3, OUTPUT);
  pinMode(vibePin4, OUTPUT);
  pinMode(vibePin5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pkt2.value1 = map(analogRead(FLEX_PIN1), 0, 320, 0, 255); //maps them to PWM scale
  pkt2.value2 = map(analogRead(FLEX_PIN2), 100, 600, 0, 255); 
  pkt2.value3 = map(analogRead(FLEX_PIN3), 100, 600, 0, 255);
  pkt2.value4 = map(analogRead(FLEX_PIN4), 100, 600, 0, 255); 
  pkt2.value5 = map(analogRead(FLEX_PIN5), 100, 600, 0, 255);
  
  delay(100);

  radio.rfWrite((uint8_t *) & pkt2, sizeof(Packet2));

  if(radio.rfAvailable()) {
    radio.rfRead((uint8_t *) & pkt, sizeof(Packet));
    radio.rfFlush();
  }
  
  analogWrite(vibePin1, pkt.snsrVal1);
  analogWrite(vibePin2, pkt.snsrVal2);
  analogWrite(vibePin3, pkt.snsrVal3);
  analogWrite(vibePin4, pkt.snsrVal4);
  analogWrite(vibePin5, pkt.snsrVal5);
}
