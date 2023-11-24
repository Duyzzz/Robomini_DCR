#include <controllerCommand.h>

void setup()
{
    expander.begin();
    controllerSetup();
    carSetup();
    gunSetup();
    Serial.begin(115200);
}

void loop()
{
    espExecuteCommand();
    delay(1);
}
