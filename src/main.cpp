#include <Arduino.h>

String ultra();

const int sendPin = 10;
const int receivePin = 11;

void setup() {
    Serial.begin(115200);
}

void loop() {
    unsigned long sendTime;
    unsigned long receiveTime;
    unsigned long timeBetween;
    unsigned long distanceCm;
    int returnValue;

    unsigned long sendTimeMillis, receiveTimeMillis;

    digitalWrite(sendPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sendPin, LOW);

    sendTime = micros();
    sendTimeMillis = millis();


    Serial.println("started timer");
    while(digitalRead(receivePin) == 0);
    Serial.println("begun hearing signal");
    while(digitalRead(receivePin) == 1);

    receiveTime = micros();
    receiveTimeMillis = millis();

    timeBetween = (unsigned long) receiveTime-sendTime;

    Serial.print("the send time in milliseconds is: "); Serial.println((unsigned long) receiveTimeMillis - sendTimeMillis);

    distanceCm = 17*timeBetween/1000;

    if(distanceCm < 20) returnValue = 5;
    else if(distanceCm < 40) returnValue = 4;
    else if(distanceCm < 60) returnValue = 3;
    else if(distanceCm < 80) returnValue = 2;
    else if(distanceCm < 100) returnValue = 1;
    else returnValue = 0;
    Serial.print(timeBetween);
    Serial.print(", ");
    Serial.print(distanceCm);
    Serial.print(", ");
    Serial.println(returnValue);
    delay(100);
}

// String ultra() {
//   unsigned long sendTime;
//   unsigned long receiveTime;
//   unsigned long timeBetween;
//   unsigned long distance;
//   int returnValue;
//
//   sendTime = micros();
//   digitalWrite(sendPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(sendPin, LOW);
//
//   while(digitalRead(receivePin) == 0);
//   while(digitalRead(receivePin) == 1);
//
//   receiveTime = micros();
//   timeBetween = sendTime-receiveTime;
//
//   // int lowerBound = 950;
//   // int upperBound = 850;
//
//   distance = timeBetween*17/1000%1000;
//
//   // (distance - upperBound) * (5.0/(upperBound - lowerBound));
//
//   if(distance > 940) returnValue = 5;
//   else if(distance > 930) returnValue = 4;
//   else if(distance > 920) returnValue = 3;
//   else if(distance > 905) returnValue = 2;
//   else if(distance > 895) returnValue = 1;
//   else returnValue = 0;
//   Serial.println(returnValue);
//   delay(100);
// }
