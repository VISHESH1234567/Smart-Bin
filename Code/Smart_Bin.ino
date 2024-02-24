#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <Servo.h> // including library for servo motor
Servo servo;

char ssid[] = "Vishesh mobile"; //SSID here
char pass[] = "vishesh12"; // Passowrd here
unsigned long Channel_ID = 2136776; // Your Channel ID
const char * myWriteAPIKey = "AANGE1EZJFSY3FFY"; //Your write API key

// Ultrasonic Sensor present at top of the dustbin.
const int trigPin1 = 9;
const int echoPin1 = 10;
// Ultrasonic sensor present on outer part of bin to open the lid
int trigPin2 = 5;
int echoPin2 = 6;
int servoPin = 7;
const int buzzer = 11;
const int ledPin = 13;

const float totalheight = 23;//(in cm)
long duration1,duration2, distance2;
float distance1,percentfull,safetydistance = 10;
int flag = 0;
const int Field_Number_1 = 1;
WiFiClient  client;

void setup() {
  Serial.begin(115200);
  delay(10);
  //WiFi.mode(WIFI_STA);
  internet();
  ThingSpeak.begin(client);

  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT); // Sets the echoPin as an Input

  servo.attach(servoPin);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  servo.write(0); //close cap on power on
  delay(100);
  servo.detach(); 
}

void loop() {
  // Clears the trigPin
  internet();
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;
  percentfull = ((totalheight-distance1)/totalheight) *100;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin2, LOW);

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;

  if (percentfull>=70){
    // Giving tone signal to the piezobuzzer (RC)
    tone(buzzer, 330);
    digitalWrite(ledPin, HIGH);
    }
  else{
    digitalWrite(ledPin, LOW);
    noTone(buzzer);
  }
  Serial.print("Percentatge of Dustbin full: ");
  Serial.println(percentfull);
  if (distance2<10) {
  //Change distance as per your need
    if (!flag){
      flag = 1;
      servo.attach(servoPin);
      delay(1);
      servo.write(0);
      delay(500);
      servo.write(120);
      delay(500);
      servo.detach();
    }
  }
  else{
    if (flag){
      flag = 0;
      delay(3000);
      servo.attach(servoPin);
      servo.write(0);
      delay(500);
      servo.detach();
    }
  }
  upload();

  delay(1000);
}

void internet()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(5000);
    }
  }
}

void upload()
{
  ThingSpeak.writeField(Channel_ID, Field_Number_1, distance1, myWriteAPIKey);
  delay(15000);
}