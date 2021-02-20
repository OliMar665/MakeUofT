const int TRIG_PIN   = 12; 
const int ECHO_PIN   = 11; 
const int BUZZER_PIN = 13; 
const int DISTANCE_THRESHOLD = 200; // cm

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);         
  pinMode(TRIG_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT);    
  pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {
 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(BUZZER_PIN, HIGH); 
  else
    digitalWrite(BUZZER_PIN, LOW);  


  delay(500);
}
