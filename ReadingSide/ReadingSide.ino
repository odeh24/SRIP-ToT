#include <Radio.h>
Radio radio(11);

#include <Servo.h>
Servo servo1; //creates control for servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

struct Packet {
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int checkSum;
} pkt;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(3); //attaches pin 3 to the servo control 
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(8);
  servo5.attach(9);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if(radio.rfAvailable()) {
    radio.rfRead((uint8_t *) & pkt, sizeof(Packet));
  }
  int checkSum1 = pkt.value1 + pkt.value2 + pkt.value3 + pkt.value4 + pkt.value5;
  Serial.print("checkSum:");
  Serial.println(checkSum1);
  Serial.println("CHECKING");
  if(checkSum1 == pkt.checkSum) {
    Serial.println("READING RECEIVED PACKET");
    Serial.println(pkt.value1);
    Serial.println(pkt.value2);
    Serial.println(pkt.value3);
    Serial.println(pkt.value4);
    Serial.println(pkt.value5);
 
    servo1.write(pkt.value1); //turn to value given by flex sensor
    servo2.write(pkt.value2);
    servo3.write(pkt.value3);
    servo4.write(pkt.value4);
    servo5.write(pkt.value5);
  }
  else {
    Serial.println("ERROR");
  }
  Serial.println("");
  delay(500);
}

