int val = 0;

void setup() {
  pinMode(13, OUTPUT); // connect to fast backward movement input of syringe pump
  pinMode(2, OUTPUT);  // connect to fast forward movement input of syringe pump
  digitalWrite(13, HIGH); // HIGH setting stops movement
  digitalWrite(2, HIGH);
  Serial.begin(9600);
  Serial.println('a');
  }
}

void loop() {
  if (Serial.available() > 0){
  val = Serial.read();
   if (val == '1') // inject and mix
   {
    for (int i = 0; i < 5; i++) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(2, LOW); // LOW setting turns movement on
    delay(7000); // change this depending on the volume you want to dispense
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(7000); // change this depending on the volume you want to dispense
    }
    digitalWrite(13, HIGH); // important to turn the movement off at the end!
   }
  }
}
