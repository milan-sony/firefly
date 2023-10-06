#define ledPin1 3 //Green
#define ledPin2 4  //Red
#define ledPin3 5 //Yellow or Blue
#define buzzerPin 6 //BuzzerPin
#define sensorPin A0
#define thresholdValue 600
#define calibrationTime 10000 //Give the value in milliseconds Eg: 1 sec:

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Sensor Calibrating...");
  digitalWrite(ledPin3, HIGH);
  delay(calibrationTime);
  digitalWrite(ledPin3, LOW);
  Serial.println("Sensor Calibrated");
}

void loop()
{
  int analogValue = analogRead(sensorPin); // reads digital value
  if (analogValue > thresholdValue)
  {
    Serial.print("Value: ");
    Serial.println(analogValue); //Prints analog value
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    tone(buzzerPin, 1); //Set the voltage to high and makes a noise
    delay(1000); //Waits for 1000 seconds
    noTone(buzzerPin); //Sets the voltage to low and makes no noise
    delay(1000); //Waits for 1000 milliseconds
  }
  else
  {
    Serial.print("Value: ");
    Serial.println(analogValue); //Prints analog value
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    noTone(buzzerPin); //Sets the voltage to low and makes no noise
    delay(1000); // wait 1sec for next reading
  }
}
