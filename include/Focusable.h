#pragma once

class Focusable
{

public:
    // The idea is to let each item have a different focus state, buttons can have clicked, None and focuse, while input field just needs a boolean
    virtual void set_focus_state(bool new_focus_state) = 0;

    virtual bool is_focused() = 0;

};