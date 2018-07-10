#include <Radio.h>
#include <Servo.h>

#define snsrPin1 0
#define snsrPin2 1
#define snsrPin3 2
#define snsrPin4 3
#define snsrPin5 4

Servo servo1; //creates control for servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

Radio radio(11);

struct Packet {
  int snsrVal1 = 0;
  int snsrVal2 = 0;
  int snsrVal3 = 0;
  int snsrVal4 = 0;
  int snsrVal5 = 0;
} pkt;

struct Packet2 {
  int value1 = 0;
  int value2 = 0;
  int value3 = 0;
  int value4 = 0;
  int value5 = 0;
} pkt2;

void setup() {
  Serial.begin(9600);
  servo1.attach(3); //attaches pin 3 to the servo control 
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(8);
  servo5.attach(9);

}

void loop() {
  pkt.snsrVal1 = map(analogRead(snsrPin1), 0, 1023, 0, 255);
  pkt.snsrVal2 = map(analogRead(snsrPin2), 0, 1023, 0, 255);
  pkt.snsrVal3 = map(analogRead(snsrPin3), 0, 1023, 0, 255);
  pkt.snsrVal4 = map(analogRead(snsrPin4), 0, 1023, 0, 255);
  pkt.snsrVal5 = map(analogRead(snsrPin5), 0, 1023, 0, 255);

  radio.rfWrite((uint8_t *) & pkt, sizeof(Packet));

  if(radio.rfAvailable()) {
    radio.rfRead((uint8_t *) & pkt2, sizeof(Packet2));
  }

  servo1.write(pkt2.value1); //turn to value given by flex sensor
  servo2.write(pkt2.value2);
  servo3.write(pkt2.value3);
  servo4.write(pkt2.value4);
  servo5.write(pkt2.value5);

  delay (100);

}
