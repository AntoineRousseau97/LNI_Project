#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX

#define echoPin1 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 5 //attach pin D3 Arduino to pin Trig of HC-SR04

long duration1; // variable for the duration of sound wave travel
int distance1; // variable for the distance measurement
int sensor1;
//String sensorValue1 = "";

int HC_SR04() {
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance1;
}

void setup()
{
    Serial.begin(9600);
    Serial.println("Ready to send");
    BTSerial.begin(9600);
    //sensor 1
    pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT

}

//uint8_t ID = 12;

void loop()
{
sensor1 = HC_SR04();
//sensorValue1 = String(sensor1);
//BTSerial.println(sensorValue1);
//Serial.print(sensorValue1);
BTSerial.println(sensor1);
//BTSerial.write(sensor1);
Serial.print(sensor1);
delay(500);
}


