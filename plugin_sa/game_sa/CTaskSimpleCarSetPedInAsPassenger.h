#pragma once

#include "plbase/PluginBase.h"
#include "CTaskSimple.h"

class PLUGIN_API CTaskSimpleCarSetPedInAsPassenger : public CTaskSimple {
protected:
    CTaskSimpleCarSetPedInAsPassenger(plugin::dummy_func_t a) : CTaskSimple(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleCarSetPedInAsPassenger, 0x);