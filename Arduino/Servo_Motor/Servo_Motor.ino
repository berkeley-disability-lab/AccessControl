#include <Servo.h>
 
Servo servo;        //initialize a servo object for the connected servo       
int angle = 0;    

const float close_distance = 30; //cm
const float medium_distance = 60; //cm
const float far_distance = 90; //cm

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

    
void setup() 
{ 
  servo.attach(9);
  servo.write(90);// attach the signal pin of servo to pin9 of arduino
} 

void loop() 
{ 
//  rotate(close_distance);
//rotate(medium_distance);
rotate(far_distance);
}
