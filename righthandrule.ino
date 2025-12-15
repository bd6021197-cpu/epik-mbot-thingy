#include <Arduino.h>
#include <MeMCore.h>

MeUltrasonicSensor ultraSonic(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
float turned_right = false;
float go_forward = true;

void forward(){
  motor1.run(-100);
  motor2.run(100);
}

void turn_right(){
  motor1.stop();
  motor2.stop();
  go_forward = false;
  motor1.run(-100);
  motor2.run(-100);
  delay(555);
  go_forward = true;
}

void turn_180(){
  motor1.stop();
  motor2.stop();
  go_forward = false;
  motor1.run(-100);
  motor2.run(-100);
  delay(1110);
  turned_right = false;
  go_forward = true;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  if (ultraSonic.distanceCm() >  10){
    if (go_forward){
      forward();
    }
  } else {
    if (turned_right){
      turn_180();
    } else {
      turn_right();
      turned_right = true;
    }
  }
}
