/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_VC.h"
#include "CVector.h"
#include "eVehicleModel.h"

class CVehicle;

#pragma pack(push, 4)
class CCarGenerator {
public:
    eVehicleModel  m_nModelId;
    CVector        m_vPos;
    float          m_fAngle;
    short          m_nPrimaryColor;
    short          m_nSecondaryColor;
    unsigned char  m_nForceSpawn;
    unsigned char  m_nAlarm;
    unsigned char  m_nDoorLock;
    char field_1B;
    unsigned short m_nMinDelay;
    unsigned short m_nMaxDelay;
    unsigned int   m_nTimeNextGen;
    CVehicle      *m_pVehicle;
    short          m_nEnabled;
    char field_2A;
    char field_2B;
    
    //funcs
    bool CheckForBlockage(int modelId);
    bool CheckIfWithinRangeOfAnyPlayers();
    void DoInternalProcessing();
    void Process();
    unsigned int Setup(float x, float y, float z, float angle, int modelId, short primaryColor, short secondaryColor, unsigned char forceSpawn, unsigned char alarm, unsigned char doorLock, unsigned short minDelay, unsigned short maxDelay);
    void SwitchOff();
    void SwitchOn();
};
#pragma pack(pop)

VALIDATE_SIZE(CCarGenerator, 0x2C);