#include <Arduino.h>

const char relayPin = 0;
const char limitSwitchPin = 2;
unsigned long timeWait = 0;
bool readyToFire = false;
bool pullState = false;
// tranh doc cam bien nhieu lan
unsigned long block = 0;
void gunSetup(){
    pinMode(relayPin, OUTPUT);
    pinMode(limitSwitchPin, INPUT_PULLUP);
}
void autoPull(){
    if(!readyToFire && digitalRead(limitSwitchPin) == HIGH && millis() - timeWait > 20 && pullState == false){
        digitalWrite(relayPin, LOW);
        Serial.println("start pull");
        pullState = true;
    } else if(!readyToFire && digitalRead(limitSwitchPin) == LOW &&  millis() - block > 200){
        digitalWrite(relayPin, HIGH);
        Serial.println("Press circle to fire");
        readyToFire = true;
        pullState = true;
    }
}
void fire(){
    if(readyToFire){
        digitalWrite(relayPin, LOW);
        Serial.println("FIRE!");
        timeWait = millis();
        block = millis();
        readyToFire = false;
        pullState = false;
    }
}