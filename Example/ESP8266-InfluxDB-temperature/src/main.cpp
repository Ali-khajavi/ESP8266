#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

// Define Wifi Connections for Multiwifi Lib
#define WIFI_SSID1 "wifi-1"
#define WIFI_PASSWORD1 "pass"
#define WIFI_SSID0 "wifi-2"
#define WIFI_PASSWORD0 "pass"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Setup InfluxDB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
#define INFLUXDB_URL "your_influx_db_URL"
#define INFLUXDB_TOKEN "your_influx_db_token"
#define INFLUXDB_ORG "the_organisatiob_name"
#define INFLUXDB_BUCKET "Backet_name"

InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);
Point pointDevice("your name"); // Enter your name or any desired label for the device.
#define DEVICE "Tag"  // You can define your device tag here.  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// If the temperature sensor is not required, comment out all the functions below.  
//~~~~~~~~~~~~~~~~~~~~~~~~~ Temperature Sensore Onewire Lib ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
#define TempSensor your_sensor_name
#ifdef TempSensor 
  #include <OneWire.h>
  #include <DallasTemperature.h>
#endif
#define ONE_WIRE_BUS D2   // J1 = D1    &&   J2 = D2
DallasTemperature DS18B20( &oneWire );
OneWire oneWire( ONE_WIRE_BUS );
float temperature;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

ESP8266WiFiMulti wifi_multi;
uint16_t connectTimeOutPerAP=5000;

void setup(){
  Serial.begin(115200);
  // Initialize the temperature sensor GPIO and set up "OneWire.h".
  pinMode(D6, OUTPUT);
  digitalWrite(D6, HIGH);
  DS18B20.begin();
  DS18B20.requestTemperatures(  );
  temperature = DS18B20.getTempCByIndex( 0 );
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


  // Wifi Connection......
  Serial.println("Connecting to Wifi...");
  wifi_multi.addAP(WIFI_SSID0,WIFI_PASSWORD0);
  wifi_multi.addAP(WIFI_SSID1,WIFI_PASSWORD1);
  int i = 0;
  while(wifi_multi.run(connectTimeOutPerAP)!=WL_CONNECTED)
  {
    delay(500);
    Serial.println(i);
    i++;
  }

  delay(20);

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi Connected to :");
    Serial.println(WiFi.SSID());
  }else{
    Serial.println("Wifi connection problem!!!!!!!!");
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Influx DB Configuration ~~~~~~~~~~~~~~~~~~~~~~~//
  // The timeSync function returns the time zone and additional unnecessary information.  
  // The time.nist.gov server was too slow to respond, so I disabled it by default.  
  // If needed, uncomment it to enable its use.

  // timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");
  // Serial.print("temperature:");
  // Serial.println(temperature);
  pointDevice.addTag("DEVICE", DEVICE);
  pointDevice.addField("temperature", temperature);
  client.writePoint(pointDevice);
  pointDevice.clearFields();

  // To control the sensor's power, you can use a transistor to switch it on and off.  
  // This can be managed via a GPIO pin, helping to improve power efficiency.
  digitalWrite(D6, LOW);
  delay(50);
  WiFi.mode(WIFI_OFF);

  // Deep sleep mode is implemented here if needed.  
  // If not required, comment out the code below.  
  Serial.println("Entering deep sleep for 50 seconds");  
  ESP.deepSleep(50e6);
}


void loop() {
  
}