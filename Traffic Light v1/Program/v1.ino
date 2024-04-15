//import library for lcd
#include <LiquidCrystal.h>

//Intializing Pin number to the traffic light color
int green = 0;
int yellow = 1;
int red = 2;

//Delays for each color (in ms)
int delay_green = 1000;
int delay_yellow = 1000;
int delay_red = 1000;

//Initializing the pins for the lcd
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:

  //set up lcd columns and row (dimensions)
  lcd.begin(16, 2);

  //print a message 
  lcd.print("Made by Clyde");

  //Define the LED as output
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //turn off all lights and delay
  no_light();
  delay(1000);

  //initialize lcd
  lcd.display();
  lcd.clear();

  //turn on red
  red_light();
  delay(delay_red);
  lcd.print("STOP");
  delay(1000);
  lcd.clear();

  //turn on yellow
  yellow_light();
  delay(delay_yellow);
  lcd.print("WAIT");
  delay(1000);
  lcd.clear();

  //turn on green
  green_light();
  delay(delay_green);
  lcd.clear();
  lcd.print("GO");
  delay(1000);
  lcd.clear();

}

//other functions

//turn off all lights
void no_light(){

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

}

//turn on a specific color
void red_light(){

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);

}

void yellow_light(){

  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  
}

void green_light(){

  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  
}
