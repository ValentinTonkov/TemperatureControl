#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DATA 2
#define SCL 5
#define SDA 4
#define RELAY_PIN 13

#define LEFT_BUTTON 16
#define RIGHT_BUTTON 15

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

OneWire oneWire(DATA);
DallasTemperature sensor(&oneWire);

float temperature;
uint8_t setTemp = 25;
unsigned long lastMeasureTime = 0;

void setup() {

  pinMode(LEFT_BUTTON, INPUT_PULLDOWN_16);
  pinMode(RIGHT_BUTTON, INPUT);

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

}

void loop() {
  
}

void printText(const char* text) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 11);
  display.println(text);
  display.display();
}

float getTemperature() {
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0);
}