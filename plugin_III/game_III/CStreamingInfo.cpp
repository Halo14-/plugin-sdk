/*
Plugin-SDK (Grand Theft Auto) header file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#include "CStreamingInfo.h"

// Converted from thiscall CStreamingInfo* CStreamingInfo::AddToList(CStreamingInfo* listStart) 0x406380
CStreamingInfo* CStreamingInfo::AddToList(CStreamingInfo* listStart) {
    return plugin::CallMethodAndReturn<CStreamingInfo*, 0x406380, CStreamingInfo *, CStreamingInfo*>(this, listStart);
}

// Converted from thiscall bool CStreamingInfo::GetCdPosnAndSize(uint &posn, uint &size) 0x4063E0
bool CStreamingInfo::GetCdPosnAndSize(unsigned int& posn, unsigned int& size) {
    return plugin::CallMethodAndReturn<bool, 0x4063E0, CStreamingInfo *, unsigned int&, unsigned int&>(this, posn, size);
}

// Converted from thiscall int CStreamingInfo::GetCdSize(void) 0x4063D0
int CStreamingInfo::GetCdSize() {
    return plugin::CallMethodAndReturn<int, 0x4063D0, CStreamingInfo *>(this);
}

// Converted from thiscall CStreamingInfo* CStreamingInfo::RemoveFromList(void) 0x4063A0
CStreamingInfo* CStreamingInfo::RemoveFromList() {
    return plugin::CallMethodAndReturn<CStreamingInfo*, 0x4063A0, CStreamingInfo *>(this);
}

// Converted from thiscall void CStreamingInfo::SetCdPosnAndSize(uint posn, uint size) 0x406410
void CStreamingInfo::SetCdPosnAndSize(unsigned int posn, unsigned int size) {
    plugin::CallMethod<0x406410, CStreamingInfo *, unsigned int, unsigned int>(this, posn, size);
}
