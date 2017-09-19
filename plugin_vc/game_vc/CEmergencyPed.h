/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_VC.h"
#include "CPed.h"

class CEmergencyPed : public CPed
{
    CEmergencyPed(unsigned int arg0);
    void FiremanAI();
    void MedicAI();
};

VALIDATE_SIZE(CEmergencyPed, 0x5F4);