/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"

class CVehicle;

class CAutoPilot {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned int m_nSpeedScaleFactor;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    char field_28;
    char field_29;
    char field_2A;
    char field_2B;
    char field_2C;
    char m_nDrivingStyle;
    char m_nCarMission;
    char m_nAnimationId;
    unsigned int m_nAnimationTime;
    float field_34;
    unsigned char m_nCruiseSpeed;
    char field_39;
    char field_3A[14];
    void *m_pPathNodes[8];
    short m_nNumPathNodes;
    char field_6A[2];
    CVehicle *m_pCarToRam;
    
    //funcs
    void ModifySpeed(float arg0);
    void RemoveOnePathNode();
};

VALIDATE_SIZE(CAutoPilot, 0x70);