#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
//GÖREV YÜKÜ İÇİN BME280

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;

void setup() {

  Serial.begin(9600);

  if (!bme.begin(0x76)) {
    Serial.println("BME280 SENSÖRÜ BULUNAMADI, BAĞLANTIYI KONTROL EDİNİZ! 3.3V kullanmayı unutmayın**");
    while (1)
      ;
  }
}
void loop() {

  //float dizi_bir[4]; //Payload 1 için kullanılacak.
 
  float sicaklik = bme.readTemperature();
  float nem = bme.readHumidity();
  float basinc = bme.readPressure() / 100.0F;
  float irtifa = bme.readAltitude(SEALEVELPRESSURE_HPA);

  Serial.print("P4,"); // bme280 p1, gpsneo8m p2,10dof p3,p4 gorev yuku bme
  Serial.print(sicaklik);
  Serial.print(",");
  Serial.print(nem);
  Serial.print(",");
  Serial.print(basinc);
  Serial.print(",");
  Serial.println(irtifa);
  delay(1000);
}


