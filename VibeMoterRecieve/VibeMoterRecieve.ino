#include <Radio.h>

Radio radio(11);

#define vibePin1 3
#define vibePin2 4
#define vibePin3 5
#define vibePin4 8
#define vibePin5 9

struct Packet {
  int snsrVal1 = 0;
  int snsrVal2 = 0;
  int snsrVal3 = 0;
  int snsrVal4 = 0;
  int snsrVal5 = 0;
} pkt;

void setup() {
  pinMode(vibePin1, OUTPUT);
  pinMode(vibePin2, OUTPUT);
  pinMode(vibePin3, OUTPUT);
  pinMode(vibePin4, OUTPUT);
  pinMode(vibePin5, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  if(radio.rfAvailable()) {
    radio.rfRead((uint8_t *) & pkt, sizeof(Packet));
  }

  analogWrite(vibePin1, pkt.snsrVal1);
  analogWrite(vibePin2, pkt.snsrVal2);
  analogWrite(vibePin3, pkt.snsrVal3);
  analogWrite(vibePin4, pkt.snsrVal4);
  analogWrite(vibePin5, pkt.snsrVal5);
  Serial.print("Pressure Sensor 1:"); Serial.print(pkt.snsrVal1);
  Serial.print("   Pressure Sensor 2:"); Serial.print(pkt.snsrVal2);
  Serial.print("   Pressure Sensor 3:"); Serial.print(pkt.snsrVal3);
  Serial.print("   Pressure Sensor 4:"); Serial.print(pkt.snsrVal4);
  Serial.print("   Pressure Sensor 5:"); Serial.println(pkt.snsrVal5);
}

