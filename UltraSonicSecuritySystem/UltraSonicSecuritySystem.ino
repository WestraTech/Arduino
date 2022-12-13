/*
 * Programmer: Gabe Westra
 * Date: 12.12.22
 * Program: Ultrasonic Security System
 * 
 * Recource: https://create.arduino.cc/projecthub/Krepak/ultrasonic-security-system-3afe13?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1
 */

int trigPin = 7;
int echoPin = 6;
int LEDlampRed = 9;
int LEDlampYellow = 10;
int LEDlampGreen = 11;
int soundbuzzer = 1;
int sound = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) {
      digitalWrite(LEDlampGreen, HIGH);
}
  else {
      digitalWrite(LEDlampGreen, LOW);
  }
  
  if (distanceincm < 20) {
    digitalWrite(LEDlampYellow, HIGH);
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distanceincm < 5) {
    digitalWrite(LEDlampRed, HIGH);
    sound = 1000;
}
  else {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 5 || distanceincm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println(" cm");
    tone(soundbuzzer, sound);
  }
  
  delay(300);
}
