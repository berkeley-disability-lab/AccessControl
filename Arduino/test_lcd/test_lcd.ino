#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int n = 1;

void display1(){
  
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("hi");

  
  lcd.rightToLeft();
  lcd.setCursor(15,0);
  lcd.print("01234567891234");
  
}

void display2(){
  
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("hello");
  
}

void setup()
{

  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

}


void loop()
{
  if(n==1){
    display1();  
  }else{
    display2(); 
  }
  delay(2000);
  n+=1;
  
  
}
