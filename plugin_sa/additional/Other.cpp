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
    		
    		logFile << "g_Console taking input w/ " << inputKey << "\n";
    		return true;
    	}
    }
}
int plugin::HandleConsoleKeyPress(unsigned int keyCode)
{
    switch(keyCode) {
        case VK_SHIFT:
            shift = !shift;
            break;
        case VK_F1:
            g_Console.drawConsole = !g_Console.drawConsole;
            break;
        case VK_RETURN:
            ParseConsoleCommand();
            break;
    }   
    logFile << "HandleConsoleKeyPress() called with " << keyCode << "\n";
}
