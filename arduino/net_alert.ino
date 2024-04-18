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

int ledPin = 9;        // Red LED connected to digital pin 9
int buzzerPin = 12;    // Buzzer connected to digital pin 12
int greenLedPin = 8;   // Green LED connected to digital pin 8
bool alertState = false;  // State to track whether the alert should be active

void setup() {
  pinMode(ledPin, OUTPUT);       // Set the red LED pin as an output
  pinMode(buzzerPin, OUTPUT);    // Set the buzzer pin as an output
  pinMode(greenLedPin, OUTPUT);  // Set the green LED pin as an output
  Serial.begin(9600);            // Initialize serial communication at 9600 bits per second
}

void loop() {
  if (Serial.available() > 0) {   // Check if data is available to read
    char signal = Serial.read();  // Read the incoming byte
    alertState = (signal == '1');
  }

  if (alertState) {
    digitalWrite(greenLedPin, LOW);   // Ensure the green LED is off when alert is active
    digitalWrite(ledPin, HIGH);       // Turn the red LED on
    digitalWrite(buzzerPin, HIGH);    // Turn the buzzer on
    delay(500);                       // Blink interval of 500 milliseconds
    digitalWrite(ledPin, LOW);        // Turn the red LED off
    digitalWrite(buzzerPin, LOW);     // Turn the buzzer off
    delay(500);                       // Blink interval of 500 milliseconds
  } else {
    digitalWrite(greenLedPin, HIGH);  // Turn the green LED on when connection is stable
    digitalWrite(ledPin, LOW);        // Ensure the red LED is off
    digitalWrite(buzzerPin, LOW);     // Ensure the buzzer is off
  }
}