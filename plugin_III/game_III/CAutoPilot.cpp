/*
Plugin-SDK (Grand Theft Auto) source file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#include "CAutoPilot.h"

// Converted from thiscall void CAutoPilot::ModifySpeed(float) 0x4137B0 
void CAutoPilot::ModifySpeed(float arg0) {
    plugin::CallMethod<0x4137B0, CAutoPilot *, float>(this, arg0);
}

// Converted from thiscall void CAutoPilot::RemoveOnePathNode(void) 0x413A00 
void CAutoPilot::RemoveOnePathNode() {
    plugin::CallMethod<0x413A00, CAutoPilot *>(this);
}
