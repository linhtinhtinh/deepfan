#include <Arduino.h>
#define trig 10 
#define echo 11
int distance;
long runtime;
#define in3 7
#define in4 8
#define enb 9



void setup(){
    Serial.begin(9600); 
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(enb,OUTPUT); 
}



void loop(){

    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(5);
    digitalWrite(trig,LOW);



    runtime = pulseIn(echo,HIGH);//thoi gian nhan lai song am
    distance= int(runtime/2/29.412);

    if(distance<=30)
    {
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enb,255);
    }
    else if(distance>30)
    {
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enb,0);
    }


    Serial.println(distance);
    delay(400);

}