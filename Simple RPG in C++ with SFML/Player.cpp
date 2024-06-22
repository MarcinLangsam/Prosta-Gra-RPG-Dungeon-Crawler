#include "Player.h"

//lr - ruch w lewo badz prawo, ud - ruch w gore badz dol, sprite_x i sprite_y - wspolrzadne x i y w sprite'cie  
void Player::movment(sf::Sprite &hero, sf::Clock &animation, sf::IntRect &rect, int lr,int ud, int sprite_x, int sprite_y)
{
    static int frame = 0;
    hero.move(lr,ud);
    if (animation.getElapsedTime().asSeconds()>0.15)
    {
        frame++;
        if(frame>5) frame=0;
        rect.left=sprite_x;
        rect.top=sprite_y;

        rect.left+=32*frame;
            
        hero.setTextureRect(rect);
        animation.restart();
    }
}

void Player::idle(sf::Sprite &hero, sf::Clock &animation, sf::IntRect &rect, int lr,int ud, int sprite_x, int sprite_y)
{
    static int frame = 0;
    if (animation.getElapsedTime().asSeconds()>0.40)
    {
        frame++;
        if(frame>3) frame=0;
        rect.left=sprite_x;
        rect.top=sprite_y;

        rect.left+=32*frame;
            
        hero.setTextureRect(rect);
        animation.restart();
    }
}

int Player::level_up()
{
	if (EXP >= 10 * Lv)
	{
        MAX_HP+=20;
        MAX_MP+=10;

		HP = MAX_HP;
		MP = MAX_MP;
		STR = STR + (2 * Lv);
		INT = INT + (2 * Lv);
        EXP = 0;
		Lv += 1;
        return 1;
    }
    return 0;
}

void Player::menu(sf::RenderWindow &window, sf::Font font)
{
    std::string L=std::to_string(Lv);
    std::string max_health=std::to_string(MAX_HP);
    std::string max_mana=std::to_string(MAX_MP);
    std::string health=std::to_string(HP);
    std::string mana=std::to_string(MP);
    std::string strength=std::to_string(STR);
    std::string inteligence=std::to_string(INT);
    std::string xp=std::to_string(EXP);
    std::string next_lv=std::to_string(Lv*10);
    std::string strength_plus=std::to_string(weapon_s);
    std::string inteligence_plus=std::to_string(amulet_s);
    std::string G=std::to_string(gold);
    std::string h_potion = std::to_string(health_potion);
    std::string m_potion = std::to_string(mana_potion);
    std::string s_lv = std::to_string(spell_lv);
    std::string stats="\nLv: "+L+"\nHP "+health+"/"+max_health+"\nMP "+mana+"/"+max_mana+"\nSTR: "+strength+"+"+strength_plus+"\nINT: "+inteligence+"+"+inteligence_plus+"\nEXP: " + xp + "/" + next_lv + "\n" + weapon + "\n" + amulet +"\nPoziom czaru: "+ s_lv + "\nMikstury zdrowa: " + h_potion + "\nMikstury many: " + m_potion+"\nZloto: "+G;
    status.setPosition(hero.getPosition().x-170,hero.getPosition().y-155);
    status.setScale(0.5,0.5);
    window.draw(status);
    text_for_menu.setFont(font);
    text_for_menu.setString(stats);
    text_for_menu.setCharacterSize(11);
    text_for_menu.setFillColor(sf::Color::White);
    text_for_menu.setPosition(status.getPosition().x+12,status.getPosition().y+20);
    window.draw(text_for_menu);
    window.display();
}

std::string Player::tomb_loot()
{
    int loot=rand()%100;
    if (loot < 50)
    {
        if (weapon_s == 30) { gold += 500; return "Zdobyles: Zloto + 500"; }
        else weapon_s+=5;
        if(weapon_s==5) weapon="Stalowy miecz";
        if(weapon_s==10) weapon="Topor bojowy";
        if(weapon_s==15) weapon="Metorytowe ostrze";
        if(weapon_s==20) weapon="Runiczny Sihill";
        if(weapon_s==25) weapon="Długi Pazur";
        if(weapon_s==30) weapon="Areondight";
        return "Zdobyles: "+weapon;
    }
    if(loot>=50)
    {
        if(amulet_s==30) { gold += 500; return "Zdobyles: Zloto + 500"; }
        else amulet_s+=5;
        if(amulet_s==5) amulet="Pierscien magi";
        if(amulet_s==10) amulet="Magiczny naszyjnik";
        if(amulet_s==15) amulet="Runiczne rekawice";
        if(amulet_s==20) amulet="Naszyjnik Talosa";
        if(amulet_s==25) amulet="Opncza Wauken";
        if(amulet_s==30) amulet="Korona Krolow";
        return "Zdobyles: "+amulet;
    }
}

void Player::pop_up(std::string t,sf::Font font,sf::RenderWindow &window)
{
    sf::Text text;
    
    text_holder.setPosition(hero.getPosition().x-30,hero.getPosition().y-150);
    
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setString(t);
    text.setPosition(text_holder.getPosition().x+4,text_holder.getPosition().y+8);

    window.draw(text_holder);
    window.draw(text);
    window.display();
    sf::sleep(sf::milliseconds(2000));
}

void Player::stats_reset()
{
    MAX_HP=200;
    MAX_MP=100;
    HP=MAX_HP;
    MP=MAX_MP;
    STR=10;
    INT=10;
    EXP=0;
    Lv=1;
    gold=0;
    weapon_s=0;
    amulet_s=0;
    weapon="";
    amulet="";
    spell_lv=0;
    health_potion=1;
    mana_potion=1;
}