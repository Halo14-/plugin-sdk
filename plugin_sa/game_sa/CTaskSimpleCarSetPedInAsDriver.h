#pragma once

#include "plbase/PluginBase.h"
#include "CTaskSimple.h"

class PLUGIN_API CTaskSimpleCarSetPedInAsDriver : public CTaskSimple {
protected:
    CTaskSimpleCarSetPedInAsDriver(plugin::dummy_func_t a) : CTaskSimple(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleCarSetPedInAsDriver, 0x);