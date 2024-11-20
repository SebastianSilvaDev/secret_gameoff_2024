#pragma once

class Tickable
{
public:
    virtual void tick(double delta_time) = 0;

    virtual void post_tick(double delta_time) = 0;
};