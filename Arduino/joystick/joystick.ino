int x = A0;
int y = A1;
int button = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH); //pullup resistor: source: https://arduino.stackexchange.com/questions/186/button-state-changing-randomly
  Serial.begin(9600);
}

void display_states(){
  Serial.print("button: ");
  Serial.print(digitalRead(button));
  Serial.print("  X: ");
  Serial.print(analogRead(x));
  Serial.print("  Y: ");
  Serial.println(analogRead(y));
}
void loop() {
  // put your main code here, to run repeatedly:
  display_states();
}
