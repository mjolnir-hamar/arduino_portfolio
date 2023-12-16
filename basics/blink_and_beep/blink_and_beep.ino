/*
Simple program to blink an array of lights.

The speed and brightness of the lights are controled by 2 potentiometers.

At the beginning of every loop of the lights array, a beeper goes off.
*/


// Light pins
int BLUE = 3;
int RED = 5;
int GREEN = 6;
int YELLOW = 9;

// Group light pins into a list to make it easier to call all of them
int LIGHTS[] = {
  BLUE, RED, GREEN, YELLOW
};
// Get the size of the light pin list automatically
int NUM_LIGHTS = sizeof(LIGHTS) / sizeof(int);

// Beeper pin
int BEEP = 10;

// Potentiometer pins
int SPEED_POT = A0;
int BRIGHT_POT = A1;


void setup() {

  // Iterate over the light list and set the pins to OUTPUT
  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(LIGHTS[i], OUTPUT);
  }

  // Set beeper pin to OUTPUT
  pinMode(BEEP, OUTPUT);

  // Set pot pins to INPUT
  pinMode(SPEED_POT, INPUT);
  pinMode(BRIGHT_POT, INPUT);

  // Start serial for debugging
  Serial.begin(9600);

}

void loop() {

  // Create variables to speed and brightness
  int speed;
  int bright;

  // Iterate over the lights
  for (int i = 0; i < NUM_LIGHTS; i++) {
    // Read the speed and brightness pots to get new values
    speed = analogRead(SPEED_POT);
    // Divide brightness by 4 to change the range from 0-1023 to 0-255, which is the valid range for analogWrite
    bright = analogRead(BRIGHT_POT) / 4;

    // Turn on the light
    analogWrite(LIGHTS[i], bright);
    // If it's the first light, turn on the beeper
    if (i == 0)
      digitalWrite(BEEP, HIGH);
    // Delay by speed
    delay(speed);
    // Turn off the light
    analogWrite(LIGHTS[i], 0);
    // Turn off the beeper
    if (i == 0)
      digitalWrite(BEEP, LOW);
    // Delay by speed
    delay(speed);
  }

}
