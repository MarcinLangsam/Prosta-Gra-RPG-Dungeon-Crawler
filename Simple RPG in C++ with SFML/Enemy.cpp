#include "Enemy.h"
#include <math.h>

float Enemy::length(sf::Vector2<float> const &a)
{
    return hypot(a.x, a.y);
}

void Enemy::enemy_movment(sf::Sprite enemys[20], sf::Sprite &hero,sf::Clock &animation, int sprite_x, int sprite_y)
{
    const int enemy_range=280/3;
    static int frame1 = 0;
    static int frame2 = 0;
 
    for(int i=0;i<20;i++)
    {
        sf::Vector2<float> pos = enemys[i].getPosition();
        sf::Vector2<float> pos2 = hero.getPosition();
        float dd =length(pos-pos2);
        if (dd < enemy_range)
        
        
        if(dd!=0)
        {
            if (animation.getElapsedTime().asSeconds()>0.10)
            {
                frame2++;
                if(frame2>5) frame2=0;
                enemy_rect.left=sprite_x;
                enemy_rect.top=sprite_y;

                enemy_rect.left+=32*frame2;
                    
                enemy[i].setTextureRect(enemy_rect);
                animation.restart();
            }
            sf::Vector2<float> d,k;
            d=pos-pos2;
            k=-d/dd;
            k.x=k.x*0.55;
            k.y=k.y*0.55;
            enemys[i].move(k);
        }
    }
}

void Enemy::idle(int witch_enemy, sf::Sprite enemys[20], sf::Clock& animation, int sprite_x, int sprite_y)
{

    static int frame2 = 0;

    if (animation.getElapsedTime().asSeconds() > 0.40)
    {
        frame2++;
        if (frame2 > 3) frame2 = 0;
        enemy_rect.left = sprite_x;
        enemy_rect.top = sprite_y;

        enemy_rect.left += 32 * frame2;

        enemy[witch_enemy].setTextureRect(enemy_rect);
        animation.restart();
    }
   
}