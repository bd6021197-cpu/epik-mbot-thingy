#include <Arduino.h>
#include <MeMCore.h>

MeUltrasonicSensor ultraSonic(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
float turned_right = false;

void forward(){
  motor1.run(-100);
  motor2.run(100);
}

void turn_right(){
  motor1.run(100);
  motor1.run(100);
  delay(560);
}

void turn_180(){
  motor1.run(100);
  motor1.run(100);
  delay(1120);
  turned_right = false;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  if (ultraSonic.distanceCm() > 10){
    forward();
  } else {
    if (turned_right){
      turn_180();
    } else {
      turn_right();
      turned_right = true;
    }
  }
}