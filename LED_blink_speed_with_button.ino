int buttonState = 0;        // stores the current reading of the button
int lastButtonState = 0;    // stores the previous reading of the button
bool fastBlink = false;     // tracks whether we’re in fast or slow blink mode

unsigned long previousMillis = 0;  // stores the last time the LED changed state
int blinkInterval = 1000;          // time (in ms) between LED changes — start slow
bool ledState = LOW;               // keeps track of whether LED is ON or OFF

void setup() {
  pinMode(6, INPUT); // set pin 6 as an input with an internal pull-up resistor
  pinMode(10, OUTPUT);      // set pin 10 as output for the LED
  Serial.begin(9600);       // start serial communication at 9600 baud
}

void loop() {
  unsigned long currentMillis = millis(); // get current time in milliseconds since Arduino started
  buttonState = digitalRead(6);           // read the current state of the button (HIGH or LOW)

  // Detect a button press (HIGH → LOW transition)
  if (buttonState == LOW && lastButtonState == HIGH) {
    fastBlink = !fastBlink;               // toggle between fast and slow blink modes
    blinkInterval = fastBlink ? 100 : 1000; // set blink speed (100 ms for fast, 1000 ms for slow)
    Serial.print("Mode: ");               // print label
    Serial.println(fastBlink ? "FAST" : "SLOW"); // print which mode we're in
    delay(200);                           // short delay to debounce button (ignore bounces)
  }

  lastButtonState = buttonState;          // remember current button state for next loop

  // Blink logic using millis() (non-blocking)
  if (currentMillis - previousMillis >= blinkInterval) { // check if it's time to toggle the LED
    previousMillis = currentMillis;     // remember the current time
    ledState = !ledState;               // invert LED state (ON → OFF or OFF → ON)
    digitalWrite(10, ledState);         // set LED to new state
  }
}
