/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CVector.h"

class CBox {
public:
	CVector m_vecSup;
	CVector m_vecInf;

	void Set(CVector  const& sup, CVector  const& inf);
	// updates box corners, like (if left>right then swap(left, right))
	void Recalc();
};

VALIDATE_SIZE(CBox, 0x18);