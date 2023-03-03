#include<SoftwareSerial.h>
//M1
int M1_RIS = 3;
int M1_REN = 2;
int M1_RPWM = 5;
int M1_LIS = 13;
int M1_LEN = 4;
int M1_LPWM = 6;

//M2
int M2_RIS = 9;
int M2_REN = 7;
int M2_RPWM = 11;
int M2_LIS = 0;
int M2_LEN = 1;
int M2_LPWM = 10;

int receiver_pins[] = {A0, A1, A2, A3, A4, A5};
int receiver_values[] = {0, 0, 0, 0, 0, 0};
int res_min = 1100;
int res_max = 1900;

int working_range = 255;// motor driver range

boolean prt = true;

int mode = 0;
//-1 - transmeter not connected or out of range
//0- trans connected and ready
//1 - low speed
//2 = high speed mode


SoftwareSerial mySerial(2, 3); // RX, TX

String data;
int btVal;

void setup() 
{  
  //Serial.begin(115200);
  
  pinMode(M1_RIS, OUTPUT);
  pinMode(M1_REN, OUTPUT);
  pinMode(M1_RPWM, OUTPUT);
  pinMode(M1_LIS, OUTPUT);
  pinMode(M1_LEN, OUTPUT);
  pinMode(M1_LPWM, OUTPUT);
  digitalWrite(M1_RIS, LOW);
  digitalWrite(M1_LIS, LOW);
  digitalWrite(M1_LEN, HIGH);
  digitalWrite(M1_LEN, HIGH);
  
  pinMode(M2_RIS, OUTPUT);
  pinMode(M2_REN, OUTPUT);
  pinMode(M2_RPWM, OUTPUT);
  pinMode(M2_LIS, OUTPUT);
  pinMode(M2_LEN, OUTPUT);
  pinMode(M2_LPWM, OUTPUT);
  digitalWrite(M2_RIS, LOW);
  digitalWrite(M2_LIS, LOW);
  digitalWrite(M2_LEN, HIGH);
  digitalWrite(M2_LEN, HIGH);
  mySerial.begin(9600);
}

void loop()
{
 while (mySerial.available())
 {  
  {  
      data = mySerial.readStringUntil('\n');
      //Serial.print(str);             
  } 
    
    btVal = (data.toInt());
    //Serial.print("BlueTooth Value ");
    //Serial.println(btVal);    



  switch (btVal) 
   {
      case 1:                                
        //Serial.println("Forward");
        forward();
        break;

      case 2:                 
       //Serial.println("Reverse");
        reverse();
        break;

      case 3:         
       //Serial.println("Left");
        left();
        break;
        
      case 4:                     
        //Serial.println("Right");
        right();
        break;
        
      case 5:                                            
        //Serial.println("Stop");
        stoprobot();
        break;      

  }

 } 
 
                                                              
   if (mySerial.available() < 0)                              
    {
     //Serial.println("No Bluetooth Data ");          
    }
  
}

void forward()
{
   analogWrite(M1_RPWM, 255);
   analogWrite(M1_LPWM, 0);
   analogWrite(M2_RPWM, 255);
   analogWrite(M2_LPWM, 0);
}

void reverse()
{
   analogWrite(M1_RPWM, 0);
   analogWrite(M1_LPWM, 255);
   analogWrite(M2_RPWM, 0);
   analogWrite(M2_LPWM, 255);
}

void left()
{
   analogWrite(M1_RPWM, 0);
   analogWrite(M1_LPWM, 127);
   analogWrite(M2_RPWM, 0);
   analogWrite(M2_LPWM, 255); 
}

void right()
{
   analogWrite(M1_RPWM, 0);
   analogWrite(M1_LPWM, 255);
   analogWrite(M2_RPWM, 0);
   analogWrite(M2_LPWM, 127); 
}

void stoprobot()
{
   analogWrite(M1_RPWM, 0);
   analogWrite(M1_LPWM, 0);
   analogWrite(M2_RPWM, 0);
   analogWrite(M2_LPWM, 0); 
}
