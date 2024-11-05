#pragma once

#include "libtcod.h"

class Drawable
{
public:
    virtual void draw(tcod::Console* in_console) = 0;
};