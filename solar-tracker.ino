#include <Servo.h>

Servo myServo;

int ldrKiri = A3;
int ldrKanan = A4;

int posisi = 90;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  myServo.write(posisi);
  Serial.println("start");
}

void loop() {
  int nilaiKiri = analogRead(ldrKiri);
  int nilaiKanan = analogRead(ldrKanan);

  int selisih = nilaiKiri - nilaiKanan;

  int threshold = 50;
  Serial.print(nilaiKiri);
  Serial.print(nilaiKanan);
  Serial.println(threshold);

  if(selisih > threshold){
    posisi++;
  }
  else if(selisih < -threshold){
    posisi--;
  }

  posisi = constrain(posisi, 0, 180);
  myServo.write(posisi);
  delay(20);
}
