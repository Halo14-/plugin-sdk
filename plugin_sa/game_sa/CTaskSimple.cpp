/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CTaskSimple.h"

bool CTaskSimple::ProcessPed(class CPed *ped)
{
	return ((bool (__thiscall *)(CTaskSimple *, class CPed *))GetVMT(this, 7))(this, ped);
}

bool CTaskSimple::SetPedPosition(class CPed *ped)
{
	return ((bool (__thiscall *)(CTaskSimple *, class CPed *))GetVMT(this, 8))(this, ped);
}