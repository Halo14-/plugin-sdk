#pragma once

namespace plugin {
    bool KeyPressed(unsigned int keyCode);
    
    bool CheckValidConsoleKeyPress();   
    int HandleConsoleKeyPress(unsigned int keyCode);
}
