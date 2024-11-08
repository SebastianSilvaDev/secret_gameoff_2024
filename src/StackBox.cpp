#include "StackBox.h"
#include "MenuButton.h"

StackBox::StackBox()
{
    buttons.reserve(5);
}

StackBox::~StackBox()
{
    for (auto& button : buttons)
    {
        delete button;
    }
    buttons.clear();
}

void StackBox::process_input(double delta_time, SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDL_KeyCode::SDLK_UP:
            cycle_buttons(VerticalDirections::Up);
            break;
        case SDL_KeyCode::SDLK_DOWN:
            cycle_buttons(VerticalDirections::Down);
            break;
        case SDL_KeyCode::SDLK_SPACE:
            auto current_button = buttons[m_focused_button_index];
            if(current_button != nullptr)
            {
                current_button->execute_action();
            }
            break;
    }
}

void StackBox::draw(tcod::Console *in_console)
{
    for (auto& button : buttons)
    {
        button->draw(in_console);
    }
}

void StackBox::add_button(MenuButton *new_button)
{
    buttons.push_back(new_button);
}

MenuButton* StackBox::create_button(iVector2 in_position, int in_width, int in_height, std::string in_text, bool start_focused)
{
    auto new_button = buttons.emplace_back(new MenuButton(in_position, in_width, in_height, in_text, start_focused));
    if(start_focused)
    {
        for (auto& button : buttons)
        {
            button->set_state(ButtonStates::None);
        }
        new_button->set_state(ButtonStates::Focused);
        m_focused_button_index = buttons.size() - 1;
        return new_button;
    }
    if (buttons.size() <= 1)
    {
        new_button->set_state(ButtonStates::Focused);
        m_focused_button_index = 0;
    }
    return new_button;
}

void StackBox::cycle_buttons(VerticalDirections direction)
{
    auto current_button = buttons[m_focused_button_index];
    if (current_button != nullptr) 
    {
        current_button->set_state(ButtonStates::None);
    }
    switch(direction)
    {
        case VerticalDirections::Up:
            
            if (m_focused_button_index <= 0)
            {
                m_focused_button_index = buttons.size() - 1;
            }
            else
            {
                --m_focused_button_index;
            }
            break;
        case VerticalDirections::Down:
            ++m_focused_button_index;
            if (m_focused_button_index >= buttons.size())
            {
                m_focused_button_index = 0;
            }
            break;
        case VerticalDirections::None:
            break;
    }
    current_button = buttons[m_focused_button_index];
    if (current_button != nullptr)
    {
        current_button->set_state(ButtonStates::Focused);
    }
}
