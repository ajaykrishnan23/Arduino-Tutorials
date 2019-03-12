int prevled;
int rd = 2;
int bl = 3;
int wt = 6;
int sensepin = A1;
void setup() {
  pinMode(rd,OUTPUT);
  pinMode(wt,OUTPUT);
  pinMode(bl,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(sensepin);
  val = map(val,2,225,0,1023);
  val = constrain(val,0,1023);
  Serial.println(val);
    if (val == 1023)
  {
    digitalWrite(rd,HIGH);
    digitalWrite(bl,LOW);
    digitalWrite(wt,LOW);
  }
  else if (val == 0)
  {
    digitalWrite(rd,LOW);
    digitalWrite(wt,HIGH);
    digitalWrite(bl,LOW);
  }
  else 
  {
    digitalWrite(rd,LOW);
    digitalWrite(wt,LOW);
    digitalWrite(bl,HIGH);
  }
  delay(1000);
}
