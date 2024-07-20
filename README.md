# Electronics Task 3
This project demonstrates using the ESP32 microcontroller with an analog Light Dependent Resistor (LDR) and a digital DHT22 temperature and humidity sensor. 

## 1. Components
* ESP32
* LDR
* DHT22
* LCD (I2C)

### ESP32
The ESP32 is a microcontroller developed by Espressif Systems. It is known for having built-in Wi-Fi and Bluetooth, making it ideal for a wide range of Internet of Things (IoT) applications. The ESP32 integrates a dual-core CPU, numerous GPIOs, and various communication interfaces.

__Key Features__
* __Dual-Core Processor__: The ESP32 features a dual-core microprocessor that operates at 240 Mhz.

* __Memory__:
  * _RAM_: 520 KB of internal SRAM.
  * _Flash_: Typically comes with 4 MB of external flash memory.

* __Connectivity__:
   * _Wi-Fi_: IEEE 802.11 b/g/n.
   * _Bluetooth_: Bluetooth Classic (BR/EDR) and Bluetooth Low Energy (BLE).

* __GPIOs__:
  * _Total GPIO Pins_: 34 GPIO pins (PWM, ADC, DAC).
  * _Analog Inputs_: 18 channels with a 12-bit ADC for measuring analog       signals.
  * _Digital Outputs_: Capable of generating digital signals.
 
* __Communication Interfaces__:
  * _I2C_
  * _SPI_
  * _UART_
  * _CAN_

* __PWM__: Pulse Width Modulation outputs for controlling motors, LEDs, etc.

* __Power Supply__: 3.3V operating voltage. Directly powered through the 3.3V pin or regulated using an external 5V supply.

* __Development and Programming__: Can be programmed using the ESP-IDF (Espressif IoT Development Framework), Arduino IDE, or other compatible software.

* __Pinout and GPIO Functions__:

  The ESP32 offers a variety of GPIOs that can be configured for different functions. Key pins include:
  * _GPIO0_: Used for boot mode selection and can also be used as a general-purpose input/output.
  * _GPIO1 (TXD0)_: Transmit pin for UART0.
  * _GPIO3 (RXD0)_: Receive pin for UART0.
  * _GPIO21 (SDA)_: Default I2C data line.
  * _GPIO22 (SCL)_: Default I2C clock line.
  * _GPIO34 - GPIO39_: Input-only pins used for ADC input.
  For detailed pin configuration and alternate functions, refer to the ESP32 Pinout Diagram below.

  ![download](https://github.com/user-attachments/assets/c09c4058-6b13-49f0-84d1-c94f5061dc95)

### LDR (Light Dependent Resistor)
An LDR, or Light Dependent Resistor, is an analog sensor whose resistance decreases with increasing light intensity.  
  * __Working Principle__: The resistance of the LDR varies inversely with light intensity. In bright light, the resistance is low, and in darkness, it’s high.
  * __Usage__: It’s used to measure ambient light levels, and the analog signal can be read by the ESP32’s ADC to determine light intensity.

### DHT22 (Digital Humidity and Temperature Sensor)
The DHT22 is a digital sensor that measures both temperature and humidity. It provides a digital signal that the ESP32 can read to obtain temperature and humidity data.
  * __Working Principle__: The DHT22 uses a capacitive humidity sensor and a thermistor to measure relative humidity and temperature. It communicates data to the microcontroller using a digital signal.
  * __Usage__: It’s used in applications where monitoring of environmental conditions is necessary.

### LCD with I2C
An LCD with I2C is a display module that simplifies the connection and communication with a microcontroller. It uses the I2C protocol to send data and commands to the LCD, reducing the number of required connections.
  * __Working Principle__: The LCD uses I2C communication to display text and data. The I2C interface allows the LCD to be controlled with only two data lines (SDA and SCL) along with power and ground.
  * __Usage__: It’s used to display text or numerical data from sensors in a compact, easy-to-read format.

## 2. Pinout
### ESP32 Pinout
  * __3.3V__: Power supply for sensors and LCD.
  * __GND__: Ground connection.
  * __GPIO21 (SDA)__: I2C Data Line.
  * __GPIO22 (SCL)__: I2C Clock Line.

### LDR Pinout
  * __VCC__: Connect to 3.3V.
  * __GND__: Connect to GND.
  * __Analog Output__: Connect to Analog Input (e.g., GPIO34).

### DHT22 Pinout
  * __VCC__: Connect to 3.3V.
  * __GND__: Connect to GND.
  * __DATA__: Connect to Digital Input (e.g., GPIO14).

### LCD with I2C Pinout
  * __VCC__: Connect to 3.3V.
  * __GND__: Connect to GND.
  * __SDA__: Connect to GPIO21 (SDA).
  * __SCL__: Connect to GPIO22 (SCL).

## 3. How to Connect
1. Open Wowki and create a new ESP32 project.
2. Add the ESP32 microcontroller to your workspace.
3. For the LDR simulation:
   * Connect the LDR and LCD to the ESP32 according to the pinout and wiring diagram.
4. For the DHT22 simulation:
   * Connect the DHT22 and LCD to the ESP32 according to the pinout and wiring diagram.
5. Ensure all connections are secure.

__LDR:__

<img width="553" alt="image" src="https://github.com/user-attachments/assets/fdff73e9-15f7-471f-bc08-9eb71240a1a1">

[Wowki Link](https://wokwi.com/projects/403956419723332609)

__DHT22:__

<img width="535" alt="image" src="https://github.com/user-attachments/assets/c57969a0-11ec-4bd7-a860-ecc8dc9dbaa9">

[Wowki Link](https://wokwi.com/projects/403301172351336449)

## 4. Example Code

__LDR:__
```
#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the LDR pin
#define LDR_PIN 34

// Initialize the LCD with the I2C address 
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
  // Read the analog value from the LDR
  int ldrValue = analogRead(LDR_PIN); 
  
  // Display LDR value on LCD
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("LDR Value:");
  LCD.setCursor(0, 1);
  LCD.print(ldrValue);

  // Print LDR value to Serial Monitor for debugging
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  delay(1000); 
}
```

__DHT22:__
```
#include <WiFi.h>                 
#include <Wire.h>                    
#include <LiquidCrystal_I2C.h>        
#include "DHT.h"                      

// Initialize the LCD with I2C address 
LiquidCrystal_I2C LCD(0x27, 16, 2);

// Define the pin connected to the DHT22 sensor and its type
#define DHTPIN 14
#define DHTTYPE DHT22

// Create an instance of the DHT class
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);          

  // Initialize the LCD
  LCD.init();                        
  LCD.backlight();                  
  
  // Connect to Wi-Fi
  WiFi.begin("Wokwi-GUEST", "", 6);  // Connect to Wi-Fi network (SSID: Wokwi-GUEST, no password, channel 6)

  // Display initial message
  LCD.clear();                       
  LCD.print("Online");              
  dht.begin();                      
}

void loop() {
  // Read the temperature from the DHT22 sensor
  float t = dht.readTemperature();
  
  // Check if the reading failed
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!"); 
    return;                                    
  }

  // Print the temperature to the serial monitor
  Serial.printf("Temperature: %.2f°C\n", t);

  // Display the temperature on the LCD
  LCD.setCursor(0, 0);                     
  LCD.printf("Temp: %.2f C", t);          

  delay(1000);                            
  LCD.clear();                             
}
```














  

  



