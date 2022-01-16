#include <Ultrasonic.h>
Ultrasonic ultrasonic (10);

void setup (){
  Serial.begin(38400);
  }
  

void loop ()
  {
  long range;
  range = ultrasonic.MeasureInMillimeters();  

  Serial.println(range);
  }
  //Tinu di geili Sou
