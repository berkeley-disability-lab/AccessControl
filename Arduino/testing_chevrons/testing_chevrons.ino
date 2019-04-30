#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


const float max_distance = 90; //cm
const int lcd_width = 16;
const float distance = 40; //cm

int n_chevrons = 0;

String create_string(char c, int string_length){

  String chevrons = "";
  
  for(int i = 0; i < string_length; i++){
       chevrons += c;
  }
  return chevrons;

}


void display_chevrons(){
  
  int n_chevrons = int(lcd_width * distance/max_distance); //proportion
  
  String left = create_string('>', n_chevrons/2);
  String right = create_string('<', n_chevrons/2);
  
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


void setup()
{

  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

}


void loop()
{
  n_chevrons = int(lcd_width * distance/max_distance); //proportion
 
  
  String left = create_string('>', n_chevrons/2);
  String right = create_string('<', n_chevrons/2);

  Serial.print("left: ");
  Serial.println(left);
  Serial.print("right: ");
  Serial.println(right); 
  
}
