// simple sequentuall turn on/off of 3 leds
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;

//setting pin for button
const int buttonPin = 2;

//value of button
int buttonState = 0;

//setting up used pins
void setup() {
  
  //outputs for LEDS
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  //setup button
  pinMode(buttonPin, INPUT);
}

//looped code
void loop() {
  
  //read button value;
  buttonState = digitalRead(buttonPin);

  //if its pressed loop LEDS
  if (buttonState == HIGH){
  //looping through LEDS
    digitalWrite(LED1, HIGH);//turn on led1
    delay(100);              //wait 200ms
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED1, LOW); //turn off led1
    delay(100);
    digitalWrite(LED2, LOW);
    delay(100);
    digitalWrite(LED3, LOW);
    delay(100);
  }
}
