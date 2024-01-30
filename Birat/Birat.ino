#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>    // Include the DHT library

#include "index.h" // Our HTML webpage contents with javascripts

#define LED 2        // On board LED
#define DHTpin 0     // D3 of NodeMCU is GPIO0

DHT dht(DHTpin, DHT11); // Initialize DHT object for DHT11 sensor
Adafruit_BMP085 bmp;

// SSID and Password of your WiFi router
const char* ssid = "Public High School";
const char* password = "PHSdharan12";

ESP8266WebServer server(80); // Server on port 80

void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}

float humidity, temperature;

void handleADC() {
  int a = analogRead(A0);
  int altitude = bmp.readAltitude();
  int pressure = bmp.readPressure();

  humidity = dht.readHumidity();      // Read humidity from DHT sensor
  temperature = dht.readTemperature(); // Read temperature from DHT sensor

  String data = "{\"Pressure\":\"" + String(pressure) + "\", \"Altitude\":\"" + String(altitude) + "\", \"Temperature\":\"" + String(temperature) + "\", \"Humidity\":\"" + String(humidity) + "\"}";

  digitalWrite(LED, !digitalRead(LED));
  server.send(200, "text/plain", data);
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  dht.begin(); // Initialize the DHT sensor

  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }

  WiFi.begin(ssid, password);
  Serial.println();
 
  pinMode(LED, OUTPUT);
  delay(1000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);
  server.on("/readADC", handleADC);
 
  server.begin();
  Serial.println("HTTP server started");

  Serial.print("WiFi Status: ");
Serial.println(WiFi.status());
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}
