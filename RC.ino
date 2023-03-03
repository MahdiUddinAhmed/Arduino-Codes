#include <SoftwareSerial.h>

// Create a software serial object to communicate with the Bluetooth module
SoftwareSerial bluetooth(2, 3); // RX, TX

// Motor pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;

void setup() {
  // Set the motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Initialize the software serial communication with the Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  // Read data from the Bluetooth module
  if (bluetooth.available() > 0) {
    int data = bluetooth.read();

    // If the received data is 'F', move the car forward
    if (data == 'F') {
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }

    // If the received data is 'B', move the car backward
    else if (data == 'B') {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    }

    // If the received data is 'L', turn the car left
    else if (data == 'L') {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }

    // If the received data is 'R', turn the car right
    else if (data == 'R') {
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    }

    // If the received data is 'S', stop the car
    else if (data == 'S') {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
    }
  }
}
