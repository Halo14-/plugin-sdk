#pragma once

#include "plbase/PluginBase.h"
#include "CTaskSimpleRunAnim.h"

class PLUGIN_API CTaskSimpleHitByGunFromRight : public CTaskSimpleRunAnim {
protected:
    CTaskSimpleHitByGunFromRight(plugin::dummy_func_t a) : CTaskSimpleRunAnim(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleHitByGunFromRight, 0x);