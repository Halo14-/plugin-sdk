/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"

template<typename T>
class CLink {
public:
    T data;
    CLink<T>* prev;
    CLink<T>* next;
};

VALIDATE_SIZE(CLink<void *>, 0xC);