// Define segment pins
int segmentPins[] = {7, 6, 3, 4, 5, 8, 9, 2};

// Button pin
const int buttonPin = 10;

// Button state
int buttonState = 0;

// Delay time
int t = 1000;

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Set button pin as input
  pinMode(buttonPin, INPUT);
}

void displayNumber(int num) {
  int numbers[10][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}  // 9
  };

  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], numbers[num][i]);
  }
  delay(t);
}

void loop() {
  // Read button state
  buttonState = digitalRead(buttonPin);
/*
  // Display numbers 0 to 9
  for (int i = 0; i <= 9; i++) {
    displayNumber(i);
  }
*/
  //if button pressed/display random number
  if (buttonState == HIGH){
    long i = random(0, 9);
    displayNumber(i);
  }
}