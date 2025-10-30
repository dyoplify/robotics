const int buzzer = 10;


void setup() {
  pinMode (buzzer, OUTPUT);
}

void loop() {
  int i;

  for (i=0; i<255; i=i+5) {
  analogWrite(buzzer, i);
  }

  for (i=255; i>0; i=i-5) {
    analogWrite (buzzer, i);
  }
}
