// C++ code
//
int moisture = 0;
int tonevalue = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  //mapping the tone value for buzzer
  //tonevalue = map(moisture, 0, 1023, 100, 1000);
  //Mapping sounds between F to G and F# to G#
  tonevalue = map(moisture, 4000, 6000, 5000, 7000);
  
  tone(A0, tonevalue); //tunes based on sensor value
  Serial.print("Moisture Level: ");
  Serial.println(moisture);

  digitalWrite(A0, LOW);
  //Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 200) {
    digitalWrite(12, HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(11, HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(10, HIGH);
      } else {
        if (moisture < 800) {
          digitalWrite(9, HIGH);
        } else {
          digitalWrite(8, HIGH);
        }
      }
    }
  }
  delay(500); // Wait for 100 millisecond(s)
  noTone(A0);

}