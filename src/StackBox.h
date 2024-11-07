#pragma once

// std
#include <vector>
#include <string>

#include "InputProcessor.h"
#include "ButtonStates.h"
#include "Drawable.h"
#include "Utils.h"

class MenuButton;

struct StackBoxInitParams
{
    iVector2 initial_position{0, 0};

    uint32_t distance_between_entries = 0;

    int buttons_width = 10;

    int buttons_height = 1;

    std::vector<std::string> buttons_texts{};

    uint32_t initial_focused_button_index = 0;

    StackBoxInitParams(
        iVector2 in_initial_position,
        uint32_t in_distance_between_entries,
        int in_buttons_width,
        int in_buttons_height,
        std::initializer_list<std::string> in_buttons_texts,
        uint32_t in_initial_focused_button_index
    )
    {
        initial_position = in_initial_position;
        distance_between_entries = in_distance_between_entries;
        buttons_width = in_buttons_width;
        buttons_height = in_buttons_height;
        buttons_texts = in_buttons_texts;
        initial_focused_button_index = in_initial_focused_button_index;
    }
};

class StackBox : public InputProcessor, public Drawable
{
public:

    StackBox();

    StackBox(size_t button_reserved_space);

    StackBox(const StackBoxInitParams& init_params);

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