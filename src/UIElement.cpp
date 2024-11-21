#include "UIElement.h"

UIElement::UIElement(iVector2 in_position, int in_width, int in_height, std::string in_text)
    : m_position(in_position), m_width(in_width), m_height(in_height)
{
    if (in_text.length() >= in_width)
    {
        m_text = in_text;
    }
    else
    {
        int length_dif = in_width - in_text.length();
        int text_padding = (length_dif) / 2;
        int front_padding = (length_dif & 1 == 0) ? text_padding : text_padding + 1;
        m_text = std::string(front_padding, ' ') + in_text + std::string(text_padding, ' ');
    }
}

UIElement::~UIElement()
{
}

void UIElement::draw(tcod::Console *in_console)
{
}
