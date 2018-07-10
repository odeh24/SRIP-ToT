#include <Radio.h>
 
Radio radio(11);

#define FLEX_PIN1 0 // Pin connected to each flex sensor
#define FLEX_PIN2 1 
#define FLEX_PIN3 2 
#define FLEX_PIN4 3 
#define FLEX_PIN5 4 

struct Packet {
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
} pkt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int flex1 = analogRead(FLEX_PIN1); //read value 
  int flex2 = analogRead(FLEX_PIN2); //from flex sensors
  int flex3 = analogRead(FLEX_PIN3);
  int flex4 = analogRead(FLEX_PIN4);
  int flex5 = analogRead(FLEX_PIN5);

  pkt.value1 = map(flex1, 0, 1023, 0, 255); //maps them to PWM scale
  pkt.value2 = map(flex2, 0, 1023, 0, 255); 
  pkt.value3 = map(flex3, 0, 1023, 0, 255);
  pkt.value4 = map(flex4, 0, 1023, 0, 255); 
  pkt.value5 = map(flex5, 0, 1023, 0, 255);

  Serial.println(String(flex1) + String (" ") + String(pkt.value1)); //print output value of around 530 to start
  Serial.println(String(flex2) + String (" ") + String(pkt.value2)); //values decease as voltage decrease when 
  Serial.println(String(flex2) + String (" ") + String(pkt.value3));
  Serial.println(String(flex2) + String (" ") + String(pkt.value4));
  Serial.println(String(flex2) + String (" ") + String(pkt.value5));
  Serial.println("");

  delay(500);

  radio.rfWrite((uint8_t *) & pkt, sizeof(Packet));
  radio.rfFlush();
}


