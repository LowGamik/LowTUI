// CROSS PLATFORM STANDARD INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

// NATIVE PLATFORM INCLUDES
#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#else
    #include <termios.h>
    #include <unistd.h>

    struct termios orig_termios; 
#endif

// EVERYTHING FUCKING ELSE
#include "LowTUI.h"

void clearScreen(){
    printf(ESCAPE_CLEAR_SCREEN);
    fflush(stdout);
}

void resetMousePosition(){
    printf(ESCAPE_HOME_POSITION);
    fflush(stdout);
}

void sleepMS(size_t time){
    #ifdef _WIN32
        Sleep(time);
    #else
        usleep(time * 1000);
    #endif
}

void setStyle(int foreGround, int backGround, bool isBold){
    if(isBold){
        printf("\033[1;%d;%dm", foreGround, backGround);
    }else{
        printf("\033[%d;%dm", foreGround, backGround);
    }
    fflush(stdout);
}

#ifdef _WIN32
    void enableRawMode() {}
    void disableRawMode() {}
#else
    void enableRawMode() {
        struct termios raw;
        tcgetattr(STDIN_FILENO, &orig_termios);
        raw = orig_termios;
        raw.c_lflag &= ~(ECHO | ICANON | ISIG);
        raw.c_cc[VMIN] = 1;
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void disableRawMode() {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }
#endif