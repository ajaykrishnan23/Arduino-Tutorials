int switchp1 = 2;
int switchp2 = 3;
int l1 = 4;
int l2 = 5;
int l3 = 6;
int led = 4;
boolean prevbut1 = LOW;
boolean ledon = false;
boolean currentbut1 = LOW;
boolean prevbut2 = LOW;
//boolean ledon = false;
boolean currentbut2 = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchp1,INPUT);
  pinMode(switchp2,INPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  digitalWrite(4,HIGH);
  Serial.begin(9600);
}
boolean debounce(boolean last,int switchp)
{
  boolean current = digitalRead(switchp);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchp);
  }
  return current;
}
void loop() {
  currentbut1 = debounce(prevbut1,switchp1);
  currentbut2 = debounce(prevbut2,switchp2);
  
  if(prevbut1 == LOW && currentbut1 == HIGH) //1 is button to toggle right
  { 
    digitalWrite(led,!digitalRead(led));
    led = (led + 1)%4+4;
    if(led>6)
      led = 4;
    digitalWrite(led,!digitalRead(led));
    Serial.println("First");
  }
  prevbut1 = currentbut1;
  if(prevbut2 == LOW && currentbut2 == HIGH)
  {
    digitalWrite(led,!digitalRead(led));
    Serial.println(led);
    led = (led - 1)%4+4;
    if(led>6)
      led = 6;
    digitalWrite(led,!digitalRead(led));
    Serial.println(led);
    Serial.println("Second");
  }
  prevbut2 = currentbut2;
}
