#define BLYNK_TEMPLATE_ID "TMPL6Le_8LO7G"
#define BLYNK_TEMPLATE_NAME "ESP32"
#define BLYNK_AUTH_TOKEN "YD_zAfScjpuT8SBswXFL0tRx4OLIF_JJ"

#define BLYNK_PRINT Serial

#include <ESP32Servo.h>
#include <GyverMotor.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Artem";
char pass[] = "26062007";

GMotor motor1(DRIVER2WIRE, 5, 18, HIGH);
int i = 90;
int t = 0;

BLYNK_WRITE(V0) {
  digitalWrite(13, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(12, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(14, param.asInt());
}
BLYNK_WRITE(V3) {
  digitalWrite(27, param.asInt());
}
BLYNK_WRITE(V4) {
  digitalWrite(26, param.asInt());
}
BLYNK_WRITE(V5) {
  digitalWrite(33, param.asInt());
}
BLYNK_WRITE(V6) {
    digitalWrite(15, LOW);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);

}
BLYNK_WRITE(V7) {
    digitalWrite(15, HIGH);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);
    digitalWrite(4, HIGH);
    delay(10);
    digitalWrite(4, LOW);
    delay(10);

}
BLYNK_WRITE(V8) {
    digitalWrite(27, param.asInt());
  if (param.asInt() == HIGH){
   motor1.setSpeed(-205);
  } else{
    motor1.setSpeed(0);
  }
}
BLYNK_WRITE(V9) {
    if (param.asInt() == HIGH){
   motor1.setSpeed(205);
  } else{
    motor1.setSpeed(0);
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(4, OUTPUT);   //step
  pinMode(15, OUTPUT);  //dir
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(33, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  motor1.setMode(AUTO);
  // put your setup code here, to run once:
}

void loop() {
  Blynk.run();
  // put your main code here, to run repeatedly:
}
