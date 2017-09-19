/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_III.h"

class CEntity;

class CReference {
public:
    CReference *m_pNext;
    CEntity **m_ppEntity;
};

VALIDATE_SIZE(CReference, 8);