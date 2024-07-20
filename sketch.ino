#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C LCD(0x27, 16, 2);
#define DHTPIN 14
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  LCD.init();
  LCD.backlight();
  
  WiFi.begin("Wokwi-GUEST", "", 6);
  LCD.clear();
  LCD.print("Online");
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.printf("Temperature: %.2f°C\n", t);

  LCD.setCursor(0, 0);
  LCD.printf("Temp: %.2f C", t);

  delay(1000);
  LCD.clear();
}
