//A sketch to demonstrate the tone() function
#define ledpwr1         4
#define ledpwr2         5
//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 1;
int piezoPin1 = 2;

void setup() {
  pinMode(ledpwr1, OUTPUT);
  pinMode(ledpwr2, OUTPUT);
  
  delay (100);
  digitalWrite(ledpwr1, LOW);
  digitalWrite(ledpwr2, LOW);
}//close setup

void loop() {

  /*Tone needs 2 arguments, but can take three
    1) Pin#
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */
  //tone(piezoPin, 16000, 500);
  //tone(piezoPin1, 1000, 100);

  //tone(piezoPin, 1000, 500);
  //delay(1000);

}
