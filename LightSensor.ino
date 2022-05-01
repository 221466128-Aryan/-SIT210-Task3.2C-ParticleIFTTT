#include "BH1750Lib.h"
#define UARTDEBUG 1

BH1750Lib lightsensor(0x23);
int lightvalue = 0;

void setup() {

    lightsensor.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
    Particle.variable("LightValue", &lightvalue, INT);

}

void loop() {

    lightvalue = lightsensor.lightLevel();
    
    
    
    char szEventInfo[64];
    sprintf(szEventInfo, "Light = %d lux", lightvalue);
    Particle.publish("bh1750info", szEventInfo);
    
    //wait for the next reading
    delay(10000);
}
