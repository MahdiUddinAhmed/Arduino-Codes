// Example testing sketch for DHT22 temperature and humidity sensor
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
// - LiquidCrystal_I2C Library: https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
#define LCD_COLS 16 // Number of columns in the LCD screen
#define LCD_ROWS 2 // Number of rows in the LCD screen

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS); // Set the LCD address to 0x27 for a 20x4 display

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print the temperature and humidity readings to the LCD
  lcd.setCursor(0, 0);
  lcd.print(F("Temp: "));
  lcd.print(t);
  lcd.print(F("C"));

  lcd.setCursor(0, 1);
  lcd.print(F("Humidity: "));
  lcd.print(h);
  lcd.print(F("%"));

  // Print the temperature and humidity readings to the serial monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
}
