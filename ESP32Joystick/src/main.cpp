#include <Arduino.h>

int UD = 0;
int LR = 0;

int left = 19;
int down = 21;
int up = 22;
int right = 23;

int inputUp = 4;
int inputLR = 2;

int mid = 10; // Test out swapping this with 4?
int lrMid = 0;
int upMid = 0;

void setup() {
    pinMode(left, OUTPUT);
    pinMode(down, OUTPUT);
    pinMode(up, OUTPUT);
    pinMode(right, OUTPUT);

    digitalWrite(left, HIGH);
    digitalWrite(down, HIGH);
    digitalWrite(up, HIGH);
    digitalWrite(right, HIGH);

    lrMid = analogRead(inputLR);
    upMid = analogRead(inputUp);
}

void loop() {
    UD = analogRead(inputUp);
    LR = analogRead(inputLR);

    // Down
    if (UD < upMid-mid) {
        digitalWrite(down, HIGH);
    } else {
        digitalWrite(down, LOW);
    }

    // Up
    if (UD < upMid-mid) {
        digitalWrite(up, HIGH);
    } else {
        digitalWrite(up, LOW);
    }

    // Left
    if (LR < lrMid-mid) {
        digitalWrite(left, HIGH);
    } else {
        digitalWrite(left, LOW);
    }

    // Right
    if (LR > lrMid+mid) {
        digitalWrite(right, HIGH);
    } else {
        digitalWrite(right, LOW);
    }

    delay(100);
}