/*
  Burglar Alarm Using Blynk and NodeMCU
*/

#include <ESP8266WiFi.h>  // Pendeklarasian Library
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

char auth[] = "xxxxxxxxxx"; // Masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno"; // Nama WiFi
char pass[] = "xxxxxxxxxx"; // Password

#define ledPin D7  // Pemilihan Pin dan pendeklarasian variabel
#define pirPin D1
int pirValue;

void setup() { // Pengaturan Pin dan Variabel
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() { // Perulangan Program
  getPirValue();
  Blynk.run();
  delay(1000); // Tambahkan delay untuk menghindari pembacaan sensor yang terlalu cepat
}

void getPirValue(void) { // Deklarasi Pembacaan PIR
  pirValue = digitalRead(pirPin);
  if (pirValue == HIGH) { // Bila ada gerakan terbaca
    Serial.println("Gerakan terdeteksi");
    Blynk.notify("Gerakan terdeteksi");
  }
  digitalWrite(ledPin, pirValue);
}
