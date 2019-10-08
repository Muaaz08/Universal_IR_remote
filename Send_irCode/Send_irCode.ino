#include <IRremote.h>

IRsend irsend;
int read1, read2;
long value = 0x8800257;
int on = 11;
int off = 10;
int down = 8;
int up =9;
void setup() {
  Serial.begin(9600);
  pinMode(on, INPUT_PULLUP);
  pinMode(off, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(on) == 0) {
    irsend.sendNEC(0x880085D, 28); //Power ON
    Serial.println("Power ON");
    delay(500);
  }
  if (digitalRead(off) == 0) {
    irsend.sendNEC(0x88C0051, 28); //Power Off
    Serial.println("Power OFF");
    delay(500);
  }
  if(digitalRead(up) == 0){
    irsend.sendNEC(value, 28); //degree up
    Serial.println(value,HEX);
    if(value == 0x8800A5F) value = 0x8800A5F;
    else value += 0x0000101;
    delay(500);
  }
  if(digitalRead(down) == 0){
    irsend.sendNEC(value, 28); //degree down
    Serial.println(value,HEX);
    if(value == 0x8800257) value = 0x8800257;
    else value -= 0x0000101;
    delay(500);
  }
  delay(100);
}
