#include <LiquidCrystal.h>
//initialise the library with the numbers of the interface pins 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
 
int resval = 0;  // holds the value
int respin = A5; // sensor pin used
int motor = 9;  // motor pin 9
void setup() {
  // initialise motor pin as output 
 pinMode(motor,OUTPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); 
  
  // Print a message to the LCD. 
  lcd.print("WATER LEVEL: "); 
} 
  
void loop() { 
  // set the cursor to column 0, line 1 
  lcd.setCursor(0, 1); 
    
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=100){ lcd.println("Empty ") ;digitalWrite(motor,HIGH);}
   else if (resval>100 && resval<=300){ lcd.println("low ");digitalWrite(motor,HIGH); }  // turn on motor if water level is low
     else if (resval>300 && resval<=330){ lcd.println("Medium ") ;} 
        else if (resval>330){ lcd.println("High "); } 
  //delay(1000); //uncomment if delay is required 
}
