#include "MenuButton.h"
#include "libtcod.h"

MenuButton::MenuButton(iVector2 in_position, int in_width, int in_height, std::string in_text, bool start_focused)
    : m_position(in_position), m_height(in_height), m_width(in_width), m_text(in_text)
{
    if(start_focused)
    {
        m_state = ButtonStates::Focused;
    }
    else
    {
        m_state = ButtonStates::None;
    }
}

MenuButton::~MenuButton()
{
}

void MenuButton::draw(tcod::Console *in_console)
{
    switch (m_state)
    {
    case ButtonStates::None:
        tcod::print_rect(*in_console, {m_position.x, m_position.y, m_width, m_height}, m_text, m_foreground_color, m_background_color, TCOD_alignment_t::TCOD_CENTER);
        break;
    
    case ButtonStates::Focused:
        tcod::print_rect(*in_console, {m_position.x, m_position.y, m_width, m_height}, m_text, m_background_color, m_foreground_color, TCOD_alignment_t::TCOD_CENTER);

    default:
        break;
    }

}

void MenuButton::click(iVector2 in_position)
{
}

void MenuButton::execute_action()
{
    if (button_callback == nullptr) return;

    button_callback();

}

void MenuButton::set_state(ButtonStates in_state)
{
    m_state = in_state;
}

void MenuButton::set_action_callback(void (*in_callback)())
{
    button_callback = in_callback;
}
