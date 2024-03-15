#include <Joystick.h>
#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // Address of the slave Arduino

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  // Initialize I2C communication
  Wire.begin();
}

// Constant that maps the physical pin to the joystick button.
const int pinToButtonMap = 9;

// Last state of the button
int lastButtonState[4] = {0, 0, 0, 0};

void loop() {
  // Read local button inputs
  for (int index = 0; index < 4; index++) {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index]) {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  // Read button states from the slave Arduino
  Wire.requestFrom(SLAVE_ADDRESS, 4); // Request 4 bytes (button states)

  // Update joystick buttons with received button states from slave
  for (int index = 0; index < 4; index++) {
    if (Wire.available()) {
      int buttonState = Wire.read();
      Joystick.setButton(index + 3, buttonState); // Offset button index to avoid conflicts with local buttons
    }
  }

  // Read and update joystick axes (if needed)
  // int x = analogRead(A0);
  // int y = analogRead(A1);
  // Joystick.setXAxis(x);
  // Joystick.setYAxis(y);

  delay(50); // Adjust delay as needed
}
