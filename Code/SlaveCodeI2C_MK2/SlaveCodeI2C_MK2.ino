#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // Address of this Arduino as slave

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);

  // Initialize Button Pins
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  // Additional logic if needed in the loop
}

void requestEvent() {
  // Read pin values and send over I2C
  for (int index = 0; index < 4; index++) {
    int currentButtonState = !digitalRead(index + 9); // Adjusted pinToButtonMap
    Wire.write(currentButtonState);
  }
  delay(50); // Adjust delay as needed
}
