#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"

// DHT Pins
#define DHTPIN A0
#define DHTTYPE DHT11

// Modules Setup
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

int green = 8;

void setup() {
  // Begin Sensors & Modules
  Serial.begin(9600);
  dht.begin();
  lcd.init();

  // Light the backlight
  lcd.backlight();
  
  pinMode(green, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  lcd.setCursor(0 , 0);
  lcd.print("Temp: " + String(temp));
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(humid));

  digitalWrite(green, HIGH);
}
