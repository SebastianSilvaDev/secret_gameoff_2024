#include "StackBox.h"
#include "MenuButton.h"
#include "InputField.h"

StackBox::StackBox()
{
    buttons.reserve(5);
    focusable_elements.reserve(5);
}

StackBox::StackBox(size_t button_reserved_space)
{
    buttons.reserve(button_reserved_space);
    focusable_elements.reserve(button_reserved_space);
}

StackBox::StackBox(const StackBoxInitParams& init_params)
{
    if (init_params.buttons_texts.empty()) return;

    // we reseve the amount we want in the vector
    buttons.reserve(init_params.buttons_texts.size());

    iVector2 current_position = init_params.initial_position;
    size_t index = 0;
    for (auto& text : init_params.buttons_texts)
    {
        create_button(current_position, init_params.buttons_width, init_params.buttons_height, text, index == init_params.initial_focused_button_index);
        current_position.y += init_params.buttons_height + init_params.distance_between_entries;
        ++index;
    }
    create_input_field(current_position, init_params.buttons_width, init_params.buttons_width);
}

StackBox::~StackBox()
{
    // focusables dont own the objects
    focusable_elements.clear();
    for (auto& button : buttons)
    {
        delete button;
    }
    buttons.clear();
}

void StackBox::process_input(double delta_time, SDL_Keycode keycode)
{
    if (buttons.size() <= m_focused_button_index) return;
    auto current_button = buttons[m_focused_button_index];
    switch (keycode)
    {
        case SDL_KeyCode::SDLK_UP:
            cycle_buttons(VerticalDirections::Up);
            break;
        case SDL_KeyCode::SDLK_DOWN:
            cycle_buttons(VerticalDirections::Down);
            break;
        case SDL_KeyCode::SDLK_SPACE:
            if(current_button != nullptr)
            {
                if (auto actionable_button = dynamic_cast<Actionable*>(current_button))
                {
                    actionable_button->execute_action();
                }
            }
            break;
        default:
            if (auto input_processor_button = dynamic_cast<InputProcessor*>(current_button))
            {
                input_processor_button->process_input(delta_time, keycode);
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
    auto new_button = static_cast<MenuButton*>(buttons.emplace_back(new MenuButton(in_position, in_width, in_height, in_text)));
    focusable_elements.emplace_back(new_button);
    if(start_focused)
    {
        for (auto& button : buttons)
        {
            if (auto current_focusable = dynamic_cast<Focusable*>(button))
            {
                current_focusable->set_focus_state(false);
            }
        }
        new_button->set_focus_state(true);
        m_focused_button_index = buttons.size() - 1;
        return new_button;
    }
    if (buttons.size() <= 1)
    {
        new_button->set_focus_state(false);
        m_focused_button_index = 0;
    }

    return new_button;
}

InputField *StackBox::create_input_field(iVector2 in_position, int in_width, int in_height)
{
    auto new_input_field = dynamic_cast<InputField*>(buttons.emplace_back(new InputField(in_position, in_width, in_height, "")));
    focusable_elements.emplace_back(new_input_field);
    return new_input_field;
}

void StackBox::cycle_buttons(VerticalDirections direction)
{
    if (focusable_elements.empty()) return;
    auto current_button = focusable_elements[m_focused_button_index];
    if (current_button != nullptr) 
    {
        current_button->set_focus_state(false);
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
            if (m_focused_button_index >= focusable_elements.size())
            {
                m_focused_button_index = 0;
            }
            break;
        case VerticalDirections::None:
            break;
    }
    current_button = focusable_elements[m_focused_button_index];
    if (current_button != nullptr)
    {
        current_button->set_focus_state(true);
    }
}
