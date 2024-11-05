#pragma once

// std
#include <vector>
#include <string>

#include "InputProcessor.h"
#include "ButtonStates.h"
#include "Drawable.h"
#include "Utils.h"

class MenuButton;

class StackBox : public InputProcessor, public Drawable
{
public:

    StackBox();

    ~StackBox();

    // begin InputProcessor Interface
    virtual void process_input(double delta_time, SDL_Keycode keycode) override;
    // end Input Processor Interface

    // begin Drawablke Interface
    virtual void draw(tcod::Console* in_console);
    // end Drawable interface

    void add_button(MenuButton* new_button);

    MenuButton* create_button(iVector2 in_position, int in_width, int in_height, std::string in_text, bool start_focused = false);

protected:
    void cycle_buttons(VerticalDirections direction = VerticalDirections::Down);

private:

    std::vector<MenuButton*> buttons;

    uint32_t m_focused_button_index = 0;

};