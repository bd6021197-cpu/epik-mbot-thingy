#include <Arduino.h>
#include <MeMCore.h>

MeRGBLed led(0,30); 

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

int forward(int ammount){
  motor1.run(-100); // Can be an int from -255 to 255
  motor2.run(100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}

int left(int ammount){
  motor1.run(100); // Can be an int from -255 to 255
  motor2.run(100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}
int right(int ammount){
  motor1.run(-100); // Can be an int from -255 to 255
  motor2.run(-100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}

int backward(int ammount){
  motor1.run(100); // Can be an int from -255 to 255
  motor2.run(-100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}

int turn_around(int ammount){
  motor1.run(-100); // Can be an int from -255 to 255
  motor2.run(-100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}

void stop(){
  motor1.stop();
  motor2.stop();
  led.setColorAt(0,255,0,0);
  led.setColorAt(1,255,0,0);
  led.show();
}

void setup() {
  led.setpin(13);
  pinMode(A7,INPUT);
  while(analogRead(A7) !=0) ; // Start code when button pushed
  stop();
  delay(3100);
  forward(4750);
  stop();
  delay(3100);
  right(560);
  forward(3550);
  stop();
  delay(3100);
  left(490);
  forward(4450);
  stop();
  delay(3100);
  backward(1000);
  stop();
  delay(100);
  turn_around(1000);
  stop();

}

void loop() {
  // put your main code here, to run repeatedly:

}