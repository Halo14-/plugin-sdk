/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"

#pragma pack(push, 4)
class PLUGIN_API CEntityScanner
{
protected:
    void *vtable;
public:
    int field_4;
    unsigned __int32 m_dwCount;
    class CEntity *m_apEntities[16];
    int field_4C;
};
#pragma pack(pop)

VALIDATE_SIZE(CEntityScanner, 0x50);