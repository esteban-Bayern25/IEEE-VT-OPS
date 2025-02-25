// Project 4 Potentiometer Blink
// define input pint for potentiometer (pot)
#define POT A4
// define pin for LED
#define LED 6

void setup(){
  // declare pins(IO)
  pinMode(POT, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  // Get value form potentiometer
  int potValue = analogRead(POT);
  Serial.println(potValue);
  
  int delayTime = map(potValue, 0, 1023, 0, 1000);

  // Turn LED on
  digitalWrite(LED, HIGH);

  // Make it stay on depedning on the value read from the pot
  delay (delayTime);

  // Turn LED off
  digitalWrite(LED, LOW);

  //Make it stay off depending on the value read from the pot
  delay(delayTime);
}