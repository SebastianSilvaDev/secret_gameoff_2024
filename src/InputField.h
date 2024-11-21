#pragma once

#include "UIElement.h"
#include "InputProcessor.h"
#include "Focusable.h"

class InputField : public UIElement, public InputProcessor, public Focusable
{

public:

    InputField(iVector2 in_position, int in_width, int in_height, std::string in_text);

    virtual ~InputField() override;

    // Begin of Drawable Interface
    
    virtual void draw(tcod::Console* in_console) override;

    // End of Drawable Interface

    // Begin of Input Processor
    virtual void process_input(double delta_time, SDL_Keycode keycode);

    // End of Input Processor

    // Begin of Focusable Interface

    virtual void set_focus_state(bool new_focus_state) override;

    virtual bool is_focused() override
    {
        return m_is_focused;
    }

    // End of Focusable Interface

protected:

    bool m_is_focused = false;

};