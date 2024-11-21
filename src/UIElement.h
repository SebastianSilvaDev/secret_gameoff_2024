#pragma once

#include "Drawable.h"
#include "Utils.h"

#include <string>

class UIElement : public Drawable
{

public:

    UIElement() = delete;

    UIElement(const UIElement&) = delete;

    UIElement(iVector2 in_position, int in_width, int in_height, std::string in_text);

    virtual ~UIElement();

    virtual void draw(tcod::Console* in_console);

protected:

    iVector2 m_position{0, 0};

    int m_width = 0;

    int m_height = 0;

    std::string m_text = "";

    TCOD_ColorRGB m_foreground_color = {255, 255, 255};

    TCOD_ColorRGB m_background_color = {};

};