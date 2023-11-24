#include <PCF8575.h>

short topLeftTolerance = 10;
short topRightTolerance = -8;
short bottomLeftTolerance = -21;
short bottomRightTolerance = -11;

PCF8575 expander(0x20);

class Motor {
    private:
        uint8_t LeftPin;
        uint8_t RightPin;
        char PwmChannel;
        char PwmPin;
    public:
        Motor (uint8_t leftPin, uint8_t rightPin, char pwmPin, char pwmChannel){
            LeftPin = leftPin;
            RightPin = rightPin;
            PwmChannel = pwmChannel;
            PwmPin = pwmPin;
        }
        void setup(){
            expander.pinMode(LeftPin, OUTPUT);
            expander.pinMode(RightPin, OUTPUT);
            pinMode(PwmChannel, OUTPUT);
            Serial.println("this");
            ledcSetup(PwmChannel, 30000, 8);
            ledcAttachPin(PwmPin, PwmChannel);
        }
        void rotateLeft(short speed){
            if(speed >= 255) speed = 255; 
            expander.digitalWrite(LeftPin, 1);
            expander.digitalWrite(RightPin, 0);
            ledcWrite(PwmChannel, speed);
        }
        void rotateRight(short speed){
            if(speed >= 255) speed = 255; 
            expander.digitalWrite(LeftPin, 0);
            expander.digitalWrite(RightPin, 1);
            ledcWrite(PwmChannel, speed);
        }
        void stop(){
            expander.digitalWrite(LeftPin, 0);
            expander.digitalWrite(RightPin, 0);
            ledcWrite(PwmChannel, 0);
        }
};

Motor topLeft(P7, P6, 32, 0);
Motor bottomLeft(P4, P5, 33, 1);
Motor topRight(P2, P3, 25, 2);
Motor bottomRight(P1, P0, 26, 3);

void robotRotateLeft(short speed){
    topLeft.rotateLeft(speed - topLeftTolerance);
    topRight.rotateLeft(speed - topRightTolerance);
    bottomLeft.rotateRight(speed - bottomLeftTolerance);
    bottomRight.rotateRight(speed - bottomRightTolerance);
}

void robotRotateRight(short speed){
    topLeft.rotateRight(speed - topLeftTolerance);
    topRight.rotateRight(speed - topRightTolerance);
    bottomLeft.rotateLeft(speed - bottomLeftTolerance);
    bottomRight.rotateLeft(speed - bottomRightTolerance);
}

void robotRunForward(short speed){
    topLeft.rotateRight(speed - topLeftTolerance);
    topRight.rotateLeft(speed - topRightTolerance);
    bottomLeft.rotateLeft(speed - bottomLeftTolerance);
    bottomRight.rotateRight(speed - bottomRightTolerance);
}
void robotRunBackward(short speed){
    topLeft.rotateLeft(speed - topLeftTolerance);
    topRight.rotateRight(speed - topRightTolerance);
    bottomLeft.rotateRight(speed - bottomLeftTolerance);
    bottomRight.rotateLeft(speed - bottomRightTolerance);
}
void robotMoveLeft(short speed){
    topLeft.rotateLeft(speed - topLeftTolerance);
    topRight.rotateLeft(speed - topRightTolerance);
    bottomLeft.rotateLeft(speed - bottomLeftTolerance );
    bottomRight.rotateLeft(speed - bottomRightTolerance);
}
void robotMoveRight(short speed){
    topLeft.rotateRight(speed - topLeftTolerance);
    topRight.rotateRight(speed - topRightTolerance);
    bottomLeft.rotateRight(speed - bottomLeftTolerance);
    bottomRight.rotateRight(speed - bottomRightTolerance);
}

void carStop(){
    topLeft.rotateRight(0);
    topRight.rotateRight(0);
    bottomLeft.rotateRight(0);
    bottomRight.rotateRight(0);
    Serial.println("car stop");
}
void carSetup(){
    topLeft.setup();
    topRight.setup();
    bottomLeft.setup();
    bottomRight.setup();
}