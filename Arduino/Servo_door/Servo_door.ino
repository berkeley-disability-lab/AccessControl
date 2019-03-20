#include <Servo.h>
int button = 8;

Servo myservo; 

void setup() {
  
  pinMode(button, INPUT);
  digitalWrite(button, LOW);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(button));
   if(digitalRead(button)){
      open_door();
  }
}



void open_door(){
    myservo.write(0);
    myservo.write(95);
    myservo.write(0);
}
