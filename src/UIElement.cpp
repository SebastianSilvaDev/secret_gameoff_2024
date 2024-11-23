#include "UIElement.h"

UIElement::UIElement(iVector2 in_position, int in_width, int in_height, std::string in_text)
    : m_position(in_position), m_width(in_width), m_height(in_height), m_text(in_text)
{
    for (int i = 0; i < in_height; i++)
    {
        m_background += std::string(in_width, ' ');
    }
}

UIElement::~UIElement()
{
}

void UIElement::draw(tcod::Console *in_console)
{
}
