// Intelligent Home Automation System
// Developed by: Amna Boughamoura (2025)

// Libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// Pin Configurations
#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_PIN A0
#define LDR_PIN A1
#define LIGHT_RELAY 8
#define PUMP_RELAY 9

// Initialize Sensors
DHT dht(DHTPIN, DHTTYPE);

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(SOIL_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(PUMP_RELAY, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Home Automation");
  delay(2000);
}

void loop() {
  // Read Sensors
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int soil = analogRead(SOIL_PIN);
  int lightLevel = analogRead(LDR_PIN);

  // Display Sensor Values
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C H:");
  lcd.print(h);

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(soil);

  // Logic: Soil Dry → Activate Pump
  if (soil < 400) {
    digitalWrite(PUMP_RELAY, HIGH);
  } else {
    digitalWrite(PUMP_RELAY, LOW);
  }

  // Logic: Dark → Turn On Light
  if (lightLevel < 300) {
    digitalWrite(LIGHT_RELAY, HIGH);
  } else {
    digitalWrite(LIGHT_RELAY, LOW);
  }

  delay(2000);
}
