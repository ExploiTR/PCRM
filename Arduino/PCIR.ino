#include <IRremote.h>
IRrecv irrecv(2); // Receive on pin 11
decode_results results;

int powerPin  = 9;
int ledPin = 12;

int ledOn = HIGH;
int powerOn = HIGH;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)){
    if(results.value == 33706159 || results.value == 1977588780 || results.value == 1994366399 || results.value == 3305888170 || results.value == 2011144018){
        pinMode(powerPin,OUTPUT);
        Serial.println(powerOn ? "Power ON" : "Power OFF");
        powerOn = !powerOn;
        delay(250);
        pinMode(powerPin,INPUT);
    }
    else if(results.value == 33749509 || results.value == 3924233869 || results.value == 3873901012 || results.value == 3890678631){
      digitalWrite(ledPin,ledOn);
      Serial.println(ledOn ? "Led ON" : "Led OFF");
      ledOn = !ledOn;
    }
    else if (results.value == 33718909 || results.value == 1891127386 || results.value == 1907905005 || results.value ==4272685797){
        pinMode(powerPin,OUTPUT);
        Serial.println("Power OFF Emergency");
        delay(5000);
        pinMode(powerPin,INPUT);
    }else{
      Serial.println(results.value);
     }
    irrecv.resume();
  }
}
