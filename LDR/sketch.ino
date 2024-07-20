#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the LDR pin
#define LDR_PIN 34

// Initialize the LCD with the I2C address (0x27 or 0x3F, depending on your LCD)
LiquidCrystal_I2C LCD(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  
  // Initialize the LCD
  LCD.init();
  LCD.backlight();

  // Connect to Wi-Fi
  WiFi.begin("Wokwi-GUEST", "", 6);

  // Display initial message
  LCD.clear();
  LCD.print("Connected");
  delay(2000);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN); // Read the analog value from the LDR
  
  // Display LDR value on LCD
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("LDR Value:");
  LCD.setCursor(0, 1);
  LCD.print(ldrValue);

  // Print LDR value to Serial Monitor for debugging
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  delay(1000); // Delay for stability
}
