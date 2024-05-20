void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  int sensorValue = random(35);  // Generate temperature value
  Serial.println(sensorValue);       // Send the value to the serial port
  delay(10000);                       // Wait for 1 second
}
  
