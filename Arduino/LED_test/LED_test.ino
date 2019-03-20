#include <Servo.h>
int button = 8;
int led = 9;
int state = 1;

Servo myservo; 

void setup() {
  
  pinMode(button, INPUT);
  digitalWrite(button, LOW);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(digitalRead(button));
   if(digitalRead(button)){
      open_door();
  }
}



void open_door(){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
}
