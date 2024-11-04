#include <Arduino.h>

const int samplingPin = A0;

// Define serial baud rate
const long baudRate = 2000000; // Baud Rate, baud
const int frequency = 1000; //Sampling Frequency, Hz
long start_time = 0;
const int led1 = PB3;  // Nucleo-G431KB LED Pin 13

void setup() {
  // Set up serial communication
  Serial.begin(baudRate);
  analogReadResolution(12);
  pinMode(led1, OUTPUT);
  pinMode(PA4, OUTPUT);
  analogWriteResolution(12);
}

void loop() {
  if (micros() - start_time >= 1000000/frequency) {

    start_time = micros();
    digitalWrite(led1, !digitalRead(led1));

    int t = analogRead(samplingPin);
    analogWrite(PA4,t);
    Serial.println(t);
  }
}
