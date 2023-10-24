#include <Wire.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd_1(34,16,2); 
int soilsensore=0;
int minMoisture = 0;
int maxMoisture = 876;


void setup()
{
  lcd_1.init(); 
  lcd_1.backlight();
 
  
  
 }


void loop()
{
  soilsensore = analogRead(A0);
  int moisturePercentage = map(soilsensore, minMoisture, maxMoisture, 0, 100);

  
  if(soilsensore > 10){
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("System is ON");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Hello Mike !");
    delay(1000);
    lcd_1.clear();

    lcd_1.setCursor(0, 0);
    lcd_1.print("Moisture % :");
    lcd_1.setCursor(0, 1);
    lcd_1.print(moisturePercentage);
    delay(2000);
    lcd_1.clear();
    
  }else{
    lcd_1.setCursor(0, 0);
  	lcd_1.print("System is OFF");
    delay(2000);
  
  }
  
}

