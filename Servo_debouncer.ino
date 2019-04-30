//debounce code from Arduino.cc

#include <Servo.h>

int buzzer = 6;
int red_led = 13;
int green_led = 12;
int auth = 8;
int denied = 7;
int angle = 0; 
Servo myservo;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;

void setup() {

  pinMode(auth, INPUT);
  digitalWrite(auth, LOW);
  pinMode(denied, INPUT);
  digitalWrite(denied, LOW);
  pinMode(red_led, OUTPUT);
  digitalWrite(red_led, LOW);
  pinMode(green_led, OUTPUT);
  digitalWrite(green_led, LOW);
  myservo.attach(9);
  myservo.write(angle);
  Serial.begin(9600);
  
}

void loop() {
  
  int reading = digitalRead(auth);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState) {
            blink(green_led);
            open_door();
      }
    }
  }
  
  if(digitalRead(denied)){
    blink(red_led);
  }
  

}

void blink(int led){
  digitalWrite(led, HIGH);
  delay(150);
  digitalWrite(led, LOW);
}

void open_door(){
    tone(buzzer, 1000, 500);
    myservo.write(0);
    delay(1000);
    myservo.write(95);
    delay(500);
    myservo.write(0);
}

