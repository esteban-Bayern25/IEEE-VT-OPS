// Pin Definitions
const int IR_RECEIVER_PIN = A4;  // Analog pin to read IR receiver values
const int LED_PIN = 3;           // PWM pin to control LED brightness

// Variables for noise calibration
long zero = 0; // Stores the noise baseline

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Pin Modes
  pinMode(IR_RECEIVER_PIN, INPUT); // IR receiver as input
  pinMode(LED_PIN, OUTPUT);        // LED as output

  // Calibration: Take the average reading over 100 samples to get the "zero" value
  for (int i = 0; i < 100; i++) {
    zero += analogRead(IR_RECEIVER_PIN);
  }
  zero = zero / 100;  // Calculate the average
}

void loop() {
  // Step 1: Read IR Receiver value
  int raw_value = analogRead(IR_RECEIVER_PIN);

  // Step 2: Constrain the raw IR reading to ensure it's noise-adjusted
  int constrained_value = constrain(raw_value, 0, 1023);

  // Step 3: Map the reading to an output value from 0 to 255 for LED brightness
  int brightness = 175 - map(constrained_value, 0, 1023, 30, 255);

  // Step 4: Adjust the LED brightness based on the mapped reading
  analogWrite(LED_PIN, brightness);

  // Optional: Print values for debugging
  Serial.print("Constrained_value: ");
  Serial.print(constrained_value);
  Serial.print(" | Raw Value: ");
  Serial.print(raw_value);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  // Delay for stability
  delay(100);  // Adjust as needed
}
