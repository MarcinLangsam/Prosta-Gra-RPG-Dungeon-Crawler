#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    sf::Texture icons_w_bg;
    sf::IntRect attack_butt;
    sf::IntRect spell_butt;
    sf::IntRect defend_butt;
    sf::IntRect HP_butt;
    sf::IntRect MP_butt;
    sf::IntRect heal_spell_butt;
    sf::IntRect lighting_spell_butt;
    sf::IntRect magicSword_spell_butt;
    sf::IntRect nullEvil_spell_butt;
    sf::IntRect back_butt;
    sf::Sprite attack;
    sf::Sprite spell;
    sf::Sprite defend;
    sf::Sprite HP;
    sf::Sprite MP;
    sf::Sprite heal;
    sf::Sprite lighting;
    sf::Sprite magicSword;
    sf::Sprite nullEvil;
    sf::Sprite back; 
    sf::Mouse mouse;
    Button()
    {
        icons_w_bg.loadFromFile("graphic/icons.png");
        attack_butt.left=0; attack_butt.top=0; attack_butt.width=32; attack_butt.height=32;
        attack.setTexture(icons_w_bg);
        attack.setTextureRect(attack_butt);

        spell_butt.left=64; spell_butt.top=0; spell_butt.width=32; spell_butt.height=32;
        spell.setTexture(icons_w_bg);
        spell.setTextureRect(spell_butt);

        defend_butt.left=32; defend_butt.top=0; defend_butt.width=32; defend_butt.height=32;
        defend.setTexture(icons_w_bg);
        defend.setTextureRect(defend_butt);

        HP_butt.left=96; HP_butt.top=0; HP_butt.width=61; HP_butt.height=32;
        HP.setTexture(icons_w_bg);
        HP.setTextureRect(HP_butt);

        MP_butt.left=157; MP_butt.top=0; MP_butt.width=61; MP_butt.height=32;
        MP.setTexture(icons_w_bg);
        MP.setTextureRect(MP_butt);

        heal_spell_butt.left=0; heal_spell_butt.top=32; heal_spell_butt.width=64; heal_spell_butt.height=32;
        heal.setTexture(icons_w_bg);
        heal.setTextureRect(heal_spell_butt);

        lighting_spell_butt.left=64; lighting_spell_butt.top=32; lighting_spell_butt.width=64; lighting_spell_butt.height=32;
        lighting.setTexture(icons_w_bg);
        lighting.setTextureRect(lighting_spell_butt);

        magicSword_spell_butt.left=128; magicSword_spell_butt.top=32; magicSword_spell_butt.width=64; magicSword_spell_butt.height=32;
        magicSword.setTexture(icons_w_bg);
        magicSword.setTextureRect(magicSword_spell_butt);

        nullEvil_spell_butt.left=192; nullEvil_spell_butt.top=32; nullEvil_spell_butt.width=64; nullEvil_spell_butt.height=32;
        nullEvil.setTexture(icons_w_bg);
        nullEvil.setTextureRect(nullEvil_spell_butt);

        back_butt.left=218; back_butt.top=0; back_butt.width=32; back_butt.height=32;
        back.setTexture(icons_w_bg);
        back.setTextureRect(back_butt);

    }
    
    int button_click(sf::Sprite &a, sf::RenderWindow &window);


};