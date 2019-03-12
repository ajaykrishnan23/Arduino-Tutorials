int switchp = 3;
int led = 2;
int led2 = 4;
int led3 = 6;
int c = 0;
boolean prevbut = LOW;
boolean ledon = false;
boolean currentbut = LOW;
boolean arr[3];
void setup() {
  // put your setup code here, to run once:
  pinMode(switchp,INPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(switchp);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchp);
  }
  return current;
}

void oct2bin(int c)
{
  switch(c)
  {
    case 0:
      {
        arr[0] = LOW;
        arr[1] = LOW;
        arr[2] = LOW;
      }
      break;
     case 1:
       {
          arr[0] = LOW;
          arr[1] = LOW;
          arr[2] = HIGH;
       }
       break;
      case 2:
        {
           arr[0] = LOW;
           arr[1] = HIGH;
           arr[2] = LOW;
        }
        break;
       case 3:
        {
            arr[0] = LOW;
            arr[1] = HIGH;
            arr[2] = HIGH;
        }
        break;
        case 4:
        {
            arr[0] = HIGH;
            arr[1] = LOW;
            arr[2] = LOW;
        }
        break;
        case 5:
        {
            arr[0] = HIGH;
            arr[1] = LOW;
            arr[2] = HIGH;
        }
        break;  
        case 6:
        {
            arr[0] = HIGH;
            arr[1] = HIGH;
            arr[2] = LOW;
        }
        break;
        case 7:
        {
            arr[0] = HIGH;
            arr[1] = HIGH;
            arr[2] = HIGH;
        }
        break;
        
      
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  currentbut = debounce(prevbut);
  if (prevbut == LOW && currentbut == HIGH)
  {
    ledon = !ledon;
    c += 1;
    c %= 8;
    oct2bin(c);
    digitalWrite(led,arr[0]);
    digitalWrite(led2,arr[1]);
    digitalWrite(led3,arr[2]);
    Serial.println(c);
  }
    prevbut = currentbut;
    
}
