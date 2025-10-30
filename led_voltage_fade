const int ledPin = 10;

void setup() {
  pinMode (ledPin, OUTPUT);
}

void loop() {
  int i;

  for (i=0; i<255; i=i+5) {
    analogWrite (ledPin, i);
    delay (50); 
  }
  for (i=255; i>0; i=i-5) {
    analogWrite (ledPin, i);
    delay (50);
  }
}
