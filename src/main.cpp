#include <Arduino.h>

// String ultra();

#define trigPin SCL //21;  //output SCL
#define echoPin SDA //= 20;  //input SDA

// int trigPin = 10;
// int echoPin = 11;

void setup() {
    Serial.begin(115200);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    long duration;
    double distanceCm;
    // int returnValue;
    //
    // unsigned long sendTimeMillis, receiveTimeMillis;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // sendTimeMillis = millis();

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    // receiveTimeMillis = millis();


    Serial.print("the send time in microseconds is: "); Serial.println(duration);//(unsigned long) receiveTimeMillis - sendTimeMillis);

    distanceCm = (double) duration * 0.01715;

    // if(distanceCm < 20) returnValue = 5;
    // else if(distanceCm < 40) returnValue = 4;
    // else if(distanceCm < 60) returnValue = 3;
    // else if(distanceCm < 80) returnValue = 2;
    // else if(distanceCm < 100) returnValue = 1;
    // else returnValue = 0;
    // Serial.print(timeBetween);
    // Serial.print(", ");
    // Serial.print(distanceCm);
    // Serial.print(", ");
    Serial.print("the distance in cm is: "); Serial.println(distanceCm);

    delay(1000);
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
