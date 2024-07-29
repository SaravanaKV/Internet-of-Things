// C++ code
//
#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int soilMoisturePin = A0;  // Pin analog untuk soil moisture sensor
const int motorControlPin = 2;   // Pin digital untuk mengontrol DC motor

void setup() {
  pinMode(soilMoisturePin, INPUT); // pin A0 soilmoistureoin menjadi input pada arduino
  pinMode(motorControlPin, OUTPUT); // pin 2 motorcontrolpin menjadi output pada arduino
  Serial.begin(9600);
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);//membuat fungsi untuk variabel soilMoistureValue
  Serial.println(soilMoistureValue);

  // Sesuaikan nilai ambang sesuai dengan kebutuhan
  if (soilMoistureValue < 500) {
    // Jika tanah kering, hidupkan motor untuk membuka keran
    digitalWrite(motorControlPin, HIGH);
  } else {
    // Jika tanah cukup basah, matikan motor untuk menutup keran
    digitalWrite(motorControlPin, LOW);
  }

  delay(1000);  // Tunggu 1 detik sebelum membaca sensor lagi
}