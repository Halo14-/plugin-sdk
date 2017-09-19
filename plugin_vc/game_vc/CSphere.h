/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_VC.h"
#include "CVector.h"

class CSphere {
public:
    CVector m_vecCenter;
    float   m_fRadius;

    void Set(float radius, CVector  const& center);
};

VALIDATE_SIZE(CSphere, 0x10);