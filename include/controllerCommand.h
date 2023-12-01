#include <moving.h>
#include <Ps3Controller.h>
#include <fire.h>
int player = 0;
int battery = 0;
bool isMoving = false;
bool isBrake = false;
short lowSpeed = 150;
short highSpeed = 250;

void onConnect(){
    Serial.println("Connected.");
}

void controllerSetup(){
    //Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin("00:01:02:00:00:00");
    Serial.println("Controller is Ready.");
}

void espExecuteCommand(){
    // moving
    if(true){
        if(Ps3.data.button.l2 && (Ps3.data.button.l1 || Ps3.data.button.r1) ){
            robotRotateLeft(highSpeed - 60);
            Serial.println("fast rotate left");
            isMoving = true;
            isBrake = true;
        } else if(Ps3.data.button.l2){
            robotRotateLeft(lowSpeed - 5);
            Serial.println("slow rotate left");
            isBrake = false;
            isMoving = false;
        }
        else if(Ps3.data.button.r2 && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotRotateRight(highSpeed - 60);
            Serial.println("fast rotate right");
            isMoving = true;
            isBrake = true;
        } else if(Ps3.data.button.r2){
            robotRotateRight(lowSpeed - 5);
            Serial.println("slow rotate right");
            isBrake = false;
            isMoving = false;
        }
        else if(Ps3.data.button.up && (Ps3.data.button.l1 || Ps3.data.button.r1)){
                robotRunForward(highSpeed);
                Serial.println("fast up");
                isMoving = true;
                isBrake = true;
            } else if(Ps3.data.button.up){
                Serial.println("slow up");
                robotRunForward(lowSpeed);
                isBrake = false;
                isMoving = false;
            }
        else if(Ps3.data.button.down && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotRunBackward(highSpeed);
            Serial.println("fast back");
            isBrake = false;
            isMoving = false;
        } else if(Ps3.data.button.down){
            robotRunBackward(lowSpeed);
            Serial.println("slow back");
            isBrake = false;
            isMoving = false;
        }
        else if(Ps3.data.button.left && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            Serial.println("fast left");
            robotMoveLeft(highSpeed);
            isMoving = true;
            isBrake = true;
        } else if(Ps3.data.button.left){
            Serial.println("slow left");
            robotMoveLeft(lowSpeed);
            isMoving = false;
            isBrake = false;
        }
        else if(Ps3.data.button.right && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotMoveRight(highSpeed);
            Serial.println("fast right");
            isMoving = true;
            isBrake = true;
        } else if(Ps3.data.button.right){
            Serial.println("slow right");
            robotMoveRight(lowSpeed);
            isMoving = false;
            isBrake = false;
        }
    }
    //infraredDetermine();
    if(isBrake == true && !Ps3.data.button.right && !Ps3.data.button.left && !Ps3.data.button.down && !Ps3.data.button.up && !Ps3.data.button.r2 && !Ps3.data.button.l2){
        isBrake = false;
        carBrake();
    }
    if(isMoving == false && isBrake == false && !Ps3.data.button.r2 && !Ps3.data.button.l2 && !Ps3.data.button.right && !Ps3.data.button.left && !Ps3.data.button.down && !Ps3.data.button.up){
        isMoving = true;
        carStop();
    }
    // ban
    if(Ps3.event.button_down.r3 || Ps3.event.button_down.l3){
        fire();
    }
    autoPull();
}
