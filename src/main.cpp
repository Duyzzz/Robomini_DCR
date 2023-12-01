#include <controllerCommand.h>
#include <makeColor.h>

void setup()
{
    expander.begin();
    controllerSetup();
    setBlink();
    carSetup();
    gunSetup();
    Serial.begin(115200);
}

void loop()
{
    espExecuteCommand();
    led();
    delay(10);
}
