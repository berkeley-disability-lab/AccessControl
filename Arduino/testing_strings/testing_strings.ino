String a = "Hey";
String b = "banana!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String c = a*3;
  Serial.println(c);
}
