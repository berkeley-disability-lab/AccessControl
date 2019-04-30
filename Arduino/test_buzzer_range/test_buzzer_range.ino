const int buzzer = 7; //buzzer to arduino pin 3

const float close_distance = 0.1; //seconds
const float medium_distance = 0.5; //seconds
const float far_distance = 1; //seconds

void beep(float time_interval){
  
    tone(buzzer, 1000);
    delay(time_interval*1000);
    noTone(buzzer);
    delay(time_interval*1000);
}

void setup() {

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  
  beep(medium_distance);
 
}
