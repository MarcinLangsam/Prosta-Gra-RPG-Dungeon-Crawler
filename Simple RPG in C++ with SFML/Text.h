#include <SFML/Graphics.hpp>
#include <iostream>

class Text
{
public:
    sf::Font font;
    sf::Text HP_hero;
    sf::Text MP_hero;
    sf::Text HP_enemy;
    sf::Text notification_hp;
    sf::Text notification_mp;
    sf::Text health_potion_left;
    sf::Text mana_potion_left;

    Text()
    {
        font.loadFromFile("graphic/font.ttf");
        HP_hero.setFont(font);
        MP_hero.setFont(font);
        HP_enemy.setFont(font);
        notification_hp.setFont(font);
        notification_mp.setFont(font);
        health_potion_left.setFont(font);
        mana_potion_left.setFont(font);
    }

    void set_text_hero(int HP,int MP,int HP_e,int h_p, int m_p);
    void text_damage(std::string n,int STR,sf::RenderWindow &window,int who);
    void text_magic(std::string n,int STR,sf::RenderWindow &window,int who);
};