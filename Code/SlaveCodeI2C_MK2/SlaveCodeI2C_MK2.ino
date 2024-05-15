#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // Address of this Arduino as slave

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);

  // Initialize Button Pins
  pinMode(4, INPUT_PULLUP); // Add pin 4 initialization
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

}

void loop() {
  // Additional logic if needed in the loop
}

void requestEvent() {
  // Read pin values and send over I2C
  for (int index = 4; index <= 10; index++) {
    int currentButtonState = !digitalRead(index); // Adjusted pinToButtonMap
    Wire.write(currentButtonState);
  }
  delay(0); // Adjust delay as needed
}

// For note it is far easier to not miss out any pins even if nothing is wired in
