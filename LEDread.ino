#define A 22
#define B 23
#define C 24
#define D 25
#define E 26
#define AF 27
#define F 27



byte inbyte;
char inchar;
String serialDataIn;
int LEDVal;

void setup()
{
  initialize();
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available()>0){
  LEDVal=serReadInt().toInt();
  }

  for (int i=1; i<=LEDVal;i++)
  {
    writeLED(i);
  }


}



String serReadInt()
{
  int i, serAva;                           // i is a counter, serAva hold number of serial available
  String serialData;    
  if (Serial.available()>0)            // Check to see if there are any serial input
  {
    delay(5);                              // Delay for terminal to finish transmitted
                                               // 5mS work great for 9600 baud (increase this number for slower baud)
    serAva = Serial.available();  // Read number of input bytes
    for (i=0; i<serAva; i++) {      // Load input bytes into array
          inbyte=Serial.read();
          inchar = char(inbyte);
          serialData += inchar;
    }
    return serialData;
  }
 else return ""; 
}
  
  
  

void initialize()
{
  for (int i=22;i<28;i++)
  {
    pinMode(i,INPUT);
    digitalWrite(i,LOW);
  }
}

void writeLED(int number)
{
  initialize();
  switch (number){
  case 1:
    pinMode(A,OUTPUT);
    pinMode(C,OUTPUT);
    digitalWrite(A,HIGH);
    digitalWrite(C,LOW);
    break;
  case 2:
    pinMode(C,OUTPUT);
    pinMode(A,OUTPUT);
    digitalWrite(C,HIGH);
    digitalWrite(A,LOW);
    break;
  case 3:
    pinMode(A,OUTPUT);
    pinMode(D,OUTPUT);
    digitalWrite(A,HIGH);
    digitalWrite(D,LOW);
    break;
  case 4:
    pinMode(D,OUTPUT);
    pinMode(A,OUTPUT);
    digitalWrite(D,HIGH);
    digitalWrite(A,LOW);
    break;
  case 5:
    pinMode(A,OUTPUT);
    pinMode(E,OUTPUT);
    digitalWrite(A,HIGH);
    digitalWrite(E,LOW);
    break;
  case 6:
    pinMode(E,OUTPUT);
    pinMode(A,OUTPUT);
    digitalWrite(E,HIGH);
    digitalWrite(A,LOW);
    break;
  case 7:
    pinMode(E,OUTPUT);
    pinMode(AF,OUTPUT);
    digitalWrite(E,HIGH);
    digitalWrite(AF,LOW);
    break;
  case 8:
    pinMode(AF,OUTPUT);
    pinMode(E,OUTPUT);
    digitalWrite(AF,HIGH);
    digitalWrite(E,LOW);
    break;
  case 9:
    pinMode(D,OUTPUT);
    pinMode(E,OUTPUT);
    digitalWrite(D,HIGH);
    digitalWrite(E,LOW);
    break;
  case 10:
    pinMode(E,OUTPUT);
    pinMode(D,OUTPUT);
    digitalWrite(E,HIGH);
    digitalWrite(D,LOW);
    break;
  case 11:
    pinMode(C,OUTPUT);
    pinMode(D,OUTPUT);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
  case 12:
    pinMode(D,OUTPUT);
    pinMode(C,OUTPUT);
    digitalWrite(D,HIGH);
    digitalWrite(C,LOW);
    break;
  case 13:
    pinMode(C,OUTPUT);
    pinMode(B,OUTPUT);
    digitalWrite(C,HIGH);
    digitalWrite(B,LOW);
    break;
  case 14:
    // pinMode(B,OUTPUT);
    // pinMode(C,OUTPUT);
    // digitalWrite(B,HIGH);
    // digitalWrite(C,LOW);
    break;
  case 15:
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    break;
  case 16:
    pinMode(B,OUTPUT);
    pinMode(A,OUTPUT);
    digitalWrite(B,HIGH);
    digitalWrite(A,LOW);
    break;

  }
}






