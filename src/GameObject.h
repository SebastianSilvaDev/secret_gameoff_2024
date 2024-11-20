#pragma once

// std
#include <string>

#include "Drawable.h"
#include "Tickable.h"
#include "InputProcessor.h"
#include "Utils.h"

class GameObject : public Drawable, public Tickable, public InputProcessor
{
public:
    GameObject() = delete;

    GameObject(iVector2 in_location, std::string in_characters);

    // begin Drawable interface

    virtual void draw(tcod::Console* in_console) override;

    // end Drawable interface

    // begin tickable interface

    virtual void tick(double delta_time) override;

    virtual void post_tick(double delta_time) override;

    // end tickable interface

    // begin input processor interface

    virtual void process_input(double delta_time, SDL_Keycode keycode) override;

    // end input processor interface

protected:
    iVector2 m_location;

    std::string_view m_characters;

};