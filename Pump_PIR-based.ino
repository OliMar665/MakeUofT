const int motor_pin = 3; // pin; this is where pump pin will be
bool motor_state = false;

const int pir_inputPin = 4; // pir sensor
bool pirState = false;

const int ledPin = 5; // indicator led; doesn't need to be in final
bool ledState = false;

unsigned long previousMillis = 0;
const long interval_motor = 200; // arbitrary value

void setup()
{
  pinMode(motor_pin, OUTPUT);
  pinMode(pir_inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{  
  unsigned long currentMillis = millis();
  
  pirState = digitalRead(pir_inputPin);
  
  if(pirState) // pir detects movement
  {
    previousMillis = currentMillis;
    motor_state = true;
    digitalWrite(motor_pin, motor_state);
    digitalWrite(ledPin, HIGH);
    
  if ((currentMillis - previousMillis) >= interval_motor) // once pir turns off
  {
    motor_state = false;
    digitalWrite(motor_pin, motor_state);
  }
    
  }
  
  else // if pir sensor detects no movement 
  {
    digitalWrite(motor_pin, LOW);
    digitalWrite(ledPin, LOW);
  }
}
}
