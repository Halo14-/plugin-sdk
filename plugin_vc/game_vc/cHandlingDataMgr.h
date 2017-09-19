/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_VC.h"
#include "tHandlingData.h"
#include "tBikeHandlingData.h"
#include "tFlyingHandlingData.h"
#include "tBoatHandlingData.h"

#pragma pack(push, 4)
class cHandlingDataMgr {
public:
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    tHandlingData       m_aVehicleHandling[106];
    tBikeHandlingData   m_aBikeHandling[5];
    tFlyingHandlingData m_aFlyingHandling[10];
    tBoatHandlingData   m_aBoatHandling[11];

    cHandlingDataMgr();
    // update some handling variables with some game-specific multipliers
    void ConvertDataToGameUnits(tHandlingData* handling);
    // get vehicle number id in names table
    int FindExactWord(char* line, char* nameTable, int entrySize, int entryCount);
    // get boat handling by id
    tBoatHandlingData* GetBoatPointer(unsigned char handlingId);
    // get flying handling by id
    tFlyingHandlingData* GetFlyingPointer(unsigned char handlingId);
    // get handling id by name
    int GetHandlingId(char const* name);
    void Initialise();
    // process handling.cfg
    void LoadHandlingData();
};
#pragma pack(pop)

//VALIDATE_SIZE(cHandlingDataMgr, 0x61FC);