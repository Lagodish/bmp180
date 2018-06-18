#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <iarduino_Pressure_BMP.h>                          // Подключаем библиотеку iarduino_Pressure_BMP для работы с датчиками атмосферного давления BMP180 или BMP280.
iarduino_Pressure_BMP sensor;       
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
	// initialize the LCD
 Serial.begin(115200);
	lcd.begin();
sensor.begin();  
	// Turn on the blacklight and print a message.
  lcd.backlight();

}

void loop()
{
     
    if(sensor.read(1))       {
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print(String(sensor.pressure) + " MM.PT.CT ");
      lcd.setCursor(0,1);
      lcd.print("T = " + String(sensor.temperature) + " C");
      Serial.println((String)"CEHCOP BMP" + sensor.type + ": \t P = " + sensor.pressure + "\tMM.PT.CT, \t T = " + sensor.temperature + " *C, \t\t B = "+sensor.altitude+" M.");}
    else                     {Serial.println("HET OTBETA OT CEHCOPA");
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("Vse xyinya davay");
      lcd.setCursor(0,1);
      lcd.print("po novoy!");
    }
    
    
//  Считываем данные и выводим: температуру в °С и давление в Па, давление в мм. рт. ст., изменение высоты относительно указанной в функции begin(по умолчанию 0 метров).
    if(sensor.read(2))       {Serial.println((String)"CEHCOP BMP" + sensor.type + ": \t P = " + sensor.pressure + "\tPa, \t\t T = "     + sensor.temperature + " *C, \t\t B = "+sensor.altitude+" M.");}
    else                     {Serial.println("HET OTBETA OT CEHCOPA");}
    
    delay(5000);
}
