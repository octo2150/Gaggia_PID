//Include necacart librays
#include <SPI.h>
#include "max6675.h"
#include <PID_v1.h>

//Define the Relay pin 
#define RelayPin 5

//Define the pins used for the MAX6675
int thermoDO = 4;
int thermoCS = 2;
int thermoCLK = 3;

//initialize the thermocouple
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

//Define Variables for the PID
double Setpoint, Input, Output;

//PID controller settings
PID myPID(&Input, &Output, &Setpoint, 1, 7, 1, DIRECT);

//Time window size
int WindowSize = 1000;
unsigned long windowStartTime;

void setup() {
  //set the relay to be an output pin
  pinMode(RelayPin, OUTPUT);
  windowStartTime = millis();

  //set the set point
  Setpoint = 95;

  //tell the PID to range between 0 and the full window size
  myPID.SetOutputLimits(0, WindowSize);

  //turn the PID on
  myPID.SetMode(AUTOMATIC);

  //Begin comunicating with the computer
  Serial.begin(9600);
  Serial.println("MAX6675 test");

  // Wait for Thermocouple to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  Serial.println("DONE.");
}

void loop() {
  //read the temperature
  double c = thermocouple.readCelsius();
  Input = thermocouple.readCelsius()+5;
  //print the tempature
  Serial.print("C = ");
  Serial.println(c);

  //compute with the pid algorithm
  myPID.Compute();

  //calculate current time
  unsigned long now = millis();

  //check if time window ended
  if (now - windowStartTime > WindowSize) {  //time to shift the Relay Window
    windowStartTime += WindowSize;
  }

  //turn on or off relay based on output and time window
  if (Output > now - windowStartTime) digitalWrite(RelayPin, HIGH);
  else digitalWrite(RelayPin, LOW);

  //wait 200ms
  delay(200);
}