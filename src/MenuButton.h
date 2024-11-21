#pragma once

#include <string>
#include "UIElement.h"
#include "ButtonStates.h"
#include "Actionable.h"
#include "Focusable.h"

class MenuButton : public UIElement, public Actionable, public Focusable
{
public:

    MenuButton(iVector2 in_position, int in_width, int in_height, std::string in_text);

    // MenuButton(iVector2 in_position, int in_width, int in_height, std::string in_text, bool start_focused = false);

    virtual ~MenuButton() override;

    // begin Drawable Interface

    virtual void draw(tcod::Console* in_console) override;

    // end Drawable Interface

    // begin Actionable Interface
    
    virtual void execute_action() override;

    // end Actionable Interface

    // begin Focusable interface

    virtual void set_focus_state(bool new_focus_state) override;

    virtual bool is_focused() override
    {
        return m_state != ButtonStates::None;
    }

    // end Focusable interface

    void set_state(ButtonStates in_state);

    inline ButtonStates get_state() const
    {
        return m_state;
    }

    void set_action_callback(void (*in_callback)());

protected:
    ButtonStates m_state = ButtonStates::None;

    // function pointer
    void (*button_callback)() = nullptr;

};