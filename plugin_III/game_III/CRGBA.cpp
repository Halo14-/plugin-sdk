/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CRGBA.h"

// Converted from thiscall void CRGBA::CRGBA(uchar r, uchar g, uchar b, uchar a) 0x4F8C20
CRGBA::CRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    ((void(__thiscall *)(CRGBA*, unsigned char, unsigned char, unsigned char, unsigned char))0x4F8C20)(this, r, g, b, a);
}

// Converted from thiscall void CRGBA::~CRGBA() 0x40B290
CRGBA::~CRGBA() {
    plugin::CallMethod<0x40B290, CRGBA *>(this);
}
