
int sensorValue;
float voltage;
int BlinkenLED;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);                      // output LED definieren 
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin),blink,CHANGE);
}

void loop() 
{
  sensorValue = analogRead(A0);             // read the input on analog pin 0:
  voltage = sensorValue * (5.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage);                  // print out the value you read:

 
  if (state == HIGH)
  {
    if (voltage > 4.9)
    {
       digitalWrite(13, HIGH);
    }
    else if (voltage < 0.1)
    {
      digitalWrite(13, LOW);
    }
    else 
    {
    BlinkenLED = -93.75 * voltage+500;
    
    digitalWrite(13, HIGH);                    // turn the LED on (HIGH is the voltage level)
    delay(BlinkenLED);                         // wait for a second
    digitalWrite(13, LOW);                     // turn the LED off by making the voltage LOW
    delay(BlinkenLED);                         // wait for a second
    }
  }
  else
  {
    digitalWrite(13, LOW);
  }
 }


void blink ()
{
  state = !state;
}

  
