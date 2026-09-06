#ifndef LOWTUI_H
#define LOWTUI_H

#define ESCAPE_CLEAR_SCREEN "\033[2J"
#define ESCAPE_HOME_POSITION "\022[H"

void clearScreen();
void resetMousePosition();

#endif