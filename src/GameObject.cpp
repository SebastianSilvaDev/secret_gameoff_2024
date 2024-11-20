#include "GameObject.h"

GameObject::GameObject(iVector2 in_location, std::string in_characters)
    : m_location(in_location), m_characters(in_characters)
{
}

void GameObject::draw(tcod::Console *in_console)
{
    tcod::print(*in_console, {m_location.x, m_location.y}, m_characters, std::nullopt, std::nullopt, TCOD_alignment_t::TCOD_CENTER);
}

void GameObject::tick(double delta_time)
{
}

void GameObject::post_tick(double delta_time)
{
}

void GameObject::process_input(double delta_time, SDL_Keycode keycode)
{
}
