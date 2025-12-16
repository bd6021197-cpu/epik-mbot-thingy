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
  motor1.stop();
  motor2.stop();
  motor1.run(105);
  motor2.run(105);
  delay(550);
}

void turn_left(){
  motor1.stop();
  motor2.stop();
  motor1.run(-105); 
  motor2.run(-105);
  delay(550);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");
  if (ultraSonic.distanceCm() >  8){
    forward(); //go forward until there is a wall
  } else {
    if (turned_right == false){
      turn_right(); //if the mBot hasn't tried turning right yet, turn right
      if (ultraSonic.distanceCm() <=  8){
        turned_right = true;
        turn_left(); //if the mBot tried turning right and there is still a wall infront of it do a left turn
      }
    } else {
      turn_left(); // try the left path
      turned_right = false; 
    }
  }
}
