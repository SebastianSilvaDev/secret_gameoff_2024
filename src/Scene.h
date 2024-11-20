#pragma once

// std includes
#include <string>

#include "Drawable.h"
#include "Actionable.h"

class Scene
{

public:
    // Remove the default Constructor
    Scene() = delete;

    Scene(std::string in_scene_name /*in the future we will have a initialization with a file*/);

    std::string get_name() const;

    // I wont implement the interface. it will have its independend draw
    // Im not considering scene inside scene yet
    void draw(tcod::Console* in_console);

    void tick(double delta_time);

private:
    std::string m_name = "";

};