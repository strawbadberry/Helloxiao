#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;
Adafruit_MPU6050 mpu;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int ledPin = A0;
const float flipThreshold = -2.0;
const unsigned long ledDuration = 5000;

unsigned long lastLedChange = 0;
bool wristFlipped = false;
bool highHumidity = false;


void printValues();

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);

    Serial.println(F("BME280, MPU6050, and SSD1306 test"));

    if (!bme.begin(0x76)) {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        while (1) delay(10);
    }

    if (!mpu.begin()) {
        Serial.println(F("Failed to find MPU6050 chip"));
        while (1) delay(10);
    }

    Serial.println(F("MPU6050 Found!"));
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }

    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
}

void loop() {
    printValues();
    delay(1000);
}

void printValues() {

}




