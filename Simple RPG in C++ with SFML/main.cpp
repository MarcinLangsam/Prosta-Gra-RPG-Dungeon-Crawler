#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Button.h"
#include "Text.h"
#include "Menu.h"

using namespace std;

std::string game_state="menu";
int witch_enemy=0;
int witch_obj=0;
int keyleft=0,keyright=0,keyup=0,keydown=0;
const int W=1920;
const int H=1080;
bool wait=false;
bool respond=false;
bool fight_in_tomb = false;
int action=0;
int stage=0;

void events(sf::RenderWindow &window) //obslugo zdarzen okna
{
    sf::Event event;
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A)) keyleft=1; else keyleft=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)) keyright=1; else keyright=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W)) keyup=1; else keyup=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S)) keydown=1; else keydown=0;
        }
}

int collision_sprite_sprite(sf::Sprite &a, sf::Sprite &b)
{
    sf::FloatRect shape1 = a.getGlobalBounds();
    sf::FloatRect shape2 = b.getGlobalBounds();

    if(a.getPosition().x < b.getPosition().x + shape2.width)
        if(a.getPosition().x + shape1.width > b.getPosition().x)
            if(a.getPosition().y < b.getPosition().y + shape2.height)
                if(a.getPosition().y + shape1.height > b.getPosition().y)
                {
                    return 1;
                }
    return 0;
}

int collision(sf::Sprite enemys[], sf::Sprite &b)
{
    int is_collsion=0;
    for(int i=0;i<20;i++)
    {
        is_collsion += collision_sprite_sprite(enemys[i],b);
        if(collision_sprite_sprite(enemys[i],b)==1) witch_enemy=i;
    }
    return is_collsion;
}

int collision_obj(sf::Sprite object[20], sf::Sprite &b)
{
    int is_collsion=0;
    for(int i=0;i<20;i++)
    {
        is_collsion += collision_sprite_sprite(object[i],b);
        if(collision_sprite_sprite(object[i],b)==1) witch_obj=i;
    }
    return is_collsion;
}

int collision_exit(sf::Sprite &object, sf::Sprite &b)
{
    int is_collsion=0;
    is_collsion += collision_sprite_sprite(object,b);
    return is_collsion;
}

int collision_wall(sf::Sprite wall[1089], sf::Sprite &b)
{
    int is_collsion=0;
    for(int i=0;i< 1089;i++)
    {
        is_collsion += collision_sprite_sprite(wall[i],b);
    }
    return is_collsion;
}
void Set_up_map(sf::RenderWindow &window,sf::Sprite floor[],sf::Sprite wall[],std::string map[33][33],sf::Sprite &hero,sf::Sprite fountain[],sf::Sprite shrine[],sf::Sprite tomb[],sf::Sprite chest[], sf::Sprite &stairs,sf::Sprite enemy[])
{
    int count=0;
    int count_for_obj=0;
    int move_right=0;
    int move_down=0;
       
    for(int i=0;i<33;i++)
    {
        for(int j=0;j<33;j++)
        {
            if(map[i][j]=="#" || map[i][j]==",")
            {
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]==".")
            {
                wall[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="P")
            {
                hero.setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="C")
            {
                chest[count_for_obj].setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="F")
            {
                fountain[count_for_obj].setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="S")
            {
                shrine[count_for_obj].setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="T")
            {
                tomb[count_for_obj].setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="O")
            {
                stairs.setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            if(map[i][j]=="W")
            {
                enemy[count_for_obj].setPosition(move_right,move_down);
                floor[count].setPosition(move_right,move_down);
            }
            
            move_right+=40;
            count++;
        }
        move_right=0;
        move_down+=40;
        count_for_obj++;
    }
}

void battle_next_turn(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window, sf::Sprite battle_background, Button button)
{
    window.clear();
    player.idle(player.hero, player.animation, player.rect_hero, 0, 0, 0, 0);
    enemy.idle(witch_enemy,enemy.enemy, enemy.animation, 0, 44);
    text.set_text_hero(player.HP, player.MP, enemy.HP, player.health_potion, player.mana_potion);
    window.draw(battle_background);
    window.draw(player.hero);
    window.draw(enemy.enemy[witch_enemy]);
    window.draw(button.attack);
    window.draw(button.spell);
    window.draw(button.defend);
    window.draw(button.HP);
    window.draw(button.MP);
    window.draw(text.HP_hero);
    window.draw(text.MP_hero);
    window.draw(text.HP_enemy);
    window.draw(text.health_potion_left);
    window.draw(text.mana_potion_left);
    window.display();
}

void check_victory(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window, sf::Sprite battle_background, Button button)
{
    if (enemy.HP <= 0)
    {
        battle_next_turn(player, enemy, text, window, battle_background, button);
        respond = false;
        wait = false;
        action = 0;
        player.EXP += enemy.EXP_gain;
        enemy.HP = enemy.MAX_HP;
        player.gold += 100;
        player.pop_up("ZWYCIESTWO!", text.font, window);
        player.pop_up("Zloto +100, EXP +2", text.font, window);
        if (player.level_up()) { player.pop_up("Osiagnieto nowy poziom", text.font, window); }
        if (fight_in_tomb == true) { player.pop_up(player.tomb_loot(), text.font, window); fight_in_tomb = false; }
        enemy.enemy[witch_enemy].setPosition(9999, 9999);
        player.hero.setPosition((player.hero.getPosition().x) + 80, player.hero.getPosition().y);
        game_state = "map";
    }
}

void check_defeat(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window)
{
    if (player.HP <= 0)
    {
        respond = false;
        action = 0;
        player.pop_up("KONIEC GRY!", text.font, window);
        player.pop_up("Wynik koncowy to: " + std::to_string(player.gold), text.font, window);
        window.close();
    }
}

void enemy_respond(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window)
{
    if (action == 3) { player.HP -= enemy.STR / 4; text.text_damage("-", enemy.STR/4, window, 1); }
    else { player.HP -= enemy.STR; text.text_damage("-", enemy.STR, window, 1); }
    wait = false;
    check_defeat(player,enemy,text,window);
}

void player_attack(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window)
{
    enemy.HP -= player.STR + player.weapon_s;
    text.text_damage("-", player.STR + player.weapon_s, window, 0);
}

void player_turn(Player& player, Enemy& enemy, Text& text, sf::RenderWindow& window, sf::Sprite battle_background, Button button)
{
    if(wait != true) battle_next_turn(player, enemy, text, window, battle_background, button);
    if (button.button_click(button.attack, window)) { action = 1; }
    if (button.button_click(button.spell, window)) { action = 2; }
    if (button.button_click(button.defend, window)) { action = 3; }
    if (button.button_click(button.HP, window)) { action = 4; }
    if (button.button_click(button.MP, window)) { action = 5; }
    switch (action)
    {
    case 1:
        player_attack(player, enemy, text, window);
        respond = true;
        check_victory(player, enemy, text, window,battle_background,button);
        break;
    case 2:
        if (player.spell_lv == 0) {
            player.pop_up("Nie masz zadnych zaklec", text.font, window);
            action = 0;
        }
        else
        {
            window.draw(button.back);
            if (player.spell_lv > 0) window.draw(button.heal);
            if (player.spell_lv > 1) window.draw(button.lighting);
            if (player.spell_lv > 2) window.draw(button.magicSword);
            if (player.spell_lv > 3) window.draw(button.nullEvil);
            if (wait != true) window.display();
            wait = true;
            if (button.button_click(button.back, window))
            {
                wait = false;
                battle_next_turn(player, enemy, text, window, battle_background, button);
                action = 0;
            }
            if (button.button_click(button.heal, window))
            {
                if (player.MP < 30) { player.pop_up("Brakuje many", text.font, window); action = 0; wait = false; }
                else
                {
                    player.MP -= 30;
                    player.HP += (30 + player.INT + player.amulet_s);
                    text.text_magic("-", 30, window, 1);
                    text.text_damage("+", 30 + player.INT + player.amulet_s, window, 1);
                    if (player.HP > player.MAX_HP) player.HP = player.MAX_HP;
                    respond = true;
                    wait = true;
                    check_victory(player, enemy, text, window, battle_background, button);
                }
            }
            
            if (button.button_click(button.lighting, window))
            {
                if (player.MP < 30) { player.pop_up("Brakuje many", text.font, window); action = 0; wait = false; }
                else
                {
                    player.MP -= 30;
                    enemy.HP -= (30 + player.INT + player.amulet_s);
                    text.text_magic("-", 30, window, 1);
                    text.text_damage("-", 30 + player.INT + player.amulet_s, window, 0);
                    respond = true;
                    wait = true;
                    check_victory(player, enemy, text, window, battle_background, button);
                }
            }
            
            if (button.button_click(button.magicSword, window))
            {
                if (player.MP < 50) { player.pop_up("Brakuje many", text.font, window); action = 0; wait = false; }
                else
                {
                    player.MP -= 50;
                    enemy.HP -= 80;
                    text.text_magic("-", 50, window, 1);
                    text.text_damage("-", 80, window, 0);
                    respond = true;
                    wait = true;
                    check_victory(player, enemy, text, window, battle_background, button);
                }
            }
            
            if (button.button_click(button.nullEvil, window))
            {
                if (player.MP < 100) { player.pop_up("Brakuje many", text.font, window); action = 0; wait = false;}
                else
                {
                    player.MP -= 100;
                    enemy.HP -= 9999;
                    text.text_magic("-", 100, window, 1);
                    text.text_damage("-", 9999, window, 0);
                    respond = true;
                    wait = true;
                    check_victory(player, enemy, text, window, battle_background, button);
                }
            }
            break;
    case 3:
        respond = true;
        wait = false;
        break;
    case 4:
        if (player.health_potion > 0)
        {
            player.HP += 100;
            if (player.HP > player.MAX_HP) player.HP = player.MAX_HP;
            text.text_damage("+", 100, window, 1);
            player.health_potion -= 1;
            respond = true;
            wait = false;
        }
        else {player.pop_up("Nie masz mikstor zdrowia", text.font, window); action = 0;}
        break;
    case 5:
        if (player.mana_potion > 0)
        {
            player.MP += 100;
            if (player.MP > player.MAX_MP) player.MP = player.MAX_MP;
            text.text_magic("+", 100, window, 1);
            player.mana_potion -= 1;
            respond = true;
            wait = false;
        }
        else {player.pop_up("Nie masz mikstor many", text.font, window); action = 0; }
        break;

    default:
        break;
        }
    }
}

int main()
{
    Map mapa;
    mapa.generator();
    Menu menu;
    Player player;
    Enemy enemy;
    Button button;
    Text text;

    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    sf::Texture battle_background_texture;
    battle_background_texture.loadFromFile("graphic/battle_background.png");
    sf::Sprite battle_background;
    battle_background.setTexture(battle_background_texture);
    battle_background.setScale(0.45,0.45);
    sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(350.0f,300.0f));

    sf::Texture floor_texture;
    floor_texture.loadFromFile("graphic/floor.png");
    sf::Texture wall_texture;
    wall_texture.loadFromFile("graphic/wall.png");
    sf::Texture fountain_texture;
    sf::Texture shrine_texture;
    sf::Texture tomb_texture;
    sf::Texture chest_texture;
    sf::Texture stairs_texture;
    fountain_texture.loadFromFile("graphic/fountain.png");
    shrine_texture.loadFromFile("graphic/shrine.png");
    tomb_texture.loadFromFile("graphic/tomb.png");
    chest_texture.loadFromFile("graphic/chest.png");
    stairs_texture.loadFromFile("graphic/stairs.png");
    sf::IntRect rect(0,0,20,20);
    sf::Sprite floor[1089] = {};
    sf::Sprite wall[1089] = {};
    sf::Sprite fountain[20] = {};
    sf::Sprite shrine[20] = {};
    sf::Sprite tomb[20] = {};
    sf::Sprite chest[20] = {};
    sf::Sprite stairs=sf::Sprite(stairs_texture);
    stairs.scale(1.2,1.2);
    for(int i=0;i<1089;i++)
    {
        floor[i]=sf::Sprite(floor_texture,rect);
        wall[i]=sf::Sprite(wall_texture,rect);
        floor[i].setScale(2.0, 2.0);
        wall[i].setScale(2.0, 2.0);
    }
    for(int i=0;i<20;i++)
    {
        fountain[i]=sf::Sprite(fountain_texture);
        fountain[i].scale(0.6,0.6);
        fountain[i].setPosition(9999,9999);
        shrine[i]=sf::Sprite(shrine_texture);
        shrine[i].scale(0.5,0.5);
        shrine[i].setPosition(9999,9999);
        tomb[i]=sf::Sprite(tomb_texture);
        tomb[i].scale(1.15,1.15);
        tomb[i].setPosition(9999,9999);
        chest[i]=sf::Sprite(chest_texture);
        chest[i].scale(0.85,0.85);
        chest[i].setPosition(9999,9999);
    }
        
    window.setFramerateLimit(60); //ustawienie 60 klatek na skeundę
    Set_up_map(window,floor,wall,mapa.map,player.hero,fountain,shrine,tomb,chest,stairs,enemy.enemy);
    sf::Clock clock;
    


    while (window.isOpen()) //petla gry
    {
        events(window);
        if (collision_obj(tomb, player.hero))
        {
            if (tomb[witch_obj].getColor() == sf::Color::Red);
            else
            {
                
                player.pop_up("Artefaktu pilnuje wrog!", text.font, window);
                view.setCenter(player.hero.getPosition());
                window.setView(view);
                battle_background.setPosition((player.hero.getPosition().x) - 220, player.hero.getPosition().y - 160);
                player.hero.setPosition((player.hero.getPosition().x) - 80, player.hero.getPosition().y);
                enemy.enemy[witch_enemy].setPosition((player.hero.getPosition().x) + 140, player.hero.getPosition().y);
                button.attack.setPosition((player.hero.getPosition().x) - 52, player.hero.getPosition().y + 85);
                button.spell.setPosition((player.hero.getPosition().x) - 8, player.hero.getPosition().y + 85);
                button.defend.setPosition((player.hero.getPosition().x) + 36, player.hero.getPosition().y + 85);
                button.HP.setPosition((player.hero.getPosition().x) + 80, player.hero.getPosition().y + 85);
                button.MP.setPosition((player.hero.getPosition().x) + 153, player.hero.getPosition().y + 85);
                button.heal.setPosition((player.hero.getPosition().x) - 80, player.hero.getPosition().y + 40);
                button.lighting.setPosition((player.hero.getPosition().x) - 6, player.hero.getPosition().y + 40);
                button.magicSword.setPosition((player.hero.getPosition().x) + 68, player.hero.getPosition().y + 40);
                button.nullEvil.setPosition((player.hero.getPosition().x) + 142, player.hero.getPosition().y + 40);
                button.back.setPosition((player.hero.getPosition().x) + 216, player.hero.getPosition().y + 40);
                text.HP_hero.setPosition((player.hero.getPosition().x), player.hero.getPosition().y - 40);
                text.MP_hero.setPosition((player.hero.getPosition().x), player.hero.getPosition().y - 25);
                text.HP_enemy.setPosition((enemy.enemy[witch_enemy].getPosition().x + 10), enemy.enemy[witch_enemy].getPosition().y - 30);
                text.health_potion_left.setPosition((player.hero.getPosition().x) + 117, player.hero.getPosition().y + 85);
                text.mana_potion_left.setPosition((player.hero.getPosition().x) + 190, player.hero.getPosition().y + 85);
                window.clear();
                window.display();
                game_state = "fight";
                fight_in_tomb = true;
                tomb[witch_obj].setColor(sf::Color::Red);
            }
        }
        if (collision(enemy.enemy, player.hero))
        {
            battle_background.setPosition((player.hero.getPosition().x) - 220, player.hero.getPosition().y - 160);
            player.hero.setPosition((player.hero.getPosition().x) - 80, player.hero.getPosition().y);
            enemy.enemy[witch_enemy].setPosition((player.hero.getPosition().x) + 140, player.hero.getPosition().y);
            button.attack.setPosition((player.hero.getPosition().x) - 52, player.hero.getPosition().y + 85);
            button.spell.setPosition((player.hero.getPosition().x) - 8, player.hero.getPosition().y + 85);
            button.defend.setPosition((player.hero.getPosition().x) + 36, player.hero.getPosition().y + 85);
            button.HP.setPosition((player.hero.getPosition().x) + 80, player.hero.getPosition().y + 85);
            button.MP.setPosition((player.hero.getPosition().x) + 153, player.hero.getPosition().y + 85);
            button.heal.setPosition((player.hero.getPosition().x) - 80, player.hero.getPosition().y + 40);
            button.lighting.setPosition((player.hero.getPosition().x) - 6, player.hero.getPosition().y + 40);
            button.magicSword.setPosition((player.hero.getPosition().x) + 68, player.hero.getPosition().y + 40);
            button.nullEvil.setPosition((player.hero.getPosition().x) + 142, player.hero.getPosition().y + 40);
            button.back.setPosition((player.hero.getPosition().x) + 216, player.hero.getPosition().y + 40);
            text.HP_hero.setPosition((player.hero.getPosition().x), player.hero.getPosition().y - 40);
            text.MP_hero.setPosition((player.hero.getPosition().x), player.hero.getPosition().y - 25);
            text.HP_enemy.setPosition((enemy.enemy[witch_enemy].getPosition().x+10), enemy.enemy[witch_enemy].getPosition().y - 30);
            text.health_potion_left.setPosition((player.hero.getPosition().x) + 117, player.hero.getPosition().y + 85);
            text.mana_potion_left.setPosition((player.hero.getPosition().x) + 190, player.hero.getPosition().y + 85);
            window.clear();
            window.display();
            game_state = "fight";
            
        }
        if (game_state == "menu") //menu glowne
        {
            window.clear();
            player.status.setPosition(3, 200);
            player.status.setScale(3.7, 1.8);
            window.draw(player.status);
            menu.main_menu(text.font, window);
            if (button.button_click(menu.new_game, window))
            {
                game_state = "map";
            }
            if (button.button_click(menu.exit, window))
            {
                window.close();
            }
            window.display();
        }
        if (game_state == "map") //chodzenie po mapie
        {
            if (keyleft == 1)
            {
                player.movment(player.hero, player.animation, player.rect_hero, -1.8, 0, 0, 132);
            }
            if (keyright == 1)
            {
                player.movment(player.hero, player.animation, player.rect_hero, 1.8, 0, 0, 88);
            }
            if (keyup == 1)
            {
                player.movment(player.hero, player.animation, player.rect_hero, 0, -1.8, 0, 88);
            }
            if (keydown == 1)
            {
                player.movment(player.hero, player.animation, player.rect_hero, 0, 1.8, 0, 132);
            }
            if (keyup == 0 && keydown == 0 && keyleft == 0 && keyright == 0)
            {
                player.idle(player.hero, player.animation, player.rect_hero, 0, 0, 0, 0);
            }
            
            enemy.enemy_movment(enemy.enemy, player.hero, enemy.animation, 0, 88);


            if (collision_wall(wall, player.hero))
            {
                if (keyright == 1) player.hero.move(-1, 0);
                if (keyup == 1) player.hero.move(0, 1);
                if (keydown == 1) player.hero.move(0, -1);
                if (keyleft == 1) player.hero.move(1, 0);
            }
            if (collision_obj(fountain, player.hero))
            {
                if (fountain[witch_obj].getColor() == sf::Color::Red);
                else
                {
                    player.HP = player.MAX_HP;
                    player.MP = player.MAX_MP;
                    player.pop_up("Odnowiono zdrowie i mane", text.font, window);
                    fountain[witch_obj].setColor(sf::Color::Red);
                }

            }
            if (collision_obj(shrine, player.hero))
            {
                if (shrine[witch_obj].getColor() == sf::Color::Red);
                else
                {
                    if (player.spell_lv >= 4) { player.gold += 500; player.pop_up("Znasz juz wszystkie zakleica", text.font, window); player.pop_up("Zloto +500", text.font, window); }
                    else { player.spell_lv += 1; player.pop_up("Nauczyles sie nowego zaklecia", text.font, window); }
                    shrine[witch_obj].setColor(sf::Color::Red);
                }
            }

            if (collision_obj(chest, player.hero))
            {
                if (chest[witch_obj].getColor() == sf::Color::Red);
                else
                {
                    int los = rand() % 100;
                    if (los < 40) { player.gold += 50; player.pop_up("Znalazles zloto +50", text.font, window); }
                    if (los >= 40 && los < 60) { player.gold += 250; player.pop_up("Znalazles zloto +250", text.font, window); }
                    if (los >= 60 && los < 80) { player.health_potion += 1; player.pop_up("Znalazles miksture zdrowia", text.font, window); }
                    if (los >= 80 && los < 100) { player.mana_potion += 1; player.pop_up("Znalazles miksture many", text.font, window); }
                    chest[witch_obj].setColor(sf::Color::Red);
                }
            }

            if (collision_exit(stairs, player.hero))
            {
                mapa.generator();
                mapa.show();
                view.setCenter(player.hero.getPosition());
                window.clear();
                window.setView(view);
                for (int i = 0; i < 1089; i++)
                {
                    floor[i].setPosition(9999, 9999);
                    wall[i].setPosition(9999, 9999);
                }
                window.draw(player.hero);
                for (int i = 0; i < 20; i++)
                    enemy.enemy[i].setPosition(9999, 9999);
                for (int i = 0; i < 20; i++)
                {
                    fountain[i].setPosition(9999, 9999);
                    fountain[i].setColor(sf::Color::White);
                    shrine[i].setPosition(9999, 9999);
                    shrine[i].setColor(sf::Color::White);
                    tomb[i].setPosition(9999, 9999);
                    tomb[i].setColor(sf::Color::White);
                    chest[i].setPosition(9999, 9999);
                    chest[i].setColor(sf::Color::White);
                }
                stairs.setPosition(9999, 9999);
                Set_up_map(window, floor, wall, mapa.map, player.hero, fountain, shrine, tomb, chest, stairs, enemy.enemy);
                window.display();
                stage++;
                if (stage % 5 == 0)
                {
                    enemy.MAX_HP += 50;
                    enemy.STR += 10;
                    enemy.HP = enemy.MAX_HP;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) game_state = "status";

            view.setCenter(player.hero.getPosition());
            window.clear();
            window.setView(view);
            for (int i = 0; i < 1089; i++)
            {
                window.draw(floor[i]);
                window.draw(wall[i]);
            }
            for (int i = 0; i < 20; i++)
                window.draw(enemy.enemy[i]);
            for (int i = 0; i < 20; i++)
            {
                window.draw(fountain[i]);
                window.draw(shrine[i]);
                window.draw(tomb[i]);
                window.draw(chest[i]);
            }
            window.draw(player.hero);
            window.draw(stairs);
            window.display();
        }
        if (game_state == "status") //status
        {
            player.menu(window, text.font);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) game_state = "map";
        }
        if (game_state == "fight") //walka
        {           
            player_turn(player, enemy, text, window, battle_background, button);
            if (respond == true) { enemy_respond(player, enemy, text, window); action = 0; respond = false; player_turn(player, enemy, text, window, battle_background, button); }
        
        }
    }
    return 0;
} 