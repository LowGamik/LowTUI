#ifndef LOWTUI_H
#define LOWTUI_H

#include <stdbool.h>
#include <stddef.h>

#define ESCAPE_CLEAR_SCREEN "\033[2J"
#define ESCAPE_HOME_POSITION "\033[H"
#define ESCAPE_RESET_STYLE "\033[0m"

void clearScreen();
void resetMousePosition();
void sleepMS(size_t time);
void setStyle(int foreGround, int backGround, bool isBold);
void enableRawMode();
void disableRawMode();

#endif