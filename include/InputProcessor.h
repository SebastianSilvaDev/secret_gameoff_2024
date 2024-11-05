#pragma once
#include "SDL_keycode.h"

class InputProcessor
{
public:
    virtual void process_input(double delta_time, SDL_Keycode keycode) = 0;
};