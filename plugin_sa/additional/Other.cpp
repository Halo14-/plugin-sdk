#include "Other.h"
#include <Windows.h>

bool plugin::KeyPressed(unsigned int keyCode) {
    return (GetKeyState(keyCode) & 0x8000) != 0;
}

bool plugin::TwoKeysPressed(unsigned int keyCode,
                            unsigned int keyCodeTwo) {
    //return (GetKeyState(keyCode) & 0x8000) != 0;
    return (GetAsyncKeyState(keyCode) &0x8000 && (GetAsyncKeyState(keyCodeTwo) &0x8000) != 0;
}
