#include <DHT.h>
#include <Servo.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int s = 9;          
int spd = 0;    
Servo myservo;  
int pos=0;    
int x;
void setup() {
  Serial.begin(9600);
 // pinMode(13,OUTPUT);
  pinMode(s, OUTPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  myservo.attach(9);
}
void loop()
{
  delay(100);
  analogWrite(s, spd);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  x=(1180-35*t)/4;
  for (pos = 0; pos <= 180; pos += 1)
  {
    myservo.write(pos);              
    delay(x);                      
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {
    myservo.write(pos);              
    delay(x);                      
  }
  Serial.print(F("Humidity: "));
  Serial.println(h);
  Serial.print(F("Temperature: "));
  Serial.println(t);
}
