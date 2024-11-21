#pragma once

#include <SDL_events.h>

class TextInput
{
public:
    virtual void process_text_input(const SDL_TextInputEvent& text_input_event) = 0;
};