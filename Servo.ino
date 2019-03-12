#include<Servo.h>
Servo obj;
int potpin = 0;
float val;
void setup() {
  // put your setup code here, to run once:
  obj.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);
  Serial.println(val);
  val = val/5.683333;
  obj.write(val);
  Serial.println(val);
  //obj.write(0);
  delay(1000);
}
