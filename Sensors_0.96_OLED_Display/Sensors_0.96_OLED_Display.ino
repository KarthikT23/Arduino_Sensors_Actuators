#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"
#include <BH1750.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// BMP180 sensor
Adafruit_BMP085 bmp;

// DHT11 sensor
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// BH1750 light sensor
BH1750 lightMeter;

// Gas sensor
const int gasSensorPin = 4;

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();

  // Initialize BMP180 sensor
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }

  // Initialize DHT sensor
  dht.begin();

  // Initialize BH1750 light sensor
  Wire.begin();
  lightMeter.begin();
}

void loop() {
  // Read gas sensor value
  int gasSensorValue = analogRead(gasSensorPin);

  // Read BMP180 sensor values
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float altitude = bmp.readAltitude();
  float seaLevelPressure = bmp.readSealevelPressure();
  float realAltitude = bmp.readAltitude(101500);

  // Read DHT11 sensor values
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  float heatIndexC = dht.computeHeatIndex(tempC, humidity, false);
  float heatIndexF = dht.computeHeatIndex(tempF, humidity);

  // Read BH1750 light sensor value
  float lux = lightMeter.readLightLevel();

  Serial.print("Gas Value:");
  Serial.println(gasSensorValue);

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");


  // Clear display
  display.clearDisplay();

  // Display gas sensor value
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Gas: ");
  display.println(gasSensorValue);

  // Display BMP180 sensor values
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.print("Pressure: ");
  display.print(pressure);
  display.println(" Pa");
  display.print("Altitude: ");
  display.print(altitude);
  display.println(" m");

  // Display DHT11 sensor values
  display.print("Humidity: ");
  display.print(humidity);
  display.println("%");
  display.print("TempC: ");
  display.print(tempC);
  display.println(" C");
  display.print("TempF: ");
  display.print(tempF);
  display.println(" F");

  // Display BH1750 light sensor value
  display.print("Light: ");
  display.print(lux);
  display.println(" lx");

  // Display the updated information
  display.display();

  delay(2000); // Delay for 2 seconds
}
