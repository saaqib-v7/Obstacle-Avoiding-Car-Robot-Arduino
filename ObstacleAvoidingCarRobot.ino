#include <Servo.h>

Servo myservo;  // create servo object to control a servo  your servo is called myservo
const int trigPin = 5; // this goes to the trig pin 
const int echoPin = 4;// this goes to the echo pin
int dis1,dis2;


long duration;
int distance;



void setup() {
 
  myservo.attach(7);  // attch your servo to pin 7
  
  myservo.write(90);  // the servo will fo to angle 90
 
pinMode(9,OUTPUT); //   LEFT MOTOR   BACKWARD
pinMode(10,OUTPUT);//   LEFT MOTOR FORWARD
pinMode(11,OUTPUT);//     RIGHT MOTOR BACKWARD
pinMode(12,OUTPUT);//   RIGHT MOTOR  FORWARD

 
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}

void loop() {
  dis();
 

forward();


if ((dis())<20){
  stops();
     myservo.write(0); 
     delay(500);
     dis1= dis();
  if (dis1>15){
     myservo.write(90); 
     delay(500);
     while( dis()<20){
      right();
      delay(100);
      dis();}
     }
    
  if( dis1<20){
      myservo.write(180); 
      delay(500);
      dis2 =dis(); 
        
     if( dis2>20){
       myservo.write(90); 
       delay(500);
       while(dis()<15){
        left();
        delay(100);
        dis();}
     }
     if( dis2<20) {
       myservo.write(90); 
       delay(500);
      while( dis()<20){
        left();
        delay(100);
        dis();}
     }
  }
}
}

int dis(){ // this function gives you the distance in CM
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return(distance);

}
void forward(){
digitalWrite(12,1);
digitalWrite(10,1);
digitalWrite(11,0);
digitalWrite(9,0);
}

 void  backward(){
digitalWrite(12,0);
digitalWrite(10,0);
digitalWrite(11,1);
digitalWrite(9,1);
}

void left(){
  digitalWrite(11,0);
  digitalWrite(9,1);
  digitalWrite(12,1);
  digitalWrite(10,0);}
 void right(){
  digitalWrite(12,0);
  digitalWrite(10,1);
  digitalWrite(11,1);
  digitalWrite(9,0);}

 void stops(){
  digitalWrite(12,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
  digitalWrite(9,0);}