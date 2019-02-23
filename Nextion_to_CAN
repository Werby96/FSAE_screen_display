//teensy 3.2 Can test sanity check
//transciever TX connects to pin #3 (tx)
//transciever RX connects to pin #4(RX)
//this is not like serial which is weird.
#include <FlexCAN.h>
#include <Adafruit_NeoPixel.h>

int rpm = 0;
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
                              
// -------------------------------------------------------------
void loop(void)
{
  CAN_message_t Msg;
  Msg.ext = true;
  while (Can0.available())
  {
    Can0.read(Msg);

    int lowByte = Msg.buf[0];
    int highByte = Msg.buf[1];
    int newRPM = ((highByte * 256) + lowByte);
    rpm = newRPM;
    RPM(rpm);

    digitalWrite(13, HIGH);
    
  }
}

void RPM(int x){

    Serial1.print("PotentVal.val=");
    Serial1.print(x);
    Serial1.write(255);
    Serial1.write(255);
    Serial1.write(255);

  
}
