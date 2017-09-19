/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskComplexKillPedOnFoot.h"

class PLUGIN_API CTaskComplexKillPedOnFootStealth : public CTaskComplexKillPedOnFoot {
protected:
    CTaskComplexKillPedOnFootStealth(plugin::dummy_func_t a) : CTaskComplexKillPedOnFoot(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexKillPedOnFootStealth, 0x);