/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"
#include "CBuilding.h"

class CTreadable : public CBuilding {
public:
    //funcs

    CTreadable();
    static void operator delete(void* data);
    static void* operator new(unsigned int size);

    CTreadable(const CTreadable &) = delete;
    CTreadable &operator=(const CTreadable &) = delete;
};

VALIDATE_SIZE(CTreadable, 0x64);