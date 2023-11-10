#define ledPin1 3 //Red
#define ledPin2 4  //Green
#define ledPin3 5 //Yellow or Blue
#define buzzerPin 6 //BuzzerPin
#define mqsensorPin A0 //Analog pin for MQ sensor
#define thresholdValue 600 //Setting the min threshold value for MQ sensor
#define calibrationTime 10000 //Give the value in milliseconds Eg: 1 sec:
// #define flamesensorPin A0 //Analog pin for flame sensor
#define flamePin 8 //Digital pin for flame sensor
int flame = HIGH; //Initially setting flame value as HIGH

void setup()
{
  pinMode(mqsensorPin, INPUT);
  pinMode(flamePin, INPUT);
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
  int mqSensorValue = analogRead(mqsensorPin); // Reads analog value of MQ sensor
  // int flameSensorValue = analogRead(flamesensorPin); //Reads analog value of flame sensor
  flame = digitalRead(flamePin); //Reads the digital value of  flame sensor
  if (mqSensorValue > thresholdValue || flame == LOW)
  {
    Serial.print("Value of MQ Sensor: ");
    Serial.println(mqSensorValue); //Prints analog value of MQ sensor
    Serial.print("Value of Flame Sensor: ");
    Serial.println(flame); //Prints digital value of MQ sensor
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    tone(buzzerPin, 1); //Set the voltage to high and makes a noise
    delay(1000); //Waits for 1000 seconds
    noTone(buzzerPin); //Sets the voltage to low and makes no noise
    delay(1000); //Waits for 1000 milliseconds
  }
  else
  {
    Serial.print("Value of MQ Sensor: ");
    Serial.println(mqSensorValue); //Prints analog value
    Serial.print("Value of Flame Sensor: ");
    Serial.println(flame); //Prints digital value of MQ sensor
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    noTone(buzzerPin); //Sets the voltage to low and makes no noise
    delay(1000); // wait 1sec for next reading
  }
}
