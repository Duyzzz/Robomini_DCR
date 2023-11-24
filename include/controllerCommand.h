#include <moving.h>
#include <Ps3Controller.h>
#include <fire.h>
int player = 0;
int battery = 0;
bool isMoving = false;
short lowSpeed = 150;
short highSpeed = 250;
void notify()
{
    //--- Digital cross/square/triangle/circle button events ---
    
    if( Ps3.event.button_up.cross )
        Serial.println("Released the cross button");

    if( Ps3.event.button_down.square )
        Serial.println("Started pressing the square button");
    if( Ps3.event.button_up.square )
        Serial.println("Released the square button");

    if( Ps3.event.button_down.triangle )
        Serial.println("Started pressing the triangle button");
    if( Ps3.event.button_up.triangle )
        Serial.println("Released the triangle button");

    if( Ps3.event.button_down.circle )
        Serial.println("Started pressing the circle button");
    if( Ps3.event.button_up.circle )
        Serial.println("Released the circle button");

    //--------------- Digital D-pad button events --------------
    if( Ps3.event.button_down.up )
        Serial.println("Started pressing the up button");
    if( Ps3.event.button_up.up )
        Serial.println("Released the up button");

    if( Ps3.event.button_down.right )
        Serial.println("Started pressing the right button");
    if( Ps3.event.button_up.right )
        Serial.println("Released the right button");

    if( Ps3.event.button_down.down )
        Serial.println("Started pressing the down button");
    if( Ps3.event.button_up.down )
        Serial.println("Released the down button");

    if( Ps3.event.button_down.left )
        Serial.println("Started pressing the left button");
    if( Ps3.event.button_up.left )
        Serial.println("Released the left button");

    //------------- Digital shoulder button events -------------
    if( Ps3.event.button_down.l1 )
        Serial.println("Started pressing the left shoulder button");
    if( Ps3.event.button_up.l1 )
        Serial.println("Released the left shoulder button");

    if( Ps3.event.button_down.r1 )
        Serial.println("Started pressing the right shoulder button");
    if( Ps3.event.button_up.r1 )
        Serial.println("Released the right shoulder button");

    //-------------- Digital trigger button events -------------
    if( Ps3.event.button_down.l2 )
        Serial.println("Started pressing the left trigger button");
    if( Ps3.event.button_up.l2 )
        Serial.println("Released the left trigger button");

    if( Ps3.event.button_down.r2 )
        Serial.println("Started pressing the right trigger button");
    if( Ps3.event.button_up.r2 )
        Serial.println("Released the right trigger button");

    //--------------- Digital stick button events --------------
    if( Ps3.event.button_down.l3 )
        Serial.println("Started pressing the left stick button");
    if( Ps3.event.button_up.l3 )
        Serial.println("Released the left stick button");

    if( Ps3.event.button_down.r3 )
        Serial.println("Started pressing the right stick button");
    if( Ps3.event.button_up.r3 )
        Serial.println("Released the right stick button");

    //---------- Digital select/start/ps button events ---------
    if( Ps3.event.button_down.select )
        Serial.println("Started pressing the select button");
    if( Ps3.event.button_up.select )
        Serial.println("Released the select button");

    if( Ps3.event.button_down.start )
        Serial.println("Started pressing the start button");
    if( Ps3.event.button_up.start )
        Serial.println("Released the start button");

    if( Ps3.event.button_down.ps )
        Serial.println("Started pressing the Playstation button");
    if( Ps3.event.button_up.ps )
        Serial.println("Released the Playstation button");


    //---------------- Analog stick value events ---------------
    if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){
        Serial.print("Moved the left stick:");
        Serial.print(" x="); Serial.print(Ps3.data.analog.stick.lx, DEC);
        Serial.print(" y="); Serial.print(Ps3.data.analog.stick.ly, DEC);
        Serial.println();
    }

    if( abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2 ){
        Serial.print("Moved the right stick:");
        Serial.print(" x="); Serial.print(Ps3.data.analog.stick.rx, DEC);
        Serial.print(" y="); Serial.print(Ps3.data.analog.stick.ry, DEC);
        Serial.println();
    }

   //--------------- Analog D-pad button events ----------------
    if( abs(Ps3.event.analog_changed.button.up) ){
        Serial.print("Pressing the up button: ");
        Serial.println(Ps3.data.analog.button.up, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.right) ){
        Serial.print("Pressing the right button: ");
        Serial.println(Ps3.data.analog.button.right, DEC);
    }    

    if( abs(Ps3.event.analog_changed.button.down) ){
        Serial.print("Pressing the down button: ");
        Serial.println(Ps3.data.analog.button.down, DEC);
    }    

    if( abs(Ps3.event.analog_changed.button.left) ){
        Serial.print("Pressing the left button: ");
        Serial.println(Ps3.data.analog.button.left, DEC);
    }

   //---------- Analog shoulder/trigger button events ----------
    if( abs(Ps3.event.analog_changed.button.l1)){
        Serial.print("Pressing the left shoulder button: ");
        Serial.println(Ps3.data.analog.button.l1, DEC);
    }    

    if( abs(Ps3.event.analog_changed.button.r1) ){
        Serial.print("Pressing the right shoulder button: ");
        Serial.println(Ps3.data.analog.button.r1, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.l2) ){
        Serial.print("Pressing the left trigger button: ");
        Serial.println(Ps3.data.analog.button.l2, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.r2) ){
        Serial.print("Pressing the right trigger button: ");
        Serial.println(Ps3.data.analog.button.r2, DEC);
    }

   //---- Analog cross/square/triangle/circle button events ----
    if( abs(Ps3.event.analog_changed.button.triangle)){
        Serial.print("Pressing the triangle button: ");
        Serial.println(Ps3.data.analog.button.triangle, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.circle) ){
        Serial.print("Pressing the circle button: ");
        Serial.println(Ps3.data.analog.button.circle, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.cross) ){
        Serial.print("Pressing the cross button: ");
        Serial.println(Ps3.data.analog.button.cross, DEC);
    }

    if( abs(Ps3.event.analog_changed.button.square) ){
        Serial.print("Pressing the square button: ");
        Serial.println(Ps3.data.analog.button.square, DEC);
    }

   //---------------------- Battery events ---------------------
    if( battery != Ps3.data.status.battery ){
        battery = Ps3.data.status.battery;
        Serial.print("The controller battery is ");
        if( battery == ps3_status_battery_charging )      Serial.println("charging");
        else if( battery == ps3_status_battery_full )     Serial.println("FULL");
        else if( battery == ps3_status_battery_high )     Serial.println("HIGH");
        else if( battery == ps3_status_battery_low)       Serial.println("LOW");
        else if( battery == ps3_status_battery_dying )    Serial.println("DYING");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("SHUTDOWN");
        else Serial.println("UNDEFINED");
    }

}

void onConnect(){
    Serial.println("Connected.");
    Ps3.setPlayer(7);

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
            robotRotateLeft(highSpeed);
            Serial.println("fast rotate left");
            isMoving = false;
        } else if(Ps3.data.button.l2){
            robotRotateLeft(lowSpeed);
            Serial.println("slow rotate left");
            isMoving = false;
        }
        else if(Ps3.data.button.r2 && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotRotateRight(highSpeed);
            Serial.println("fast rotate right");
            isMoving = false;
        } else if(Ps3.data.button.r2){
            robotRotateRight(lowSpeed);
            Serial.println("slow rotate right");
            isMoving = false;
        }
        else if(Ps3.data.button.up && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotRunForward(highSpeed);
            Serial.println("fast up");
            isMoving = false;
        } else if(Ps3.data.button.up){
            Serial.println("slow up");
            robotRunForward(lowSpeed);
            isMoving = false;
        }
        else if(Ps3.data.button.down && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotRunBackward(highSpeed);
            Serial.println("fast back");
            isMoving = false;
        } else if(Ps3.data.button.down){
            robotRunBackward(lowSpeed);
            Serial.println("slow back");
            isMoving = false;
        }
        else if(Ps3.data.button.left && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            Serial.println("fast left");
            robotMoveLeft(highSpeed);
            isMoving = false;
        } else if(Ps3.data.button.left){
            Serial.println("slow left");
            robotMoveLeft(lowSpeed);
            isMoving = false;
        }
        else if(Ps3.data.button.right && (Ps3.data.button.l1 || Ps3.data.button.r1)){
            robotMoveRight(highSpeed);
            Serial.println("fast right");
            isMoving = false;
        } else if(Ps3.data.button.right){
            Serial.println("slow right");
            robotMoveRight(lowSpeed);
            isMoving = false;
        }
        
    }
    if(isMoving == false && !Ps3.data.button.r2 && !Ps3.data.button.l2 && !Ps3.data.button.right && !Ps3.data.button.left && !Ps3.data.button.down && !Ps3.data.button.up){
        carStop();
        isMoving = true;
    }
    // ban
    if(Ps3.event.button_down.circle){
        fire();
    }
    autoPull();
}
