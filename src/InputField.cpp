#include "InputField.h"

InputField::InputField(iVector2 in_position, int in_width, int in_height, std::string in_text) : UIElement(in_position, in_width, in_height, in_text)
{
}

InputField::~InputField()
{
}

void InputField::draw(tcod::Console *in_console)
{
    if (m_is_focused)
    {
        tcod::print_rect(*in_console, {m_position.x, m_position.y, m_width, m_height}, m_text, m_background_color, m_foreground_color, TCOD_alignment_t::TCOD_CENTER, TCOD_BKGND_LIGHTEN);
    }
    else
    {
        tcod::print_rect(*in_console, {m_position.x, m_position.y, m_width, m_height}, m_text, m_foreground_color, m_background_color, TCOD_alignment_t::TCOD_CENTER, TCOD_BKGND_LIGHTEN);
    }
}

void InputField::process_input(double delta_time, SDL_Keycode keycode)
{
    if(is_focused())
    {
        m_text += keycode;
    }
}

void InputField::set_focus_state(bool new_focus_state)
{
    m_is_focused = new_focus_state;
}
