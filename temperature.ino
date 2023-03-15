//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>

//Constants
#define DHTPIN A5     // What pin we're connected to
#define DHTTYPE DHT22   // DHT 22  
DHT dht(DHTPIN, DHTTYPE); 
const int LED = D7;

SYSTEM_THREAD(ENABLED);

void setup() 
{
    pinMode(LED, OUTPUT);
    dht.begin();
}

void loop() 
{
    digitalWrite(LED, HIGH);
    float temp = dht.readTemperature();
    Particle.publish("temp", String(temp), PRIVATE);
    delay(30000);               // Wait for 3 seconds

    digitalWrite(LED, LOW);    // Turn OFF the LED
    delay(30000); 
} 