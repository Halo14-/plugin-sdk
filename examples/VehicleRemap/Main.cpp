﻿/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "plugin.h"
#include "game_sa\common.h"
#include "game_sa\CTimer.h"
#include "game_sa\CGeneral.h"
#include "game_sa\CModelInfo.h"

using namespace plugin;

class Remap {
public:
    class RemapInfo {
    public:
        bool permitRemap;

        RemapInfo(CVehicle *vehicle) {
            unsigned int random = CGeneral::GetRandomNumberInRange(0, 3);
            if (random == 1)
                permitRemap = true;
            else permitRemap = false;
        }
    };

    Remap() {
        static VehicleExtendedData<RemapInfo> remInfo;
        static unsigned int m_nLastTimeWhenAnyActionWasEnabled = 0;
        static unsigned int randomRemap;
        static unsigned int amountRemap;
        static int currentRemap = -1;

        Events::vehicleRenderEvent += [](CVehicle *vehicle) {
            if (vehicle && vehicle->m_wModelIndex > 399 && vehicle->m_wModelIndex < 612) {
                RemapInfo &info = remInfo.Get(vehicle);
                if (info.permitRemap) {
                    CVehicleModelInfo *vehModel = reinterpret_cast<CVehicleModelInfo *>(CModelInfo::ms_modelInfoPtrs[vehicle->m_wModelIndex]);
                    amountRemap = vehModel->GetNumRemaps();
                    if (amountRemap > 0) {
                        randomRemap = CGeneral::GetRandomNumberInRange(0, amountRemap);
                        vehicle->SetRemap(randomRemap);
                    }
                    info.permitRemap = false;
                }
            }
        };

        Events::gameProcessEvent += [] {
            CVehicle *plVehicle = FindPlayerVehicle(-1, false);
            if (plVehicle && plVehicle->m_wModelIndex > 399 && plVehicle->m_wModelIndex < 612) {
                if (CTimer::m_snTimeInMilliseconds >(m_nLastTimeWhenAnyActionWasEnabled + 1000) && KeyPressed(75)) {
                    m_nLastTimeWhenAnyActionWasEnabled = CTimer::m_snTimeInMilliseconds;
                    CVehicleModelInfo *plVehModel = reinterpret_cast<CVehicleModelInfo *>(CModelInfo::ms_modelInfoPtrs[plVehicle->m_wModelIndex]);
                    amountRemap = plVehModel->GetNumRemaps();
                    if (amountRemap > 0) {
                        if (currentRemap < static_cast<int>(amountRemap - 1))
                            ++currentRemap;
                        else currentRemap = -1;
                        plVehicle->SetRemap(currentRemap);
                    }
                }
            }
        };
    }
} remap;