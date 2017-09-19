/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskComplexEnterCar.h"

class PLUGIN_API CTaskComplexOpenPassengerDoor : public CTaskComplexEnterCar {
protected:
    CTaskComplexOpenPassengerDoor(plugin::dummy_func_t a) : CTaskComplexEnterCar(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexOpenPassengerDoor, 0x);