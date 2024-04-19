/*
  NetAlertPi - Blinking Alert System
  This sketch controls an LED, a buzzer, and a green status LED connected to an Arduino Uno. 
  It listens for serial commands from a Raspberry Pi to activate a blinking alert pattern. 
  The red LED and buzzer blink synchronously when activated, indicating a network alert 
  condition based on the Pi's network monitoring, while the green LED indicates stable connectivity.
  
  Pin Assignments:
  - Red LED connected to digital pin 9
  - Buzzer connected to digital pin 12
  - Green LED connected to digital pin 8 (indicating stable connection)

  The system uses serial communication to receive alert signals ('1' for on, '0' for off)
  from a Raspberry Pi. When an alert is active ('1'), both the red LED and buzzer will blink
  every 500 milliseconds to visually and audibly notify users of network issues.
  When the connection is stable ('0'), the green LED remains on.

  This was just a personal project for myself, as i don't always notice when i lose an internet connect & because i host a number of services that are outside of my local network,
  i wanted a system that could alert me to the loss of a connection.
*/

int redLedPin = 9;        // Red LED connected to digital pin 9
int buzzerPin = 12;       // Buzzer connected to digital pin 12
int greenLedPin = 8;      // Green LED connected to digital pin 8
int yellowLedPin = 11;    // Yellow LED connected to digital pin 11
bool alertState = false;  // State to track whether the alert should be active
unsigned long lastHeartbeat = 0;  // Timestamp of the last heartbeat
unsigned long heartbeatInterval = 10000;  // Interval to wait for next heartbeat (10 seconds)

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);   // Initialize yellow LED as an output
  Serial.begin(9600);              // Initialize serial communication at 9600 bits per second
  digitalWrite(greenLedPin, HIGH); // Default state for green LED is ON
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();
    lastHeartbeat = millis();  // Update the last heartbeat timestamp on any signal

    switch(signal) {
      case '0':
        digitalWrite(redLedPin, LOW);
        digitalWrite(buzzerPin, LOW);
        digitalWrite(greenLedPin, HIGH);
        alertState = false;
        break;
      case '1':
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
        alertState = true;
        break;
    }
  }

  // Check if the heartbeat is missing
  if (millis() - lastHeartbeat > heartbeatInterval && !alertState) {
    // Blink the yellow LED if no heartbeat received
    digitalWrite(yellowLedPin, HIGH);
    delay(500);
    digitalWrite(yellowLedPin, LOW);
    delay(500);
  } else {
    digitalWrite(yellowLedPin, LOW);
  }
}
