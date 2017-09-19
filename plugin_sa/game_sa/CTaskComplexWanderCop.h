/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskComplexWander.h"

class PLUGIN_API CTaskComplexWanderCop : public CTaskComplexWander {
protected:
    CTaskComplexWanderCop(plugin::dummy_func_t a) : CTaskComplexWander(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexWanderCop, 0x);