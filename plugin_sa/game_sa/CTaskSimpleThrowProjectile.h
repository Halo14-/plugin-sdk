#pragma once

#include "plbase/PluginBase.h"
#include "CTaskSimple.h"

class PLUGIN_API CTaskSimpleThrowProjectile : public CTaskSimple {
protected:
    CTaskSimpleThrowProjectile(plugin::dummy_func_t a) : CTaskSimple(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleThrowProjectile, 0x);