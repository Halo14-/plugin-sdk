#include "Other.h"
#include <Windows.h>

bool plugin::KeyPressed(unsigned int keyCode) {
    return (GetKeyState(keyCode) & 0x8000) != 0;
}
bool plugin::CheckValidConsoleKeyPress()
    for(int i = 8; i <= 190; i++) {
    	if(GetAsyncKeyState(i) != -32767) { 
    		int inputKey = PrepareInputForCommandParsing(&i);		
    		g_Console.takeInput(inputKey);
    		
    		return true;
    	}
    }
}
