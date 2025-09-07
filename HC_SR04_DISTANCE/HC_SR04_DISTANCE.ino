const int trigPin = 10;   // Trig connected to Pin 10
const int echoPin = 9;    // Echo connected to Pin 9
long duration;            // Variable to store travel time of sound
int distance;             // Calculated distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);     // Start serial monitor
}

void loop() {
  // Send a short HIGH pulse on Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time Echo pin stays HIGH
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance in cm
  distance = duration * 0.034 / 2;

  // Show on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Small delay before next reading
}
