#pragma once

#include "plbase/PluginBase.h"
#include "CTaskComplex.h"

class PLUGIN_API CTaskComplexEnterCarAsDriverTimed : public CTaskComplex {
protected:
    CTaskComplexEnterCarAsDriverTimed(plugin::dummy_func_t a) : CTaskComplex(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexEnterCarAsDriverTimed, 0x);