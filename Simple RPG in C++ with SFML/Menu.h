#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
public:
    sf::Texture menu_button_texture;
    sf::Sprite new_game;
    sf::Sprite exit;
    sf::Text new_game_text;
    sf::Text exit_text;
    sf::Text instrucion_text;

    Menu()
    {
        menu_button_texture.loadFromFile("graphic/text_holder.png");
        new_game.setTexture(menu_button_texture);
        exit.setTexture(menu_button_texture);
    }

    void main_menu(sf::Font font,sf::RenderWindow &window);
    int menu_click(sf::Sprite &a, sf::RenderWindow &window);
    void game_over_menu(sf::RenderWindow &window, int stage, int gold,sf::Font font);
};