void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("fanState.bco=");
  Serial.print(1152);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  Serial.print("RpmVal.val=");
  Serial.print(6000);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(1500);
  Serial.print("fanState.bco=");
  Serial.print(3);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  Serial.print("gearVal.val=");
  Serial.print(3);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  Serial.print("mphVal.val=");
  Serial.print(20);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(1500);
  Serial.print("RpmVal.val=");
  Serial.print(12000);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  Serial.print("gearVal.val=");
  Serial.print(1);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  Serial.print("mphVal.val=");
  Serial.print(80);
  Serial.write(255);
  Serial.write(255);
  Serial.write(255);
  delay(1500);
}




