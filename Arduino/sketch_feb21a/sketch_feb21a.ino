byte data[5];
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

  Serial.write(0xFF);
  Serial.write(0x01);
  Serial.write(0x09);
  Serial.write(0x87);
  Serial.write(0x01);
  Serial.write(0x03);
  Serial.write(0x02);
  Serial.write(0x00);
  Serial.write(0x10);
  Serial.write(0x20);
  Serial.write(0x30);
  Serial.write(0x40);
  Serial.write(0x37) ;

  delay(500);
  Serial.flush();
  Serial.println();
  Serial.println("RFID module started in Auto Read Mode, Waiting for Card...");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = Serial.read();
  while(val != 0xff){
    val = Serial.read();
    delay(1000);
  }

  Serial.read();
  Serial.read();
  Serial.read();
  data[0] = Serial.read();
  data[1] = Serial.read();
  data[2] = Serial.read();
  data[3] = Serial.read();
  data[4] = Serial.read();
  Serial.read();
  
  Serial.print("Card found - Code: ");
  for(int i = 0; i<5; i++){
    if (data[i] < 16) Serial.print("0");
    Serial.print(data[i], HEX);
  }
  Serial.println();
  

}
