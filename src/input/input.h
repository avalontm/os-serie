// ------------------------------------------------------------------------------------------------
// input/input.h
// ------------------------------------------------------------------------------------------------

#pragma once

#include "stdlib/types.h"

// ------------------------------------------------------------------------------------------------
extern int g_mouseX;
extern int g_mouseY;

void InputOnKey(uint code, uint val);
void InputOnMouse(int dx, int dy);