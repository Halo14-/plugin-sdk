#pragma once

#include "plbase/PluginBase.h"
#include "CTaskComplex.h"

class PLUGIN_API CTaskComplexHitResponse : public CTaskComplex {
protected:
    CTaskComplexHitResponse(plugin::dummy_func_t a) : CTaskComplex(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexHitResponse, 0x);