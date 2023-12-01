#include <Arduino.h>
const char eyes = 19;
bool eyesState = false;
unsigned long timerBlink = 0;
void setBlink(){
    pinMode(eyes, OUTPUT);
}

void led(){
    if(millis() - timerBlink > 100){
        eyesState = !eyesState;
        digitalWrite(eyes, eyesState);
        timerBlink = millis();
    }
}