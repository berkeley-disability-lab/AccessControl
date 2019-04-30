#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "URAP.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);


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

void display_chevrons(){
  
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

void calculate_time(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //arbitrary
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
}
void calculate_distance(){
  
  
  distance= duration*sound_speed/2;
}

void setup() {
  
  lcd.begin();
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {


  display_chevrons();
 
  beep(distance);

  Serial.print("Distance: ");
  Serial.println(distance);

}
