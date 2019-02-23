#include <FlexCAN.h>

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int rpm = 0;
CAN_message_t Msg;

void setup(void)
{
  // Serial.begin(9600);
  // Serial.println("online");

  Serial1.begin(9600);

  Can0.begin(250000); //PE3 ECU SPEED

  //Allow Extended CAN id's through
  CAN_filter_t allPassFilter;
  allPassFilter.ext = 1;
  for (uint8_t filterNum = 1; filterNum < 16; filterNum++)
  {
    Can0.setFilter(allPassFilter, filterNum);
  }
  pinMode(13, OUTPUT);
}

void loop() {
  
  Msg.ext = true;
  while (Can0.available())
  {
    Can0.read(Msg);

    int lowByte = Msg.buf[0];
    int highByte = Msg.buf[1];
    int newRPM = ((highByte * 256) + lowByte);
    int rpm = newRPM 
    potentVal.val(rpm);
  }
}

void potentVal(int x){
  Serial.print("PotentVal.val=");
  Serial.print(x);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(200);
}

void waterTemp(int x) {
  Serial.print("wtrTempVal.val=");
  Serial.print(x);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(200);
}

void BatteryVolts(int x) {
  Serial.print("battVal.val=");
  Serial.print(x);
  Serial.print();
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(200);
}

void shiftNumber(int x) {
  Serial.print("gearVal.val=");
  Serial.print(x);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(200);
}
