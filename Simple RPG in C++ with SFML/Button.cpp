#include "Button.h"

int Button::button_click(sf::Sprite &a, sf::RenderWindow &window)
{   
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    sf::Event event;
    if(a.getGlobalBounds().contains(translated_pos))
            while (window.pollEvent(event)) 
            {
                switch (event.type)
                {
                case sf::Event::MouseButtonReleased:
                     return 1;
                break;
                }
            }
    return 0;
}