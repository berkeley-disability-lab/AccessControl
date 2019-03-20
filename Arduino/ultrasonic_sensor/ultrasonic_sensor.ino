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

void set_tone(float time_interval){
    tone(buzzer, 1000);
    delay(time_interval*1000);
    noTone(buzzer);
    delay(time_interval*1000);  
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

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*sound_speed/2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  beep(distance);
 
}
