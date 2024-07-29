#include <SoftwareSerial.h>

// Define PIR sensor pin
const int pirPin = D2;
// Define buzzer pin
const int buzzerPin = D3;

// Initialize SoftwareSerial object to communicate with SIM800L
SoftwareSerial SIM800L(D6, D5); // RX, TX

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Set baud rate for serial communication with SIM800L
  SIM800L.begin(9600);
  // Give some time for SIM800L to initialize
  delay(1000);
}

void loop() {
  // Read the PIR sensor state
  int pirState = digitalRead(pirPin);
  
  if (pirState == HIGH) {
    // If motion is detected, send message and trigger alarm
    sendMessage();
    triggerAlarm();
    delay(5000); // Delay to avoid sending multiple messages in quick succession
  }
}

void sendMessage() {
  // AT command to set SIM800L in text mode
  SIM800L.println("AT+CMGF=1");
  delay(100);
  // Phone number to send the message
  SIM800L.println("AT+CMGS=\"8667745859\""); // Replace +1234567890 with your desired phone number
  delay(100);
  // Message to be sent
  SIM800L.println("Motion detected at home!");
  delay(100);
  // End the message with a Ctrl+Z character
  SIM800L.println((char)26);
  delay(100);
}

void triggerAlarm() {
  // Sound the buzzer
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
}