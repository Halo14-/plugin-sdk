/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CMotionBlurStreaks.h"

unsigned int MAX_NUM_MOTIONBLUR_STREAKS = 4;

CRegisteredMotionBlurStreak *CMotionBlurStreaks::aStreaks = (CRegisteredMotionBlurStreak *)0xC7CA08;

// Converted from cdecl void CMotionBlurStreaks::Update(void) 0x7240C0
void CMotionBlurStreaks::Update() {
    plugin::Call<0x7240C0>();
}

// Converted from cdecl void CMotionBlurStreaks::Render(void) 0x7240E0
void CMotionBlurStreaks::Render() {
    plugin::Call<0x7240E0>();
}

// Converted from cdecl void CMotionBlurStreaks::RegisterStreak(uint red, uchar green, uchar blue, uchar alpha, CVector leftPoint, CVector rightPoint) 0x721DC0
void CMotionBlurStreaks::RegisterStreak(unsigned int red, unsigned char green, unsigned char blue, unsigned char alpha, CVector leftPoint, CVector rightPoint) {
    plugin::Call<0x721DC0, unsigned int, unsigned char, unsigned char, unsigned char, CVector, CVector>(red, green, blue, alpha, leftPoint, rightPoint);
}

// Converted from cdecl void CMotionBlurStreaks::Init(void) 0x721D90
void CMotionBlurStreaks::Init() {
    plugin::Call<0x721D90>();
}