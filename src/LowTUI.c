// CROSS PLATFORM INCLUDES
#include <stdio.h>

// NATIVE PLATFORM INCLUDES
#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#else
    #include <termios.h>
#endif

#include "LowTUI.h"

void clearScreen(){
    printf(ESCAPE_CLEAR_SCREEN);
    fflush(stdout);
}

void resetMousePosition(){
    printf(ESCAPE_HOME_POSITION);
    fflush(stdout);
}