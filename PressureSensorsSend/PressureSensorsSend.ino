#include <Radio.h>

Radio radio(11);

#define snsrPin1 0
#define snsrPin2 1
#define snsrPin3 2
#define snsrPin4 3
#define snsrPin5 4

struct Packet {
  int snsrVal1 = 0;
  int snsrVal2 = 0;
  int snsrVal3 = 0;
  int snsrVal4 = 0;
  int snsrVal5 = 0;
} pkt;
  

void setup() {
  Serial.begin(9600);
}

void loop() {
  pkt.snsrVal1 = map(analogRead(snsrPin1), 0, 1023, 0, 255);
  pkt.snsrVal2 = map(analogRead(snsrPin2), 0, 1023, 0, 255);
  pkt.snsrVal3 = map(analogRead(snsrPin3), 0, 1023, 0, 255);
  pkt.snsrVal4 = map(analogRead(snsrPin4), 0, 1023, 0, 255);
  pkt.snsrVal5 = map(analogRead(snsrPin5), 0, 1023, 0, 255);
  Serial.print("Pressure Sensor 1:"); Serial.print(pkt.snsrVal1);
  Serial.print("   Pressure Sensor 2:"); Serial.print(pkt.snsrVal2);
  Serial.print("   Pressure Sensor 3:"); Serial.print(pkt.snsrVal3);
  Serial.print("   Pressure Sensor 4:"); Serial.print(pkt.snsrVal4);
  Serial.print("   Pressure Sensor 5:"); Serial.println(pkt.snsrVal5);

  radio.rfWrite((uint8_t *) & pkt, sizeof(Packet));


}
