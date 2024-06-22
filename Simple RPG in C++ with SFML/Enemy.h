#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public:
    int MAX_HP=50;
    int HP=50;
    int STR=5;
    int EXP_gain=2;
    sf::Texture enemy_texture;
    sf::IntRect enemy_rect;
    sf::Sprite enemy[20]={};
    sf::Clock animation;

    Enemy()
    {
        enemy_texture.loadFromFile("graphic/skeleton_animation.png");
        enemy_rect.top=88;
        enemy_rect.left=0;
        enemy_rect.width=32;
        enemy_rect.height=44;
        for(int i=0;i<20;i++)
        {
            enemy[i]=sf::Sprite(enemy_texture,enemy_rect);
        }
    }

    float length(sf::Vector2<float> const &a);
    void idle(int witch_enemy,sf::Sprite enemys[20], sf::Clock& animation, int sprite_x, int sprite_y);
    void enemy_movment(sf::Sprite enemys[20], sf::Sprite &hero,sf::Clock &animation, int sprite_x, int sprite_y);
};