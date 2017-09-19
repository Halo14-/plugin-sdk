/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_III.h"
#include "CVector.h"
#include "cTransmission.h"
#include "eVehicleFlags.h"

enum eVehicleLightsSize : unsigned __int8 {
    LIGHTS_LONG,
    LIGHTS_SMALL,
    LIGHTS_BIG,
    LIGHTS_TALL
};

#pragma pack(push, 4)
struct tHandlingData {
    tHandlingData *index;
    float m_fMass; // 1.0 to 50000.0
    float field_8; 
    float m_fTurnMass; 
    RwV3d m_vDimensions; // 0.0 > x > 20.0
    RwV3d m_vCentreOfMass; // -10.0 > x > 10.0
    int m_nPercentSubmerged; // 10 to 120
    float m_fBuoyancyConstant; 
    float m_fTractionMultiplier; // 0.5 to 2.0
    cTransmission m_transmissionData; 
    float m_fBrakeBias; // 0.0 > x > 1.0
    bool m_bABS; 
    char field_9D; 
    char field_9E; 
    char field_9F; 
    float m_fSteeringLock; // 10.0 to 40.0
    float m_fTractionLoss; // 0.0 > x > 1.0
    float m_fTractionBias; // 0.0 > x > 1.0
    int field_AC; 
    float m_fSuspensionForceLevel;   // not [L/M/H]
    float m_fSuspensionDampingLevel; // not [L/M/H]
    float m_fSuspensionUpperLimit; 
    float m_fSuspensionLowerLimit; 
    float m_fSuspensionBiasBetweenFrontAndRear; 
    float m_fCollisionDamageMultiplier; // 0.2 to 5.0
    union {
        eVehicleFlags m_nVehicleFlags;
        struct {
            unsigned __int32 m_b1gBoost : 1;
            unsigned __int32 m_b2gBoost : 1;
            unsigned __int32 m_bRevBonnet : 1;
            unsigned __int32 m_bHangingBoot : 1;
            unsigned __int32 m_bNoDoors : 1;
            unsigned __int32 m_bIsVan : 1;
            unsigned __int32 m_bIsBus : 1;
            unsigned __int32 m_bIsLow : 1;
            unsigned __int32 m_bDblExhaust : 1;
            unsigned __int32 m_bTailgateBoot : 1;
            unsigned __int32 m_bNoswingBoot : 1;
            unsigned __int32 m_bNonplayerStabiliser : 1;
            unsigned __int32 m_bNeutralHandling : 1;
            unsigned __int32 m_bHasNoRoof : 1;
            unsigned __int32 m_bIsBig : 1;
            unsigned __int32 m_bHalogenLights : 1;
        };
    };
    float m_fSeatOffsetDistance; // ped seat position offset towards centre of car
    unsigned __int32 m_nMonetaryValue; // 1 to 100000
    eVehicleLightsSize m_nFrontLights;
    eVehicleLightsSize m_nRearLights;
    short field_D6;
};
#pragma pack(pop)

VALIDATE_SIZE(tHandlingData, 0xD8);