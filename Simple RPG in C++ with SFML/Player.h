#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
    int MAX_HP=200;
    int MAX_MP=100;
    int HP=200;
    int MP=100;
    int EXP=0;
    int Lv=1;
    int STR=10;
    int INT=10;
    int spell_lv=0;
    int gold=0;
    std::string weapon="";
    std::string amulet="";
    int weapon_s=0;
    int amulet_s=0;
    int health_potion=1;
    int mana_potion=1;
    sf::Texture hero_animation;
    sf::IntRect rect_hero;
    sf::IntRect rect_hero_battle;
    sf::RectangleShape collsion_rect;
    sf::Sprite hero;
    sf::Clock animation;
    sf::Texture status_texture;
    sf::Sprite status;
    sf::Text text_for_menu;
    sf::Texture text_holder_texture; 
    sf::Sprite text_holder;

    Player()
    {
        hero_animation.loadFromFile("graphic/hero_animation.png");
        rect_hero.top=0;
        rect_hero.left=0;
        rect_hero.width=32;
        rect_hero.height=44;
        
        hero.setTexture(hero_animation);
        hero.setTextureRect(rect_hero);
        hero.setOrigin(hero.getPosition()/2.0f);
        collsion_rect.setSize(sf::Vector2f(32,44));

        status_texture.loadFromFile("graphic/status.png");
        status.setTexture(status_texture);
        status.scale(0.3,0.3);

        text_holder_texture.loadFromFile("graphic/text_holder.png");
        text_holder.setTexture(text_holder_texture);
        text_holder.setScale(0.40,0.25);
        
    }

   //lr - ruch w lewo badz prawo, ud - ruch w gore badz dol, sprite_x i sprite_y - wspolrzadne x i y w sprite'cie  
   void movment(sf::Sprite &hero, sf::Clock &animation, sf::IntRect &rect, int lr,int ud, int sprite_x, int sprite_y);
   void idle(sf::Sprite &hero, sf::Clock &animation, sf::IntRect &rect, int lr,int ud, int sprite_x, int sprite_y);
   int level_up();
   void menu(sf::RenderWindow &window,sf::Font font);
   std::string tomb_loot();
   void pop_up(std::string t,sf::Font font,sf::RenderWindow &window);
   void stats_reset();
};