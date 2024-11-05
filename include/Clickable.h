#pragma once
#include "Utils.h"

class Clickable
{
public:
    virtual void click(iVector2 in_position) = 0;
};