/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"
#include "tTransmissionGear.h"

#pragma pack(push, 4)
class cTransmission {
public:
    tTransmissionGear m_aGears[6];
    unsigned __int8   m_nDriveType; // F/R/4
    unsigned __int8   m_nEngineType; // P/D/E
    unsigned __int8   m_nNumberOfGears; // 1 to 6
    struct {
        unsigned __int8 m_b1gBoost : 1;
        unsigned __int8 m_b2gBoost : 1;
    } m_nBoostFlags;
    float             m_fEngineAcceleration; // 0.1 to 10.0
    float             m_fMaxGearVelocity;
    float             m_fEngineInertia; // 0.0 to 50.0
    float             m_fMinGearVelocity;
    float             m_fCurrentGearVelocity;
    float field_60;

    //funcs
    float CalculateDriveAcceleration(float const& gasPedal, unsigned char& currrentGear, float& arg2, float const& arg3, bool arg4);
    void CalculateGearForSimpleCar(float velocity, unsigned char& currrentGear);
    void InitGearRatios();
    cTransmission();
};
#pragma pack(pop)

VALIDATE_SIZE(cTransmission, 0x64);