#include <Arduino.h>
#include <FlexCAN.h>

const int analogInPin =
    A0; // Analog input pin that the potentiometer is attached to

int rpm = 0;
CAN_message_t Msg;

// prototypes
void potentVal(int x);

void setup(void) {
  // Serial1.begin(9600);
  // Serial1.println("online");

  Serial1.begin(9600);

  Can0.begin(250000); // PE3 ECU SPEED

  // Allow Extended CAN id's through
  CAN_filter_t allPassFilter;
  allPassFilter.ext = 1;
  for (uint8_t filterNum = 1; filterNum < 16; filterNum++) {
    Can0.setFilter(allPassFilter, filterNum);
  }
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {

  Msg.ext = true;
  while (Can0.available()) {
    Can0.read(Msg);
    digitalWrite(13, !digitalRead(13));

    int lowByte = Msg.buf[0];
    int highByte = Msg.buf[1];
    int newRPM = ((highByte * 256) + lowByte);
    int rpm = newRPM;
    potentVal(rpm);
  }
}

void potentVal(int x) {
  Serial1.print("PotentVal.val=");
  Serial1.print(x);
  Serial1.write(255);
  Serial1.write(255);
  Serial1.write(255);
  delay(20);
}

void waterTemp(int x) {
  Serial1.print("wtrTempVal.val=");
  Serial1.print(x);
  Serial1.write(255);
  Serial1.write(255);
  Serial1.write(255);
  // delay(200);
}

void BatteryVolts(int x) {
  Serial1.print("battVal.val=");
  Serial1.print(x);
  Serial1.write(255);
  Serial1.write(255);
  Serial1.write(255);
  // delay(200);
}

void shiftNumber(int x) {
  Serial1.print("gearVal.val=");
  Serial1.print(x);
  Serial1.write(255);
  Serial1.write(255);
  Serial1.write(255);
  // delay(200);
}
