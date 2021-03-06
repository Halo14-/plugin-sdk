/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskSimpleAnim.h"

class PLUGIN_API CTaskSimpleRunNamedAnim : public CTaskSimpleAnim {
protected:
    CTaskSimpleRunNamedAnim(plugin::dummy_func_t a) : CTaskSimpleAnim(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleRunNamedAnim, 0x);