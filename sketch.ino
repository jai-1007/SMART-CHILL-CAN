#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Reference temperature used for calibration
float referenceTemp = 5.00;

// Calibration offset
float calibrationOffset = 0.30;

void setup() {
  Serial.begin(115200);
  sensors.begin();

  Serial.println("DS18B20 Calibration");
  Serial.println("-------------------");
}

void loop() {

  sensors.requestTemperatures();

  // Raw temperature from DS18B20
  float sensorTemp = sensors.getTempCByIndex(0);

  // Calculate error
  float error = sensorTemp - referenceTemp;

  // Apply calibration offset
  float correctedTemp = sensorTemp - calibrationOffset;

  Serial.print("Reference Temperature : ");
  Serial.print(referenceTemp, 2);
  Serial.println(" °C");

  Serial.print("Raw Sensor Temperature: ");
  Serial.print(sensorTemp, 2);
  Serial.println(" °C");

  Serial.print("Error                 : ");
  Serial.print(error, 2);
  Serial.println(" °C");

  Serial.print("Calibration Offset    : ");
  Serial.print(calibrationOffset, 2);
  Serial.println(" °C");

  Serial.print("Corrected Temperature : ");
  Serial.print(correctedTemp, 2);
  Serial.println(" °C");

  Serial.println("-------------------");

  delay(2000);
}
