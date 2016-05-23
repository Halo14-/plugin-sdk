#pragma once

#include "plbase/PluginBase.h"

class PLUGIN_API CGame
{
public:
	// Current number of area
	static __int32& currArea;

	static void TidyUpMemory(bool arg1, bool arg2);
	
	class CSpawnInfo {
	public:
		CVector SpawnCoords;
		CVector GotoCoords;
		
		int ModelID;
		
		int nSpecial;
		int nSpecial2;
		
		int nWeaponID;
	};
};
