#include "Text.h"

void Text::set_text_hero(int HP, int MP, int HP_e, int h_p, int m_p)
{
    std::string health=std::to_string(HP);
    std::string mana=std::to_string(MP);
    std::string health_e=std::to_string(HP_e);
    std::string health_potion=std::to_string(h_p);
    std::string mana_potion=std::to_string(m_p);
    HP_hero.setString(health);
    HP_hero.setCharacterSize(16);
    HP_hero.setFillColor(sf::Color::Red);
    MP_hero.setString(mana);
    MP_hero.setCharacterSize(16);
    MP_hero.setFillColor(sf::Color::Blue);
    HP_enemy.setString(health_e);
    HP_enemy.setCharacterSize(16);
    HP_enemy.setFillColor(sf::Color::Red);
    health_potion_left.setString(health_potion);
    health_potion_left.setCharacterSize(25);
    health_potion_left.setFillColor(sf::Color::White);
    mana_potion_left.setString(mana_potion);
    mana_potion_left.setCharacterSize(25);
    mana_potion_left.setFillColor(sf::Color::White);
}

void Text::text_damage(std::string n,int value,sf::RenderWindow &window,int who)
{
    std::string v=std::to_string(value);
    notification_hp.setString(n+v);
    notification_hp.setCharacterSize(16);
    if(n=="+") notification_hp.setFillColor(sf::Color::Green);
    else notification_hp.setFillColor(sf::Color::Red);
    if(who==1) notification_hp.setPosition((HP_hero.getPosition().x+30),HP_hero.getPosition().y);
    if(who==1&&n=="+") notification_hp.setPosition((HP_hero.getPosition().x-40),HP_hero.getPosition().y);
    if(who==0) notification_hp.setPosition((HP_enemy.getPosition().x+20),HP_enemy.getPosition().y);
    window.draw(notification_hp);
    window.display();
    sf::sleep(sf::milliseconds(1000));
}

void Text::text_magic(std::string n, int value, sf::RenderWindow& window, int who)
{
    std::string v = std::to_string(value);
    notification_mp.setString(n + v);
    notification_mp.setCharacterSize(16);
    if (n == "+") notification_mp.setFillColor(sf::Color::Cyan);
    else notification_mp.setFillColor(sf::Color::Blue);
    if (who == 1) notification_mp.setPosition((HP_hero.getPosition().x + 30), HP_hero.getPosition().y+15);
    if (who == 1 && n == "+") notification_mp.setPosition((HP_hero.getPosition().x - 40), HP_hero.getPosition().y+15);
    window.draw(notification_mp);
    window.display();
    sf::sleep(sf::milliseconds(1000));
}