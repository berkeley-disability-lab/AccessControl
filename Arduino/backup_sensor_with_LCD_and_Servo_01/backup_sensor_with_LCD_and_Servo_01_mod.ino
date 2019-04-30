/*
 *   Undergraduate Research Apprentice Program (URAP) 
 *   Prof. Karen Nakamura
 *   
 *   File: bakcup_sensor_with_LCD_03.ino
*   Author(s): Enrico Cruvinel (Email: enrico.cruvinel@berkeley.edu) & Nathan Tilton (Email: nathantilton82@berkeley.edu)
 *   
 *   Description: An ultrasonic sensor calculates the distance between itself and an object in front of it. 
 *   Remarks: 
 *   
*/



#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo;

const float max_distance = 80; //cm
const int lcd_width = 16;

const int echoPin = 9;
const int trigPin = 8;
const int buzzer = 7;

const float close_time = 0.1; //seconds
const float medium_time = 0.5; //seconds
const float far_time = 1; //seconds

const float close_distance = 30; //cm
const float medium_distance = 60; //cm
const float far_distance = 90; //cm

const float sound_speed = 0.034; //cm/us

long duration;
int distance;

int close_rot_speed = 1;
int medium_rot_speed = 3;
int far_rot_speed = 6;

void rotation_speed(int rot_speed){
  for (int i = 0; i < 180; i++){
    servo.write(i);
    delay(rot_speed);
  }  
  for (int i = 180; i > 0; i--){
    servo.write(i);
    delay(rot_speed);
  }  
}

void rotate(float distance){
  
  if (distance <= close_distance){
    rotation_speed(close_rot_speed);
  }
  else if(distance <= medium_distance){
    rotation_speed(medium_rot_speed);
  }
  else if(distance <= far_distance){
    rotation_speed(far_rot_speed);
  }
}


String create_string(char c, int string_length){

  String chevrons = "";
  
  for(int i = 0; i < string_length; i++){
       chevrons += c;
  }
  return chevrons;

}


void set_tone(float time_interval, float default_tone = 1000){
    tone(buzzer, default_tone);
    delay(time_interval*1000);
    noTone(buzzer);
    delay(time_interval*1000);  
}

void display_chevrons(int distance){
  
  int total_chevrons = lcd_width - int(lcd_width * distance/max_distance); //proportion
  total_chevrons = total_chevrons <= lcd_width ? total_chevrons : 16;
  
  lcd.clear();
  
  String left = create_string('>', total_chevrons/2);
  String right = create_string('<', total_chevrons/2);
  
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print(left);
  lcd.setCursor(0,1);
  lcd.print(left);
  
  lcd.rightToLeft();
  lcd.setCursor(15,0);
  lcd.print(right);
  lcd.setCursor(15,1);
  lcd.print(right);
  
}

void beep(float distance){
  
  if (distance <= close_distance){
    set_tone(close_time);
  }
  else if(distance <= medium_distance){
    set_tone(medium_time);
  }
  else if(distance <= far_distance){
    set_tone(far_time);
  }
    
}

long calculate_time(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Datasheet: Using IO trigger for at least 10us high level signal
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH)/2;
}

int calculate_distance(float time_interval, float spd = sound_speed){

  return distance = time_interval*sound_speed;

}

void setup() {
  
  lcd.begin();
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);

  servo.attach(3);
  servo.write(90);

}

void loop() {

  distance = calculate_distance(calculate_time());
  
  display_chevrons(distance);
 
  beep(distance);

  Serial.print("Distance: ");
  Serial.println(distance);

  rotate(distance);

}
