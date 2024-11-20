#pragma once

#include <string>
#include "Utils.h"
#include "Drawable.h"
#include "ButtonStates.h"
#include "Actionable.h"

class MenuButton : public Drawable, public Actionable
{
public:
    MenuButton() = delete;

    MenuButton(iVector2 in_position, int in_width, int in_height, std::string in_text, bool start_focused = false);

    MenuButton(MenuButton& b) = delete;

    virtual ~MenuButton();

    // begin Drawable Interface

    virtual void draw(tcod::Console* in_console) override;

    // end Drawable Interface

    // begin Actionable Interface
    
    virtual void execute_action() override;

    // end Actionable Interface

    void set_state(ButtonStates in_state);

    inline ButtonStates get_state() const
    {
        return m_state;
    }

    void set_action_callback(void (*in_callback)());

protected:

    iVector2 m_position = {0, 0};

    int m_width = 0;

    int m_height = 0;

    std::string m_text = "";

    ButtonStates m_state = ButtonStates::None;

    TCOD_ColorRGB m_foreground_color = {255, 255, 255};

    TCOD_ColorRGB m_background_color = {};

    // function pointer
    void (*button_callback)() = nullptr;

};