int rd = 2;
int bl = 4;
int wt = 11;
String str = "";
char c;
boolean intch = LOW;
boolean stch = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(rd,OUTPUT);
  pinMode(bl,OUTPUT);
  pinMode(wt,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {
    c = Serial.read();
    if (c != '\n')
    {
      str += c;
    }
    else
    {
      str +='\n';
      int i = 0;
      while(str[i] != '\n')
      {
        if (str[i]>='0' && str[i]<='9')
          intch = HIGH;
        else if(str[i] >= 'A' && str[i] <='z')
          stch = HIGH;
        i++;
      }
      str = "";
      //Serial.println(i);
      
      if ((intch == HIGH && stch == HIGH)) 
       { 
        digitalWrite(wt,intch);
        delay(1000);
        intch = LOW;
        stch = LOW;
        digitalWrite(wt,intch);
        Serial.println(1);
       }

      else if(stch == HIGH && i>=5)
      {
        digitalWrite(bl,stch);
        stch = LOW;
        delay(1000);
        digitalWrite(bl,stch);
        Serial.println(2);
      }
      else if(intch == HIGH)
      {
        digitalWrite(rd,intch);
        delay(1000);
        intch = LOW;
        digitalWrite(rd,intch);
        Serial.println(3);
      }
       else //if(i<5 && stch == HIGH)
      {
        digitalWrite(wt,stch);
        delay(1000);
        intch = LOW;
        stch = LOW;
        digitalWrite(wt,stch);
        Serial.println(1);
      }
    }
  }
  
}
