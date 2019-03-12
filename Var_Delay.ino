#include<math.h>
int gr = 4;
long prevmill = 0;
long prevmill1;
long val;
boolean check = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(gr,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    val = Serial.parseInt();  
    check = true;
    prevmill1=0;
  }
  if(check == true)
  {
      if((long)millis() - prevmill1 >= val)
       {
        prevmill1 = millis();
        digitalWrite(gr,!digitalRead(gr));
       }
      if(millis()-prevmill >=10000)
      { 
        prevmill = millis();
        Serial.println(val);
      } 
  }
  else
  {
    if(millis()-prevmill >=10000)
        {
          Serial.println(0);
        }
  }
}
