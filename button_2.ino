/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int ledPin1 =  5;   
const int ledPin2 =  6; 
const int ledPin3 =  7;   
const int analogInPin = A0;
const int analogInPin2 = A2;
const int analogInPin3 = A3;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int sensorValue2 = 0;        // value read from the pot
int outputValue2 = 0;        // value output to the PWM (analog out)
int sensorValue3 = 0;        // value read from the pot
int outputValue3 = 0;        // value output to the PWM (analog out)
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned int temp;
unsigned int time;



uint32_t xorshift1024star(int s) {
  uint32_t x = s;  /* The state must be seeded with a nonzero value. */
  x ^= x >> 12; // a
  x ^= x << 25; // b
  x ^= x >> 27; // c
  s = x;
  return x * 0x2545F4914F6CDD1D;
}

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
   pinMode(ledPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  sensorValue2 = analogRead(analogInPin2);
  
  sensorValue3 = analogRead(analogInPin3);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  // change the analog out value:
 

  time = micros();

 // Serial.println(time);
  
   digitalWrite(ledPin1,LOW);
   digitalWrite(ledPin2,LOW);
   digitalWrite(ledPin3,LOW);
    //randomSeed(sensorValue2+sensorValue3);
    
    int s=sensorValue^sensorValue3^time^sensorValue2;
     temp = xorshift1024star(s);
   if(buttonState==HIGH){
   Serial.print(temp%100);
  //Serial.print(sensorValue2);
      Serial.print("\n");
   }
     if(temp % 3 == 0){
    digitalWrite(ledPin1,HIGH);
   }else if(temp % 3 == 1){
    digitalWrite(ledPin2,HIGH);
   }else {
    digitalWrite(ledPin3,HIGH);
   }
   // Serial.print(random(0,100));
   // Serial.print("\n");
   
  delay(100);
   
}
