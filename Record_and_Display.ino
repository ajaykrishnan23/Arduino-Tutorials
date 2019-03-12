int switchp1 = 2, switchp2 = 3;
int led = 5,c = 0;
boolean prevbut1 = LOW;
boolean check = false;
boolean currentbut1 = LOW;
boolean prevbut2 = LOW;
boolean currentbut2 = LOW;
long onarr[20],offarr[20];
int i = 0,j = 0,count = 0,k,l;
long starttime=0;
long timeelapsed,stoptime;
void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
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
void loop()
{
  x1:
  currentbut2 = debounce(prevbut2,switchp2);
  if(prevbut2 == LOW && currentbut2 == HIGH)
  {
    count++;
    if(count%2 != 0)
    {
    
        long onarr[20],offarr[20];
        Serial.println("Start");
    }
    
  }
  prevbut2 = currentbut2;
  if(count>0)
  {
    if(digitalRead(switchp1) == HIGH)
    {
    starttime = millis();
    while(digitalRead(switchp1) == HIGH)
    {
      timeelapsed = millis();
    }
  stoptime = timeelapsed-starttime;
  onarr[i%20] = stoptime;
  Serial.print("Ontime");
  Serial.println(stoptime);
    i++;
    check = true;
    }

    starttime = millis();
   while(millis()-starttime<=1000)
   {
   if(check == true)
   {
      currentbut2 = debounce(prevbut2,switchp2);
      if(prevbut2==LOW && currentbut2== HIGH)
        {
          count++;
          prevbut2 = currentbut2;
          goto x;
        }
   }
  prevbut2 = currentbut2;
   }
   
   
   
    if(digitalRead(switchp1) == LOW)
    {
      starttime = millis();
      while(digitalRead(switchp1) == LOW)
      {
        timeelapsed = millis();
      }
      stoptime = timeelapsed-starttime;
      offarr[i%20] = stoptime;
      Serial.print("Offtime");
      Serial.println(stoptime);
      j++;
      check = true;
    }
    starttime = millis();
   while(millis()-starttime<=1000)
   {
   if(check == true)
   {
      currentbut2 = debounce(prevbut2,switchp2);
      if(prevbut2==LOW && currentbut2== HIGH)
        {
          count++;
          prevbut2 = currentbut2;
        }
   }
  prevbut2 = currentbut2;
   
   }
  }
    
  x:
  if(count%2==0&&check == true)
  {
    k = 0;
    l = 0;
  while(k<i && l<j)
  {
    digitalWrite(led,HIGH);
    delay(onarr[k%20]);
    k++;
    digitalWrite(led,LOW);
    delay(offarr[l%20]);
    l++; 
  }
  if(k<i&& l>=j)
  {
    while(k<i)
    {
      digitalWrite(led,HIGH);
      delay(onarr[k%20]);
      k++;
    }
  }
  if(l<j&&k>=i)
  {
    while(l<j)
    {
    digitalWrite(led,LOW);
    delay(offarr[l%20]);
    l++;
    }
    }
    Serial.println("Sequence done");
    count = -1;
    check = false;
    digitalWrite(led,LOW);
    goto x1;
  }
 
}
  
