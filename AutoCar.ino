// Pin definitions
#define solpwm1 9
#define solpwm2 10
#define sagpwm1 3
#define sagpwm2 11
#define solsensor A1
#define sagsensor A4
#include <Servo.h>
Servo steering_system;
const int trigPin = 8;
const int echoPin = 12;
int forward=113;
int right=132;
int left=93;
// defines variables
long duration;
int distance;
void setup() 
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(solpwm1, OUTPUT); // Sets the trigPin as an Output
pinMode(solpwm2, OUTPUT); // Sets the trigPin as an Output
pinMode(sagpwm1, OUTPUT); // Sets the trigPin as an Output
pinMode(sagpwm2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
steering_system.attach(A0);
  steering_system.write(forward);
Serial.begin(9600); // Starts the serial communication
setSpeed(150,1,100);

}
void loop() {
//   setSpeed(150, 1, 1);
//  int mesafe= getDistance();
//   if(mesafe<30){
//     steering_system.write(right);
//     delay(400);
//     steering_system.write(forward);
//   }
delay(500);
steering_system.write(right);
  delay(800);
     steering_system.write(forward);
  // steering_system.write(forward);
}
void setSpeed(int speed,int direction,int time){
  if(direction==0){
    analogWrite(solpwm1,200);
    analogWrite(sagpwm1,200);
    digitalWrite(solpwm2,LOW);
    digitalWrite(sagpwm2,LOW);
  }else{
    analogWrite(solpwm2,200);
    analogWrite(sagpwm2,200);
    digitalWrite(solpwm1,LOW);
    digitalWrite(sagpwm1,LOW); 
  }
  delay(time);
}
int getDistance(){
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
// Prints the distance on the Serial Monitor
Serial.print("Distance from the object = ");
Serial.print(distance);
Serial.println(" cm");
delay(100);
return distance;
}

void servodeyish(int last,int newv){
  if(last<newv){
    for(int i=last;i<newv;i++){
          steering_system.write(i);
          delay(1);
    }
  }else{
     for(int i=newv;i<last;i++){
          steering_system.write(i);
          delay(1);
    }
  }

}
