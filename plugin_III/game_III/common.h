/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"
#include "CVector.h"
#include "CPed.h"
#include "CVehicle.h"
#include "CTrain.h"
#include "CAnimBlendClumpData.h"

// returns player angle in radians
float FindPlayerHeading();
// gets player coords with skipping sniper shift
CVector& FindPlayerCentreOfWorld_NoSniperShift();
// gets player coords
CVector& FindPlayerCentreOfWorld(int playerId);
// returns player ped
CPed* FindPlayerPed();
// returns player train
CTrain* FindPlayerTrain();
// returns player ped or player vehicle if he's driving
CEntity* FindPlayerEntity();
// returns player vehicle
CVehicle* FindPlayerVehicle();
// returns player speed
CVector& FindPlayerSpeed();
// returns player coors
CVector& FindPlayerCoors();

RwTexture* GetFirstTexture(RwTexDictionary* texDictionary);
RwObject* GetFirstObject(RwFrame* frame);
RpAtomic* GetFirstAtomic(RpClump* clump);
RwFrame* GetFirstChild(RwFrame* frame);
RpAtomic* GetFirstAtomicCallback(RpAtomic* atomic, void* data);
RwObject* GetFirstObjectCallback(RwObject* object, void* data);
RwFrame* GetFirstFrameCallback(RwFrame* frame, void* data);
RwTexture* GetFirstTextureCallback(RwTexture* texture, void* data);

void WorldReplaceScorchedLightsWithNormal(RpWorld* world);
// dummy function
void CreateDebugFont();
// dummy function                                                            
void DestroyDebugFont();
// dummy function                                                            
void FlushObrsPrintfs();
void DefinedState();
CAnimBlendClumpData* RpAnimBlendAllocateData(RpClump* clump);
bool RpAnimBlendPluginAttach();
AnimBlendFrameData* RpAnimBlendClumpFindFrame(RpClump* clump, char const* name);
void RpAnimBlendClumpInit(RpClump* clump);
bool RpAnimBlendClumpIsInitialized(RpClump* clump);
RpClump* AnimBlendClumpDestroy(RpClump* clump);
void SetAmbientColours(RwRGBAReal* colours);
void SetAmbientColoursForPedsCarsAndObjects();
void SetAmbientColours();
void ActivateDirectional();
void DeActivateDirectional();
void ReSetAmbientAndDirectionalColours();
void SetBrightMarkerColours(float power);
void SetAmbientAndDirectionalColours(float power);
void RemoveExtraDirectionalLights(RpWorld* world);
void AddAnExtraDirectionalLight(RpWorld* world, float x, float y, float z, float red, float green, float blue);
void WorldReplaceNormalLightsWithScorched(RpWorld* world, float intensity);
RpWorld* LightsDestroy(RpWorld* world);
RpWorld* LightsCreate(RpWorld* world);
void SetLightsWithTimeOfDayColour(RpWorld* world);

extern uint32_t &ClumpOffset;
extern AnimBlendFrameData **pFrameDataFound;