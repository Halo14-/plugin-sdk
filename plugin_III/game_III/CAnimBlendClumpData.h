/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"
#include "AnimBlendFrameData.h"

#pragma pack(push, 4)
class CAnimBlendClumpData {
public:
    void *m_pLastAssociationLink;
    int dword4;
    int m_nNumBones;
    int dwordC;
    AnimBlendFrameData *m_pBones;
        
    //funcs
    CAnimBlendClumpData();
    void SetNumberOfBones(int arg0);
    ~CAnimBlendClumpData();
    //CAnimBlendClumpData::ForAllFrames(void (*)(AnimBlendFrameData *,void *),void *) 0x401930
};
#pragma pack(pop)

VALIDATE_SIZE(CAnimBlendClumpData, 0x14);