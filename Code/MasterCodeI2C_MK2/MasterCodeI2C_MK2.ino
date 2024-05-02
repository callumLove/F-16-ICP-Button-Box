#include <Joystick.h>
#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // Address of the slave Arduino

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  // Initialize I2C communication
  Wire.begin();
}

// Constant that maps the physical pin to the joystick button.
const int pinToButtonMap[] = {4, 5, 6, 7, 8, 9, 10, 14, 15, 16};

// Last state of the button
int lastButtonState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop() {
  // Read local button inputs
  for (int index = 0; index < sizeof(pinToButtonMap) / sizeof(pinToButtonMap[0]); index++)
  {
    int currentButtonState = !digitalRead(pinToButtonMap[index]);
    if (currentButtonState != lastButtonState[index]) 
    {
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
      Joystick.setButton(index + 10, buttonState); // Offset button index to avoid conflicts with local buttons
    }
  }



  delay(50); // Adjust delay as needed
}
