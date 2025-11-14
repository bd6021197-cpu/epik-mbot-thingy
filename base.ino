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

int right(int ammount){
  motor1.run(100); // Can be an int from -255 to 255
  motor2.run(100);
  led.setColorAt(0,0,255,0);
  led.setColorAt(1,0,255,0);
  led.show();
  delay(ammount);
}
int left(int ammount){
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
  forward(1000);
  stop();
  delay(1000);
  backward(1000);
  stop();
  delay(1000);
  right(560);
  stop();
  delay(1000);
  left(560);
  stop();

}

void loop() {
  // put your main code here, to run repeatedly:

}