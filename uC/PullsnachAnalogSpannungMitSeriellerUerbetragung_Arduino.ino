const int analogPin = A0;  // Pin für die analoge Spannung
const int ledPin = 9;      // Pin für die LED

void setup() {
  pinMode(ledPin, OUTPUT); // Setzt den LED-Pin als Ausgang
  Serial.begin(9600);      // Initialisiert die serielle Kommunikation mit 9600 Baud
}

void loop() {
  int sensorValue = analogRead(analogPin); // Liest den analogen Wert von A0
  int pwmValue = map(sensorValue, 0, 1023, 0, 255); // Wandelt den analogen Wert in einen PWM-Wert um

  analogWrite(ledPin, pwmValue); // Setzt die Helligkeit der LED entsprechend dem PWM-Wert

  float voltage = sensorValue * (5.0 / 1023.0); // Berechnet die Spannung in Volt
  Serial.print("Spannung: ");
  Serial.print(voltage);
  Serial.println(" V"); // Sendet die Spannung über die serielle Schnittstelle

  delay(1000); // Verzögerung von 1 Sekunde für Stabilität und Lesbarkeit
}