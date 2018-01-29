
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin (optional)
const int ledPin1 =  5;      // the number of the LED pins
const int ledPin2 =  6; 
const int ledPin3 =  7;   
const int analogInPin = A0;  //the photoresistor
const int analogInPin2 = A2;    //the sound sensor
const int analogInPin3 = A3;    //the free cable
int sensorValue = 0;        // value read from the first sensor
int sensorValue2 = 0;        // value read from the second sensor
int sensorValue3 = 0;        // value read from the third sensor
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned int temp;
unsigned int time;


//the random xorshift* function
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
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
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
  // read the time in microseconds since the program started
  time = micros();
  
  //initialize the LED array
   digitalWrite(ledPin1,LOW);
   digitalWrite(ledPin2,LOW);
   digitalWrite(ledPin3,LOW);
    
   //the xor of all the values we want to seed
   int s=sensorValue^sensorValue3^time^sensorValue2;
   //useing the function
   temp = xorshift1024star(s);
  
   //prints a random value whenever the button is pushed and also includes range from 0-99
   if(buttonState==HIGH){
   Serial.print(temp%100);
  //Serial.print(sensorValue2);
      Serial.print("\n");
   }
  
   //the randomization of the LED array blinking
   if(temp % 3 == 0){
    digitalWrite(ledPin1,HIGH);
   }else if(temp % 3 == 1){
    digitalWrite(ledPin2,HIGH);
   }else {
    digitalWrite(ledPin3,HIGH);
   }
  
  delay(100);
   
}
